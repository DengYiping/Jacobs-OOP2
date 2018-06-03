/*
    JTSK-320111
    concat.cpp
    Yiping Deng
    y.deng@jacobs-university.de
*/
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(int argc, char** argv){
    //read n
    int n;
    cin >> n;
    vector<string> fnames;
    string tmp; //temperary file name
    while(n--){
        //get the file name
        cin >> tmp;
        fnames.push_back(tmp);
        //store in the vector
    }

    ofstream out("concatn.txt", ios::binary); //the file to write to
    // in binary

    for(auto& fname: fnames){
        //open the file
        ifstream in(fname, ios::binary);
        if(in.fail()){
            out.close();
            exit(1); //cannot open the file
        }
        out << in.rdbuf(); //dump the data
        out << '\n'; //seperate the file
        in.close();
    }
    out.close();
}

