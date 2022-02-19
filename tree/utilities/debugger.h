#ifndef DEBUGGER_H
#define DEBUGGER_H

#include <string>
using namespace std;

class Debugger
{
    string _funcName;
public:    
    explicit Debugger(const char *funname);
    ~Debugger();
    void clear();
    void printMessage(const string& msg);
};

#endif
