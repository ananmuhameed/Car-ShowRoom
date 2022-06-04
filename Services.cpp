#define _CRT_SECURE_NO_WARNINGS
#include"Classes.h"
#include <windows.h>
#include<ctime>


fstream myFilee;
Garage garage;
Service serv;
//GetLocalTime(&a);


void Service::addServices() {

	system("CLS");

	myFilee.open("Services.txt", ios::app);
	cout << "Service ID: ";
	cin >> ID;
	cout << "Service Name: ";
	cin >> Name;
	cout << "Service price: ";
	cin >> price;
	cout << "Service time: ";
	cin >> time;
	cout << "Worker Name: ";
	cin >> workerrName;
	if (myFilee.is_open()) {
		myFilee << "Service ID :" << ID << endl;
		myFilee << "Service Name :" << Name << endl;
		myFilee << "Service price :" << price << endl;
		myFilee << "Service Time :" << time << endl;
		myFilee << "Worker Name :" << workerrName << endl;
		myFilee << endl;
		myFilee.close();
	}
}

void Service::updateServices() {

	char key[25], IdInfo[25], ServiceName[25], ServicePrice[25], ServiceTime[25],worker[25];
	fstream newf;
	fstream temp;
	newf.open("Services.txt", ios::in);
	temp.open("temp.txt", ios::out);
	int Choice = 0;
	string Value_Up = "";
	cout << "Please enter Service ID that you want to change it's Data " << endl;
	cin >> key;

	if (newf.is_open()) {


		while (!newf.eof()) {

			newf.getline(IdInfo, 25, ':');
			newf.getline(IdInfo, 25);
			newf.getline(ServiceName, 25, ':');
			newf.getline(ServiceName, 25);
			newf.getline(ServicePrice, 25, ':');
			newf.getline(ServicePrice, 25);
			newf.getline(ServiceTime, 25, ':');
			newf.getline(ServiceTime, 25);
			newf.getline(worker, 25, ':');
			newf.getline(worker, 25);



			if (IdInfo[0] != 0)
			{
				if (strcmp(key, IdInfo) == 0) {
					//check Service exist
					cout << "please enter 1 to change Service Name" << endl;
					cout << "please enter 2 to change Service Price" << endl;
					cout << "please enter 3 to change Service Time" << endl;
					cout << "please enter 4 to change Worker Name" << endl;


					cin >> Choice;

					switch (Choice) {
						// use same format instead of variables to ensure file consistency
					case 1:

						cout << "please enter new Name" << endl;
						cin >> Value_Up;

						temp << "Service ID :" << IdInfo << endl;
						temp << "Service Name :" << Value_Up << endl;
						temp << "Service Price :" << ServicePrice << endl;
						temp << "Service Time :" << ServiceTime << endl;
						temp << "Worker Name :" << worker << endl;
						temp << endl;

						break;
					case 2:
						cout << "please enter new Price" << endl;
						cin >> Value_Up;
						temp << "Service ID :" << IdInfo << endl;
						temp << "Service Name :" << ServiceName << endl;
						temp << "Service Price :" << Value_Up << endl;
						temp << "Service Time :" << ServiceTime << endl;
						temp << "Worker Name :" << worker << endl;
						temp << endl;
						break;

					case 3:
						cout << "please enter new Time" << endl;
						cin >> Value_Up;
						temp << "Service ID :" << IdInfo << endl;
						temp << "Service Name :" << ServiceName << endl;
						temp << "Service Price :" << ServicePrice << endl;
						temp << "Service Time :" << Value_Up << endl;
						temp << "Worker Name :" << worker << endl;
						temp << endl;
						break;

					case 4:
						cout << "please enter new Worker Name" << endl;
						cin >> Value_Up;
						temp << "Service ID :" << IdInfo << endl;
						temp << "Service Name :" << ServiceName << endl;
						temp << "Service Price :" << ServicePrice << endl;
						temp << "Service Time :" << ServiceTime << endl;
						temp << "Worker Name :" << Value_Up << endl;
						temp << endl;
						break;


					}




				}

				else {

					temp << "Service ID :" << IdInfo << endl;
					temp << "Service Name :" << ServiceName << endl;
					temp << "Service Price :" << ServicePrice << endl;
					temp << "Service Time :" << ServiceTime << endl;
					temp << "Worker Name :" << worker << endl;
					temp << endl;

				}
			}

		}
	}
	temp.close();
	newf.close();

	newf.open("Services.txt", ios::out);
	temp.open("temp.txt", ios::in);

	if (temp.is_open()) {
		while (!temp.eof()) {



			temp.getline(IdInfo, 25, ':');
			temp.getline(IdInfo, 25);
			temp.getline(ServiceName, 25, ':');
			temp.getline(ServiceName, 25);
			temp.getline(ServicePrice, 25, ':');
			temp.getline(ServicePrice, 25);
			temp.getline(ServiceTime, 25, ':');
			temp.getline(ServiceTime, 25);
			temp.getline(worker, 25, ':');
			temp.getline(worker, 25);





			if (IdInfo[0] != 0)
			{
				newf << "Service ID :" << IdInfo << endl;
				newf << "Service Name :" << ServiceName << endl;
				newf << "Service Price :" << ServicePrice << endl;
				newf << "Service Time :" << ServiceTime << endl;
				newf << "Worker Name :" << worker << endl;
				newf << endl;
			}
		}
	}
	temp.close();
	newf.close();

	system("CLS");
	cout << "       \tDONE!       " << endl;

	remove("temp.txt");






}

void Service::deleteServices() {



	char key[25],Id[25],
		 IdInfo[25],
		 ServiceName[25],
		 ServicePrice[25],
		 ServiceTime[25],
		 WorkerName[25];
	string name;
	fstream newf;
	fstream temp;
	newf.open("Services.txt", ios::in);
	temp.open("temp.txt", ios::out);
	int Choice = 0;
	string Value_Up = "";
	cout << "Please enter service ID that you want to delete" << endl;
	cin >> key;

	if (newf.is_open()) {


		while (!newf.eof()) {

			newf.getline(Id, 25, ':');
			newf.getline(IdInfo, 25);
			newf.getline(ServiceName, 25, ':');
			newf.getline(ServiceName, 25);
			newf.getline(ServicePrice, 25, ':');
			newf.getline(ServicePrice, 25);
			newf.getline(ServiceTime, 25, ':');
			newf.getline(ServiceTime, 25);
			newf.getline(WorkerName, 25, ':');
			newf.getline(WorkerName, 25);

			if (IdInfo[0] != 0) {

				if (strcmp(key, IdInfo) == 0) {
					//transfer data to temp !EXCEPT! for the data we want to delete
					continue;
				}

				else {
					temp << "Service Id :" << IdInfo << endl;
					temp << "ServiceName :" << ServiceName << endl;
					temp << "ServicePrice :" << ServicePrice << endl;
					temp << "ServiceTime :" << ServiceTime << endl;
					temp << "WorkerName :" << WorkerName << endl;
					temp << endl;
				}
			}
		}
	}
	temp.close();
	newf.close();

	newf.open("Services.txt", ios::out);
	temp.open("temp.txt", ios::in);

	if (temp.is_open()) {
		while (!temp.eof()) {

			temp.getline(IdInfo, 25, ':');
			temp.getline(IdInfo, 25);
			temp.getline(ServiceName, 25, ':');
			temp.getline(ServiceName, 25);
			temp.getline(ServicePrice, 25, ':');
			temp.getline(ServicePrice, 25);
			temp.getline(ServiceTime, 25, ':');
			temp.getline(ServiceTime, 25);
			temp.getline(WorkerName, 25, ':');
			temp.getline(WorkerName, 25);

			if (IdInfo[0] != 0) {
				newf << "Service Id :" << IdInfo << endl;
				newf << "ServiceName :" << ServiceName << endl;
				newf << "ServicePrice :" << ServicePrice << endl;
				newf << "ServiceTime :" << ServiceTime << endl;
				newf << "WorkerName :" << WorkerName << endl;
				newf << endl;
			}
		}
	}
	temp.close();
	newf.close();

	system("CLS");
	cout << "       \tDONE!       " << endl;

	remove("temp.txt");

}

void Service::search(int key) {

	system("cls");
	bool found = false;
	char ans;
	int id;
	list <Service> ::iterator it;



	for (it = servicelist.begin(); it != servicelist.end(); it++) {

		if (key == it->ID) {
			cout << "\n\nService Id : " << it->ID << endl;
			cout << "Service Name : " << it->Name << endl;
			cout << "Service Price : " << it->price << endl;
			cout << "Service Time : " << it->time << endl;
			cout << "Worker Name : " << it->workerrName << endl;
			

			found = true;
			break;
		}

	}
	if (!found)
		cout << "\nnot found\n";

	if (found) {
		cout << "\n\nConfirm choosing this Service? (y/n)\n";
		cin >> ans;
		if (ans == 'y' || ans == 'Y') {
			cout << "Enter your id to complete payment process\n";
			cin >> id;
			time_t t = std::time(0);   // get time now
			tm* now = std::localtime(&t);

			int year = (now->tm_year + 1900);
			int month = (now->tm_mon + 1);
			int day = now->tm_mday;
			string date = to_string(day)+"-"+ to_string(month)+"-"+ to_string(year);
			service_process s(id, it->Name, it->price,date);
			garage.garage_appoinment(s);
		}
			
			

	}



}

void Service::load() {

	Service s;
	char Id[25],
		ServiceName[25],
		ServicePrice[25],
		ServiceTime[25],
		WorkerName[25];



	myFilee.open("Services.txt", ios::in);
	if (myFilee.is_open())
	{
		while (!myFilee.eof())
		{
			myFilee.getline(Id, 25, ':');
			myFilee.getline(Id, 25);
			myFilee.getline(ServiceName, 25, ':');
			myFilee.getline(ServiceName, 25);
			myFilee.getline(ServicePrice, 25, ':');
			myFilee.getline(ServicePrice, 25);
			myFilee.getline(ServiceTime, 25, ':');
			myFilee.getline(ServiceTime, 25);
			myFilee.getline(WorkerName, 25, ':');
			myFilee.getline(WorkerName, 25);
			if (Id[0] == 0)
				break;
			s.ID = atoi(Id);
			s.Name = ServiceName;
			s.price = atof(ServicePrice);
			s.time = ServiceTime;
			s.workerrName = WorkerName;


			

			servicelist.push_back(s);

		}
	}
	myFilee.close();

}

void Garage::view_service(Garage g) {

	serv.load();

	char ans;
	int choice;
	list <Service> ::iterator it;
	system("cls");

	cout << "Available Services : ";

	for (it = serv.servicelist.begin(); it != serv.servicelist.end(); it++) {
		for (int i = 0; i < 3; i++) {
			if (it->Name == g.arr[i].Name) {

				cout << "\n\nService Id : " << it->ID << endl;
				cout << "Service Name : " << it->Name << endl;
				cout << "Service Price : " << it->price << endl;
				cout << "Service Time : " << it->time << endl;
				cout << "Worker Name : " << it->workerrName << endl;
				cout << endl << endl;
			}
		}
	}


	cout << "Search for a specific Service?(y/n) \n";
	cin >> ans;
	if (ans == 'y' || ans == 'Y')
	{
		cout << "id : ";
		cin >> choice;
		serv.search(choice);
	}
	else
	{
		cout << "choose a Service id : ";
		cin >> choice;
		serv.search(choice);


	}

}



