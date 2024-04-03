#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>
#include <random>

using namespace std;

vector<string> split(const string &s, char delim)
{
    vector<string> result;
    stringstream ss(s);
    string item;

    while (getline(ss, item, delim))
    {
        result.push_back(item);
    }

    return result;
}

int rnd(int l, int r)
{
    random_device dev;
    mt19937 rng(dev());
    uniform_int_distribution<mt19937::result_type> d(l, r);

    return d(rng);
}

class Ship
{
public:
    // инициализационные
    string name;
    int type, weight, stayTime, arrivalDay, arrivalTime, unloadingTime;
    // случайность
    // статистика
    int delay, penalty, waitingTime, sUnloadingDay, sUnloadingTime, plannedUnloadingTime, plannedArrivalDay;
    bool isUnloadStarted = false;

    int dayOfArrival;

    // int delayDay;

    Ship(string name, int type, int weight, int stayTime, int arrivalDay, int arrivalTime)
    {
        this->name = name;
        this->type = type;
        this->weight = weight;
        this->stayTime = stayTime;
        this->arrivalDay = arrivalDay;
        this->arrivalTime = arrivalTime;

        float coeff;
        if (type == 1)
        {
            coeff = 0.2;
        }
        else if (type == 2)
        {
            coeff = 0.1;
        }
        else
        {
            coeff = 0.35;
        }
        this->unloadingTime = weight * coeff;
        this->plannedUnloadingTime = weight * coeff;
        this->plannedArrivalDay = arrivalDay;
    }

    void add_penalty()
    {
        penalty += 2000;
    }

    friend ostream &operator<<(ostream &output, const Ship &ship)
    {
        string type;
        if (ship.type == 1)
            type = "Сыпучий";
        if (ship.type == 2)
            type = "Жидкий";
        if (ship.type == 3)
            type = "Контейнеры";

        output << ship.name << " | " << type << " | " << ship.weight << " т.тн. | Прибытие: " << ship.arrivalDay << " день " << ship.arrivalTime << ":00 |  Время разгрузки: " << ship.unloadingTime << " ч.";
        return output;
    }
};

class Port
{
public:
    vector<Ship> ships;

    vector<vector<Ship>> queuesDry;       // Очереди на сыпучие краны
    vector<vector<Ship>> queuesLiquid;    // Очереди на жидкостные краны
    vector<vector<Ship>> queuesContainer; // Очереди на контейнерные краны
    int dry_cranes, liquid_cranes, container_cranes, day_num;

    int wholeDelay = 0;
    int delayCount = 0;

    // Итоговая статисткиа
    int unloadedShips = 0;
    float averageQueueSize = 1;
    float averageQueueWait = 1;
    int maxQueueDelay = 0;
    float averageQueueDelay = 1;
    int penalty = 0;

    // Промежуточная статистика
    int dryPenalty = 0;
    int liquidPenalty = 0;
    int containerPenalty = 0;

    int sumOfQueueLengths = 0;
    int sumOfWaitingLengths = 0;

    bool is_show_log = true;

    Port(vector<Ship> ships, int dry_cranes, int liquid_cranes, int container_cranes, bool is_show_log = true, bool do_rand = true)
    {
        this->ships = ships;

        this->dry_cranes = dry_cranes;
        this->liquid_cranes = liquid_cranes;
        this->container_cranes = container_cranes;
        for (int i = 0; i < dry_cranes; i++)
        {
            vector<Ship> queue;
            queuesDry.push_back(queue);
        }
        for (int i = 0; i < liquid_cranes; i++)
        {
            vector<Ship> queue;
            queuesLiquid.push_back(queue);
        }
        for (int i = 0; i < container_cranes; i++)
        {
            vector<Ship> queue;
            queuesContainer.push_back(queue);
        }

        this->day_num = 1;

        if (do_rand)
            apply_random();
        this->is_show_log = is_show_log;
    }
    void cycle()
    {
        if (is_show_log)
        {
            cout << endl
                 << "===============ДЕНЬ " << day_num << "===============" << endl
                 << endl;
        }

        // Заполняем прибывших на текущий день
        vector<Ship> shipsDry;
        vector<Ship> shipsLiquid;
        vector<Ship> shipsContainer;
        for (int i = 0; i < ships.size(); i++)
        {
            ships[i].dayOfArrival = day_num;

            if (ships[i].arrivalDay == day_num)
            {
                if (ships[i].type == 1)
                {
                    shipsDry.push_back(ships[i]);
                }
                else if (ships[i].type == 2)
                {
                    shipsLiquid.push_back(ships[i]);
                }
                else if (ships[i].type == 3)
                {
                    shipsContainer.push_back(ships[i]);
                }
            }
        }

        // Идём по каждому часу в дне
        for (int time = 0; time < 24; time++)
        {
            // Удаляем из очереди корабли которые закончили разгрузку
            erase_queue(queuesDry, time);
            erase_queue(queuesLiquid, time);
            erase_queue(queuesContainer, time);

            // Добавляем следующие корабли
            add_queue(time, shipsDry, queuesDry);
            add_queue(time, shipsLiquid, queuesLiquid);
            add_queue(time, shipsContainer, queuesContainer);
        }

        this->day_num++;
    }

    int min_queue_size(vector<vector<Ship>> &queue)
    {
        int m = 1000;
        for (int i = 0; i < queue.size(); i++)
        {
            int s = queue[i].size();
            m = min(m, s);
        }
        return m;
    }

    void apply_random()
    {
        for (int i = 0; i < ships.size(); i++)
        {
            int is = rnd(1, 100);
            // Отклонение с шансом 5%
            if (is < 3)
            {
                ships[i].arrivalDay += rnd(-2, 9);
                cout << "Отклонения дня прибытия " << ships[i].name << endl;
            }
            is = rnd(1, 100);
            if (is < 3)
            {
                // Добавляем время разгрузки в зависимости от типа груза
                ships[i].unloadingTime += rnd(0, 4 * ships[i].type * 24);
                cout << "Отклонения времени разгрузки " << ships[i].name << endl;
            }
        }
    }

    void erase_queue(vector<vector<Ship>> &shipQueue, int time)
    {
        for (int j = 0; j < shipQueue.size(); j++)
        {
            sumOfQueueLengths += shipQueue[j].size();
            if (shipQueue[j].size() > 0)
            {
                if (shipQueue[j][0].unloadingTime == 0)
                {
                    int waitingDays = day_num - shipQueue[j][0].arrivalDay;
                    sumOfWaitingLengths += waitingDays;

                    if (is_show_log)
                    {
                        cout << "РАЗГРУЗКА | "
                             << shipQueue[j][0].name << " | ОЖИДАНИЕ РАЗГРУЗКИ " << waitingDays << " дней  | "
                             << "НАЧАЛО РАЗГРУЗКИ " << shipQueue[j][0].sUnloadingDay << " день " << shipQueue[j][0].sUnloadingTime << ":00 | "
                             << "ПРОДОЛЖИТЕЛЬНОСТЬ РАЗГРУЗКИ " << shipQueue[j][0].plannedUnloadingTime << " ч. | "
                             << "ОЧЕРЕДЬ " << j + 1 << endl;
                    }
                    // Статистика

                    int delay = (day_num - shipQueue[j][0].plannedArrivalDay) - shipQueue[j][0].stayTime;
                    if (delay > 0)
                    {
                        int shipPenalty = delay * 2000;
                        if (is_show_log)
                            cout << "ШТРАФ КОРАБЛЮ " << shipQueue[j][0].name << " ЗА ЗАДЕРЖКУ В " << delay << " ДНЕЙ В РАЗМЕРЕ " << shipPenalty << " у.е." << endl;

                        delayCount += 1;
                        wholeDelay += delay;
                        maxQueueDelay = max(maxQueueDelay, delay);

                        if (shipQueue[j][0].type == 1)
                            dryPenalty += shipPenalty;
                        if (shipQueue[j][0].type == 2)
                            liquidPenalty += shipPenalty;
                        if (shipQueue[j][0].type == 3)
                            containerPenalty += shipPenalty;
                        penalty += shipPenalty;
                    }

                    unloadedShips += 1;
                    shipQueue[j].erase(shipQueue[j].begin());
                }
                else
                {
                    shipQueue[j][0].unloadingTime -= 1;
                }
            }
        }
    }

    void add_queue(int time, vector<Ship> &ships, vector<vector<Ship>> &shipQueue)
    {
        for (int t = 0; t < ships.size(); t++)
        {
            if (ships[t].arrivalTime == time)
            {
                ships[t].sUnloadingDay = day_num;
                ships[t].sUnloadingTime = time;
                int m = min_queue_size(shipQueue);
                for (int i = 0; i < shipQueue.size(); i++)
                {
                    if (shipQueue[i].size() == m)
                    {
                        if (is_show_log)
                            cout << "ПРИБЫТИЕ  | " << ships[t] << endl;
                        shipQueue[i].push_back(ships[t]);
                        break;
                    }
                }
            }
        }
    }

    void show_log()
    {
        cout << "Сыпучих кранов: " << dry_cranes << endl;
        cout << "Жидких кранов: " << liquid_cranes << endl;
        cout << "Контейнерых кранов: " << container_cranes << endl
             << endl;

        cout << "Всего разгружено кораблей: " << unloadedShips << endl;
        cout << "Средняя длина очереди: " << sumOfQueueLengths / float((24 * 30) * (dry_cranes + liquid_cranes + container_cranes)) << endl;
        cout << "Среднее время ожидания в очереди: " << sumOfWaitingLengths / float(unloadedShips) << " д." << endl;
        cout << "Максимальная задержка: " << maxQueueDelay << " дней" << endl;
        if (delayCount != 0)
            cout << "Средняя задержка: " << wholeDelay / delayCount << " дней" << endl;
        cout << "Общая сумма штрафов: " << penalty << " у.е." << endl
             << endl;
        // cout << "Сухие штрафы: " << dryPenalty << " у.е." << endl;
        // cout << "Жидкие штрафы: " << liquidPenalty << " у.е." << endl;
        // cout << "Контейнерные ештрафы: " << containerPenalty << " у.е." << endl;
    }
};

void generateShipTable(int shipCount = 300)
{
    ifstream fin("shipNames.txt");
    string line;
    vector<string> shipNames;
    while (getline(fin, line))
    {
        shipNames.push_back(line);
    }

    fin.close();
    ofstream fout("ships.txt");

    for (int i = 0; i < shipCount; i++)
    {
        string name = shipNames[rnd(0, shipNames.size() - 1)] + "-" + to_string(rnd(1, 100));
        int qwx = rnd(1, 100);
        string type = "1";
        if (qwx < 45)
            type = "1";
        else if (qwx >= 45 && qwx < 70)
            type = "2";
        else if (qwx >= 70)
            type = "3";
        else
            type = to_string(rnd(1, 3));

        string weight = to_string(rnd(25, 100));
        string stayTime = to_string(rnd(2, 5));
        string arriveDay = to_string(rnd(1, 30));
        string arriveTime = to_string(rnd(0, 23));

        string res = name + " " + type + " " + weight + " " + stayTime + " " + arriveDay + " " + arriveTime;
        fout << res + "\n";
        // cout << res + "\n";
    }
    fout.close();
}

vector<Ship> getShipTable()
{
    ifstream f("ships.txt");
    vector<Ship> ships;

    string line;
    while (getline(f, line))
    {
        vector<string> data = split(line, ' ');
        string name = data[0];
        int type = stoi(data[1]);
        int weight = stoi(data[2]);
        int stayTime = stoi(data[3]);
        int arriveDay = stoi(data[4]);
        int arriveTime = stoi(data[5]);

        Ship ship(name, type, weight, stayTime, arriveDay, arriveTime);
        ships.push_back(ship);
    }

    sort(ships.begin(), ships.end(), [](Ship ship1, Ship ship2)
         { return ship1.arrivalTime < ship2.arrivalTime; });

    f.close();
    return ships;
}

int main()
{
    cout << "Сгенерировать новый список прибытия кораблей? (да/нет): ";
    string doGen;
    cin >> doGen;

    if (doGen == "да")
    {
        cout << "Количество кораблей для генерации (0-100.000): ";
        int scount;
        cin >> scount;
        cout
            << "Генерируем расписание кораблей..." << endl;

        generateShipTable(scount);
        cout << "Готово" << endl;
    }
    vector<Ship> ships = getShipTable();

    cout << "Посчитать оптимальное кол-во кранов? (да/нет): ";
    string doOpt;
    cin >> doOpt;

    int dry = 1, liq = 1, con = 1;

    Port port(ships, dry, liq, con, false, false);
    if (doOpt == "да")
    {
        int allowedPenalty = 8000;
        cout << "Введите допустимую сумму штрафа на тип груза (0 - 100.000): ";
        cin >> allowedPenalty;
        cout << endl
             << "Вычисляем оптимальное количество кранов..." << endl;

        do
        {
            port = Port(ships, dry, liq, con, false, false);
            for (int i = 0; i < 30; i++)
            {
                port.cycle();
            }

            if (port.dryPenalty > allowedPenalty)
                dry += 1;
            if (port.liquidPenalty > allowedPenalty)
                liq += 1;
            if (port.containerPenalty > allowedPenalty)
                con += 1;

        } while (port.dryPenalty > allowedPenalty || port.liquidPenalty > allowedPenalty || port.containerPenalty > allowedPenalty);
    }
    else
    {

        cout << "Ввведите кол-во кранов через пробел (сыпучие/жидкие/контейнеры): ";
        cin >> dry >> liq >> con;
    }
    port = Port(ships, dry, liq, con);
    for (int i = 0; i < 30; i++)
    {
        port.cycle();
    }

    cout << endl
         << "=====================================" << endl
         << endl;
    port.show_log();
    

    return 0;
}