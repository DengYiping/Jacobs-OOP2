#include "Access.h"
#include <iostream>

using namespace std;
int main(int argc, char** argv){
    Access access; //access object

    access.addCode(1234);
    access.addCode(9999);
    access.addCode(9876);

    cout << "enter your code:" << endl;
    unsigned int input;
    while(cin >> input){
        access.activate(input);
        //successful opening
        if(access.isactive(input)){
            cout << "Congrats!" << endl;
            break;
        }

        cout << "Sorry, wrong code, enter again:" << endl;
    }

    cout << "deactivate code ..." << endl;
    access.deactivate(input);
    access.deactivate(9999);
    access.deactivate(1111);

    cout << "enter your code:" << endl;
    while(cin >> input){
        access.activate(input);
        //successful opening
        if(access.isactive(input)){
            cout << "Congrats!" << endl;
            break;
        }

        cout << "Sorry, wrong code, enter again:" << endl;
    }

    return 0;
}
