#include <iostream>
#include <stdexcept>

using namespace std;
class Motor {
    public:
        Motor(){
            throw "This motor has problems";
            //it throws a error
        }
};

class Car {
    private:
        Motor m;
        // it has a motor
    public:
        Car(){}
};

class Garage {
    private:
        Car c;
    public:
        Garage() try {}
        catch(char const* msg){
            cerr << msg << endl;
            //throw again an error
            throw "The car is this garage has problems with the motor";
        }
};

int main(){
    try{
        Garage g;
    } catch(char const* msg){
        //print the error message
        cerr << msg << endl;
    }
}

