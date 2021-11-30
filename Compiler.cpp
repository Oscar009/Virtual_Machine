#include "Compiler.h"

Compiler::Compiler() {}

Compiler::Compiler(string _nameOfFile) : nameFile(_nameOfFile) {}

void Compiler::analyzeFile()
{
    ifstream file;
    string line;
    LexicalAnalyzer analyzer;
    SyntacticAnalyzer sanalyzer;

    file.open(nameFile, ios::in); //Abrir modo lectura

    if (file.fail())
    {
        cout << "Error opening file";
        exit(1);
    }

    int i = 0;
    while (!file.eof()) //mientras no sea el final del archivo
    {
        getline(file, line);
        cout << "line " << i + 1 << "  " << line << endl;
        if (!line.empty())
        {
            analyzer.lexicalRules(line, i + 1, &errorHandler);
            sanalyzer.syntacticRules(line, i + 1, &errorHandler);
        }
        i++;
    }

    file.close();
    errorHandler.printErrorHandler();
}