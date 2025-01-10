#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <bitset>

using namespace std;

struct Symbol {
    char character;
    double probability;
    string code;

    Symbol(char ch, double prob, const string& c) : character(ch), probability(prob), code(c) {}
};

bool compareByProbability(const Symbol& a, const Symbol& b) {
    return a.probability > b.probability;
}

void shannonFanoCode(vector<Symbol>& symbols, int start, int end) {
    if (start >= end) return;

    int splitIndex = start;
    double totalProbLeft = 0, totalProbRight = 0;

    for (int i = start; i <= end; i++) {
        totalProbRight += symbols[i].probability;
    }

    double diff = totalProbRight;
    for (int i = start; i <= end; i++) {
        totalProbLeft += symbols[i].probability;
        totalProbRight -= symbols[i].probability;

        if (abs(totalProbLeft - totalProbRight) < diff) {
            diff = abs(totalProbLeft - totalProbRight);
            splitIndex = i;
        }
    }
    
    for (int i = start; i <= splitIndex; i++) {
        symbols[i].code += "0";
    }
    for (int i = splitIndex + 1; i <= end; i++) {
        symbols[i].code += "1";
    }

    shannonFanoCode(symbols, start, splitIndex);
    shannonFanoCode(symbols, splitIndex + 1, end);
}

string encodeText(string& text, map<char, string>& encodingMap) {
    string encodedText;
    for (char ch : text) {
        encodedText += encodingMap.at(ch);
    }
    return encodedText;
}

string decodeText(const string& encodedText, map<string, char>& decodingMap) {
    string decodedText;
    string temp;
    for (char bit : encodedText) {
        temp += bit;
        if (decodingMap.find(temp) != decodingMap.end()) {
            decodedText += decodingMap.at(temp);
            temp.clear();
        }
    }
    return decodedText;
}

void writeBinaryFile(const string& filename, const string& bitString) {
    ofstream outputFile(filename, ios::binary);
    if (!outputFile) {
        cerr << "Error opening output file." << endl;
        return;
    }

    for (size_t i = 0; i < bitString.size(); i += 8) {
        bitset<8> byte(bitString.substr(i, 8));
        outputFile.put(static_cast<char>(byte.to_ulong()));
    }
    outputFile.close();
}

string readBinaryFile(const string& filename) {
    ifstream inputFile(filename, ios::binary);
    if (!inputFile) {
        cerr << "Error opening input file." << endl;
        return "";
    }

    string bitString;
    char byte;
    while (inputFile.get(byte)) {
        bitset<8> bits(byte);
        bitString += bits.to_string();
    }

    inputFile.close();
    return bitString;
}

size_t getFileSize(const string& filename) {
    ifstream file(filename, ios::binary | ios::ate);
    return file.tellg();
}

double calculateCompressionRatio(const string& inputFilename, const string& encodedFilename) {
    return static_cast<double>(getFileSize(inputFilename)) / getFileSize(encodedFilename);
}

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    string inputText;
    ifstream inputFile("input.txt");

    if (!inputFile.is_open()) {
        cout << "Error openning file." << endl;
        return 1;
    }
    getline(inputFile, inputText, '\0');
    inputFile.close();

    map<char, int> frequencyMap;
    for (char ch : inputText) {
        frequencyMap[ch]++;
    }

    vector<Symbol> symbols;
    for (const auto& pair : frequencyMap) {
        symbols.emplace_back(pair.first, static_cast<double>(pair.second) / inputText.size(), "");
    }

    sort(symbols.begin(), symbols.end(), compareByProbability);

    shannonFanoCode(symbols, 0, symbols.size() - 1);

    map<char, string> encodingMap;
    map<string, char> decodingMap;


    for (const auto& symbol : symbols) {
        encodingMap[symbol.character] = symbol.code;
        decodingMap[symbol.code] = symbol.character;
    }

    string encodedText = encodeText(inputText, encodingMap);

    writeBinaryFile("encoded.bin", encodedText);
    ofstream encodedFile("encoded.txt");
    encodedFile << encodedText;
    encodedFile.close();

    string readEncodedText = readBinaryFile("encoded.bin");
    string decodedText = decodeText(encodedText, decodingMap);
    ofstream decodedFile("decoded.txt");
    decodedFile << decodedText;
    decodedFile.close();


    double compressionRatio = calculateCompressionRatio("input.txt", "encoded.bin");
    cout << "Исходный размер: " << getFileSize("input.txt") << " bytes" << endl;
    cout << "Исходная строка: " << inputText << endl;
    cout << "Зашифрованная строка: " << encodedText << endl;
    cout << "Сжатый размер: " << getFileSize("encoded.bin") << " bytes" << endl;
    cout << "Коэфициент сжатия: " << compressionRatio << endl;
    cout << "Дешифрованная строка: " << decodedText << endl;


    return 0;
}