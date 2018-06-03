/*
    JTSK-320111
    hw4_1.cpp
    Yiping Deng
    y.deng@jacobs-university.de
*/
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
int main(int argc, char** argv){
    vector<int> vec;

    //fill in the num
    for(int i = 1; i <= 30; i++){
        vec.push_back(i);
    }
    vec.push_back(5); //add 5

    reverse(vec.begin(), vec.end()); //reverse it

    cout << "before: " << endl;
    for(auto it = vec.begin(); it != vec.end(); it++){
        cout << *it << " "; //print
    }
    cout << endl; //end line

    cout << "after: " << endl;

    int origin = 5;
    int newVal = 129;
    replace(vec.begin(), vec.end(), origin, newVal);

    for(auto it = vec.begin(); it != vec.end(); it++){
        cout << *it << " "; //print
    }

    return 0;
}
