#pragma once
#include<iostream>
using namespace std;
class date
{
private:
	int year;
	int month;
	int day;
	int* start_time;
	int length_start_time;
public:
	date();
	date(int year, int month, int day, int* start_time, int length_start_time);
	date(const date& d);
	date& operator=(const date& d);
	void setYear(int year);
	int getYear();
	void setMonth(int month);
	int getMonth();
	void setDay(int day);
	int getDay();
	void setStartTime(int* start_time, int length_start_time);
	int* getStartTime();
	void setLengthStartTime(int length_start_time);
	int getLengthStartTime();
	int operator[](int index);
	bool operator!();
	string FirstHalfOrSecondHalf(int day);
	string Season(int month);
	~date();
	friend ostream& operator<<(ostream& out, date d);
	friend istream& operator>>(istream& in, date& d);
};


