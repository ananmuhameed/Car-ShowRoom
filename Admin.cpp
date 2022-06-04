#include"Classes.h"
Car c;
Garage g;
Service s;
Showrooms room;

void Admin::login() {
	system("CLS");
	int charcount = 0;
	char ch;
	string username;
	string admin_username = "fcis_asu";
	char correct[] = "fcis2024";
	int trials = 0;
	bool verified = true;

	do
	{
		cout << "Enter your username:";
		cin >> username;
		cout << "Enter your password:";
		ch = _getch();
		int i = 0;
		verified = true;

		while (ch != '\r')
		{
			cout << "*";
			if (ch != correct[i++])
				verified = false;
			ch = _getch();
		}

		if (!verified) {
			cout << "\nWrong password !" << endl;
			trials++;
		}
		else if (verified && username == admin_username)
		{
			cout << "\nLogin successfully" << endl;
			admin_page();
		}
		else
			cout << "\nWrong Username" << endl;
		trials++;
	} while (!verified && trials <= 3 && username == admin_username || !verified && trials <= 3 || username != admin_username && trials <= 3);

}



void Admin::admin_page() {
	system("cls");
	int choice1, choice2;
	char Cid[25];
	cout << "                       \n \t\t      \t\t WELCOME ADMIN\n\n\n";
	cout << "                                   \t    MENU\n\n\n";

	cout << "1.ADD DATA" << endl;
	cout << "2.UPDATE DATA" << endl;
	cout << "3.DELETE DATA" << endl;
	cout << "4.Show Garage Appointments" << endl;
	cout << "5.LOGOUT" << endl;
	cout << "\nEnter your choice :";
	cin >> choice1;

	switch (choice1) {
	case 1:
		cout << "\t\t1.ADD CARS" << endl;
		cout << "\t\t2.ADD SHOWROOMS" << endl;
		cout << "\t\t3.ADD SERVICES" << endl;
		cout << "\t\t4.ADD GARAGES" << endl;
		cout << "\t\t5.ADD GARAGES" << endl;
		cout << "\t\t\nEnter your choice :";
		cin >> choice1;
		switch (choice1) {
		case 1:
			c.addCars();
			system("cls");
			cout << "press 1 to return to main menu\n";
			cin >> choice2;
			if (choice2 == 1)
				admin_page();
			break;
		case 2:
			room.addShowrooms();
			system("cls");
			cout << "press 1 to return to main menu\n";
			cin >> choice2;
			if (choice2 == 1)
				admin_page();
			break;
		case 3:
			s.addServices();
			system("cls");
			cout << "press 1 to return to main menu\n";
			cin >> choice2;
			if (choice2 == 1)
				admin_page();
			break;
		case 4:
			g.addGarages();
			system("cls");
			cout << "press 1 to return to main menu\n";
			cin >> choice2;
			if (choice2 == 1)
				admin_page();
			break;
		}
		break;
	case 2:
		cout << "\t\t1.UPDATE CARS" << endl;
		cout << "\t\t2.UPDATE SHOWROOMS" << endl;
		cout << "\t\t3.UPDATE SERVICES" << endl;
		cout << "\t\t4.UPDATE GARAGES" << endl;
		cout << "\t\t\nEnter your choice :";
		cin >> choice1;
		switch (choice1) {
		case 1:
			c.updateCars();
			system("cls");
			cout << "press 1 to return to main menu\n";
			cin >> choice2;
			if (choice2 == 1)
				admin_page();
			break;
		case 2:
			room.updateShowrooms();
			system("cls");
			cout << "press 1 to return to main menu\n";
			cin >> choice2;
			if (choice2 == 1)
				admin_page();
			break;
		case 3:
			s.updateServices();
			system("cls");
			cout << "press 1 to return to main menu\n";
			cin >> choice2;
			if (choice2 == 1)
				admin_page();
			break;
		case 4:
			g.updateGarages();
			system("cls");
			cout << "press 1 to return to main menu\n";
			cin >> choice2;
			if (choice2 == 1)
				admin_page();
			break;
		}
		break;
	case 3:
		cout << "\t\t1.DELETE CARS" << endl;
		cout << "\t\t2.DELETE SHOWROOMS" << endl;
		cout << "\t\t3.DELETE SERVICES" << endl;
		cout << "\t\t4.DELETE GARAGES" << endl;
		cout << "\t\t\nEnter your choice :";
		cin >> choice1;
		switch (choice1) {
		case 1:
			cout << "Enter id you want to delete" << endl;
			cin >> Cid;
			c.deleteCars(Cid);
			system("cls");
			cout << "press 1 to return to main menu\n";
			cin >> choice2;
			if (choice2 == 1)
				admin_page();
			break;
		case 2:
			room.deleteShowrooms();
			system("cls");
			cout << "press 1 to return to main menu\n";
			cin >> choice2;
			if (choice2 == 1)
				admin_page();
			break;
		case 3:
			s.deleteServices();
			system("cls");
			cout << "press 1 to return to main menu\n";
			cin >> choice2;
			if (choice2 == 1)
				admin_page();
			break;
		case 4:
			g.deleteGarages();
			system("cls");
			cout << "press 1 to return to main menu\n";
			cin >> choice2;
			if (choice2 == 1)
				admin_page();
			break;
		}
		break;
	case 4:
		g.show_appointments();
		break;

	default:
		exit(0);
	}


}