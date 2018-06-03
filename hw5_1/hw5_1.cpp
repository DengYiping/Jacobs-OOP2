#include <stdexcept>
#include <vector>
#include <iostream>

using namespace std;
int main(){
    //create vector and store the value
    vector<int> vec;
    for(int i = 0; i < 20; i++){
        vec.push_back(8);
        //add 20 times
    }

    try{
        vec.at(21); //it will throw a error
    } catch(out_of_range e){
        cerr << e.what() << endl; //print the error
    }

    return 0;
}


