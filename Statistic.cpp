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