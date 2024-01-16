//
// Created by Qinshu Dai on 15/01/2024.
//

#include "Infos.h"

Infos::Infos(std::string &ipAddress, std::string &dateTime, std::string &referrer, std::string &httpRequest,
             std::string &userAgent, int &statusCode, int &dataSize) : _ipAddress(ipAddress), _dateTime(dateTime),
                                                                    _referrer(referrer), _httpRequest(httpRequest),
                                                                    _userAgent(userAgent), _statusCode(statusCode),
                                                                    _dataSize(dataSize) {
}
std::ostream & operator<<(std::ostream &cout, Infos &A){
    cout << A._ipAddress << std::endl;
    cout << A._dateTime << std::endl;
    cout << A._referrer << std::endl;
    cout << A._httpRequest << std::endl;
    cout << A._userAgent << std::endl;
    cout << "---------------Infos priinting--------------------" << std::endl;
    return cout;
}