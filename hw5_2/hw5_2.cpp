#include <stdexcept>
#include <string>
#include <iostream>

using namespace std;
class OwnException: public exception {
    private:
        string msg;
    public:
        OwnException(){
            msg = "Default case exception";
        }
        OwnException(const string& msg){
            this->msg = msg;
        }

        virtual const char* what() const throw() {
            return "OwnException\n";
        }
};

void error_func(int a){
    // a function that throws exception
    switch(a){
        case 1:
            throw 'a';
            break;
        case 2:
            throw 12;
            break;
        case 3:
            throw true;
            break;
        default:
            throw new OwnException;
    }
    return;
}

int main(){
    try{
        error_func(1); //char
    } catch(char c) {
        cerr <<  "Caught in main: " << c << endl;
    }

    try{
        error_func(2);
    } catch(int i) {
        cerr << "Caught in main: " << i << endl;
    }

    try{
        error_func(3);
    } catch(bool b) {
        cerr << "Caught in main: " << b << endl;
    }

    try{
        error_func(4);
    } catch(OwnException* e){
        cerr << "Caught in main: " << e->what() << endl;
    }

    return 0;
}
