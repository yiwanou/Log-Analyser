//
// Created by Qinshu Dai on 16/01/2024.
//

#include "Statistic.h"

void Statistic::countCible(const InfosStorage& Infos) {
    for (class Infos entry: Infos.getAllInfos()) {
        cibleHits[entry.getCible()]++;
    }
}

void Statistic::sortCible() {
    std::vector<std::pair<std::string, int> > sortedCibleHits(cibleHits.begin(), cibleHits.end());

    std::sort(sortedCibleHits.begin(), sortedCibleHits.end(),
              [](const auto &a, const auto &b) {
                  return a.second > b.second;
              });

    // Output the top 10
    int count = 0;
    for (const auto &pair: sortedCibleHits) {
        if (count < 10) {
            std::cout << "_cible: " << pair.first << ", Occurrences: " << pair.second << std::endl;
            count++;
        } else {
            break; // Stop after printing the top 10
        }
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


void Statistic::genererDotFile(const InfosStorage &infos, std::string dotFileName)
{
    std::ofstream fout(dotFileName);
    fout << "digraph {" << std::endl;

    std::map<std::string, int> cibleToNode;
    std::map<std::pair<int, int>, int> edges;
    int nodeCounter = 0;

    for (const Infos &entry : infos.getAllInfos())
    {
        addNode(entry.getReferrer(), cibleToNode, fout, nodeCounter);
        addNode(entry.getCible(), cibleToNode, fout, nodeCounter);
        edges[std::make_pair(cibleToNode[entry.getReferrer()], cibleToNode[entry.getCible()])]++;
    }

    for (const auto &edge : edges)
    {
        fout << "node" << edge.first.first << " -> node" << edge.first.second << " [label=\"" << edge.second << "\"];" << std::endl;
    }

    fout << "}" << std::endl;
}