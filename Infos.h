//
// Created by Qinshu Dai on 15/01/2024.
//

#ifndef LOG_ANALYSER_INFOS_H
#define LOG_ANALYSER_INFOS_H

#include <iostream>
#include <string>

class Infos
{
public:
    Infos(std::string &ipAddress, std::string &dateTime, std::string &referrer, std::string &cible,
          std::string &userAgent, int &statusCode, int &dataSize);

    Infos();

    friend std::ostream &operator<<(std::ostream &cout, Infos &A);

    friend class Lecture;

    std::string getCible() const
    {
        return _cible;
    }

    std::string getReferrer() const
    {
        return _referrer;
    }

protected:
    std::string _cible;
    std::string _ipAddress;
    std::string _dateTime;
    std::string _referrer;
    std::string _userAgent;
    int _statusCode;
    int _dataSize;
};
#endif // LOG_ANALYSER_INFOS_H