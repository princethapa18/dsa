#include <string>
#include <iostream>
using namespace std;

class Debugger
{
    std::string _funcName;
public:    
    explicit Debugger(const char *funname) : _funcName{funname} 
    {
        std::cout << "\n" << _funcName << " started...\n";
    }
    ~Debugger()
    {
        std::cout << "\n" << _funcName << " ended!\n";
    }
    void clear()
    {
        _funcName.clear();
    }
};