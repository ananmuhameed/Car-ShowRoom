#include"Classes.h"
fstream outFile;


void Showrooms::addShowrooms() {
	Car c;
	bool Done = false;
	bool Found = false;
	int id;
	string choice;

	system("CLS");

	outFile.open("Showrooms.txt", ios::app);
	cout << "Showroom ID: ";
	cin >> ID;
	cout << "Showroom Name: ";
	cin >> Name;
	cout << "Phone Number: ";
	cin >> phoneNumber;
	cout << "Showroom Location: ";
	cin >> Location;

	if (outFile.is_open()) {
		outFile << "Showroom ID :" << ID << endl;
		outFile << "Showroom Name :" << Name << endl;
		outFile << "Phone Number :" << phoneNumber << endl;
		outFile << "Showroom Location :" << Location << endl;
		outFile << endl;
		outFile.close();
	}
	list<Car> ::iterator it;
	cout << "Enter Car ID You Want to Add" << endl;
	cin >> id;
	while(!Done)
	{
		Found = false;
		c.LoadCars();
		for (it = c.Clist.begin(); it != c.Clist.end(); it++)
		{
			if (it->ID == id)
			{
				outFile.open("Showrooms.txt", ios::app);
				if (outFile.is_open()) {

					outFile << "Car ID :" << it->ID << endl;
					outFile << "Car Make :" << it->Make << endl;
					outFile << "Car Model :" << it->Model << endl;
					outFile << "Car Year :" << it->Year << endl;
					outFile << "Car Price :" << it->price << endl;
					//	outFile << endl;
					//	outFile.close();
					cout << "Do You Want To Add Another Car Y/N" << endl;
					cin >> choice;
					if (choice == "N" || choice == "n")
					{
						//		outFile.open("Showrooms.txt", ios::app);
						outFile << "$:";
						outFile << endl;
						outFile.close();
						Done = true;
					}
					else
					{
						cout << "Enter Car ID" << endl;
						cin >> id;
						outFile << endl;
						outFile.close();
					}
				}
				Found = true;
			}
			if (Found)
				break;
				
		}
		if (!Found)
		{
			cout << "Wrong Car ID..." << endl;
			cout << "Enter Car ID" << endl;
			cin >> id;
		}	
	}
}

void Showrooms::updateShowrooms() {


	char key[25], IdInfo[25], ShowroomName[25], ShowroomNumber[25], ShowroomLocation[25];
	fstream newf;
	fstream temp;
	newf.open("Showrooms.txt", ios::in);
	temp.open("temp.txt", ios::out);
	int Choice = 0;
	string Value_Up = "";
	cout << "Please enter Showroom ID that you want to change it's Data " << endl;
	cin >> key;

	if (newf.is_open()) {


		while (!newf.eof()) {

			newf.getline(IdInfo, 25, ':');
			newf.getline(IdInfo, 25);
			newf.getline(ShowroomName, 25, ':');
			newf.getline(ShowroomName, 25);
			newf.getline(ShowroomNumber, 25, ':');
			newf.getline(ShowroomNumber, 25);
			newf.getline(ShowroomLocation, 25, ':');
			newf.getline(ShowroomLocation, 25);


			if (IdInfo[0] != 0)
			{
				if (strcmp(key, IdInfo) == 0) {
					//check Showroom exist
					cout << "please enter 1 to change Showroom Name" << endl;
					cout << "please enter 2 to change Showroom Number" << endl;
					cout << "please enter 3 to change Showroom Location" << endl;
					cin >> Choice;

					switch (Choice) {
						// use same format instead of variables to ensure file consistency
					case 1:

						cout << "please enter new Name" << endl;
						cin >> Value_Up;

						temp << "Showroom ID :" << IdInfo << endl;
						temp << "Showroom Name :" << Value_Up << endl;
						temp << "Showroom Number :" << ShowroomNumber << endl;
						temp << "Showroom Location :" << ShowroomLocation << endl;
						temp << endl;

						break;
					case 2:
						cout << "please enter new Number" << endl;
						cin >> Value_Up;
						temp << "Showroom ID :" << IdInfo << endl;
						temp << "Showroom Name :" << ShowroomName << endl;
						temp << "Showroom Number :" << Value_Up << endl;
						temp << "Showroom Location :" << ShowroomLocation << endl;
						temp << endl;
						break;
					case 3:
						cout << "please enter new Location" << endl;
						cin >> Value_Up;
						temp << "Showroom ID :" << IdInfo << endl;
						temp << "Showroom Name :" << ShowroomName << endl;
						temp << "Showroom Number :" << ShowroomNumber << endl;
						temp << "Showroom Location :" << Value_Up << endl;
						temp << endl;
						break;



					}




				}

				else {

					temp << "Showroom ID :" << IdInfo << endl;
					temp << "Showroom Name :" << ShowroomName << endl;
					temp << "Showroom Number :" << ShowroomNumber << endl;
					temp << "Showroom Location :" << ShowroomLocation << endl;
					temp << endl;

				}
			}

		}
	}
	temp.close();
	newf.close();

	newf.open("Showrooms.txt", ios::out);
	temp.open("temp.txt", ios::in);

	if (temp.is_open()) {
		while (!temp.eof()) {



			temp.getline(IdInfo, 25, ':');
			temp.getline(IdInfo, 25);
			temp.getline(ShowroomName, 25, ':');
			temp.getline(ShowroomName, 25);
			temp.getline(ShowroomNumber, 25, ':');
			temp.getline(ShowroomNumber, 25);
			temp.getline(ShowroomLocation, 25, ':');
			temp.getline(ShowroomLocation, 25);




			if (IdInfo[0] != 0)
			{
				newf << "Showroom ID :" << IdInfo << endl;
				newf << "Showroom Name :" << ShowroomName << endl;
				newf << "Showroom Number :" << ShowroomNumber << endl;
				newf << "Showroom Location :" << ShowroomLocation << endl;
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

void Showrooms::deleteShowrooms() {


	char key[25],
		IdInfo[25],
		ShowroomName[25],
		ShowroomNumber[25],
		ShowroomLocation[25];
	fstream newf;
	fstream temp;
	newf.open("Showrooms.txt", ios::in);
	temp.open("temp.txt", ios::out);
	int Choice = 0;
	string Value_Up = "";
	cout << "Please enter Showroom ID that you want to delete" << endl;
	cin >> key;

	if (newf.is_open()) {


		while (!newf.eof()) {

			newf.getline(IdInfo, 25, ':');
			newf.getline(IdInfo, 25);
			newf.getline(ShowroomName, 25, ':');
			newf.getline(ShowroomName, 25);
			newf.getline(ShowroomNumber, 25, ':');
			newf.getline(ShowroomNumber, 25);
			newf.getline(ShowroomLocation, 25, ':');
			newf.getline(ShowroomLocation, 25);


			if (IdInfo[0] != 0) {

				if (strcmp(key, IdInfo) == 0) {
					//transfer data to temp !EXCEPT! for the data we want to delete
					continue;
				}

				else {
					temp << "Showroom ID :" << IdInfo << endl;
					temp << "Showroom Name :" << ShowroomName << endl;
					temp << "Showroom Number :" << ShowroomNumber << endl;
					temp << "Showroom Location :" << ShowroomLocation << endl;
					temp << endl;
				}
			}
		}
	}
	temp.close();
	newf.close();

	newf.open("Showrooms.txt", ios::out);
	temp.open("temp.txt", ios::in);

	if (temp.is_open()) {
		while (!temp.eof()) {

			temp.getline(IdInfo, 25, ':');
			temp.getline(IdInfo, 25);
			temp.getline(ShowroomName, 25, ':');
			temp.getline(ShowroomName, 25);
			temp.getline(ShowroomNumber, 25, ':');
			temp.getline(ShowroomNumber, 25);
			temp.getline(ShowroomLocation, 25, ':');
			temp.getline(ShowroomLocation, 25);


			if (IdInfo[0] != 0) {
				newf << "Showroom ID :" << IdInfo << endl;
				newf << "Showroom Name :" << ShowroomName << endl;
				newf << "Showroom Number :" << ShowroomNumber << endl;
				newf << "Showroom Location :" << ShowroomLocation << endl;
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

void Showrooms::LoadShowRoom()
{
	Showrooms S;
	Car cr;
	int counter = 0;
	bool done = false;

	char  Sid[25], SIdInfo[25], PN[25], PNInfo[25], Name[25], NameInfo[25], Location[25], LocationInfo[25];
	char  id[25], IdInfo[25], CarMake[25], CarMakeInfo[25], CarModel[25], CarModelInfo[25], CarYear[25], CarYearInfo[25], CarPrice[25], CarPriceInfo[25];

	outFile.open("Showrooms.txt", ios::in);
	if (outFile.is_open())
	{
		while (!outFile.eof())
		{
			outFile.getline(Sid, 25, ':');
			outFile.getline(SIdInfo, 25);
			S.ID = atoi(SIdInfo);

			if (S.ID == NULL)
				break;

			outFile.getline(Name, 25, ':');
			outFile.getline(NameInfo, 25);
			S.Name = NameInfo;

			outFile.getline(PN, 25, ':');
			outFile.getline(PNInfo, 25);
			S.phoneNumber = atoi(PNInfo);

			outFile.getline(Location, 25, ':');
			outFile.getline(LocationInfo, 25);
			S.Location = LocationInfo;
			done = false;
			// Cars Data
			outFile.getline(id, 25, ':');
			while (id[0] != '$')
			{

				outFile.getline(IdInfo, 25);

				cr.ID = atoi(IdInfo);


				outFile.getline(CarMake, 25, ':');
				outFile.getline(CarMakeInfo, 25);
				cr.Make = CarMakeInfo;

				outFile.getline(CarModel, 25, ':');
				outFile.getline(CarModelInfo, 25);
				cr.Model = CarModelInfo;

				outFile.getline(CarYear, 25, ':');
				outFile.getline(CarYearInfo, 25);
				cr.Year = atoi(CarYearInfo);

				outFile.getline(CarPrice, 25, ':');
				outFile.getline(CarPriceInfo, 25);
				cr.price = atof(CarPriceInfo);

				cr.ShowRoomId = S.ID;
				S.RoomCarList.push_back(cr);
				outFile.getline(id, 25, ':');


			}

			Slist.push_back(S);
			S.RoomCarList.clear();
		}

		outFile.close();
		//	return Slist;
	}


}
int Showrooms::search() {
	Showrooms s;
	s.LoadShowRoom();
	list<Showrooms> ::iterator it;
	bool vaild = false;

	char name[25];
	cin >> Name;
	for (it = s.Slist.begin(); it != s.Slist.end(); it++)
	{
		if (it->Name == Name)
		{
			cout << "ID: " << it->ID << endl;
			cout << "Phone Number: " << it->phoneNumber << endl;
			cout << "Location: " << it->Location << endl;
			vaild = true;
			return it->ID;
		}
		
	}
	if (!vaild)
	{
		cout << "Re-enter ShowRoom Name " << endl;
		search();
	}
		
	return -1;
}

void Showrooms::view(int CustomerId)
{
	system("cls");
	Buy_Rent_process b;
	char choice = 'n';
	Showrooms s;
	s.LoadShowRoom();
	list<Showrooms> ::iterator it;
	int i = 0;
	int SID = 0;
	int CarID = 0;
	bool vaild = false;
	bool Search = false;
	cout << "                                           ShowRooms Data" << endl;
	for (it = s.Slist.begin(); it != s.Slist.end(); it++)
	{
		cout << "ID: " << it->ID << endl;
		cout << "Name: " << it->Name << endl;
		cout << "Phone Number: " << it->phoneNumber << endl;
		cout << "Location: " << it->Location << endl;
		cout << endl;
	}

	cout << endl << endl;
	cout << "Would You Like to Search for a Specfic ShowRoom Y/N" << endl;
	cin >> choice;
	while (!Search)
	{
		if (choice == 'y' || choice == 'Y')
		{
			cout << "Enter ShowRoom Name " << endl;
			SID = s.search();
			Search = true;
		}

		else if (choice == 'n' || choice == 'N')
		{
			cout << "Enter ShowRoomId " << endl;
			cin >> SID;
			Search = true;

			while (!vaild)
			{
				
				for (it = s.Slist.begin(); it != s.Slist.end(); it++)
				{
					if (it->ID == SID)
					{
						vaild = true;
						break;
					}
				}
				if (!vaild)
				{
					cout << "ShowRoom doesn't exsist.. " << endl;
					cout << "Re-enter ShowRoom Id" << endl;
					cin >> SID;
				}
			}
		}

		if (Search)
			break;

		cout << "Invaild Choice Y/N" << endl;
		cin >> choice;
	}

	s.LoadShowRoom();
	b.Process(SID, CustomerId);


}
