#ifndef LexicalAnalyzer_h
#define LexicalAnalyzer_h

#include <string>
#include <iostream>
#include "Errorhandler.h"

using namespace std;

class LexicalAnalyzer
{

public:
    LexicalAnalyzer();

    void lexicalRules(string, int, Errorhandler *);
    int checkRule(char);
};

#endif