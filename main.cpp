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
        if (arg == "-g" )
        {
            if(i + 1 > argc)
            {
                std::cerr << "No dot file specified." << std::endl;
                return 1;
            }
            dotFileName = argv[++i]; // get name of dot file
        }
        if (arg == "-e")
        {
            excludeResources = true; // exclude resources
        }
        if (arg == "-t" )
        {
            if ( i + 1 > argc)
            {
                std::cerr << "No time filter specified." << std::endl;
                return 1;
            }
            
            timeFilter = std::stoi(argv[++i]);// get time filter
            if (timeFilter >= 24)
            {
                std::cerr << "Time filter must be less than 24 hours." << std::endl;
                return 1;
            }
            
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


    if (excludeResources)
    {
        stats.excludeResources(AllLogInfos);
        stats.sortCibleWithExclusion();
    }

    if (timeFilter != -1)
    {
        stats.timeFilter(AllLogInfos, timeFilter);
        stats.sortCibleWithExclusion();
    }
    else if (dotFileName.empty() && !excludeResources)
    {
        stats.countAllCible(AllLogInfos);
        stats.sortCible();
    }

    if (!dotFileName.empty())
    {
        stats.genererDotFile(AllLogInfos, dotFileName);
    }

    return 0;
}