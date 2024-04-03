#include <iostream>
#include <vector>

using namespace std;


int maxLineRepeater(vector<vector<int>> matrix, int n, int m) {
    int line;
    int mx = 0;
    int op_count = 3; // инициализация line, mx и i
    for (int i = 0; i < n; i++)
    {
        op_count += 3; // иницализация cur и j и сравнение в цикле
        int cur = 1;
        for (int j = 0; j < m - 1; j++)
        {
            op_count += 2; // сравнение в цикле и условный оператор
            if (matrix[i][j] == matrix[i][j + 1])
                cur += 1;
                op_count += 2; // инкремент cur и условный оператор
                if (cur >= mx)
                {
                    line = i;
                    mx = cur;
                    op_count += 2; // два присваивания line и mx
                }
            else
            {
                cur = 1;
                op_count += 1; // присваивание cur
            }
        }
    }

    op_count += 2; // инкремент и возврат line
    cout << "maxLineRepeater T(nm) = " << op_count << endl;
    return line + 1;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m));

    cout << "Тестирование: Ввода матрицы" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> matrix[i][j];
        }
    }

    int x = maxLineRepeater(matrix, n, m);
    cout << endl << "Строка номер: " << x << endl;
    return 0;
}
