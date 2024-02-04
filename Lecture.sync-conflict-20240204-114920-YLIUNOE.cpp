//
// Created by Qinshu Dai on 15/01/2024.
//

#include "Lecture.h"

using namespace std;

Lecture::Lecture(string fname) : filename(fname) {};

void Lecture::readFile() {
    fin.open(filename);
    if (!fin.is_open()) {
        cerr << "Failed to open fin: " << filename << endl;
        exit(1);
    }

    string line;
    while (getline(fin, line)) {
        stockerInfos(line);
    }

}

void Lecture::stockerInfos(const string &line) {
    istringstream iss(line);
    string ipAddress, dateTime, referrer, httpRequest,userAgent;
    string method,cible, protocol;
    int statusCode, dataSize;

    getline(iss, ipAddress, ' ');
    iss.ignore(256, ' ');
    iss.ignore(256, ' ');

    getline(iss, dateTime, ']');
    dateTime.erase(0, 1);

    /*iss.ignore();

    getline(iss, httpRequest, '"');
    getline(iss, httpRequest, '"');*/

    iss >> __quoted(httpRequest);

    istringstream http(httpRequest);
    http >> method >> cible >> protocol;

    iss >> statusCode >> dataSize;

    /*iss.ignore();

    getline(iss, referrer, '"');
    getline(iss, referrer, '"');*/

    iss >> __quoted(referrer);
    iss >> __quoted(userAgent);

    /*getline(iss, userAgent, '"');
    getline(iss, userAgent, '"');*/

    // erase the config
    size_t position = referrer.find(config);
    if (position != string::npos) {
        referrer.erase(0, strlen(config));
    }

    //print les infos
    /*
    cout << ipAddress << endl;
    cout << dateTime << endl;
    cout << referrer << endl;
    cout << cible << endl;
    cout << userAgent << endl;
    cout << "-----------------------------------" << endl;*/

    Infos entry(ipAddress, dateTime, referrer, cible, userAgent, statusCode, dataSize);
    cout<<entry;
    infos.addInfo(entry);
}