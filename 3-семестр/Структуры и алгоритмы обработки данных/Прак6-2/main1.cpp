#include <iostream>
#include <sstream>
using namespace std;

int main()
{
    string sentence = "word,wmeo,vowmbvme,vwokef,word,wrvimwe,word,foejgo,rog,word";
    istringstream ss(sentence);
    string first_word, word;
    int count = 1;
    getline(ss, first_word, ',');
    while (getline(ss, word, ','))
    {
        if(word == first_word) count += 1;
    }
    cout << "Первое слово \"" << first_word << "\" встречается в предложении "  << count << " раз." << endl; 
    return 0;
}