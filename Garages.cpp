#include"Classes.h"

fstream myFile;
list<Garage> garagelist;
Service ss;
queue <service_process> process;
service_process serv;


void Garage::addGarages() {
	string servicenamee;
	char ans;

	system("CLS");

	myFile.open("Garages.txt", ios::app);
	cout << "Garage ID: ";
	cin >> ID;
	cout << "Garage Name: ";
	cin >> Name;
	cout << "Phone Number: ";
	cin >> phoneNumber;
	cout << "Garage Location: ";
	cin >> Location;
	cout << "Services: ";
	
	for (int i = 0; i < 3; i++) {
		cin >> servicenamee;
		arr[i].Name = servicenamee;
		cout << "Do you want to Add other Service?\n";
		cin >> ans;
		if (ans == 'N' || ans == 'n')
			break;
	}

	if (myFile.is_open()) {
		myFile << "Garage ID :" << ID << endl;
		myFile << "Garage Name :" << Name << endl;
		myFile << "Phone Number :" << phoneNumber << endl;
		myFile << "Garage Location :" << Location << endl;
		myFile << "Services :";
		for (int i = 0; i < 3; i++) {
			myFile << arr[i].Name << ",";
		}
		myFile << endl<<endl;
		myFile.close();
	}

	
	


}

void Garage::updateGarages() {



	char key[25], IdInfo[25], GarageName[25], GarageNumber[25], GarageLocation[25],servicesss[35],servName[25];
	Service arr[3];

	fstream newf;
	fstream temp;
	newf.open("Garages.txt", ios::in);
	temp.open("temp.txt", ios::out);
	int Choice = 0;
	string Value_Up = "";
	cout << "Please enter Garage ID that you want to change it's Data " << endl;
	cin >> key;

	if (newf.is_open()) {


		while (!newf.eof()) {

			newf.getline(IdInfo, 25, ':');
			newf.getline(IdInfo, 25);
			newf.getline(GarageName, 25, ':');
			newf.getline(GarageName, 25);
			newf.getline(GarageNumber, 25, ':');
			newf.getline(GarageNumber, 25);
			newf.getline(GarageLocation, 25, ':');
			newf.getline(GarageLocation, 25);
			newf.getline(servicesss, 35, ':');
			for (int i = 0; i < 3; i++) {
				newf.getline(servName, 25, ',');
				arr[i].Name = servName;
			}



			if (IdInfo[0] != 0)
			{
				if (strcmp(key, IdInfo) == 0) {
					//check Garage exist
					cout << "please enter 1 to change Garage Name" << endl;
					cout << "please enter 2 to change Garage Number" << endl;
					cout << "please enter 3 to change Garage Location" << endl;
					cin >> Choice;

					switch (Choice) {
						// use same format instead of variables to ensure file consistency
					case 1:

						cout << "please enter new Name" << endl;
						cin >> Value_Up;

						temp << "Garage ID :" << IdInfo << endl;
						temp << "Garage Name :" << Value_Up << endl;
						temp << "Garage Number :" << GarageNumber << endl;
						temp << "Garage Location :" << GarageLocation << endl;
						temp << "Services :";
						for (int i = 0; i < 3; i++) {
							temp << arr[i].Name << ",";
						}
						temp << endl<<endl;

						break;
					case 2:
						cout << "please enter new Number" << endl;
						cin >> Value_Up;
						temp << "Garage ID :" << IdInfo << endl;
						temp << "Garage Name :" << GarageName << endl;
						temp << "Garage Number :" << Value_Up << endl;
						temp << "Garage Location :" << GarageLocation << endl;
						temp << "Services :";
						for (int i = 0; i < 3; i++) {
							temp << arr[i].Name << ",";
						}
						temp << endl << endl;
						break;
					case 3:
						cout << "please enter new Location" << endl;
						cin >> Value_Up;
						temp << "Garage ID :" << IdInfo << endl;
						temp << "Garage Name :" << GarageName << endl;
						temp << "Garage Number :" << GarageNumber << endl;
						temp << "Garage Location :" << Value_Up << endl;
						temp << "Services :";
						for (int i = 0; i < 3; i++) {
							temp << arr[i].Name << ",";
						}
						temp << endl << endl;
						break;



					}




				}

				else {

					temp << "Garage ID :" << IdInfo << endl;
					temp << "Garage Name :" << GarageName << endl;
					temp << "Garage Number :" << GarageNumber << endl;
					temp << "Garage Location :" << GarageLocation << endl;
					temp << "Services :";
					for (int i = 0; i < 3; i++) {
						temp << arr[i].Name << ",";
					}
					temp << endl << endl;
				}
			}

		}
	}
	temp.close();
	newf.close();

	newf.open("Garages.txt", ios::out);
	temp.open("temp.txt", ios::in);

	if (temp.is_open()) {
		while (!temp.eof()) {



			temp.getline(IdInfo, 25, ':');
			temp.getline(IdInfo, 25);
			temp.getline(GarageName, 25, ':');
			temp.getline(GarageName, 25);
			temp.getline(GarageNumber, 25, ':');
			temp.getline(GarageNumber, 25);
			temp.getline(GarageLocation, 25, ':');
			temp.getline(GarageLocation, 25);
			temp.getline(servicesss, 35, ':');
			for (int i = 0; i < 3; i++) {
				temp.getline(servName, 25, ',');
				arr[i].Name = servName;
			}




			if (IdInfo[0] != 0)
			{
				newf << "Garage ID :" << IdInfo << endl;
				newf << "Garage Name :" << GarageName << endl;
				newf << "Garage Number :" << GarageNumber << endl;
				newf << "Garage Location :" << GarageLocation << endl;
				newf << "Services :";
				for (int i = 0; i < 3; i++) {
					newf << arr[i].Name << ",";
				}
				newf << endl << endl;
			}
		}
	}
	temp.close();
	newf.close();

	system("CLS");
	cout << "       \tDONE!       " << endl;

	remove("temp.txt");







}

void Garage::deleteGarages() {


	char key[25],
		IdInfo[25],
		GarageName[25],
		GarageNumber[25],
		GarageLocation[25],
		serv[35];
	fstream newf;
	fstream temp;
	newf.open("Garages.txt", ios::in);
	temp.open("temp.txt", ios::out);
	int Choice = 0;
	string Value_Up = "";
	cout << "Please enter Garage ID that you want to delete" << endl;
	cin >> key;

	if (newf.is_open()) {


		while (!newf.eof()) {

			newf.getline(IdInfo, 25, ':');
			newf.getline(IdInfo, 25);
			newf.getline(GarageName, 25, ':');
			newf.getline(GarageName, 25);
			newf.getline(GarageNumber, 25, ':');
			newf.getline(GarageNumber, 25);
			newf.getline(GarageLocation, 25, ':');
			newf.getline(GarageLocation, 25);
			newf.getline(serv, 35, ':');
			newf.getline(serv, 35);


			if (IdInfo[0] != 0) {

				if (strcmp(key, IdInfo) == 0) {
					//transfer data to temp !EXCEPT! for the data we want to delete
					continue;
				}

				else {
					temp << "Garage ID :" << IdInfo << endl;
					temp << "Garage Name :" << GarageName << endl;
					temp << "Garage Number :" << GarageNumber << endl;
					temp << "Garage Location :" << GarageLocation << endl;
					temp << "Services :" << serv << endl;
					temp << endl;
				}
			}
		}
	}
	temp.close();
	newf.close();

	newf.open("Garages.txt", ios::out);
	temp.open("temp.txt", ios::in);

	if (temp.is_open()) {
		while (!temp.eof()) {

			temp.getline(IdInfo, 25, ':');
			temp.getline(IdInfo, 25);
			temp.getline(GarageName, 25, ':');
			temp.getline(GarageName, 25);
			temp.getline(GarageNumber, 25, ':');
			temp.getline(GarageNumber, 25);
			temp.getline(GarageLocation, 25, ':');
			temp.getline(GarageLocation, 25);
			temp.getline(serv, 35, ':');
			temp.getline(serv, 35);


			if (IdInfo[0] != 0) {
				newf << "Garage ID :" << IdInfo << endl;
				newf << "Garage Name :" << GarageName << endl;
				newf << "Garage Number :" << GarageNumber << endl;
				newf << "Garage Location :" << GarageLocation << endl;
				newf << "Services :" << serv << endl;
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

void Garage::search(int key) {
	system("cls");
	bool found = false;
	char ans;
	list <Garage> ::iterator it;
	Garage g;



	for (it=garagelist.begin(); it!=garagelist.end(); it++) {
		if (key == it->ID) {
			cout << "\n\nGarage Id : " << it->ID<< endl;
			g.ID = it->ID;
			cout << "Garage Name : " << it->Name << endl;
			g.Name = it->Name;
			cout << "Garage Number : " << it->phoneNumber << endl;
			g.phoneNumber = it->phoneNumber;
			cout << "Garage Location : " << it->Location << endl;
			g.Location = it->Location;
			cout << "Services : ";
			for (int i = 0; i < 3; i++) {
				cout << it->arr[i].Name << " , ";
				g.arr[i] = it->arr[i];
			}
			
			found = true;
			break;
		}
		
	}
	if (!found)
		cout << "\nnot found\n";

	if (found) {
		cout << "\n\nConfirm choosing this Garage? (y/n)\n";
		cin >> ans;
		if (ans == 'n' || ans == 'N')
			view();
		else
			view_service(g);
	}


	
}

void Garage::searchLocation(string key) {
	system("cls");
	bool found = false;
	char ans;
	list <Garage> ::iterator it;
	Garage g;



	for (it = garagelist.begin(); it != garagelist.end(); it++) {
		if (key == it->Location) {
			cout << "\n\nGarage Id : " << it->ID << endl;
			g.ID = it->ID;
			cout << "Garage Name : " << it->Name << endl;
			g.Name = it->Name;
			cout << "Garage Number : " << it->phoneNumber << endl;
			g.phoneNumber = it->phoneNumber;
			cout << "Garage Location : " << it->Location << endl;
			g.Location = it->Location;
			cout << "Services : ";
			for (int i = 0; i < 3; i++) {
				cout << it->arr[i].Name << " , ";
				g.arr[i] = it->arr[i];
			}

			found = true;
			break;
		}

	}
	if (!found)
		cout << "\nnot found\n";

	if (found) {
		cout << "\n\nConfirm choosing this Garage? (y/n)\n";
		cin >> ans;
		if (ans == 'n' || ans == 'N')
			view();
		else
			view_service(g);
	}



}


void Garage::view() {
	system("cls");
	char ans;
	int choice;
	string loc;


	list<Garage> ::iterator it;

	for ( it=garagelist.begin(); it != garagelist.end(); it++) {


		cout <<"\n\nGarage Id : "<< it->ID<< endl;
		cout << "Garage Name : " << it->Name << endl;
		cout << "Garage Number : " << it->phoneNumber << endl;
		cout << "Garage Location : " << it->Location<< endl;
		cout << "Services : ";

		for (int i = 0; i < 3; i++) 
			cout << it->arr[i].Name << " , ";
		
		cout << endl << endl;
	}

	cout << "Search for a Garage Near You?(y/n) \n";
	cin >> ans;
	if (ans == 'y' || ans == 'Y')
	{
		cout << "Location : ";
		cin >> loc;
		searchLocation(loc);
	}
	else
	{
		cout << "choose a garage id : ";
		cin >> choice;
		search(choice);


	}
	cout << endl << endl;

}

void Garage::load()
{
	Garage g;
	char id[25], name[25], number[25], location[25], arr[35];
	Service s[10];
	string servicename;


	myFile.open("Garages.txt", ios::in);
	if (myFile.is_open())
	{
		while (!myFile.eof())
		{
			myFile.getline(id, 25, ':');
			myFile.getline(id, 25);
			myFile.getline(name, 25, ':');
			myFile.getline(name, 25);
			myFile.getline(number, 25, ':');
			myFile.getline(number, 25);
			myFile.getline(location, 25, ':');
			myFile.getline(location, 25);

			if (id[0] == 0)
				break;
			g.ID = atoi(id);
			g.Name = name;
			g.phoneNumber = atoi(number);
			g.Location = location;


			myFile.getline(arr, 25, ':');
			for (int i = 0; i < 3; i++) {
				getline(myFile, s[i].Name, ',');
				g.arr[i].Name = s[i].Name;
			}




			garagelist.push_back(g);

		}
	}
	myFile.close();


}

void Garage::garage_appoinment(service_process s) {

	process.push(s);
	serv.history(s);



		myFile.open("appointments.txt", ios::app);
		if (myFile.is_open()) {
			myFile<< "proccess id : " << s.process_id << endl;
			myFile << "customer id : " << s.customer_id << endl;
			myFile << "Service : " << s.choosen_service << endl;
			myFile << "Price : " << s.money << endl << endl;
		}
		myFile.close();



	

	

}

void Garage::show_appointments() {
	char ans;
	Admin ad;
	Customer cu;
	system("cls");
	while (!process.empty()) {
		cout << "Process Id : " << process.front().process_id << endl;
		cout << "Customer Id : " << process.front().customer_id << endl;
		cout << "Choosen Service : " << process.front().choosen_service << endl;
		cout << "Price : " << process.front().money << endl;
		cout << "Date : " << process.front().Date << endl << endl;
		process.pop();
	}

	cout << "Do you want any other Options?(y/n)\n";
	cin >> ans;
	if (ans == 'y' || ans == 'Y')
		ad.admin_page();
	else cu.main_login();




}

