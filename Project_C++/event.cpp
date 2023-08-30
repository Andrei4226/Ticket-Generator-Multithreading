#include "event.h"
#include "otherEvent.h"
int event::nrMaxTickets = 100;
int event::nrTicketsMaxVIP = 0.1 * event::nrMaxTickets;
int event::nrTicketsMaxStandard = 0.9 * event::nrMaxTickets;
int event::nrTicketsVipNow = 10;
int event::nrTicketsStandardNow = 90;

event::event() : nrMaxColumns(10), nrMaxRows(10)
{
	location = nullptr;
	name_event = "";
}
event::event(string name_event, char* location) : nrMaxColumns(10), nrMaxRows(10)
{
	this->name_event = name_event;
	if (location != nullptr)
	{
		this->location = new char[strlen(location) + 1];
		strcpy_s(this->location, strlen(location) + 1, location);
	}
	else
	{
		this->location = nullptr;
	}
}
event::event(const event& ev) : nrMaxColumns(10), nrMaxRows(10)
{
	this->name_event = ev.name_event;
	if (ev.location != nullptr)
	{
		this->location = new char[strlen(ev.location) + 1];
		for (int i = 0; i < strlen(ev.location) + 1; i++)
		{
			this->location[i] = ev.location[i];
		}
	}
	else
	{
		this->location = nullptr;;
	}
}
event& event::operator=(const event& ev)
{
	if (this != &ev)
	{
		if (this->location != nullptr)
		{
			delete[] this->location;
		}
		if (ev.location != nullptr)
		{
			this->location = new char[strlen(ev.location) + 1];
			for (int i = 0; i < strlen(ev.location) + 1; i++)
			{
				this->location[i] = ev.location[i];
			}
			this->name_event = ev.name_event;
		}
		else
		{
			this->location = nullptr;
		}
	}
	return *this;
}
void event::setLocation(char* location)
{
	if (location != nullptr)
	{
		delete[] this->location;
		this->location = new char[strlen(location) + 1];
		for (int i = 0; i < strlen(location) + 1; i++) {
			this->location[i] = location[i];
		}
	}
}
char* event::getLocation()
{
	if (this->location != nullptr)
	{
		char* copy = new char[strlen(location) + 1];
		for (int i = 0; i < strlen(location) + 1; i++)
		{
			copy[i] = this->location[i];
		}
		return copy;
	}
	return nullptr;
}
string event::getName_event()
{
	string copie = name_event;
	return copie;
}
void event::setName_event(string name_event)
{
	this->name_event = name_event;
}

void event::setnrMaxTickets(int nrMaxTickets)
{
	if (nrMaxTickets > 0)
	{
		event::nrMaxTickets = nrMaxTickets;
	}
}

bool event::check()
{
	if (event::nrMaxTickets == (event::nrMaxRows * event::nrMaxColumns))
	{
		return true;
	}
	return false;
}

int event::getnrMaxTickets()
{
	return nrMaxTickets;
}

int event::getnrMaxColumns()
{
	return event::nrMaxColumns;
}


int event::getnrMaxRows()
{
	return event::nrMaxRows;
}
event:: ~event()
{
	if (location != nullptr)
	{
		delete[] location;
		location = nullptr;
	}
}

int event::the_current_number_tickets_left() //is a static methood, i used static in event.h
{
	return event::nrTicketsVipNow + event::nrTicketsStandardNow;
}

int event::the_number_tickets_sold()
{
	return (event::nrTicketsMaxVIP - event::nrTicketsVipNow) + (event::nrTicketsMaxStandard - event::nrTicketsStandardNow);
}

bool event::operator> (int restriction)
{
	string output = name_event;
	restriction = 30;
	if (output.length() > restriction)
	{
		return false;  // error
	}
	return true; //its good
}
bool event::operator< (int restriction)
{
	restriction = 10;
	if (the_current_number_tickets_left() < restriction)
	{
		return true;// hurry up!! there are only 10 tickets left
	}
	return false;
}

ostream& operator<<(ostream& out, event ev)
{
	out << "Location: ";
	if (ev.location != nullptr)
	{
		out << ev.location;
	}
	out << "Event name: " << ev.name_event << endl;

	cout << "Maximum number of tickets:  ";
	out << ev.nrMaxTickets;
	cout << endl;

	cout << "Maximum number of columns:  ";
	out << ev.nrMaxColumns;
	cout << endl;

	cout << "Maximum number of rows: ";
	out << ev.nrMaxRows;
	cout << endl;

	cout << "Maximum number of tickets(VIP): ";
	out << ev.nrTicketsMaxVIP;
	cout << endl;

	cout << "Maximum number of tickets(Standard): ";
	out << ev.nrTicketsMaxStandard;
	cout << endl;

	cout << "Number(now) of tickets(Standard): ";
	out << ev.nrTicketsStandardNow;
	cout << endl;

	cout << "Number(now) of tickets(Vip): ";
	out << ev.nrTicketsVipNow;
	cout << endl;


	return out;

}
istream& operator>>(istream& in, event& ev)
{
	cout << "Location: ";
	string buffer;
	in >> buffer;
	if (ev.location != nullptr)
	{
		delete[] ev.location;
		ev.location = nullptr;
	}
	ev.location = new char[buffer.length() + 1];
	strcpy_s(ev.location, buffer.length() + 1, buffer.c_str());
	cout << "Event name: ";
	in >> ev.name_event;
	return in;
};

void event::print_temp()
{
	cout << "Temperature: " << 22 << " degrees " << "C" << endl;
}
void event::addElement(int x)
{
	VectTickets.push_back(x);
}
int event::getElement(int index)
{
	return VectTickets[index];
}
vector<int> event::getVect()
{
	return VectTickets;
}
int event::getElemVect(int i)
{
	return VectTickets[i];
}


