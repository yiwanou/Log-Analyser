//
// Created by Qinshu Dai on 15/01/2024.
//

#ifndef LOG_ANALYSER_LECTURE_H
#define LOG_ANALYSER_LECTURE_H
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>


const char *const config = "http://intranet-if.insa-lyon.fr";

class Lecture {
private:
    std::string filename;
    std::ifstream fin;
public:
    Lecture(std::string fname);
    void readFile();
    static  void stockerInfos(const std::string &line);
};


#endif //LOG_ANALYSER_LECTURE_H
