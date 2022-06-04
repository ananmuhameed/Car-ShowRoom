#include"Classes.h"
Car car;
Garage gar;
Service ser;
Showrooms roomm;
fstream cust;
int LoginId = 0;

Customer::Customer()
{
	ID = 0;
	username = "";
	password[15] = {};
	phone = NULL;
}

void Customer::SignUp()
{
	system("cls");
	int index = 0;
	char ch = NULL;

	cout << "Enter Your Name: ";
	cin.ignore();
	getline(cin, username);

	cout << "Enter Your ID: ";
	cin >> ID;

	cout << "Enter Your Phone: ";
	cin >> phone;

	cout << "Enter Your Password: ";
	ch = _getch();
	while (ch != '\r')
	{

		password[index] = ch;
		cout << "*";
		index++;
		ch = _getch();
	}

	system("cls");
	cout << "                   Account Created Successfully\n";
	cout << "                       Login to complete \n\n";




	cust.open("Database.txt", ios::app);
	if (cust.is_open())
	{
		cust << "UserName:" << username << endl;

		cust << "Password:";
		for (int i = 0; i < index; i++)
			cust << password[i];
		cust << endl;

		cust << "ID:" << ID << endl;
		cust << "Phone:" << phone << endl;
		cust << "----------" << endl;

		cust.close();
	}
}

void Customer::main_login() {

	int role;

	Customer C;
	Admin a;


	cout << "                       \n\t\t \t\t\t WELCOME TO CAR SHOWROOMS & REPAIR SHOPS\n\n\n";
	cout << "                                     \t      PRESS ENTER TO CONTINUE....\n\n";
	if (cin.get() == '\n') {
		system("cls");

		cout << "Who are You?" << endl;
		cout << "1. Admin" << endl;
		cout << "2. User" << endl;
		cout << endl << "Enter Your Option Or Press any Key to Exit" << endl;
		cin >> role;

		if (role == 1)
		{
			a.login();

		}
		else if (role == 2)
		{
			system("cls");
			//			cout << "                                  WELCOME USER" << endl;
			Login();
		}
		else
			exit(0);
	}
}

void Customer::Login() {
	Customer C;
	int line = 1;
	char namedb[25], pass[25], ch, Pn[25];
	char Cid[25];
	string username = "";
	string password = "";
	string n = "";
	string p = "";

	bool flag = false;
	cout << "                                               Welcome User\n\n";
	cout << "                                  Don't have an account?SignUp (y/n)\n\n\n";
	cin >> ch;
	if (ch == 'y' || ch == 'Y')
		SignUp();


	system("cls");
	cout << "Username: ";
	cin.ignore();
	getline(cin, username);
	cout << "Password: ";
	cin >> password;



	cust.open("Database.txt", ios::in);
	while (!cust.eof()) {
		line++;
		cust.getline(namedb, 30, ':');
		cust.getline(namedb, 30);
		cust.getline(pass, 30, ':');
		cust.getline(pass, 30);

		cust.getline(Cid, 30, ':');
		cust.getline(Cid, 30);

		cust.getline(Pn, 30, ':');
		cust.getline(Pn, 30);

		n = namedb;
		p = pass;


		//	if (line % 2 == 0) {
		if (n == username && p == password) {
			LoginId = atoi(Cid);
			cout << "Login Successful";
			flag = true;
			break;
		}

		//	}

	}
	cust.close();
	if (flag)
		customer_page();
	else {

	cout << "\nLOGIN ERROR\nPlease check your username and password\n";
	int menu;
	cout << "\npress 1 to login again\n";
	cin >> menu;
	if (menu == 1) {
		Login();
	}
	else
		exit(0);
	}
}

void Customer::customer_page() {

	service_process sep;

	system("cls");
	int choice1;
	cout << "                       \n       \t\t WELCOME User\n\n\n";
	cout << "                                   \t    MENU\n\n\n";

	cout << "Would you like to Buy/Rent a Car or Repair your own Car\n";
	cout << "1.Buy/Rent/Reserve" << endl;
	cout << "2.Repair" << endl;
	cout << "3.Show Historical Services" << endl;
	cout << "4.LOGOUT" << endl;
	cout << "\nEnter your choice :";
	cin >> choice1;

	switch (choice1) {
	case 1:
		roomm.view(LoginId);
		break;

	case 2:
		gar.load();
		gar.view();
		cout << "\nDo you want other Services? \n";
		cout << "1.Yes" << endl;
		cout << "2.LogOut" << endl;
		cout << "\nEnter your choice :";
		cin >> choice1;
		if (choice1 == 1)
			customer_page();
		else if (choice1 == 2)
			system("cls");
		main_login();
		break;
	case 3:
		sep.history_search(LoginId);
		break;

	default:
		exit(0);
	}

}

