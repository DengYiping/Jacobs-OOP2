#include "Access.h"
#include <iostream>

using namespace std;
int main(int argc, char** argv){
    Access access; //access object

    access.addCode(1234, 1);
    access.addCode(9999, 5);
    access.addCode(9876, 9);

    cout << "enter your code:" << endl;
    unsigned int input;
    while(cin >> input){
        access.activate(input, 5);
        //successful opening
        if(access.isactive(input, 5)){
            cout << "Congrats!" << endl;
            break;
        }

        cout << "Sorry, wrong code, enter again:" << endl;
    }

    cout << "deactivate code ..." << endl;
    access.deactivate(input);
    access.addCode(9999, 8); //change the access level
    access.addCode(1111, 7);

    cout << "enter your code:" << endl;
    while(cin >> input){
        access.activate(input,7);
        //successful opening
        if(access.isactive(input, 7)){
            cout << "Congrats!" << endl;
            break;
        }

        cout << "Sorry, wrong code, enter again:" << endl;
    }

    return 0;
}
