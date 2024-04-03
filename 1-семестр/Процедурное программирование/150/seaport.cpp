#include <iostream>
#include <ctime>
#include <string>
#include <random>

using namespace std;

random_device rd;     // Only used once to initialise (seed) engine
mt19937 rng(rd());    // Random-number engine used (Mersenne-Twister in this case)
uniform_int_distribution<int> n10n(100,10); // Guaranteed unbiased


string shipNames[11] = {"Титаник", "Санта-Мария", "Виктория", "Александр", "Баян", "Черепаха", "Орел", "Фредрих", "Олен", "Стасян", "Домовой"};


int randrg(int a, int b) {return rand() % (a - b) + a;}


class Ship
{
public:
    string name;
    string cargoType;
    unsigned int cargoWeight;

    // Initializing ship's values and validating
    Ship(string name, string cargoType, unsigned int cargoWeight)
    {
        if (cargoType != "fluid" || cargoType != "container" || cargoType != "dry")
        {
            cout << "Invalid cargo type" << endl;
            exit(0);
        }
        if (cargoWeight > 100000)
        {
            cout << "Invalid weight value" << endl;
            exit(0);
        }

        this->name = name;
        this->cargoType = cargoType;
        this->cargoWeight = cargoWeight;
    }
};

class SeaPort
{
public:
    // Ship schedule[100];


    void generateScehdule()
    {
        cout << n10n(99, 10) << " ";
    }
};

int main()
{

    SeaPort port;
    setlocale(LC_ALL, "rus");
    for (int i = 0; i < 20; i++)
    {
        port.generateScehdule();
    }
    

    return 0;
}
