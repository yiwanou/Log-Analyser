//
// Created by Qinshu Dai on 15/01/2024.
//
#include "Lecture.h"
#include <iostream>
#include "Statistic.h"

using namespace std;

/// Users/qinshudai/Desktop/INSA/IF/3A/dev logiciel/log analyser/Fichiers Fournis-20240115/exemple-mini-non-exhaustif.txt
int main(int argc, char *argv[])
{

    string fname;
    string dotFileName;
    bool excludeResources = false;
    int timeFilter = -1;

    for (int i = 1; i < argc; ++i)
    {
        string arg = argv[i];
        if (arg == "-g" && i + 1 < argc)
        {
            dotFileName = argv[++i]; // get name of dot file
        }
        else if (arg == "-e")
        {
            excludeResources = true; // exclude resources
        }
        else if (arg == "-t" && i + 1 < argc)
        {
            timeFilter = std::stoi(argv[++i]); // get time filter
        }
        else
        {
            fname = arg; // get log file name
        }
    }

    // Check if log file name is specified
    if (fname.empty())
    {
        std::cerr << "No log file specified." << std::endl;
        return 1;
    }

    Lecture log(fname);
    log.readFile();
    auto AllLogInfos = log.returnInfosStorage();
    Statistic stats;

    if (!dotFileName.empty())
    {
        stats.genererDotFile(AllLogInfos, dotFileName);
    }

    if (excludeResources)
    {
        stats.excludeResources(AllLogInfos);
        stats.sortCibleWithExclusion();
    }

    if (timeFilter != -1)
    {
        stats.timeFilter(AllLogInfos, timeFilter);
        stats.sortCibleWithTime();
    }
    else if (dotFileName.empty() && !excludeResources)
    {
        stats.countCible(AllLogInfos);
        stats.sortCible();
    }

    return 0;
}