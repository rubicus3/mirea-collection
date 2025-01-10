#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <map>
#include <bitset>

using namespace std;

struct Node
{
	char ch;
	int frequency;
	Node *left, *right;
};

struct Comparator
{
	bool operator()(Node* a, Node* b) {
    	return a->frequency > b->frequency;
	}
};


Node* getNode(char ch, int freq, Node* left, Node* right)
{
	Node* node = new Node();

	node->ch = ch;
	node->frequency = freq;
	node->left = left;
	node->right = right;

	return node;
}

void encode(Node* root, string str,
			map<char, string> &huffmanCode)
{
	if (root == nullptr)
		return;
	if (!root->left && !root->right) {
		huffmanCode[root->ch] = str;
	}

	encode(root->left, str + "0", huffmanCode);
	encode(root->right, str + "1", huffmanCode);
}

void decode(Node* root, int &index, string str)
{
	if (root == nullptr) {
		return;
	}
	if (!root->left && !root->right)
	{
		cout << root->ch;
		return;
	}

	index++;

	if (str[index] =='0')
		decode(root->left, index, str);
	else
		decode(root->right, index, str);
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

void buildHuffmanTree(string inputText)
{
	map<char, int> freq;
	for (char ch: inputText) {
		freq[ch]++;
	}

	priority_queue<Node*, vector<Node*>, Comparator> pq;
	for (auto pair: freq) {
		pq.push(getNode(pair.first, pair.second, nullptr, nullptr));
	}

	while (pq.size() != 1)
	{
		Node *left = pq.top(); pq.pop();
		Node *right = pq.top();	pq.pop();
		int sum = left->frequency + right->frequency;
		pq.push(getNode('\0', sum, left, right));
	}
	Node* root = pq.top();
	map<char, string> huffmanCode;
	encode(root, "", huffmanCode);


	string encodedText = "";
	for (char ch: inputText) {
		encodedText += huffmanCode[ch];
	}



    writeBinaryFile("encoded.bin", encodedText);
    ofstream encodedFile("encoded.txt");
    encodedFile << encodedText;
    encodedFile.close();

    double compressionRatio = calculateCompressionRatio("input.txt", "encoded.bin");
	cout << "Исходная строка: " << inputText << endl;
    cout << "Исходный размер: " << getFileSize("input.txt") << " bytes" << endl;
	cout << "Зашифрованная строка: " << encodedText << endl;
    cout << "Сжатый размер: " << getFileSize("encoded.bin") << " bytes" << endl;


	int index = -1;
	cout << "Дешифрованная строка: ";
	while (index < (int)encodedText.size() - 2) {
		decode(root, index, encodedText);
	}
	cout << endl;
}

int main()
{
    setlocale(LC_ALL, "ru_RU.UTF-8");
    string inputText;
    ifstream inputFile("input.txt");

    if (!inputFile.is_open()) {
        cout << "Error openning file." << endl;
        return 1;
    }
    getline(inputFile, inputText, '\0');
    inputFile.close();
	string text = "Лаба Илья Михайлович";

	buildHuffmanTree(inputText);

	return 0;
}