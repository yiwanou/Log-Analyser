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
#include <fstream>

class Statistic : public InfosStorage
{
public:
    void countCible(const InfosStorage &Infos);

    void sortCible();

    void addNode(const std::string &cible, std::map<std::string, int> &cibleToNode, std::ofstream &fout, int &nodeCounter);

    void countCibleReferrer(const InfosStorage &Infos);

    void genererDotFile(const InfosStorage &Infos, std::string dotFileName);

    void excludeResources(const InfosStorage &Infos);

    void timeFilter(const InfosStorage &Infos, int timeFilter);

private:
    std::map<std::string, int> cibleHits;
    // //cible referrer and occurences

};

#endif // LOG_ANALYSER_STATISTIC_H
