#include <iostream>
#include <string>

using namespace std;

class invalidFebDay
{
    public:
        invalidFebDay()
        {
            message = "Invalid day in February.";
        }

        invalidFebDay(string str)
        {
            message = str;
        }

        string what()
        {
            return message;
        }
    private:
        string message;
};