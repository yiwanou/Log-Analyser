//
// Created by Qinshu Dai on 16/01/2024.
//

#ifndef LOG_ANALYSER_INFOSSTORAGE_H
#define LOG_ANALYSER_INFOSSTORAGE_H

#include <vector>
#include "Infos.h"

class InfosStorage {
    public:
        void addInfo(const Infos& Infos);
        const std::vector<Infos>& getAllInfos() const;

    private:
        std::vector<Infos> allInfos;
};


#endif //_ANALYSER_INFOSSTORAGE_H
