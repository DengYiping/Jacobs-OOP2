/*
    JTSK-320111
    WindGauge.cpp
    Yiping Deng
    y.deng@jacobs-university.de
*/
#include "WindGauge.h"

WindGauge::WindGauge(int period){
    //assign the value
    this->max_element = period;
}

void WindGauge::currentWindSpeed(int speed){
    if(vec.size() >= 12)
        vec.erase(vec.begin()); //remove the head
    vec.push_back(speed);
    return;
}

int WindGauge::highest() const {
    if(vec.size() == 0)
        //error value
        return -1;
    int max = -0x80000000; //min value for int
    for(auto val: vec){
        if(val > max)
            max = val;
    }
    return max;
}

int WindGauge::lowest() const {
    if(vec.size() == 0)
        //error value
        return -1;
    int min = 0x7fffffff; //max value for int
    for(auto val: vec){
        if(val < min)
            min = val;
    }
    return min;
}

int WindGauge::average() const {
    if(vec.size() == 0)
        //error value
        return -1;
    int sum = 0;
    for(auto val: vec){
        sum += val;
    }
    return sum / vec.size();
}


