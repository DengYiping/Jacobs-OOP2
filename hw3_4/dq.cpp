/*
    JTSK-320111
    dq.cpp
    Yiping Deng
    y.deng@jacobs-university.de
*/
#include <deque>
#include <iostream>

using namespace std;
int main(int argc, char** argv){
    deque<float> q;//floating point deque
    float tmp;

    //read input
    while(cin >> tmp){
        if(tmp == 0.0)
            break;
        if(tmp > 0.0)
            q.push_back(tmp);
        else
            q.push_front(tmp);
    }

    //print
    for(auto& ele: q){
        cout << ele << " ";
    }
    cout << endl;
    cout << endl; //extra empty line

    //add a zero
    auto pos = q.end();

    //find the right place to insert
    for(auto it = q.begin(); it != q.end(); it++){
        if(*it > 0.0){
            pos = it;
            break;
        }
    }

    q.insert(pos, 0.0); //insert a zero

    //print the result
    for(auto it = q.begin(); it != q.end(); it++){
        if(it == q.end() -1)
            cout << *it << endl;
        else
            cout << *it << ";";
    }
    return 0;
}
