/*
    JTSK-320111
    vec.cpp
    Yiping Deng
    y.deng@jacobs-university.de
*/
#include <vector>
#include <iostream>
#include <string>


using namespace std;
int main(int argc, char** argv){
    //main function
    vector<string> vec;
    string tmp; //readings

    //insert
    while(cin >> tmp){
        if(tmp == "END")
            break;
        vec.push_back(tmp);
    }

    //print using the index
    for(unsigned int i = 0; i < vec.size(); i++){
        if(i == vec.size() - 1)
            cout << vec[i] << endl;
        else
            cout <<  vec[i] << " ";
    }

    //print using the iterator
    for(auto i = vec.begin(); i != vec.end(); i++){
        //make sure no comma
        if(i == vec.end() - 1)
            cout << *i << endl;
        else
            cout << *i << ",";
    }
    return 0;
}
