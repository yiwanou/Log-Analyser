//
// Created by Qinshu Dai on 16/01/2024.
//

#include "InfosStorage.h"


void InfosStorage::addInfo(const Infos& Info) {
    allInfos.push_back(Info);
}

const std::vector<Infos>& InfosStorage::getAllInfos() const {
    return allInfos;
}
