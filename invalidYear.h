#include <iostream>
#include <string>

using namespace std;

class invalidYear
{
    public:
        invalidYear()
        {
            message = "Invalid year. Must be after 0, and before 2026";
        }

        invalidYear(string str)
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