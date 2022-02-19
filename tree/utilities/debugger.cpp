#include "debugger.h"
#include <iostream>

Debugger::Debugger(const char *funname) : _funcName{funname}
{
    cout << "\n" << _funcName << " started...\n";
}
Debugger::~Debugger()
{
    cout << "\n" << _funcName << " ended!\n";
}

void Debugger::clear()
{
    _funcName.clear();
}
void Debugger::printMessage(const string& msg)
{
    cout << msg;
}




