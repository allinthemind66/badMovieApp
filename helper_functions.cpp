#include <string>
#include <iostream>
#include "helper_functions.h"

using namespace std;

/*
    Gets a string reference and converts to lower case
*/
void convertStringToLowerCase(string &str) {
       for_each(str.begin(), str.end(), [](char & c){
	        c = ::tolower(c);
    });
}
