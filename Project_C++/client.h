#pragma once
#include<iostream>
using namespace std;
class client
{
protected:
	char* first_name;
	char* last_name;
	int age;
	string category;
public:
	client();
	client(char* first_name, char* last_name, int age, string category);
	client(const client& c);
	client& operator=(const client& c);
	void setFirstName(char* first_name);
	char* getFirstName();
	void setLastName(char* last_name);
	char* getLastName();
	void setAge(int age);
	int getAge();
	void setCategory(string category);
	string getCategory();
	int average_age_all_round(client* cl, int nr_clienti);
	int average_age_categoryStudent_round(client* cl, int nr_clienti, string category);
	bool operator <= (int restriction);
	bool operator ==(int restriction);
	friend istream& operator>>(istream& in, client& c);
	friend ostream& operator<<(ostream& out, client c);
	virtual void print();
};
