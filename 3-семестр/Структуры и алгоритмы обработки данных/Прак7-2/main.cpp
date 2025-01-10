
#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
using namespace std;

struct Node
{
    int from;
    int to;
    int weight;
};

using namespace std;

void findShortestPath(const vector<Node> &graph, int start, int end, vector<int> &path, int &minCost, vector<int> &bestPath)
{
    if (start == end)
    {
        int currentCost = 0;
        for (int i = 0; i < path.size() - 1; ++i)
        {
            auto it = find_if(graph.begin(), graph.end(), [&](const Node &node)
                              { return node.from == path[i] && node.to == path[i + 1]; });
            if (it != graph.end())
            {
                currentCost += it->weight;
            }
        }
        if (currentCost < minCost)
        {
            minCost = currentCost;
            bestPath = path;
        }

        return;
    }

    for (auto &edge : graph)
    {
        if (edge.from == start && find(path.begin(), path.end(), edge.to) == path.end())
        {
            path.push_back(edge.to);
            findShortestPath(graph, edge.to, end, path, minCost, bestPath);
            path.pop_back();
        }
    }
}

void menu()
{
    cout << "Программя для работы с графом. Команды:" << endl;
    cout << "1 - Добавить узел" << endl;
    cout << "2 - Найти кратчайший путь" << endl;
    cout << "3 - Использовать предустановленный граф" << endl;
    cout << "4 - Выход" << endl;

    string command;
    int start = 1, end = 6;
    vector<Node> graph = {};

    while (true)
    {
        cout << "Введите номер команды: ";
        cin >> command;
        if (command == "1")
        {
            cout << "Формат ввода: от до вес. Пример: 1 2 5" << endl;
            cout << "Введите узел: ";
            int a, b, c;
            cin >> a >> b >> c;
            graph.push_back({a, b, c});
        }
        else if (command == "2")
        {
            int start, end;
            cout << "Введите номер узла откуда искать: ";
            cin >> start;
            cout << "Введите номер узла до куда искать: ";
            cin >> end;
            vector<int> path = {start};
            vector<int> bestPath;
            int minCost = numeric_limits<int>::max(); 

            findShortestPath(graph, start, end, path, minCost, bestPath);

            cout << "Кратчайший путь: ";
            for (int node : bestPath)
            {
                cout << node << " ";
            }
            cout << endl;
            cout << "Вес всего пути: " << minCost;
        }
        else if (command == "3")
        {
            graph = {
                {1, 2, 8},
                {1, 3, 4},
                {2, 4, 6},
                {2, 5, 3},
                {3, 2, 3},
                {3, 4, 2},
                {3, 6, 10},
                {4, 5, 3},
                {4, 6, 1},
                {5, 6, 4},
            };
        }
        else if(command == "4"){
            break;
        }
        else {
            cout << "Неизвестная команда";
        }
        cout << endl;
    }
}

int main()
{
    menu();
    return 0;
}