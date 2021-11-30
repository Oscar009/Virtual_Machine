#include "SyntacticAnalyzer.h"

SyntacticAnalyzer::SyntacticAnalyzer() {}

void SyntacticAnalyzer::syntacticRules(string line, int numberOfLine, Errorhandler *eH)
{
    string lexem;
    vector<string> *tokens = new vector<string>;
    for (unsigned i = 0; i < line.size(); i++)
    {
        if (line[i] != ' ')
        {
            lexem.push_back(line[i]);
        }
        else if (line[i] == ' ')
        {
            tokens->push_back(lexem);
            tokens->push_back(to_string(line[i]));
            lexem = "";
        }
        //if(i+1 == line->size())
        if (i == line.size() - 1)
        {
            if (checkRule(tokens))
            {
                string n(to_string(numberOfLine));
                string nE = "Error in line " + n + " syntactic error";
                eH->addError(nE);
            }
        }
    }
}

int SyntacticAnalyzer::checkRule(vector<string> *tokens)
{
    map<int, string> tk;
    int i = 0;
    for (vector<string>::iterator it = tokens->begin(); it != tokens->end(); ++it)
    {
        //cout << *it <<endl;
        tk[i] = *it;
        i++;
    }
    //producciones
    int acepted = 0;
     if(tk[0] == "{") {
        if(!flagCorchetes) {
            flagCorchetes = 1;
        }
    }
    else if(tk[0] == "}"){
        if (flagCorchetes) {
            flagCorchetes = 0;
        }
    }
    if (tk[0] == "int")
    {
        if (tk[1] == "32")
        {
            if (tk[2] == "main(void)")
            {
                acepted = 1;
            }
        }
    }

    return acepted ? 0 : 1;
}