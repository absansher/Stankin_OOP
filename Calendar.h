#ifndef CALENDAR_H
#define CALENDAR_H
#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include <fstream>
class Calendar
{
private:
	unsigned short year;
	std::vector<std::string> holidays;
	bool check(int i, int j);
public:
	Calendar(unsigned short year, std::string pathToBase);
	void printCalendar(unsigned short year);
};

#endif // !CALENDAR_H

