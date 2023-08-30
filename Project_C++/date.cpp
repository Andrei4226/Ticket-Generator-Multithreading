#pragma once
#include "date.h"
date::date()
{
	year = 0;
	month = 0;
	day = 0;
	start_time = nullptr;
	length_start_time = 2;
}
date::date(int year, int month, int day, int* start_time, int length_start_time)
{
	if (year >= 2022 && year <= 2026)
		//because the user can write 4201
	{
		this->year = year;
	}
	else
	{
		this->year = NULL;
	}
	if (month >= 1 && month <= 12)
	{
		this->month = month;
	}
	else
	{
		this->year = NULL;
	}
	if (day >= 1 && day <= 31)
	{
		this->day = day;
	}
	else
	{
		this->day = NULL;
	}

	if (start_time != nullptr && length_start_time > 0 && length_start_time <= 10)
	{
		this->start_time = new int[length_start_time];
		for (int i = 0; i < length_start_time; i++)
		{
			this->start_time[i] = start_time[i];
		}
	}
	else
	{
		this->start_time = nullptr;
	}
}
date::date(const date& d)
{
	if (d.year >= 2022 && d.year <= 2026)
	{
		this->year = d.year;
	}
	else
	{
		this->year = NULL;
	}
	if (d.month >= 1 && d.month <= 12)
	{
		this->month = d.month;
	}
	else
	{
		this->month = NULL;
	}
	if (d.day >= 1 && d.day <= 31)
	{
		this->day = d.day;
	}
	else
	{
		this->day = NULL;
	}
	if (d.start_time != nullptr && d.length_start_time > 0 && d.length_start_time <= 10)
	{
		this->start_time = new int[d.length_start_time];
		for (int i = 0; i < d.length_start_time; i++)
		{
			this->start_time[i] = d.start_time[i];
		}
	}
	else
	{
		this->start_time = nullptr;
		this->length_start_time = 0;
	}
}
date& date::operator=(const date& d)
{
	if (this != &d)
	{
		if (this->start_time != nullptr)
		{
			delete[] this->start_time;
		}
		if (d.start_time != nullptr && d.length_start_time > 0 && d.length_start_time <= 10)
		{
			this->start_time = new int[d.length_start_time];
			for (int i = 0; i < d.length_start_time; i++)
			{
				this->start_time[i] = d.start_time[i];
			}
			this->length_start_time = d.length_start_time;
		}
		else
		{
			this->start_time = nullptr;
			this->length_start_time = 0;
		}
		if (d.year >= 2022 && d.year <= 2026)
		{
			this->year = d.year;
		}
		else
		{
			this->year = NULL;
		}
		if (d.month >= 1 && d.month <= 12)
		{
			this->month = d.month;
		}
		else
		{
			this->month = NULL;
		}
		if (d.day >= 1 && d.day <= 31)
		{
			this->day = d.day;
		}
		else
		{
			this->day = NULL;
		}
	}
	return *this;
}
void date::setYear(int year)
{
	if (year >= 2022 && year <= 2026)
	{
		this->year = year;
	}
}
int date::getYear()
{
	if (this->year >= 2022 && this->year <= 2026)
	{
		return this->year;
	}
	else
		return -1;
}
void date::setMonth(int month)
{
	if (month >= 1 && month <= 12)
	{
		this->month = month;
	}
}
int date::getMonth()
{
	if (this->month >= 1 && this->month <= 12)
	{
		return this->month;
	}
	else
		return -1;
}


void date::setDay(int day)
{
	if (day >= 1 && day <= 31)
	{
		this->day = day;
	}
}
int date::getDay()
{
	if (day >= 1 && day <= 31)
	{
		return this->day;
	}
	return -1;
}

void date::setStartTime(int* start_time, int length_start_time)
{
	if (start_time != nullptr && length_start_time > 0 && length_start_time <= 10)
	{
		delete[] this->start_time;
		this->length_start_time = length_start_time;
		this->start_time = new int[length_start_time];
		for (int i = 0; i < length_start_time; i++)
		{
			this->start_time[i] = start_time[i];
		}
	}
}

int* date::getStartTime()
{
	if (this->start_time != nullptr && this->length_start_time > 0 && this->length_start_time <= 10)
	{
		int* copy = new int[this->length_start_time];
		for (int i = 0; i < this->length_start_time; i++)
		{
			copy[i] = this->start_time[i];
		}
		return copy;
	}
	return nullptr;
}

void date::setLengthStartTime(int length_start_time)
{
	this->length_start_time = length_start_time;
}
int date::getLengthStartTime()
{
	return this->length_start_time;
}

int date:: operator[](int index)
{
	if (this->start_time != nullptr)
	{
		if (index >= 0 && index <= 2)
		{
			return start_time[index];
		}
		else
		{
			return -1;
		}
	}
}
bool date:: operator!()
{
	if (!length_start_time)
		return true;
	else
		return false;
}
string date::FirstHalfOrSecondHalf(int day)
{

	string output;
	if (day >= 1 && day <= 15)
	{
		output = "The day of the event is in the first half of the month";
	}
	else
	{
		output = "The day of the event is in the second half of the month";
	}
	return output;
}
string date::Season(int month)
{
	string output;
	if (month == 12 || month == 1 || month || 2)
	{
		output = "The event takes place during the winter.";
	}
	else if (month >= 3 && month <= 5)
	{
		output = "The event takes place during the spring.";
	}
	else if (month >= 6 && month <= 8)
	{
		output = "The event takes place during the summer.";
	}
	else if (month >= 9 && month <= 11)
	{
		output = "The event takes place during the autumn.";
	}
	else
	{
		output = "invalid, try again";
	}
	return output;
}
date::~date()
{
	if (start_time != nullptr)
	{
		delete[] start_time;
		start_time = nullptr;
	}
}
ostream& operator<<(ostream& out, date d)
{
	out << "Year: " << d.getYear() << endl;
	out << "Month: " << d.getMonth() << endl;
	out << "Day: " << d.getDay() << endl;
	out << "Desired number of hours: " << d.getLengthStartTime() << endl;
	out << "Available hours: " << endl;
	for (int i = 0; i < d.length_start_time; i++)
	{
		out << i << ". " << d.start_time[i];
		out << endl;
	}
	return out;
}
istream& operator>>(istream& in, date& d)
{
	cout << "Year: ";
	in >> d.year;
	cout << endl;
	cout << "Month: ";
	in >> d.month;
	cout << endl;
	cout << "Day: ";
	in >> d.day;
	cout << endl;
	cout << "Desired number of hours: ";
	in >> d.length_start_time;
	cout << endl;
	cout << "Write the desired hours: ";
	if (d.start_time != nullptr)
	{
		delete[] d.start_time;
		d.start_time = nullptr;
	}
	d.start_time = new int[d.length_start_time];
	for (int i = 0; i < d.length_start_time; i++)
	{
		cout << i << ". ";
		in >> d.start_time[i];
		cout << endl;
	}
	return in;
}
