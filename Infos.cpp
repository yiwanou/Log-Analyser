//
// Created by Qinshu Dai on 15/01/2024.
//

#include "Infos.h"

Infos::Infos(std::string &ipAddress, std::string &dateTime, std::string &referrer, std::string &cible,
             std::string &userAgent, std::string &statusCode, std::string &dataSize) : _ipAddress(ipAddress), _dateTime(dateTime),
                                                                    _referrer(referrer), _cible(cible),
                                                                    _userAgent(userAgent), _statusCode(statusCode),
                                                                    _dataSize(dataSize) {
}
std::ostream & operator<<(std::ostream &cout, Infos &A){
    cout << "---------------Infos priinting--------------------" << std::endl;
    cout << A._ipAddress << std::endl;
    cout << A._dateTime << std::endl;
    cout <<"c" <<A._cible<< std::endl;
    cout <<"r" << A._referrer << std::endl;
    cout << A._userAgent << std::endl;
    return cout;
}

int Infos::getTime() const {
    std::istringstream iss(_dateTime);
    std::string date, time;

    std::getline(iss, date, ':');
    std::getline(iss, time, ' '); 

    std::string hour = time.substr(0, 2);
    int hourInt = stoi(hour);


    // std::cout << hourInt << std::endl;

    return hourInt;
}
std::string Infos::getDate() const
{
    std::istringstream iss(_dateTime);
    std::string date, time;

    std::getline(iss, date, ':');
    std::getline(iss, time, ' ');

    std::string hour = time.substr(0, 2);
    int hourInt = stoi(hour);

    // std::cout << hourInt << std::endl;

    return date;
}

    Infos::Infos()
    {
}
