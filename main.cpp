//
// Created by Qinshu Dai on 15/01/2024.
//
#include "Lecture.h"
#include <iostream>

using namespace std;
///Users/qinshudai/Desktop/INSA/IF/3A/dev logiciel/log analyser/Fichiers Fournis-20240115/exemple-mini-non-exhaustif.txt
int main(){
    string fname = "exemple-mini-non-exhaustif.txt";
    Lecture log(fname);
    log.readFile();
    return 0;
}
