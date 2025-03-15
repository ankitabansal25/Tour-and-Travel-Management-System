#include<iostream>
#include<string.h>
#include<fstream>
#include<stdlib.h>
using namespace std;

void menu();

//Name of Modules
//1.Login/Registration Module
//2.Destination Module
//3.Booking Module
//4.Receipt Module
//5.EXIT Module

class tour
{
public:
    string name;
    string gen;
    int age;
    long long mob_num;

    tour *next, *head;
};

// head pointer with null
tour *head = NULL;

// tour class pointer
tour *ptr;

// global variables for AMOUNT and number of persons
int amt = 0, k;
int amnt;

// global variables for number of passengers
char str1[100];
char str2[100];
char place[100];
string date;

tour *newptr = head;
// tour *ptr;

void add_pass(string n, string g, int a, long long mb)
{
    newptr = new tour();
    newptr->name = n;
    newptr->gen = g;
    newptr->age = a;
    newptr->mob_num = mb;
    newptr->next = NULL;

    if (head == NULL)
    {
        head = newptr;
    }
    else
    {
        ptr = head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = newptr;
    }
}

//---------------------------------------------------------------------------------LOGIN AND REGISTRATION-----------------------------------------------------------------------------------------------------

class Login
{
public:
	void login()
	{
		int count;
		string userId, password, id, pass;
		cout << "\t\t\t Please enter the username and password: " << endl;
		cout << "\t\t\t USERNAME: ";
		cin.ignore();
		getline(cin, userId);
		
		cout << "\t\t\t PASSWORD: ";
		cin >> password;
	
		ifstream input("records.txt");
	
		while(input >> id >> pass)
		{
			if(id==userId && pass==password)
			{
				count = 1;
			}
		}
		input.close();
		
		if(count==1)
		{
			cout << "\t\t\tWelcome, " << userId << " to Travel and Tourism Company!!" << endl;
		}
		else
		{
			cout << endl;
			cout << "\t\t\t SORRY!! LOGIN ERROR, Please check your username and password" << endl;
		}
	}
	
	void registration()
	{
		string ruserId, rpassword, rid, rpass;
		cout << "\t\t\t Enter your username : ";
//		cin >> ruserId;
		cin.ignore();
		getline(cin, ruserId);
		cout << "\t\t\t Enter the password: ";
		cin >> rpassword;
	
		ofstream f1("records.txt", ios::app);
		f1<<ruserId<<' '<<rpassword<<endl;
		cout << "\n\t\t\t Registration is Succesffull! \n";
		menu();
	}

	void forgot()
	{
		int option;
		cout << "\t\t\t You forgot the password? No worries \n";
		cout << "Press 1 to search your id by username "<< endl;
		cout << "Press 2 to go back to main menu "<<endl;
		cout << "\t\t\t Enter your choice: ";
		cin >> option;
		switch(option)
		{
			case 1:
			{
				int count = 0;
				string suserId, sId, spass;
				cout <<"\t\t\t Enter the username which you remembered: ";
				cin >> suserId;
			
				ifstream f2("records.txt");
				while(f2>>sId>>spass)
				{
					if(sId == suserId)
					{
						count = 1;
					}
				}
				f2.close();
				if(count == 1)
				{
					cout << "\n\n Your account is found! \n";
					cout << "\n\n Your Password is: " << spass;
//					menu();
				}
				else{
					cout <<"\n\t Sorry! Your account is not found!\n";
//					menu();
				}
				break;
			}
		
			case 2:
				menu();
			
			default:
				cout << "\t\t\t Wrong choice! Please try again" << endl;
				forgot();
		}
	}	
};

//-------------------------------------------------------------------------------DESTIANTION PACKAGES--------------------------------------------------------------------------------------------

class destination
{
	public:
//		int amnt;
		int a, modeChoice;
		void packages()
		{
			cout << "\t\t\t\t\t\t******INDIA TOUR PACKAGES******\n\n" << endl;
    		cout << "\t\t\t\t\t\t 1. Ladakh Tour [5 days 6 nights] (12000/person) \n" << endl;
    		cout << "\t\t\t\t\t\t 2. Manali Tour [3 days 4 nights] (8000/person) \n" << endl;
    		cout << "\t\t\t\t\t\t 3. Shimla Tour [3 days 4 nights] (7000/person) \n" << endl;
    		cout << "\t\t\t\t\t\t 4. Darjeeling Tour [3 days 4 nights] (8000/person) \n" << endl;
    		cout << "\t\t\t\t\t\t 5. Goa Tour [4 days 5 nights] (10000/person) \n" << endl;
    		
    		cout << "\t\t\t\t\t Enter choice: ";
    		cin >> a;

    		switch (a)
    		{
    		case 1:
        		amt = 12000;
        		strcpy(str1, "Ladakh Tour [5 days 6 nights]");
        		break;
    		case 2:
        		amt = 8000;
        		strcpy(str1, "Manali Tour [3 days 4 nights]");
        		break;
    		case 3:
        		amt = 7000;
        		strcpy(str1, "Shimla Tour [3 days 4 nights]");
        		break;
    		case 4:
        		amt = 8000;
        		strcpy(str1, "Darjeeling Tour [3 days 4 nights]");
        		break;
    		case 5:
        		amt = 10000;
        		strcpy(str1, "Goa Tour [4 days 5 nights]");
        		break;
    		default:
        		cout << "\t\t\t\t\t\t Enter correct choice: ";
        		break;
    		}
		}
		
		void modeOfTravel()
		{
			cout << "\t\t\t\t\tSelect MODE OF TRAVEL" << endl;
    		cout << "\t\t\t\t\t 1. BY FLIGHT (4000)" << endl;
    		cout << "\t\t\t\t\t 2. BY TRAIN (2000)" << endl;
    		cout << "\t\t\t\t\t 3. BY ROAD (1500)" << endl;

    		cout << "\t\t\t\t\t Enter choice for mode of travel: ";
    		cin >> modeChoice;
	
    		if (modeChoice == 1)
    		{
        		amnt = 4000;
        		strcpy(str2, "BY FLIGHT");
    		}
    		else if (modeChoice == 2)
    		{
        		amnt = 2000;
        		strcpy(str2, "BY TRAIN");
    		}
    		else if (modeChoice == 3)
    		{
        		amnt = 1500;
        		strcpy(str2, "BY ROAD");
    		}
    		else
    		{
        		cout << "\t\t\t\t\tEnter correct choice: ";
    		}
		}
};

//------------------------------------------------------------------------------------BOOKING(PASSENGERS INFORMATION, DATE OF DEPARTURE AND ETC.)----------------------------------------------------

class Booking
{
	public:
		string nme, gn;
    	int a;
    	long long mb;

    	void details()
    	{
    		cout << "\t\t\t\t\tEnter number of passengers: ";
    		cin >> k;
    		
	    	cout << "\t\t\t\t\tEnter Date (DD/MM/YY): ";
	    	cin.ignore();
    		getline(cin, date);

    		for (int i = 1; i <= k; i++)
    		{
				cout << "\t\t\t\t\t\tEnter Passenger Details \n" << endl;
        		cout << "\t\t\t\t\t\t Enter the " << i << " passenger name: ";
        		cin.ignore();
        		getline(cin, nme);
	
	    	    cout << "\t\t\t\t\t\t Enter Gender of " << i << " passenger: ";
        		getline(cin, gn);

        		cout << "\t\t\t\t\t\t Enter age of " << i << " passenger: ";
        		cin >> a;

        		cout << "\t\t\t\t\t\t Enter mobile number of " << i << " passenger: ";
        		cin >> mb;

        		add_pass(nme, gn, a, mb);
   	 		}
		}
    	
};

//------------------------------------------------------------------------------------------------RECEIPT PRINTING----------------------------------------------------------------------------------

class Receipt{
	public:
		void printReceipt()
		{
			tour *ptr1 = head;

		    cout << endl;
		    cout << "\t\t\t\t\t****BOOKING CONFIRMATION****" << endl << endl;
		    cout << "\t\t\t\t\t****Passengers Information****" << endl << endl;
		
		    for (int i = 1; i <= k; i++)
		    {
		        cout << endl;
		        cout << "\t\t\t\t\t Passenger " << i << " information" << endl << endl;
		        cout << "\t\t\t\t\t Passenger Name: " << ptr1->name << endl;
		        cout << "\t\t\t\t\t Passenger Gender: " << ptr1->gen << endl;
		        cout << "\t\t\t\t\t Passenger Age: " << ptr1->age << endl;
		        cout << "\t\t\t\t\t Passenger Mobile Number: " << ptr1->mob_num << endl;
		
		        ptr1 = ptr1->next;
		    }
		
		    cout << endl << endl;
		    cout << "\t\t\t\t\t**********************************" << endl;
		    cout << "\t\t\t\t\t Selected Package: " << str1 << endl;
		    cout << "\t\t\t\t\t Departure Date: " << date << endl;
		    cout << "\t\t\t\t\t Mode Of Travel: " << str2 << endl;
		
		    long long x1 = (amt * k);
		    long long x2 = (amnt * k);
		    long long x3 = x1 + x2;
		
		    cout << "\t\t\t\t\t Tourism Amount: " << x1 << endl;
		    cout << "\t\t\t\t\t Travelling Amount: " << x2 << endl;
		    cout << "\t\t\t\t\t Total Amount: " << x3 << endl << endl;
		
		    cout << "\t\t\t\t *****Your booking details will be sent on the Registered Mobile number*****\n" << endl;
		    cout << "\t\t\t\t ****Thank you for planning your trip with us****\n";
		}
};

//---------------------------------------------------------------------------------------------------MENU FUNCTION----------------------------------------------------------------------------

void menu()
{
	cout << "\t\t\t\t\t\t -----------------------------------------" << endl;
	cout << "\t\t\t\t\t\t ----------------Main Menu----------------" << endl;
	cout << "\t\t\t\t\t\t -----------------------------------------" << endl << endl;
	
	cout << "\t\t\t\t\t\t 1. Login/Registration Section" << endl;
	cout << "\t\t\t\t\t\t 2. Designation Module" << endl;
	cout << "\t\t\t\t\t\t 3. Booking Module" << endl;
	cout << "\t\t\t\t\t\t 4. Receipt Module" << endl;
	cout << "\t\t\t\t\t\t 5. Exit" << endl;

	cout << "\t\t\t\t\t\t -----------------------------------------" << endl << endl;
	
	cout << "\t\t\t\t\t\t Enter your choice: ";
	int mainChoice;
	cin >> mainChoice;
	cout << endl;
	
	//creating objects of classes
	Login l;
	destination d;
	Booking b;
	Receipt r;
	
	switch (mainChoice)
	{
		case 1:
			int c;
			cout << "\t\t\t\t\t\t -----------------------------------------\n\n";
			cout << "\t\t\t\t\t\t       Welcome to the Login Page          \n\n";
			cout << "\t\t\t\t\t\t -----------------------------------------\n\n";
			cout << "                                                               \n\n\n";
			cout << "\t\t\t\t| Press 1 to LOGIN                         |" << endl;
			cout << "\t\t\t\t| Press 2 to REGISTER                      |" << endl;
			cout << "\t\t\t\t| Press 3 if you forgot your PASSWORD      |" << endl;
			cout << "\t\t\t\t| Press 4 to Exit                          |" << endl;
			cout << "\n\t\t\t Enter your choice: ";
			cin >> c;
			cout << endl;
		
			switch(c)
			{
				case 1:
					l.login();
					menu();
					break;
				
				case 2:
					l.registration();
					menu();
					break;
				
				case 3:
					l.forgot();
					menu();
					break;
				
				case 4:
					cout << "\t\t\t Thank You! \n\n";
					menu();
					break;
				
				default:
					cout << "\t\t\t Please select from the above options.\n" << endl;
					menu();
			}
			
		case 2:
			cout << "\t\t\t\t\t\t -----------------------------------" << endl;
			cout << "\t\t\t\t\t\t -----------Packages----------------" << endl;
			cout << "\t\t\t\t\t\t -----------------------------------" << endl << endl;
			d.packages();
			d.modeOfTravel();
			menu();
			break;
			
		case 3:
			cout << "\t\t\t\t\t\t -----------------------------------" << endl;
			cout << "\t\t\t\t\t\t -----------Booking details---------" << endl;
			cout << "\t\t\t\t\t\t -----------------------------------" << endl << endl;
			b.details();
			menu();
			break;
			
		case 4:
			system("cls");
			cout << "\t\t\t\t\t\t -----------------------------------" << endl;
			cout << "\t\t\t\t\t\t -----------Receipt Printing---------" << endl;
			cout << "\t\t\t\t\t\t -----------------------------------" << endl << endl;
			r.printReceipt();
			menu();
			break;
			
		case 5:
			exit(0);
			
		default:
			cout << "Enter a option from above given menu only!!" << endl;
	}
}

//-------------------------------------------------------------------------------------MAIN FUNCTION--------------------------------------------------------------------------------------

int main()
{
	int a;
    cout << endl << endl;
    cout << "\t\t\t\t\t****WELCOME****\n";
    cout << "\t\t\t\t\t****TOUR & TRAVELS COMAPNY****\n" << endl;

    int choice;
    do
    {
        cout << "\n\t\t\t\t\t*****PRESS 1 for Main Menu*****" << endl;
        cout << "\t\t\t\t\t\t";
        cin >> a;

        if (a == 1)
        {
            menu();
        }
        else
        {
            cout << "\t\t\t\t\t Enter Correct choice: ";
    	}	
    } while (choice == 0);

    return 0;
}
