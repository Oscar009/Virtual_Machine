#ifndef SyntacticAnalyzer_h
#define SyntacticAnalyzer_h

#include <string>
#include <iostream>
#include "Errorhandler.h"
#include <vector>
#include <iterator>
#include <map>

using namespace std;

class SyntacticAnalyzer
{
    int flagCorchetes = 0;
    
public:
    SyntacticAnalyzer();

    void syntacticRules(string, int, Errorhandler *);
    int checkRule(vector<string>*);
};

#endif