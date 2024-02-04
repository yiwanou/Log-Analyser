//
// Created by Qinshu Dai on 16/01/2024.
//

#include "Statistic.h"

void Statistic::countAllCible(const InfosStorage &AllInfos)
{
    infofiltered = AllInfos;
    for (class Infos entry : infofiltered.getAllInfos())
    {
        cibleHits[entry.getCible()]++;
    }
}

void Statistic::sortCible()
{
    std::vector<std::pair<std::string, int>> sortedCibleHits(cibleHits.begin(), cibleHits.end());

    std::sort(sortedCibleHits.begin(), sortedCibleHits.end(),
              [](const auto &a, const auto &b)
              {
                  return a.second > b.second;
              });

    // Output the top 10
    int count = 0;
    for (const auto &pair : sortedCibleHits)
    {
        if (count < 10)
        {

            std::cout << pair.first << "( " << pair.second << " hits)" << std::endl;
        }
        else
        {
            break; // Stop after printing the top 10
        }
        count++;
    }
}

void Statistic::addNode(const std::string &cible, std::map<std::string, int> &cibleToNode, std::ofstream &fout, int &nodeCounter)
{
    if (cibleToNode.find(cible) == cibleToNode.end())
    {
        cibleToNode[cible] = nodeCounter++;
        fout << "node" << cibleToNode[cible] << " [label=\"" << cible << "\"];" << std::endl;
    }
}

void Statistic::countCibleReferrer(const InfosStorage &AllInfos)
{
    for (class Infos entry : infofiltered.getAllInfos())
    {
        cibleReferrerHits[std::make_pair(entry.getCible(), entry.getReferrer())]++;
    }
}

void Statistic::genererDotFile(const InfosStorage &AllInfos, std::string dotFileName)
{
    countCibleReferrer(AllInfos);

    std::ofstream fout(dotFileName);

    if (!fout.is_open())
    {
        throw "Dot file open failed !";
    }

    fout << "digraph {" << std::endl;

    std::map<std::string, int> cibleToNode;
    std::map<std::pair<int, int>, int> edges;
    int nodeCounter = 0;

    for (const auto &pair : cibleReferrerHits)
    {
        addNode(pair.first.first, cibleToNode, fout, nodeCounter);
        addNode(pair.first.second, cibleToNode, fout, nodeCounter);
        edges[std::make_pair(cibleToNode[pair.first.first], cibleToNode[pair.first.second])] = pair.second;
    }

    for (const auto &edge : edges)
    {
        fout << "node" << edge.first.second << " -> node" << edge.first.first << " [label=\"" << edge.second << "\"];" << std::endl;
    }

    fout << "}" << std::endl;

    std::cout << "Dot-file " << dotFileName << " generated !" << std::endl;
}

void Statistic::timeFilter(const InfosStorage &AllInfos, int timeFilter)
{
    for (class Infos entry : AllInfos.getAllInfos())
    {
        if (entry.getTime() == timeFilter)
        {
            infofiltered.addInfo(entry);
        }
    }
    std::cout << "Warning : only hits between " << timeFilter << "h and " << timeFilter + 1 << "h have been taken into account!" << std::endl;
}

void Statistic::dateFilter(const InfosStorage &AllInfos, std::string dateFilter)
{
    for (class Infos entry : AllInfos.getAllInfos())
    {
        if (entry.getDate() == dateFilter)
        {
            infofiltered.addInfo(entry);
        }
    }
    std::cout << "Warning : only hits on " << dateFilter << " have been taken into account!" << std::endl;
}

void Statistic::excludeResources(const InfosStorage &AllInfos)
{
    for (class Infos entry : AllInfos.getAllInfos())
    {
        if (entry.getCible().find(".jpg") == std::string::npos &&
              entry.getCible().find(".png") == std::string::npos &&
              entry.getCible().find(".gif") == std::string::npos &&
              entry.getCible().find(".css") == std::string::npos &&
              entry.getCible().find(".js") == std::string::npos)
        {
            infofiltered.addInfo(entry);
        }
    }
}


void Statistic::sortCibleWithExclusion()
{
    countAllCible(infofiltered);
    sortCible();
}