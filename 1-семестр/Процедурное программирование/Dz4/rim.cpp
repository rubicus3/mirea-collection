#include <iostream>
#include <cmath>
#include <cstring>
#include <map>

using namespace std;

int main()
{
    map<char, int> sym{
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}};

    char str[1024];
    cin >> str;

    int sum = 0, c = 0;

    for (int i = 0; i < strlen(str); i++)
    {
        if (sym[str[i]] <= sym[str[i + 1]])
        {

            if (sym[str[i]] < sym[str[i + 1]] || sym[str[i]] < sym[str[i + 2]] || sym[str[i]] < sym[str[i + 3]])
                sum -= sym[str[i]];
            else
                sum += sym[str[i]];
        }
        else
            sum += sym[str[i]];

        if (str[i] == str[i + 1])
            c += 1;
        else
            c = 0;
        if (c == 3)
        {
            cout << "так нельзя";
            return 0;
        }

        int s1 = sym[str[i]], s2 = sym[str[i + 1]];
        if(float (s2 - abs(sum)) / float( s2) > float(s1) / float(s2)) {
            
            cout << "так нельзя";
            return 0;
        } 
        
    }

    cout << sum << endl;

    return 0;
}