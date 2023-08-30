#pragma once
#include<iostream>
#include "otherEvent.h"
#include <vector>
using namespace std;

class event : public otherEvent
{
private:
	vector<int> VectTickets;
	char* location;
	string name_event;
	static int nrMaxTickets;
	const int nrMaxColumns;
	const int nrMaxRows;
	static int nrTicketsMaxVIP;
	static int nrTicketsVipNow;
	static int nrTicketsMaxStandard;
	static int nrTicketsStandardNow;

public:
	event();
	event(string name_event, char* location);
	event(const event& Ev);
	event& operator=(const event& ev);
	void setLocation(char* location);
	char* getLocation();
	string getName_event();
	void setName_event(string name_event);
	static void setnrMaxTickets(int nrMaxTickets);
	static int getnrMaxTickets();
	int getnrMaxColumns();
	int getnrMaxRows();
	~event();
	static int the_current_number_tickets_left();
	static int the_number_tickets_sold();
	bool check();
	bool operator> (int restriction);
	bool operator< (int restriction);
	friend ostream& operator<<(ostream& out, event ev);
	friend istream& operator>>(istream& in, event& ev);
	void print_temp();
	void addElement(int x);
	int getElement(int index);
	vector<int> getVect();
	int getElemVect(int i);
};

