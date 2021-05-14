#include "Calendar.h"
#include <iostream>
int main()
{
    std::cout << "Enter year" << std::endl;
    int year;
    std::cin >> year;
    std::cout<< "Test ";
    Calendar cal(year, "C:\\Users\\user\\Desktop\\aza\\base.txt");
    std::cout<< "Test 2 ";
    cal.printCalendar(year);
}
