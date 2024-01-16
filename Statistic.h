//
// Created by Qinshu Dai on 16/01/2024.
//

#ifndef LOG_ANALYSER_STATISTIC_H
#define LOG_ANALYSER_STATISTIC_H


#include "InfosStorage.h"
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>


class Statistic : public Infos {
public:
    void countCible(const InfosStorage& Infos);

    void sortCible();

private:
    std::map<std::string, int> cibleHits;

};


#endif //LOG_ANALYSER_STATISTIC_H
