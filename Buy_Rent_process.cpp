#include"Classes.h"
#include<map>
#include<ctime>
#include<chrono>
#include<time.h>
#include<stdio.h>
//#include<Customer.cpp>
#define _CRT_SECURE_NO_WARNINGS


using namespace std;

fstream PFile;
int counter2 = 1;
vector<Reservations> reservationsList;


Buy_Rent_process::Buy_Rent_process()
{
	customer_id, money, process_id = 0;
	Date, ChosenCar, Processtype = " ";

}

int comparetime(time_t time1, time_t time2) {
	return difftime(time1, time2);
}

void Buy_Rent_process::Process(int SID, int CustomerId)
{
	system("cls");
	int ShowRoomCars[5];
	int S = 0;
	bool MyCar = false;
	char c;
	Showrooms s;
	Car car;
	struct tm* tm1, tm2;

	list<Showrooms> ::iterator it;
	int i = 0;
	bool vaild = false;
	char CarID[25];
	char SearchCar;
	s.LoadShowRoom();
	bool exists = true;
	for (it = s.Slist.begin(); it != s.Slist.end(); it++)
	{
		if (it->ID == SID)
		{

			while (i < it->RoomCarList.size())
			{
				if (it->RoomCarList[i].ShowRoomId == SID)
				{
					for (int j = 0; j < reservationsList.size(); j++) {
						if (reservationsList[j].carID == it->RoomCarList[i].ID && reservationsList[j].reserveTime != 'N') {
							time_t currentTime;
							time(&currentTime);
							int diff = comparetime(currentTime, reservationsList[j].reserveTime);
							if (diff >= 120) {
								exists = true;
								reservationsList[j].reserveTime = 'N';
								break;
							}
							else {
								exists = false;
								break;
							}

						}
					}
					if (exists == true) {
						ShowRoomCars[S] = it->RoomCarList[i].ID;
						S++;
						cout << "Car ID: " << it->RoomCarList[i].ID << endl;
						cout << "Car Make: " << it->RoomCarList[i].Make << endl;
						cout << "Car Model:" << it->RoomCarList[i].Model << endl;
						cout << "Car Year: " << it->RoomCarList[i].Year << endl;
						cout << "Car Price: " << it->RoomCarList[i].price << endl;
						vaild = true;
					}

				}
				i++;
				exists = true;
				cout << endl;
			}

		}
	}

	cout << "Do You Want to Search for a Specfic Car Y/N" << endl;
	while (!MyCar)
	{

		cin >> SearchCar;
		if (SearchCar == 'Y' || SearchCar == 'y')
		{
			MyCar = car.search(SID);
			if (!MyCar)
				cout << "Car Id Can't be Found " << endl;
		}

		else if (SearchCar == 'N' || SearchCar == 'n')
			MyCar = true;

		if (!MyCar)
			cout << "Invaild Choice Y/N" << endl;
	}


	cout << "Buy, Rent or Reserve B/R/S" << endl;
	cin >> c;

	while (true)
	{
		if (c == 'B' || c == 'b')
		{
			Processtype = "Buy";
			break;
		}

		else if (c == 'R' || c == 'r')
		{
			Processtype = "Rent";
			break;
		}

		else if (c == 'S' || c == 's') {
			Processtype = "Reserve";
			break;
		}

		else
		{
			cout << "Re-Enter Your Choice B/R/S" << endl;
			cin >> c;
		}

	}

	vaild = false;
	i = 0;
	cout << "Confirm Your Process by Entring Car Id you want to " << Processtype << endl;
	cin >> CarID;

	s.LoadShowRoom();
	for (it = s.Slist.begin(); it != s.Slist.end(); it++)
	{
		if (it->ID == SID)
		{
			while (i < it->RoomCarList.size())
			{
				if (it->RoomCarList[i].ID == atoi(CarID))
				{
					if (Processtype == "Buy")
						money = (it->RoomCarList[i].price);
					else if (Processtype == "Rent")
						money = (it->RoomCarList[i].price) / 2;
					else {
						money = (it->RoomCarList[i].price) / 10;
						Reservations tempReservation;
						tempReservation.carID = atoi(CarID);
						//auto startTime = chrono::system_clock::now();
						//auto currentTime = chrono::system_clock::to_time_t(startTime);
						//ctime_s(tempReservation.reserveTime,30, &currentTime);
						time_t currentTime;
						time(&currentTime);
						tempReservation.reserveTime = currentTime;
						reservationsList.push_back(tempReservation);
					}

					vaild = true;
				}
				i++;
				if (vaild)
					break;
			}
			if (vaild)
				break;

		}
	}


	process_id = counter2++;
	DisplayData(CarID, CustomerId);

}

void Buy_Rent_process::DisplayData(char CarId[25], int Cid)
{
	Car car;
	char choice;
	system("CLS");
	cout << "                            Process is Done Succesfully" << endl << endl;
	cout << "Customer Id: " << Cid << endl;
	cout << "Process Id: " << process_id << endl;
	cout << "Car ID: " << atoi(CarId) << endl;
	cout << "Cost: " << money << endl;

	Customer c;
	cout << "Press M to Main Menu or E to Exit" << endl;
	cin >> choice;


	if (choice == 'M' || choice == 'm')
		c.customer_page();
	else
		exit(0);
}