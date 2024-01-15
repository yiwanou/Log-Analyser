//
// Created by Qinshu Dai on 15/01/2024.
//

#ifndef LOG_ANALYSER_LECTURE_H
#define LOG_ANALYSER_LECTURE_H
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

const char config[] = "http://intranet-if.insa-lyon.fr/temps/\n"
                      "file=main.exe\n";

class Lecture {
private:
    string filename;
    ifstream fin;
public:
    Lecture(string fname);
    void readFile();
    static  void stockerInfos(const string &line);
};


#endif //LOG_ANALYSER_LECTURE_H
