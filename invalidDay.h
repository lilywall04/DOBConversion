#include <iostream>
#include <string>

using namespace std;

class invalidDay
{
    public:
        invalidDay()
        {
            message = "Invalid day. Must be a correct day in that month.";
        }

        invalidDay(string str)
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