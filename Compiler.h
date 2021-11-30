#ifndef Compiler_h
#define Compiler_h

#include <string>
#include <iostream>
#include <fstream>
#include "Errorhandler.h"
#include "SyntacticAnalyzer.h"
#include "LexicalAnalyzer.h"

using namespace std;

class Compiler
{
    string nameFile;
    Errorhandler errorHandler;

public:
    Compiler();
    Compiler(string);

    void analyzeFile();
};

#endif