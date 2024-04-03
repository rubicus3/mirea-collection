#include <iostream>
#include <fstream>
#include <vector>
#include <tuple>
#include <cstring>
#include <string>





using namespace std;

string find_str(string s, string del) {
    // Use find function to find 1st position of delimiter.
    int end = s.find(del); 
    while (end != -1) { // Loop until no delimiter is left in the string.
        s.erase(s.begin(), s.begin() + end + 1);
        end = s.find(del);
    }
    return s.substr(0, end);
}


int main()
{
    ifstream fin("floa.txt");
    string s;




    cout << "Исходный: " << endl;
    vector<pair <string, int>> q;
    while(getline(fin, s, ' ')) {
        cout << s << " ";
        string x = find_str(s, ".");
        int sum = 0;

        
        for (int i = 0; i < x.length(); i++)
        {
            sum += int(x[i] - 48);
        }
        
        q.push_back({s, sum});
    }
    cout << endl;


    cout << "Записанный: " << endl;
    for (int i = 0; i < q.size() - 1; i++)
    {
        cout << q[i].first << " " << q[i].second << endl;
    }
    cout << endl;

    for (int i = 0; i < q.size() - 1; i++)
    {
        for(int j = i + 1; j < q.size(); j++) {
            if(q[i].second >= q[j].second) {
                auto temp = q[j];
                q[j] = q[i];
                q[i] = temp;
            }
        }
    }
    cout << endl;

    cout << "Отсортированный: " << endl;
    for (int i = 0; i < q.size() - 1; i++)
    {
        cout << q[i].first << " " << q[i].second << endl;
    }
    cout << endl;

    fin.close();
    ofstream of("result.txt");
    for (int i = 0; i < q.size() - 1; i++)
    {

        of << q[i].first << " ";
    }
    cout << endl;

    of.close();
    ifstream fan("result.txt");
    
    cout << "Итоговый в файле: " << endl;
    while(getline(fan, s, ' ')) {
        cout << s << " ";
    }

    fan.close();
    cout << endl;
    return 0;
}