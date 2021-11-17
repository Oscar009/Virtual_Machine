#ifndef Errorhandler_h
#define Errorhandler_h

#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Errorhandler
{
    vector<string> errors;

public:
    Errorhandler();

    void addError(string);
    void printErrorHandler();
};

#endif