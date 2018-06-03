/*
    JTSK-320111
    testWindGauge.cpp
    Yiping Deng
    y.deng@jacobs-university.de
*/
#include "WindGauge.h"
#include <iostream>

using namespace std;
int main(int argc, char** argv){
    WindGauge wg; //create object

    //add data
    wg.currentWindSpeed(15);
    wg.currentWindSpeed(16);
    wg.currentWindSpeed(12);
    wg.currentWindSpeed(15);
    wg.currentWindSpeed(15);

    cout << "highest: " << wg.highest() << endl;
    cout << "average: " << wg.average() << endl;
    cout << "lowest: " << wg.lowest() << endl;

    int data[] = {16, 17, 16, 16, 20, 17, 16, 15, 16, 20};
    for(int i = 0; i < 10; i++){
        wg.currentWindSpeed(data[i]);
    }

    cout << "highest: " << wg.highest() << endl;
    cout << "average: " << wg.average() << endl;
    cout << "lowest: " << wg.lowest() << endl;
    return 0;
}


