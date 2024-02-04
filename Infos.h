//
// Created by Qinshu Dai on 15/01/2024.
//

#ifndef LOG_ANALYSER_INFOS_H
#define LOG_ANALYSER_INFOS_H

#include <iostream>
#include <string>
#include <sstream>

class Infos
{
public:
    Infos(std::string &ipAddress, std::string &dateTime, std::string &referrer, std::string &cible,
          std::string &userAgent, std::string &statusCode, std::string &dataSize);

    Infos();

    friend std::ostream &operator<<(std::ostream &cout, Infos &A);

    // friend bool operator<(const Infos &A, const Infos &B);

    friend class Lecture;

    std::string getCible() const
    {
        return _cible;
    }

    std::string getReferrer() const
    {
        return _referrer;
    }

    int getTime() const;
    std::string getDate() const;

protected:
    std::string _cible;
    std::string _ipAddress;
    std::string _dateTime;
    std::string _referrer;
    std::string _userAgent;
    std::string _statusCode;
    std::string _dataSize;
};
#endif // LOG_ANALYSER_INFOS_H