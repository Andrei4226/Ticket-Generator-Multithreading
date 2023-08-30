#pragma once
#include<iostream>
#include "event.h"
#include<vector>

using namespace std;
class ticket
{
private:

	float price;
	float ID;
	int** place;
	int nrRow;
	int nrColumn;
	string area;
	static float priceStandard;
	static float priceVip;
	static int express;
	event c;
	static int ticketsStandardSell;
	static int ticketsVipSell;
	static int ticketsSell;
public:
	ticket();
	ticket(int nrRow, int nrColumn, float price, string area, int** place);
	ticket(const ticket& tic);
	ticket& operator=(const ticket& ticket);
	~ticket();
	int getID();
	int getRow();
	void setColumn(int column);
	int getColumn();
	void setRow(int row);
	float getpriceStandard();
	void setpriceStandard(int priceStandard);
	float getpriceVip();
	void setpriceVip(int priceVip);
	float getPriceTicket();
	void setPriceTicket(string area);
	string getArea();
	void setArea(string area);
	string setArea();
	friend istream& operator>>(istream& in, ticket& tic);
	friend ostream& operator<<(ostream& out, ticket tic);
	ticket operator*(int price);
	friend ticket operator+(int price, ticket tic);
	ticket operator-(int price);
	float sum_price_tickets_areaVip_sell();
	float sum_price_tickets_areaStandard_sell();
	float sell_ticket();
	int getPlace(int row, int column);
	void setPlace(int** matrix);
	void setID(int row, int colomn, int** place);
	static int getticketsStandardSell();
	static void setticketsStandardSell(int values);
	static int getticketsVipSell();
	static void setticketsVipSell(int values);
	static int getticketsSell();
	static void setticketsSell(int a, int b);

};


