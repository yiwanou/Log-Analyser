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
    string ipAddress, dateTime, referrer, httpRequest,userAgent,method,cible,protocol,stringStatusCode,stringdataSize,statusCode, dataSize;

    getline(iss, ipAddress, ' ');
    iss.ignore(5);

    getline(iss, dateTime, ']');

    iss.ignore(2);

    getline(iss, httpRequest, '"');
    iss.ignore();

    getline(iss, stringStatusCode, ' ');

    getline(iss, stringdataSize, ' ');
    iss.ignore();

    getline(iss, referrer, '"');
    iss.ignore(2);

    getline(iss, userAgent, '"');

    istringstream http(httpRequest);
    http >> method >> cible >> protocol;


    // Supprimer la configuration du referrer
    size_t position = referrer.find(config);
    if (position != string::npos) {
        referrer.erase(0, strlen(config));
    }



    Infos entry(ipAddress, dateTime, referrer, cible, userAgent, statusCode, dataSize);
    infos.addInfo(entry);
}