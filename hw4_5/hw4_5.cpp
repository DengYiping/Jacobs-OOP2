#include <iostream>
#include <fstream>
#include <map>
#include <string>

using namespace std;
int main(int argc, char** argv){
    ifstream data_stream("data.txt");
    map<string, string> database;
    string name;
    string birthday;

    //retrive key-value pairs
    while(getline(data_stream, name)){
        getline(data_stream, birthday);
        //insertion
        database[name] = birthday;
        cout << name << ":" << birthday << endl;
    }
    getline(cin, name); //get the input
    if(database.count(name))
        cout << "birthday: " << database.at(name) << endl;
    else
        cout << "Name not found!" << endl;

    return 0;
}
