#include "ticket.h"
#include "event.h"
#include <vector>

int ticket::express = 4;
float ticket::priceStandard = 100;
float ticket::priceVip = 250;
int ticket::ticketsStandardSell = 0;
int ticket::ticketsVipSell = 0;
int ticket::ticketsSell = 0;
ticket::ticket()
{
	ID = NULL;
	place = nullptr;
	area = "N/A";
	nrRow = 0;
	nrColumn = 0;
	price = 0;
}
ticket::ticket(int nrRow, int nrColumn, float price, string area, int** place)
{
	const char* buffer = (area).c_str();
	if (strcmp(buffer, "Vip") == 0) {
		this->price = ticket::priceVip;
	}
	else if (strcmp(buffer, "Standard") == 0)
	{
		this->price = ticket::priceStandard;
	}
	else
	{
		this->price = 0;
	}

	if (nrRow <= c.getnrMaxRows() && nrColumn <= c.getnrMaxColumns() && nrRow > 0 && nrColumn > 0)
	{
		this->nrRow = nrRow;
		this->nrColumn = nrColumn;
		this->place = new int* [10];
		for (int i = 0; i < 10; i++)
		{
			this->place[i] = new int[10];
		}
		if (strcmp(buffer, "Vip") == 0)
		{
			ticketsVipSell++;
		}
		if (strcmp(buffer, "Standard") == 0)
		{
			ticketsStandardSell++;
		}
	}
	else {

		this->nrRow = NULL;
		this->nrColumn = NULL;
		this->place = nullptr;
	}
	this->area = area;
}


ticket::ticket(const ticket& tic)
{
	const char* buffer = (tic.area).c_str();
	if (strcmp(buffer, "Vip") == 0) {
		this->price = ticket::priceVip;
	}
	else if (strcmp(buffer, "Standard") == 0)
	{
		this->price = ticket::priceStandard;
	}
	else
	{
		this->price = 0;
	}
	this->ID = ID;

	if (tic.nrRow > 0 && tic.nrRow <= c.getnrMaxRows() && tic.nrColumn > 0 && tic.nrColumn <= c.getnrMaxColumns())
	{
		this->nrRow = tic.nrRow;
		this->nrColumn = tic.nrColumn;
		this->place = new int* [10];
		for (int i = 0; i < 10; i++)
		{
			this->place[i] = new int[10];
		}
	}
	else {

		this->nrRow = NULL;
		this->nrColumn = NULL;
		this->place = nullptr;
	}
	this->area = tic.area;
}

ticket& ticket::operator=(const ticket& tic)
{
	if (this != &tic)
	{
		const char* buffer = (tic.area).c_str();
		if (strcmp(buffer, "Vip") == 0) {
			this->price = ticket::priceVip;
		}
		else if (strcmp(buffer, "Standard") == 0)
		{
			this->price = ticket::priceStandard;
		}
		else
		{
			this->price = 0;
		}
		this->ID = tic.ID;
		if (place != nullptr)
		{
			for (int i = 0; i < c.getnrMaxRows(); i++)
			{
				delete[] place[i];
			}
			delete[] place;
			place = nullptr;
		}
		if (tic.nrRow > 0 && tic.nrRow <= c.getnrMaxRows() && tic.nrColumn > 0 && tic.nrColumn <= c.getnrMaxColumns())
		{
			this->nrRow = tic.nrRow;
			this->nrColumn = tic.nrColumn;
			this->place = new int* [10];
			for (int i = 0; i < 10; i++)
			{
				this->place[i] = new int[10];
			}
		}
		else {

			this->nrRow = NULL;
			this->nrColumn = NULL;
			this->place = nullptr;
		}
		this->area = tic.area;
	}
	return *this;
}

ticket::~ticket()
{
	if (place != NULL) {
		for (int i = 0; i < c.getnrMaxRows(); i++) {
			delete[] place[i];
		}
		delete[] place;
		place = nullptr;
	}
}
void ticket::setID(int row, int column, int** place)
{
	ID = pow(express, 2) * express / 2 - express;
	express = this->express + 1;
	place[row][column] = ID;
}
int ticket::getID()
{
	return this->ID;
}
int ticket::getRow()
{
	return nrRow;
}
void ticket::setRow(int row)
{
	if (row <= c.getnrMaxRows())
	{
		this->nrRow = row;
	}
}

void ticket::setColumn(int column)
{
	if (column <= c.getnrMaxColumns())
	{
		this->nrColumn = column;
	}
}
int ticket::getColumn()
{
	return nrColumn;
}

float ticket::getpriceStandard()
{
	return ticket::priceStandard;
}
void ticket::setpriceStandard(int priceStandard)
{
	this->priceStandard = priceStandard;
}

float ticket::getpriceVip()
{
	return ticket::priceVip;
}
void ticket::setpriceVip(int priceVip)
{
	this->priceVip = priceVip;
}
float ticket::getPriceTicket()
{
	return this->price;
}

void ticket::setPriceTicket(string area)
{
	const char* buffer = (area.c_str());
	if (strcmp(buffer, "Vip") == 0) {
		this->price = ticket::priceVip;
	}
	else if (strcmp(buffer, "Standard") == 0)
	{
		this->price = ticket::priceStandard;
	}
}

string ticket::getArea()
{
	return this->area;
}

void ticket::setArea(string area)
{
	const char* buffer = (area.c_str());
	if (strcmp(buffer, "Vip") == 0)
	{
		this->area = area;
	}
}
istream& operator>>(istream& in, ticket& tic)
{
	cout << "Area(only lower case: 'standard' or  'vip'): ";
	in >> tic.area;
	cout << "Column: ";
	in >> tic.nrColumn;
	cout << "Row: ";
	in >> tic.nrRow;
	return in;
}
ticket ticket::operator*(int price)
{
	ticket copie = *this;
	copie.priceStandard = copie.priceStandard * price;
	return copie;
}
ticket operator+(int price, ticket tic)
{
	tic.priceStandard = tic.priceStandard + price;
	return tic;
}
float ticket::sum_price_tickets_areaVip_sell()
{
	float sum = 0;
	sum = sum + (priceVip * ticketsVipSell);
	return sum;
}
float ticket::sum_price_tickets_areaStandard_sell()
{
	float sum = 0;
	sum = sum + (priceStandard * ticketsStandardSell);
	return sum;
}
//int** ticket::getPlace()
//{
//		int** copy = new int* [10];
//		for (int i = 0; i < 10; i++)
//		{
//			copy[i] = new int[10];
//		}
//		for (int i = 0; i < 10; i++)
//			for (int j = 0; j < 10; j++)
//			{
//				copy[i][j] = 1;
//			}
//		return copy;
//}
int ticket::getticketsSell()
{
	return ticket::ticketsSell;
}
void ticket::setticketsSell(int a, int b)
{
	ticket::ticketsSell = a + b;
}
int ticket::getticketsStandardSell()
{
	return ticket::ticketsStandardSell;
}
void ticket::setticketsStandardSell(int values)
{
	if (values > 0)
		ticket::ticketsStandardSell = values;
}
int ticket::getticketsVipSell()
{
	return ticket::ticketsVipSell;
}
void ticket::setticketsVipSell(int values)
{
	if (values > 0)
		ticket::ticketsVipSell = values;
}

int ticket::getPlace(int row, int column)
{
	if (row >= 0 && column >= 0 && row <= c.getnrMaxRows() && column <= c.getnrMaxColumns())
	{
		return place[row][column];
	}
	return -1;
}
void ticket::setPlace(int** matrix)
{
	if (matrix != nullptr)
	{
		delete[] this->place;
		this->place = new int* [10];
		for (int i = 0; i < 10; i++)
		{
			this->place[i] = new int[10];
		}
		for (int i = 0; i < 10; i++)
			for (int j = 0; j < 10; j++)
			{
				this->place[i][j] = matrix[i][j];
			}
	}
}
float ticket::sell_ticket()
{

	return place[nrRow][nrColumn];
}
ticket ticket::operator-(int price)
{
	ticket copie = *this;
	if (price <= copie.priceVip / 2)
		copie.priceVip = copie.priceVip - price;
	return copie;
}

ostream& operator<<(ostream& out, ticket tic)
{
	out << "Your ticket:" << endl;
	out << "Your area ('standard' or 'vip'): ";
	const char* buffer = (tic.area.c_str());
	if (strcmp(buffer, "Vip") == 0 || strcmp(buffer, "Standard") == 0)
	{
		out << tic.area;
	}
	out << endl;
	out << "Price of ticket VIP: ";
	out << tic.priceVip;
	out << endl;
	out << "Price of ticket Standard: ";
	out << tic.priceStandard;
	out << endl;
	out << "Column: ";
	out << tic.nrColumn;
	out << endl;
	out << "Row: ";
	out << tic.nrRow;
	out << endl;
	return out;
}
