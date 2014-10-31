#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::ifstream;

void readWord(const string &fName, vector<string> &v);
void readLine(const string &fName, vector<string> &v);
void print(vector<string> &v);

int main (int argc, char **argv) {
    const string fileName = "ReadFile.cxx";
    vector<string> v;
    readWord(fileName, v);
    print(v);
    v.clear();
    readLine(fileName, v);
    print(v);
    return 0;
}

void readWord(const string &fName, vector<string> &v) {
    ifstream fin;
    if (fin.is_open()) {
        string word;
        while (fin >> word) {
            v.push_back(word);
            v.push_back("\n");
        }
    } else {
        cout << "failed" << endl;
    }
}

void readLine(const string &fName, vector<string> &v) {
    ifstream fin(fName);
    if (fin.is_open()) {
        string line;
        while (getline(fin, line)) {
            v.push_back(line);
            v.push_back("\n");
        }
    } else {
        cout << "failed" << endl;
    }
}

void print(vector<string> &v) {
    for (vector<string>::iterator it = v.begin(); it != v.end(); ++it) {
        cout << *it;
    }
}