#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <string>

using namespace std;

int calcdays(int year, int month);
bool isleapyear(int year);
void printcalendar(int month, int year, int firstday);

const int firstyear = 1800;
const int dayoffset= 3;
const int firstleapyear = 1804;

string daynames[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

string months [] = { "January", "February", "March", "April", "May", "June", "July", "August","September", "October", "November", "December"};

int daysinmonth[] = { 31,28,31,30,31,30,31,31,30,31,30,31};

int dayspassed[] = {0,31,59,90,120,151,181,212,243,273,304,334};

int main()
{
	
	int year, month;
	int days;
	
	
	cout << "Enter Month: " << endl;
	cin >> month;
	cout << "Enter Year: " << endl;
	cin >> year;
	
	days = calcdays(year, month);
	
	int firstdayofweek = days % 7;
	
	cout << "First day of" << months[month-1] << " " << year << "is a " << daynames[firstdayofweek] << endl;
	
	printcalendar(month, year, firstdayofweek);
	
	system("pause");
}



int calcdays(int year, int month)
{
	int days;
	
	days = (year - firstyear) * 365;
	days += dayoffset;
	days += dayspassed[month-1];
	
	for (int count = firstleapyear; count < year ; count +=4)
	{
		if (isleapyear(count))
		{
			days++;
		}
	}
	
	if ( month > 2 && isleapyear(year))
	{
		days++;
	}
	
	return days;
}

bool isleapyear(int year)
{
	return (!(year%4)&&(year%100))||!(year%400);
}




void printcalendar(int month, int year, int firstday)
{
	cout << '\n';
	
	cout << months[month-1] << "    " << year << '\n';
	cout << "Sun " << "Mon " << "Tue " << "Wed " << "Thu " << "Fri " << "Sat "<< '\n';
	
	int count,offset;
	
	offset= 1 - firstday;
	
	count = daysinmonth[month-1];
	
	if(isleapyear(year) && (month==2))
	{
		count++;
	}
	
	for (int x = offset; x <= count; x +=7)
	{
		for(int column= x; (column < x+7) && (column <= count); column++)
		{
			if (column <=0)
			{
				cout << setw(4) << left << setprecision(3) << " ";
			}
			else
			{
				cout << setw(4) << left << setprecision(3) << setfill(' ') << column;
			}
		}
		
		cout << '\n';
	}
	
	cout << endl;
}