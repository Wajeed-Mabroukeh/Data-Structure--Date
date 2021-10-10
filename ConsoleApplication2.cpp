// ConsoleApplication2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <ctime>
#include <chrono> 


using namespace std;
class Date {
private:
	int day;
    int month;
	int year;

public:
	int months[12] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
	int Day[31] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31 };
	Date();
	Date(int day, int  month, int year);
	int cheackDay(int day);
	int cheackyear();
	void setDay(int day);
	void setmonth(int month);
	void setyear(int year);
	int getDay();
    int getmonth();
	int getyear();
	int cheackmonth( int month);
	void setDate(int A, int B, int c);
	Date operator >>(int w);
	Date operator ++(int y);
	Date operator --(int f);
	friend Date operator <<(Date h, int j);
	friend bool operator <(Date s1,Date s2);
	friend bool operator >(Date s1, Date s2);
	friend bool operator !=(Date s1, Date s2);
	
};
Date::Date()
{

	this->day = 01;
	this->month = 01;
	this->year = 2000;

}
Date::Date(int day, int  month, int year)
{
	this->year = year;
	if (cheackmonth(month) == 1)
	{
		this->month = month;
	}
	if (cheackDay(day) == 1)
	{
		this->day = day;
	}
	
}
void Date::setDay(int day)
{
	if (cheackDay(day) == 1)
	{
		this->day = day;
	}
	else
		cout << "The input number is invalid" << endl;

}
void Date::setmonth(int month)
{
	for (int i = 0 ; i<12 ; i++)
	{
		if (month == months[i])
		{
			this->month = month;
		}
	}
	

}
void Date::setyear(int year)
{
	this->year = year;

}
int Date::getDay()
{
	return day;
}
int Date::getmonth()
{
	return month;
}
int Date::getyear()
{
	return year;
}
int Date::cheackDay(int day)
{
	if (getmonth() == 1 || getmonth() == 3 || getmonth() == 5 || getmonth() == 7 || getmonth() == 8 || getmonth() == 10 || getmonth() == 12)
	{
		for (int i = 0; i < 31; i++)
		{
			if (day == Day[i])
			{
				return 1;
			}
		}
		return 0;
	}
	else if (getmonth() == 4 || getmonth() == 6 || getmonth() == 9 || getmonth() == 11)
	{
		for (int i = 0; i < 30; i++)
		{
			if (day == Day[i])
			{
				return 1;
			}
		}
		return 0;
	}
	else if (getmonth() == 2)
	{
		if (cheackyear() == 1)
		{
			for (int i = 0; i < 29; i++)
			{
				if (day == Day[i])
				{
					return 1;
				}
			}
			return 0;
		}
		else
			for (int i = 0; i < 28; i++)
			{
				if (day == Day[i])
				{
					return 1;
				}
			}
           return 0;
	}
	else
		return 0;
	}
int Date::cheackyear()
{
	if ((this->getyear() % 4)==0 || ((this->getyear() + 400) % 4)==0)
	{
		return 1;
	}
	else
		return 0;
}
int Date::cheackmonth(int month)
{
	for (int i = 0; i < 12; i++)
	{
		if (month == months[i])
		{
			return 1;
		}
	}
	return 0;

}
bool operator <(Date s1, Date s2)
{
	if (s1.getyear() < s2.getyear())
	{
		return true;
	}
	else if (s1.getyear() == s2.getyear())
	{
		if (s1.getmonth() < s2.getmonth())
		{
			return true;
		}
		else if (s1.getmonth() == s2.getmonth())
		{
			if (s1.getDay() < s2.getDay())
			{
				return true;
			}
			else if (s1.getDay() == s2.getDay())
			{
				cout << "The Date Obj1 Equal Obj2" << endl;
			}
			else
				return false;
		}
		else
		return false;
	}
	else
		return false;

}
bool operator >(Date s1, Date s2)
{
	if (s1.getyear() > s2.getyear())
	{
		return true;
	}
	else if (s1.getyear() == s2.getyear())
	{
		if (s1.getmonth() > s2.getmonth())
		{
			return true;
		}
		else if (s1.getmonth() == s2.getmonth())
		{
			if (s1.getDay() > s2.getDay())
			{
				return true;
			}
			else if (s1.getDay() == s2.getDay())
			{
				cout << "The Date Obj1 Equal Obj2" << endl;
			}
			else
				return false;
		}
		else
			return false;
	}
	else
		return false;

}
bool operator ==(Date s1, Date s2)
{
	 if (s1.getyear() == s2.getyear())
	 {
		 if (s1.getmonth() == s2.getmonth())
		 {
			 if (s1.getDay() == s2.getDay())
			 {
				 return true;
			 }
			 return 0;
         }
		 return 0;
	 }
	 return 0;
}
bool operator !=(Date s1, Date s2)
 {

	 if (s1.getyear() != s2.getyear())
	 {
		 return true;
	 }
	 else if (s1.getmonth() != s2.getmonth())
	 {
		 return true;
	 }
	 else if (s1.getDay() != s2.getDay())
     {
		 return true;
	 }
	 return 0;

 }
Date operator <<(Date h, int j)
 {
	Date copy;
	copy.setmonth(h.getmonth());
	copy.setyear(h.getyear());
	copy.setDay(h.getDay());
	cout << "(" << copy.getyear() << "-" << copy.getmonth() << "-" << copy.getDay() << ")" << endl;
	 return copy;
 }
Date Date:: operator >>(int w)
{
	Date copy;
	struct tm newtime;
	time_t now = time(0);
	localtime_s(&newtime, &now);
	this->month =  1 + newtime.tm_mon;
	this->year =  1900 + newtime.tm_year;
	this->day =  newtime.tm_mday;
	return copy;

}
Date Date ::  operator ++(int y) 
{
	Date copy;
	if (getmonth() == 1 || getmonth() == 3 || getmonth() == 5 || getmonth() == 7 || getmonth() == 8 || getmonth() == 10 || getmonth() == 12)
	{
		if (getDay() == 31)
		{
			if (getmonth() == 12)
			{
				this->day = 01;
				this->month = 01;
				this->year+=1;
			}
			else
			{
				this->day = 01;
				this->month+=1;
			}
		}
		else
		{
			this->day+=1;
		}

	}
	else if (getmonth() == 4 || getmonth() == 6 || getmonth() == 9 || getmonth() == 11)
	{
		if (getDay() == 30)
		{
			this->day = 01;
			this->month+=1;
		}
		else
		{
			this->day+=1;
		}
	}
	else if (getmonth() == 2)
	{

		if (cheackyear() == 1)
		{
			if (getDay() == 29)
			{
				this->day = 01;
				this->month+=1;
			}
			else 
			{
				this->day+=1;
			}
		}
		else
		{
			if (getDay() == 28)
			{
				this->day = 01;
				this->month+=1;
			}
			else
			{
				this->day+=1;
			}
		}

		
	}
	else return copy;
}
Date Date :: operator--(int f)
{
	Date copy;
	if (getmonth() == 1 || getmonth() == 3 || getmonth() == 5 || getmonth() == 7 || getmonth() == 8 || getmonth() == 10 || getmonth() == 12 || getmonth() == 4 || getmonth() == 6 || getmonth() == 9 || getmonth() == 11 || getmonth() == 2)
	{
		if (getmonth() == 1)
		{
			if (getDay() == 1)
			{
				this->day = 31;
				this->month = 12;
				this->year -= 1;
			}
			else
				this->day -= 1;
		}
		else if (getmonth() == 3)
		{
			if (cheackyear() == 1)
			{
				this->day = 29;
				this->month = 02;
			}
			else
			{
				this->day = 28;
				this->month = 02;
			}
		}
		else if (getmonth() == 2 || getmonth() == 4 || getmonth() == 6 || getmonth() == 8 || getmonth() == 9 || getmonth() == 11)
		{
			if (getDay() == 1)
			{
				this->day = 31;
				this->month -= 1;
			}
			else
			{
				this->day -= 1;
			}
		}
		else if (getmonth() == 5 || getmonth() == 7 || getmonth() == 10 || getmonth() == 12 )
		{
			if (getDay() == 1)
			{
				this->day = 30;
				this->month -= 1;
			}
			else
			{
				this->day -= 1;
			}
		}
			
	}
	return copy;
}
void Date::setDate(int A, int B, int c)
{
	int months1 = this->month;
	int years1 = this->year;
	this->month=B;
	this->year = c;
	if (cheackDay(A) == 1)
	{
		this->day = A;
		cout << "(" << getyear() << "-" << getmonth() << "-" << getDay() << ")" << endl;
	}
	else
	{
		this->month = months1;
		this->year = years1;
		cout << "The input number is invalid" << endl;
		cout << "(" << getyear() << "-" << getmonth() << "-" << getDay() << ")" << endl;
	}
}
int main() {

	Date date1(31, 1, 2019);
	Date date2(1, 3, 2019);
	Date date3(15, 4, 2019);
	Date date4(15, 4, 2019);
	Date date5;  cout << "date1 :";
	cout << "Day =" << date1.getDay();
	cout << " , Month = " << date1.getmonth();
	cout << " , Year = " << date1.getyear() << endl;
	cout << "date1 : " << endl;
	date1 << 1;
	cout << "date2 : " << endl;
	date2 << 1;
	cout << "date3 : " << endl;
	date3 << 1;
	cout << "date4 : " << endl;
	date4 << 1;
	if (date1 == date2)   cout << "date1 is equal to date2" << endl;
	if (date1 != date2)   cout << "date1 is not equal to date2" << endl;
	if (date3 == date4)   cout << "date3 is equal to date4" << endl;
	if (date3 != date4)   cout << "date3 is not equal to date4" << endl;
	if (date1 < date2)   cout << "date1 is before date2" << endl;
	if (date3 > date1)   cout << "date3 is after date1" << endl;

	cout << "date1 before auto-increment:" << endl;
	date1 << 1;
	date1++;
	cout << "date1 after auto-increment:" << endl;
	date1 << 1;
	cout << "date2 before auto-decrement:" << endl;
	date2 << 1;
	date2--;
	cout << "date2 after auto-decrement:" << endl;
	date2 << 1;

	date5 >> 1;
	cout << "date5 :" << endl;
	date5 << 1;

	date1.setyear(2020);
	date1.setmonth(12);
	date1.setDay(1);
	cout << "date1 : " << endl;
	date1 << 1;
	date1.setDate(28, 2, 2019);
	  //invalid day  cout << "date1 : " << date1 << endl; 
}
