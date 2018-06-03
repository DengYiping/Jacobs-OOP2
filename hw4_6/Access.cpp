#include "Access.h"

void Access::activate(unsigned int code, unsigned int level){
    //simply add the user
    if(codes.count(code) && codes[code] >= level)
        activated[code] = codes[code];
    return;
}

void Access::deactivate(unsigned int code){
    //remove activation
    activated.erase(code);
    return;
}

bool Access::isactive(unsigned int code, unsigned int level){
    //check if it is activated
    if(activated.count(code) > 0 && activated[code] >= level)
        return true;
    return false;
}

void Access::addCode(unsigned int code, unsigned int level){
    //add access code
    codes[code] = level;
    return;
}
