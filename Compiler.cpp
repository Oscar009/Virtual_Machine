#include "Compiler.h"

Compiler::Compiler() {}

Compiler::Compiler(string _nameOfFile) : nameFile(_nameOfFile) {}

void Compiler::analyze()
{
}

void Compiler::printFile()
{
    ifstream file;
    string line;
    LexicalAnalyzer analyzer;

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
        if(!line.empty()){
            analyzer.lexicalRules(line, i + 1, &errorHandler);
        }
        i++;
    }

    file.close();
    errorHandler.printErrorHandler();
}