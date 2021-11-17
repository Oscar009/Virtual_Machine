#include "Errorhandler.h"

Errorhandler::Errorhandler() {}

void Errorhandler::addError(string nE)
{
    errors.push_back(nE);
}

void Errorhandler::printErrorHandler()
{

    if (errors.size())
    {
        cout << endl;
        for (unsigned i = 0; i < errors.size(); i++)
        {
            cout << errors[i] << endl;
        }
    }
    else {
        cout  << endl << "Compiled successful"  << endl;
    }
}