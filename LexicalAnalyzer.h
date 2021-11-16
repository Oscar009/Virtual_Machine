#ifndef LexicalAnalyzer_h
#define LexicalAnalyzer_h

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class LexicalAnalyzer
{
    string file;

public:
    LexicalAnalyzer();
    LexicalAnalyzer(string);

    void test1();
    void test2();
    void test3();
};

#endif