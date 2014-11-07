#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void readPrint(const std::string &inFileName);
void readWrite(const std::string &inFileName, const std::string &outFileName);

int main (int argc, char **argv) {
    const std::string inFileName = "ReadWriteFile.cxx";
    const std::string outFileName = "ReadWriteFile.cpp";
    readPrint(inFileName);
    readWrite(inFileName, outFileName);
    return 0;
}

void readPrint(const std::string &inFileName) {
    //std::ifstream fin;
    //fin.open(inFileName);
    //std::ifstream fin(inFileName);//Init and open file directly
    std::ifstream fin(inFileName, std::ios::in);//Init and open file with mode

    std::vector<std::string> v;
    if (fin.is_open()) {
        std::string content;
        //while (fin >> content) {//read word by word
        while (getline(fin, content)) {//read line by line
            v.push_back(content);
            v.push_back("\n");
        }

        for (std::vector<std::string>::iterator it = v.begin(); it != v.end(); ++it) {
            std::cout << *it;
        }

        v.clear();
    } else {
        std::cout << "Failed to open file." << std::endl;
    }
    fin.close();
}

void readWrite(const std::string &inFileName, const std::string &outFileName) {
    std::ifstream fin(inFileName, std::ios::in);

    if (fin.is_open()) {
        std::ofstream fout(outFileName, std::ios::out);
        char buffer[1024];
        while (!fin.eof()) {
            fin.read(buffer, 1024);//read in a buffer array
            fout.write(buffer, fin.gcount());
        }

        fout.close();
    } else {
        std::cout << "Failed to open file." << std::endl;
    }
    fin.close();
}