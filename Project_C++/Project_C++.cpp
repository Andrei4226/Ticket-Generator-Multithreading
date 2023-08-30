#include <iostream>
#include<string>
#include<thread>
#include<map>
#include<string>
#include<chrono>
#include "event.h"
#include<fstream>
#include "date.h"
#include "client.h"
#include "ticket.h"
#include<cstring>;
#include<stdlib.h>;
#include "otherEvent.h"
#include <vector>
#include <cstdlib>
#include <csignal>
#include<mutex>

using namespace std;
using namespace std::chrono_literals;

mutex movieList_mutex;
//Flag care semnaleaza daca programul trebuie oprit
bool stop_program = false;

void signal_handler(int signal)
{
	cout << "Signal " << signal << ", stopping program.\n ";
	stop_program = false;
}
void functionThread(map<int, int>& multi)
{
	while (!stop_program)
	{
		//sincronizeaza accesul la variabila 'multi'
		lock_guard<mutex> lock(movieList_mutex);

		for (auto& item : multi)
		{
			item.second++;
			cout << item.first << " - " << item.second << endl;
		}
		this_thread::sleep_for(2000ms);
	}
}
int main()
{
	ofstream f("file.bin", ios::out | ios::binary);
	int alege;
	int start_program = 0;
	while (start_program == 0)
	{
		cout << "-------------------------------------------------------MENIU------------------------------------------------------------" << endl;
		start_program = 1;
		string name_even1 = "MovieOne";
		string locationMovie1 = "AFI Cotroceni";
		char* location = new char[locationMovie1.length() + 1];
		strcpy_s(location, locationMovie1.length() + 1, locationMovie1.c_str());
		event Movie(name_even1, location);
		Movie.setName_event("MovieOne");
		Movie.setLocation(location);
		Movie.setnrMaxTickets(100);
		cout << endl;
		signal(SIGINT, signal_handler);
		map<int, int> MovieList;




		date date_Movie;
		int* start_Movie = new int[3];
		start_Movie[0] = 15;
		start_Movie[1] = 18;
		start_Movie[2] = 22;
		date_Movie.setYear(2022);
		date_Movie.setMonth(3);
		date_Movie.setDay(20);
		date_Movie.setLengthStartTime(3);
		date_Movie.setStartTime(start_Movie, 3);

		int bufferix = 0;
		int ticketssellVip = 1;
		int ticketssellStandard = 1;
		int counter_valid_lottery = 0;
		cout << "Welcome!";
		cout << endl;
		int start = 1;
		while (start == 1)
		{
			int option1;
			cout << "Choose one of the events below(number):" << endl;
			cout << "1." << Movie.getName_event() << endl;
			cout << "2. Exit" << endl;
			cout << "Chosen option: ";
			int option2;
			cin >> option2;
			if (option2 == 2)
			{
				f.close();
				exit(0);
			}
			int ok = 1;
			if (option2 == 1)
			{
				int checker_virtual = 0;
				int** place = new int* [10];
				for (int i = 0; i < 10; i++)
				{
					place[i] = new int[10];
				}
				for (int i = 0; i < 10; i++)
					for (int j = 0; j < 10; j++)
						place[i][j] = 0;
				int nr = 0;
				while (ok == 1)
				{
					cout << "Choose the desired option(number):" << endl;
					cout << "1. Event details" << endl;
					cout << "2. Ticket reservation" << endl;
					cout << "3. Number of tickets available" << endl;
					cout << "4. Total number of tickets" << endl;
					cout << "5. Total number of tickets sold" << endl;
					cout << "6. View matrix places" << endl;
					cout << "7. Verification your ID" << endl;
					cout << "8. Lottery" << endl;
					cout << "9. View purchased tickets" << endl;
					cout << "10. Exit" << endl;
					int buffer_2 = 1;
					while (buffer_2 == 1)
					{
						int buffer_1 = 0;
						cout << "My option: ";
						cin >> option1;
						for (int i = 1; i <= 10; i++)
						{
							if (option1 == i)
							{
								buffer_1 = 1;
							}
						}
						if (buffer_1 == 0)
						{
							cout << "Please try again.";
							cout << endl;

						}
						if (buffer_1 == 1)
						{
							buffer_2 = 0;
						}
					}
					if (option1 == 10)
					{
						exit(0);
					}
					if (option1 == 1)
					{
						cout << "Name:";
						cout << Movie.getName_event();
						cout << endl;
						cout << "Location:";
						cout << Movie.getLocation();
						cout << endl;
						cout << "Maximum number of tickets:";
						cout << Movie.getnrMaxTickets();
						cout << endl;
						cout << "The current number of tickets left:";
						cout << Movie.the_current_number_tickets_left();
						cout << endl;
						cout << "Year:";
						cout << date_Movie.getYear();
						cout << endl;
						cout << "Mouth:";
						cout << date_Movie.getMonth();
						cout << endl;
						cout << "Day:";
						cout << date_Movie.getDay();
						cout << endl;
						otherEvent* o = NULL;
						o = &Movie;
						cout << endl;
						o->print_temp();
						cout << endl;
						cout << "Available hours:";
						for (int j = 0; j < date_Movie.getLengthStartTime(); j++)
						{
							cout << date_Movie.getStartTime()[j];
							if (j == date_Movie.getLengthStartTime() - 1)
							{
								cout << ".";
							}
							else
							{
								cout << ", ";
							}
						}
						cout << endl;
						if (Movie.operator<(10) == true)
						{
							cout << "Hurry up!!there are only 10 tickets left." << endl;
						}
						else
						{
							cout << "There are enough tickets for the moment!" << endl;
						}
						cout << date_Movie.FirstHalfOrSecondHalf(date_Movie.getDay());
						cout << endl;
						cout << date_Movie.Season(date_Movie.getMonth());
						cout << endl;
					}
					int ok1 = 0;

					while (ok1 == 0)
					{
						int allowed = 1;
						if (option1 == 2)
						{
							client person_1;
							cin >> person_1;
							cout << person_1;
							if (person_1.operator<=(18) == true)
							{
								cout << "About: minor." << endl;
							}
							else
							{
								cout << "About: major." << endl;
								cout << "Access allowed on the basis of a card ID." << endl;
							}
							if (person_1.operator<=(18) != true)
							{
								cout << "Status: Allowed." << endl;
							}
							else
							{
								cout << "Status: Not allowed." << endl;
								allowed = 0;
							}
							if (allowed == 1)
							{
								cout << endl << endl;
								ticket person1;
								cin >> person1;
								cout << person1;
								cout << endl;
								cout << "Options:";
								cout << endl;
								cout << "1.Buy";
								cout << endl;
								cout << "2.Exit";
								cout << endl;
								cout << "Your option: ";
								int choise;
								cin >> choise;
								if (choise == 2)
								{
									ok1 = 1;
								}
								if (choise == 1)
								{
									bufferix = 0;
									int buffer_verification = 0;

									ticket bilet1(person1.getRow(), person1.getColumn(), person1.getPriceTicket(), person1.getArea(), place);

									int verificationPlace = 0;
									for (int i = 0; i < 10; i++)
									{
										for (int j = 0; j < 10; j++)
										{
											if (place[bilet1.getRow()][bilet1.getColumn()] == 0)
											{
												verificationPlace = 1;

												bufferix = 1;
											}
										}
									}
									if (verificationPlace == 1)
									{
										cout << "The place is valid!" << endl;
									}
									if (bufferix == 1)
									{

										bilet1.setID(bilet1.getRow(), bilet1.getColumn(), place);
										MovieList.insert(std::make_pair(bilet1.getID(), 1));
										cout << "Ticket sold!" << endl;
										if (bilet1.getArea() == "standard")
										{
											ticket::setticketsStandardSell(ticketssellStandard);
											ticketssellStandard++;
										}
										if (bilet1.getArea() == "vip")
										{
											ticket::setticketsVipSell(ticketssellVip);
											ticketssellVip++;

										}

										f.write(reinterpret_cast<char*>(&bilet1), sizeof(bilet1));


										ticket::setticketsSell(ticket::getticketsStandardSell(), ticket::getticketsVipSell());
										cout << endl;
										cout << "ID: " << place[bilet1.getRow()][bilet1.getColumn()] << endl;
										cout << "Ticket validation:";
										cout << endl;
										for (int i = 0; i < 10; i++)
										{
											for (int j = 0; j < 10; j++)
											{
												if (place[i][j] != 0)
												{
													buffer_verification = 1;
													nr = 1;
												}
											}
										}
										if (nr == 1)
										{
											cout << "The ticket is valid" << endl;
										}
									}
									if (buffer_verification == 0 && nr != 1)
									{
										cout << "The ticket is invalid" << endl;
										nr = 0;
									}
									cout << endl;
									ok1 = 1;
								}
								ok1 = 1;

							}
						}
						ok1 = 1;
					}
					if (option1 == 3)
					{
						cout << endl << Movie.getnrMaxTickets() - ticket::getticketsSell() << endl;

					}
					if (option1 == 4)
					{
						cout << endl << Movie.getnrMaxTickets() << endl;
					}
					if (option1 == 5)
					{
						cout << endl;
						cout << ticket::getticketsSell() << endl;
					}
					if (option1 == 6)
					{
						for (int i = 0; i < 10; i++)
						{
							for (int j = 0; j < 10; j++)
							{
								cout << place[i][j] << " ";
							}
							cout << endl;
						}
					}
					if (option1 == 7)
					{
						int buffer_ID = 0;
						int ID1;
						cout << endl;
						cout << "Write your ID: ";
						cin >> ID1;
						for (int i = 0; i < 10; i++)
						{
							for (int j = 0; j < 10; j++)
							{
								if (place[i][j] == ID1)
								{
									buffer_ID = 1;
								}
							}
						}
						cout << endl;
						if (buffer_ID == 1)
						{
							cout << "Yes, you have a valid ticket. We are waiting for you at the event!!" << endl;
							
						}
						else
						{
							cout << "The ticket does not exist :( ." << endl;
						}
					}
					if (option1 == 8)
					{
						cout << endl;
						cout << "List of ticket IDs purchased so far: " << endl;
						for (auto number : Movie.getVect())
						{
							cout << number << endl;
						}
						cout << "Your ID: ";
						int id_win;
						cin >> id_win;
						cout << endl;
						int id_verif = 0;
						counter_valid_lottery = 0;
						for (int i = 0; i < 10; i++)
						{
							for (int j = 0; j < 10; j++)
							{
								if (place[i][j] != 0)
								{
									counter_valid_lottery++;
								}
							}
						}
						for (int number : Movie.getVect())
						{
							if (id_win == number)
							{
								id_verif = 1;
							}
						}
						if (id_verif == 1)
						{
							cout << "The ID is valid." << endl;
						}
						else
						{
							cout << "Buy a ticket and come back to participate in the lottery!";
						}
						if (counter_valid_lottery > 2)
						{
							cout << "The winning ID is: " << Movie.getElemVect(rand() % size(Movie.getVect())) << endl;
						}
						else
						{
							cout << endl << "Too few tickets :(. Try later!" << endl;
						}

					}
					if (option1 == 9)
					{
						thread multi1(functionThread, std::ref(MovieList));
						multi1.join();
					}
				}
			}
		}
		f.close();
	}
}


/*
În acest exemplu, handler-ul signal_handler() este apelat atunci când se primește semnalul SIGINT,
setând flag-ul stop_program pe true. Funcția functionThread() verifică acest flag în fiecare iterație a buclei,
și dacă este setat pe true, iese din buclă și permite firului de execuție să se termine în mod controlat.
Variabila multi este accesată într-o manieră sincronizată, prin folosirea unui mutex, pentru a preveni conflictele între diferitele
fire de execuție care modifică aceeași variabilă.
*/