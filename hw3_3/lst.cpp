/*
    JTSK-320111
    lst.cpp
    Yiping Deng
    y.deng@jacobs-university.de
*/
#include <fstream>
#include <algorithm>
#include <iostream>
#include <list>

using namespace std;
int main(int argc, char** argv){
    list<int> A;
    list<int> B;
    int tmp; //for reading

    //reading
    while(cin >> tmp){
        if(tmp <= 0)
            break; //end reading
        A.push_back(tmp);
        B.push_front(tmp);
    }

    for(auto& ele: A){
        //print A in the stdout
        cout << ele << " ";
    }
    //open a file
    ofstream ofile("listB.txt");
    for(auto& ele: B){
        ofile << ele << " ";
    }
    ofile.close();
    //change line
    cout << endl;
    //move the end
    if(A.size() > 1){
        auto frontItr = A.begin();
        auto backItr = A.end();
        backItr--;
        //swapping
        tmp = *frontItr;
        *frontItr = *backItr;
        *backItr = tmp;

        frontItr = B.begin();
        backItr = B.end();
        backItr--;
        //swapping
        tmp = *frontItr;
        *frontItr = *backItr;
        *backItr = tmp;
    }

    //print again
    for(auto i = A.begin(); i != A.end(); i++){
        if(i == --A.end())
            cout << *i << endl;
        else
            cout << *i << ",";
    }

    for(auto i = B.begin(); i != B.end(); i++){
        if(i == --A.end())
            cout << *i << endl;
        else
            cout << *i << ",";
    }
    cout << endl;

    //sort and merger
    A.sort();
    B.sort();
    A.merge(B);

    for(auto& ele: A){
        cout << ele << " ";
    }
    cout << endl;
    return 0;
}
