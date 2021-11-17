#include "LexicalAnalyzer.h"

LexicalAnalyzer::LexicalAnalyzer() {}

void LexicalAnalyzer::lexicalRules(string line, int numberOfLine, Errorhandler *eH)
{

    for (unsigned i = 0; i < line.size(); i++)
    {
        if (checkRule(line[i]))
        {
            string n(to_string(numberOfLine));
            string nE = "Error in line " + n + " check symbol: " + line[i];
            eH->addError(nE);
        }
    }
}

int LexicalAnalyzer::checkRule(char c)
{
    switch (c)
    {
    case ' ':
    case ',':
    case ';':
    case '(':
    case ')':
    case '{':
    case '}':
    case '=':
    case '+':
    case '-':
    case '*':
    case '/':
    case 'a':
    case 'b':
    case 'c':
    case 'd':
    case 'e':
    case 'f':
    case 'g':
    case 'h':
    case 'i':
    case 'j':
    case 'k':
    case 'l':
    case 'm':
    case 'n':
    case 'o':
    case 'p':
    case 'q':
    case 'r':
    case 's':
    case 't':
    case 'u':
    case 'v':
    case 'w':
    case 'x':
    case 'y':
    case 'z':
    case 'A':
    case 'B':
    case 'C':
    case 'D':
    case 'E':
    case 'F':
    case 'G':
    case 'H':
    case 'I':
    case 'J':
    case 'K':
    case 'L':
    case 'M':
    case 'N':
    case 'O':
    case 'P':
    case 'Q':
    case 'R':
    case 'S':
    case 'T':
    case 'U':
    case 'V':
    case 'W':
    case 'X':
    case 'Y':
    case 'Z':
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
        return 0;
        break;
    default:
        return 1;
        break;
    }
}