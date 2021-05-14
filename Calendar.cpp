#include "Calendar.h"
Calendar::Calendar(unsigned short year, std::string pathToBase)
{
	this->year = year;
    std::string str;
    std::ifstream In(pathToBase);

    while (!In.eof())
    {
        getline(In, str);
        holidays.push_back(str);
    }

    //copy(v.begin(), v.end(), ostream_iterator<string>(cout, "\n"));
}

bool Calendar::check(int i, int j)
{
    std::string str = std::to_string(i) + std::to_string(j);
    for (int i = 0; i < holidays.size(); i++)
    {
        if (holidays[i] == str)
        {
            return true;
        }

    }
    return false;
}

void Calendar::printCalendar(unsigned short year)
{
    int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
    int mDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    std::string monthList[] = { "January", "February", "March", "April", "May", "June",
                        "July", "August", "September", "October", "November", "December" };


    std::cout << "  --------------------------------" << std::endl;
    std::cout << "           Calendar - " << year << std::endl;
    std::cout << "  --------------------------------" << std::endl << std::endl;
    int days;
    int current;

    int y = year - 1;
    current = (y + y / 4 - y / 100 + y / 400 + t[0] + 1) % 7;

    for (int i = 0; i < 12; i++)
    {
        if (i == 1)
            if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
                days = 29;
            else
                days = mDays[i];
        else
            days = mDays[i];

        std::cout << std::endl << "  ------------" << monthList[i] << "-------------" << std::endl;

        std::cout << "  Sun  Mon  Tue  Wed  Thu  Fri  Sat" << std::endl;

        int k;
        for (k = 0; k < current; k++)
            std::cout << "     ";

        for (int j = 1; j <= days; j++)
        {
            k++;
            if (check(i, j))
            {
                std::cout << "\u001B[0m " << std::setw(5) << j;
            }
            else
            {
                std::cout << "\u001B[31m" << std::setw(5) << j;
            }

            if (k > 6)
            {
                k = 0;
                std::cout << std::endl;
            }
        }
        if (k)
            std::cout << std::endl;
        current = k;
    }
}
