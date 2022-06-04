#include"Classes.h"
fstream newfile;


int counter = 2;
service_process::service_process(int cust_id,string service,float price,string Date) {

	process_id =counter++;
	customer_id = cust_id;
	choosen_service = service;
	money = price;
	this->Date = Date;

}

service_process::service_process() {

	process_id = 0;
	customer_id = 0;
	choosen_service = "";
	money = 0;
	Date = 00-00;

}

void service_process::history(service_process s) {

	//fstream temp;

	newfile.open("history.txt", ios::app);
	//temp.open("services", ios::out);

	newfile << "customer ID : " << s.customer_id << endl;
	newfile << "process ID : " << s.process_id << endl;
	newfile << "Date of service: " << s.Date << endl;
	newfile << "Service :" << s.choosen_service << endl;
	newfile << "Price :" << s.money << endl;
	newfile << endl;
	newfile.close();
}

void service_process::history_search(int key)
{
	system("cls");
	Customer coco;
	char C_IdInfo[25], P_IdInfo[25], date_info[25], service_info[25], price_info[25];
	char temp[25];
	int ans;
	newfile.open("history.txt", ios::in);
	//temp.open("temp", ios::in);


	if (newfile.is_open()) {

		while (!newfile.eof()) {

			newfile.getline(temp, 25, ':');
			newfile.getline(C_IdInfo, 25);
			newfile.getline(temp, 25, ':');
			newfile.getline(P_IdInfo, 25);
			newfile.getline(temp, 25, ':');
			newfile.getline(date_info, 25);
			newfile.getline(temp, 25, ':');
			newfile.getline(service_info, 25);
			newfile.getline(temp, 25, ':');
			newfile.getline(price_info, 25);
			int counter;
			if (C_IdInfo[0] != 0) {
				counter = 0;
				/*for (int i = 0; i < 25; i++) {
					if (key[i] == C_IdInfo[i]) {
						counter+=i;
					}
				}*/
				
				int i = atoi(C_IdInfo);
				if (key == i)
				{
					cout << "process ID : " << P_IdInfo << endl;
					cout << "Date of service : " << date_info << endl;
					cout << "Service : " << service_info << endl;
					cout << "Price : " << price_info << endl;
					cout << endl;
				}
				else {

				}

			}
		}
		newfile.close();

	}
	cout << "\nDo you want other Services? \n";
	cout << "1.Yes" << endl;
	cout << "2.LogOut" << endl;
	cout << "\nEnter your choice :";
	cin >> ans;
	if (ans == 1)
		coco.customer_page();
	else if (ans == 2)
		system("cls");
	coco.main_login();

}