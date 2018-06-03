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

    //insert at the end
    while(cin >> tmp){
        if(tmp == "END")
            break;
        vec.push_back(tmp);
    }

    if(vec.size() < 5){
        //show a message
        cout << "second or fifth element does not exists" << endl;
    } else {
        // do a swap
        tmp = vec[1];
        vec[1] = vec[4];
        vec[4] = tmp;
    }

    //replace the last element
    if(vec.size() != 0){
        vec[vec.size() -1] = "???";
    }

    // comma seperated
    for(unsigned int i = 0; i < vec.size(); i++){
        if(i == vec.size() - 1)
            cout << vec[i] << endl;
        else
            cout << vec[i] << ",";
    }

    //semicolum seperated
    for(auto i = vec.begin(); i != vec.end(); i++){
        if(i == vec.end() -1)
            cout << *i << endl;
        else
            cout << *i << ";";
    }

    //reverse order
    if(vec.size() != 0){
        //make sure it is not empty, then we can start
        for(auto i = vec.end(); i != vec.begin(); i--){
            //in a reverse order
            if((i - 1) == vec.begin())
                cout << *(i - 1) << endl;
            else
                cout << *(i - 1) << " ";
        }
    }


    return 0;
}
