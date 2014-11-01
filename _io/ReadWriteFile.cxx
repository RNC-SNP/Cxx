#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void readPrint(const string &inFileName);
void readWrite(const string &inFileName, const string &outFileName);

int main (int argc, char **argv) {
    const string inFileName = "ReadWriteFile.cxx";
    const string outFileName = "ReadWriteFile.cpp";
    readPrint(inFileName);
    readWrite(inFileName, outFileName);
    return 0;
}

void readPrint(const string &inFileName) {
    //ifstream fin;
    //fin.open(inFileName);
    //ifstream fin(inFileName);//Init and open file directly
    ifstream fin(inFileName, ios::in);//Init and open file with mode

    vector<string> v;
    if (fin.is_open()) {
        string content;
        //while (fin >> content) {//read word by word
        while (getline(fin, content)) {//read line by line
            v.push_back(content);
            v.push_back("\n");
        }

        for (vector<string>::iterator it = v.begin(); it != v.end(); ++it) {
            cout << *it;
        }

        v.clear();
    } else {
        cout << "Failed to open file." << endl;
    }
    fin.close();
}

void readWrite(const string &inFileName, const string &outFileName) {
    ifstream fin(inFileName, ios::in);

    if (fin.is_open()) {
        ofstream fout(outFileName, ios::out);
        char buffer[1024];
        while (!fin.eof()) {
            fin.read(buffer, 1024);//read in a buffer array
            fout.write(buffer, fin.gcount());
        }

        fout.close();
    } else {
        cout << "Failed to open file." << endl;
    }
    fin.close();
}