#pragma once
#include<iostream>
#include <fstream>
#include<conio.h>
#include<string>
#include <list>
#include<queue>
#include<vector>

using namespace std;
class Admin
{
	int ID;
	string username, password;
public:
	void login();
	void admin_page();


};

class Customer
{
	int ID, phone;
	string username;
	char password[15];

public:
	Customer();
	void SignUp();
	// buy/rent/repair
	void Login();
	void customer_page();
	void search();
	void view();
	void main_login();
};

class Car
{
public:
	int ID, Year, ShowRoomId;
	string Make, Model;
	float price;
	//installment


	list<Car>Clist;
	Car();
	void addCars();
	void updateCars();
	void deleteCars(char id[]);
	bool search(int);
	void LoadCars();


};

class Showrooms
{
public:
	int ID, phoneNumber;
	string Name, Location;
	vector<Car> RoomCarList;


	list<Showrooms> Slist;
	void addShowrooms();
	void updateShowrooms();
	void deleteShowrooms();
	int search();
	void view(int id);
	void LoadShowRoom();
};



class Buy_Rent_process
{
	int process_id, customer_id;
	string Date, ChosenCar;
	float money;
	string Processtype;

public:
	void Process(int CarID, int Customerid);
	void AddProcessData(char Carid[25], int Cid);
	void DisplayData(char Carid[25], int Cid);
	Buy_Rent_process();

};

class service_process
{
public:

	int process_id, customer_id;
	string Date, choosen_service;
	float money;
	service_process();
	service_process(int,string,float,string);
	void history_search(int);
	void history(service_process);

};

class Service
{
public:
	int ID;
	string Name, time, workerrName;
	float price;

	list<Service> servicelist;

	void addServices();
	void updateServices();
	void deleteServices();
	void deleteFromGarage(string);
	void search(int);
	void load();
	

};

class Reservations {
public:
	int carID;
	time_t reserveTime;
};

class Garage
{
public:
	int ID, phoneNumber;
	string Name, Location;
	//list of services
	Service arr[6];


	void addGarages();
	void updateGarages();
	void deleteGarages();
	void search(int);
	void searchLocation(string);
	void view();
	void load();
	void garage_appoinment(service_process);
	void view_service(Garage);
	void show_appointments();


};



