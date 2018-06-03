#include "Access.h"

void Access::activate(unsigned int code){
    //simply add the user
    auto search = codes.find(code);
    if(search != codes.end())
        activated.insert(code);
    return;
}

void Access::deactivate(unsigned int code){
    //remove activation
    activated.erase(code);
    return;
}

bool Access::isactive(unsigned int code){
    //check if it is activated
    auto search = activated.find(code);
    return search != activated.end();
}

void Access::addCode(unsigned int code){
    //add access code
    codes.insert(code);
    return;
}
