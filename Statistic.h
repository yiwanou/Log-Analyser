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
    // sans option
    void countAllCible(const InfosStorage &AllInfos);
    void sortCible();
    // option -g fichier.dot
    void addNode(const std::string &cible, std::map<std::string, int> &cibleToNode, std::ofstream &fout, int &nodeCounter);

    void countCibleReferrer(const InfosStorage &AllInfos);

    void genererDotFile(const InfosStorage &AllInfos, std::string dotFileName);
    // option -e
    void excludeResources(const InfosStorage &AllInfos);
    void sortCibleWithExclusion();
    // option -t
    void timeFilter(const InfosStorage &AllInfos, int timeFilter);

private:
    std::map<std::string, int> cibleHits;
    //cible referrer and occurences
    std::map<std::pair<std::string, std::string>, int> cibleReferrerHits;
    InfosStorage infofiltered;
};

#endif // LOG_ANALYSER_STATISTIC_H
