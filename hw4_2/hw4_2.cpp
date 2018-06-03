/*
    JTSK-320111
    hw4_2.cpp
    Yiping Deng
    y.deng@jacobs-university.de
*/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;
int main(int argc, char** argv){
    //initialize the random number
    srand(time(nullptr));

    vector<int> vec;
    for(int i = 0; i < 6; i++){
        vec.push_back(rand() % 49 + 1);
    }

    //sort it
    sort(vec.begin(), vec.end());
    auto newEnd = unique(vec.begin(), vec.end());
    //remvoe the one
    vec.erase(newEnd, vec.end());
    //print
    for(auto it = vec.begin(); it != vec.end(); it++){
        cout << *it << " ";
    }

    cout << endl; // end line
    return 0;
}
