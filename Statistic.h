//
// Created by Qinshu Dai on 16/01/2024.
//

#ifndef LOG_ANALYSER_STATISTIC_H
#define LOG_ANALYSER_STATISTIC_H


#include "Infos.h"
#include <map>


class Statistic: public Infos {
public:
    void option1();
private:
    std::map<std::string,std::map<std::string,int>>;

};


#endif //LOG_ANALYSER_STATISTIC_H
