#include"Classes.h"
#include<iomanip>
using namespace std;

fstream File;

Car:: Car()
{
	ID, Year, price = 0;
	Model, Make = "";
}

void Car::addCars() {

	system("CLS");

	File.open("Cars.txt", ios::app);
	cout << "Car ID: ";
	cin >> ID;
	cout << "Car Make: ";
	cin >> Make;
	cout << "Car Model: ";
	cin >> Model;
	cout << "Car Year: ";
	cin >> Year;
	cout << "Car price: ";
	cin >> price;
	if (File.is_open()) {
		File << "Car ID :" << ID << endl;
		File << "Car Make :" << Make << endl;
		File << "Car Model :" << Model << endl;
		File << "Car Year :" << Year << endl;
		File << "Car price :" << price << setprecision(3) << endl;
		File << endl;
		File.close();
	}
}

void Car::updateCars() {

	char key[25], IdInfo[25], CarMakeInfo[25], CarModelInfo[25], CarYearInfo[25], CarPriceInfo[25];
	fstream newf;
	fstream temp;
	newf.open("Cars.txt", ios::in);
	temp.open("temp.txt", ios::out);
	int Choice = 0;
	string Value_Up = "";
	cout << "Please enter car ID that you want to change it's Data " << endl;
	cin >> key;

	if (newf.is_open()) {


		while (!newf.eof()) {

			newf.getline(IdInfo, 25, ':');
			newf.getline(IdInfo, 25);
			newf.getline(CarMakeInfo, 25, ':');
			newf.getline(CarMakeInfo, 25);
			newf.getline(CarModelInfo, 25, ':');
			newf.getline(CarModelInfo, 25);
			newf.getline(CarYearInfo, 25, ':');
			newf.getline(CarYearInfo, 25);
			newf.getline(CarPriceInfo, 25, ':');
			newf.getline(CarPriceInfo, 25);

			if (IdInfo[0] != 0)
			{
				if (strcmp(key, IdInfo) == 0) {
					//check car exist
					cout << "please enter 1 to change Car Make" << endl;
					cout << "please enter 2 to change Car Model" << endl;
					cout << "please enter 3 to change Car Year" << endl;
					cout << "please enter 4 to change Car Price" << endl;
					cin >> Choice;

					switch (Choice) {
						// use same format instead of variables to ensure file consistency
					case 1:

						cout << "please enter new Make" << endl;
						cin >> Value_Up;

						temp << "Car ID :" << IdInfo << endl;
						temp << "Car Make :" << Value_Up << endl;
						temp << "Car Model :" << CarModelInfo << endl;
						temp << "Car Year :" << CarYearInfo << endl;
						temp << "Car Price :" << CarPriceInfo << endl;
						temp << endl;

						break;
					case 2:
						cout << "please enter new Model" << endl;
						cin >> Value_Up;
						temp << "Car ID :" << IdInfo << endl;
						temp << "Car Make :" << CarMakeInfo << endl;
						temp << "Car Model :" << Value_Up << endl;
						temp << "Car Year :" << CarYearInfo << endl;
						temp << "Car Price :" << CarPriceInfo << endl;
						temp << endl;
						break;
					case 3:
						cout << "please enter new Year" << endl;
						cin >> Value_Up;
						temp << "Car ID :" << IdInfo << endl;
						temp << "Car Make :" << CarMakeInfo << endl;
						temp << "Car Model :" << CarModelInfo << endl;
						temp << "Car Year :" << Value_Up << endl;
						temp << "Car Price :" << CarPriceInfo << endl;
						temp << endl;
						break;

					case 4:
						cout << "please enter new Price" << endl;
						cin >> Value_Up;
						temp << "Car ID :" << IdInfo << endl;
						temp << "Car Make :" << CarMakeInfo << endl;
						temp << "Car Model :" << CarModelInfo << endl;
						temp << "Car Year :" << CarYearInfo << endl;
						temp << "Car Price :" << Value_Up << endl;
						temp << endl;
						break;

					}




				}

				else {

					temp << "Car ID :" << IdInfo << endl;
					temp << "Car Make :" << CarMakeInfo << endl;
					temp << "Car Model :" << CarModelInfo << endl;
					temp << "Car Year :" << CarYearInfo << endl;
					temp << "Car Price :" << CarPriceInfo << endl;
					temp << endl;

				}
			}

		}
	}
	temp.close();
	newf.close();

	newf.open("Cars.txt", ios::out);
	temp.open("temp.txt", ios::in);

	if (temp.is_open()) {
		while (!temp.eof()) {



			temp.getline(IdInfo, 25, ':');
			temp.getline(IdInfo, 25);
			temp.getline(CarMakeInfo, 25, ':');
			temp.getline(CarMakeInfo, 25);
			temp.getline(CarModelInfo, 25, ':');
			temp.getline(CarModelInfo, 25);
			temp.getline(CarYearInfo, 25, ':');
			temp.getline(CarYearInfo, 25);
			temp.getline(CarPriceInfo, 25, ':');
			temp.getline(CarPriceInfo, 25);



			if (IdInfo[0] != 0)
			{
				newf << "Car ID :" << IdInfo << endl;
				newf << "Car Make :" << CarMakeInfo << endl;
				newf << "Car Model :" << CarModelInfo << endl;
				newf << "Car Year :" << CarYearInfo << endl;
				newf << "Car Price :" << CarPriceInfo << endl;
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

void Car::deleteCars(char key[25]) {

	// key[25],
		 char	IdInfo[25],
		CarMakeInfo[25],
		CarModelInfo[25],
		CarYearInfo[25],
		CarPriceInfo[25];
	fstream newf;
	fstream temp;
	newf.open("Cars.txt", ios::in);
	temp.open("temp.txt", ios::out);
	int Choice = 0;
	string Value_Up = "";
	//cout << "Please enter car ID that you want to delete" << endl;
	//cin >> key;

	if (newf.is_open()) {


		while (!newf.eof()) {

			newf.getline(IdInfo, 25, ':');
			newf.getline(IdInfo, 25);
			newf.getline(CarMakeInfo, 25, ':');
			newf.getline(CarMakeInfo, 25);
			newf.getline(CarModelInfo, 25, ':');
			newf.getline(CarModelInfo, 25);
			newf.getline(CarYearInfo, 25, ':');
			newf.getline(CarYearInfo, 25);
			newf.getline(CarPriceInfo, 25, ':');
			newf.getline(CarPriceInfo, 25);

			if (IdInfo[0] != 0) {

				if (strcmp(key, IdInfo) == 0) {
					//transfer data to temp !EXCEPT! for the data we want to delete
					continue;
				}

				else {
					temp << "Car ID :" << IdInfo << endl;
					temp << "Car Make :" << CarMakeInfo << endl;
					temp << "Car Model :" << CarModelInfo << endl;
					temp << "Car Year :" << CarYearInfo << endl;
					temp << "Car Price :" << CarPriceInfo << endl;
					temp << endl;
				}
			}
		}
	}
	temp.close();
	newf.close();

	newf.open("Cars.txt", ios::out);
	temp.open("temp.txt", ios::in);

	if (temp.is_open()) {
		while (!temp.eof()) {

			temp.getline(IdInfo, 25, ':');
			temp.getline(IdInfo, 25);
			temp.getline(CarMakeInfo, 25, ':');
			temp.getline(CarMakeInfo, 25);
			temp.getline(CarModelInfo, 25, ':');
			temp.getline(CarModelInfo, 25);
			temp.getline(CarYearInfo, 25, ':');
			temp.getline(CarYearInfo, 25);
			temp.getline(CarPriceInfo, 25, ':');
			temp.getline(CarPriceInfo, 25);

			if (IdInfo[0] != 0) {
				newf << "Car ID :" << IdInfo << endl;
				newf << "Car Make :" << CarMakeInfo << endl;
				newf << "Car Model :" << CarModelInfo << endl;
				newf << "Car Year :" << CarYearInfo << endl;
				newf << "Car Price :" << CarPriceInfo << endl;
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

bool Car::search(int Sid) {

	Showrooms s;
	s.LoadShowRoom();
	bool found = false;
	int id;
	int count = 0;
	bool Cars = false;
	LoadCars();
	list<Car> ::iterator it;
	list<Showrooms>::iterator t;

	system("cls");
	cout << "Cars in Your Showroom" << endl;

	for (t = s.Slist.begin(); t != s.Slist.end(); t++)
	{
		if (t->ID == Sid)
		{
			while (count < t->RoomCarList.size())
			{
				cout << "ID: " << t->RoomCarList[count].ID << endl;
				cout << "Phone Number: " << t->RoomCarList[count].Make << endl;
				cout << "Model: " << t->RoomCarList[count].Model << endl;
				cout << "Year: " << t->RoomCarList[count].Year << endl;
				cout << "Price: " << t->RoomCarList[count].price << endl;
				cout << endl;
				count++;
			}
			Cars = true;
		}
		if (Cars)
			break;
	}
	cout << "Enter  Car id you want to Search" << endl;
	cin >> id;

	system("cls");
	cout << "Your Choosen Car" << endl;
	for (it = Clist.begin(); it != Clist.end(); it++)
	{
		if (it->ID == id)
		{
			cout << "ID: " << it->ID << endl;
			cout << "Phone Number: " << it->Make << endl;
			cout << "Model: " << it->Model << endl;
			cout << "Year: " << it->Year << endl;
			cout << "Price: " << it->price << endl;
			found = true;
			break;
		}

	}
	return found;
}

void Car::LoadCars()
{
	Car c;

	char  id[25], IdInfo[25], CarMake[25], CarMakeInfo[25], CarModel[25], CarModelInfo[25], CarYear[25], CarYearInfo[25], CarPrice[25], CarPriceInfo[25];
	File.open("Cars.txt", ios::in);
	if (File.is_open())
	{
		while (!File.eof())
		{
			File.getline(id, 25, ':');
			File.getline(IdInfo, 25);
			c.ID = atoi(IdInfo);
			File.getline(CarMake, 25, ':');
			File.getline(CarMakeInfo, 25);
			c.Make = CarMakeInfo;
			File.getline(CarModel, 25, ':');
			File.getline(CarModelInfo, 25);
			c.Model = CarModelInfo;
			File.getline(CarYear, 25, ':');
			File.getline(CarYearInfo, 25);
			c.Year = atoi(CarYearInfo);
			File.getline(CarPrice, 25, ':');
			File.getline(CarPriceInfo, 25);
			c.price = atof(CarPriceInfo);
			Clist.push_back(c);
		}
		File.close();
	}
}

