#include <iostream>
#include <iomanip>

using namespace std;

string func(float x)
{

    if (x == 1)
    {
        return "Undefined";
    }

    return to_string((x * x - 2 * x + 2) / (x - 1));
}

int main()
{
    for (float i = -4; i <= 4; i += 0.5)
    {
        cout << setprecision(2) << "y(" << i << ") = " << func(i) << endl;
    }

    return 0;
}