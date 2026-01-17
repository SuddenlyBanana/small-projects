#include <iostream>
#include <fstream>
#include <string>
#define password "test123"
#define cancel(x) x == ""
using namespace std;

fstream entry("C:\\Users\\user\\Desktop\\PROJEKTY\\CPP\\journal\\journal\\entries.txt", fstream::app);
fstream editing("C:\\Users\\user\\Desktop\\PROJEKTY\\CPP\\journal\\journal\\entries.txt");
fstream key("C:\\Users\\user\\Desktop\\PROJEKTY\\CPP\\journal\\journal\\entry_key.txt", fstream::app);
<<<<<<< HEAD
string login()
=======
fstream key_read("C:\\Users\\user\\Desktop\\PROJEKTY\\CPP\\journal\\journal\\entry_key.txt");
string login() 
>>>>>>> 40107b0f24d896f0b814b390fcd354a280ec9090
{
	system("CLS");
	string enter = "";
	cout << "                                   " << endl;
	cout << "*____________ LOG  IN ____________*" << endl;
	cout << "                                   " << endl;
	cout << "       PASSWORD: ";
	cin >> enter;
	return enter;
}
int menu()
{
	system("CLS");
	int user_choice = 0;
	cout << "                                   " << endl;
	cout << "*____________ JOURNAL ____________*" << endl;
	cout << "|                                 |" << endl;
	cout << "|          [1]NEW ENTRY           |" << endl;
	cout << "|          [2]READ ENTRY          |" << endl;
	cin >> user_choice;
	return user_choice;
}
<<<<<<< HEAD
void new_entry()
=======
string entry_part(int decide) 
{
	system("CLS");
	string note;
	cout << "to cancel, enter" << endl;
	if(decide == 2)
		cout << "begin your entry:" << endl;
	else
		cout << "Create a title for the new entry" << endl;
	getline(cin, note);
	return note;
}
string read(int part, string look) 
>>>>>>> 40107b0f24d896f0b814b390fcd354a280ec9090
{
	system("CLS");
	cin.ignore();
<<<<<<< HEAD
	getline(cin, write);
	if (write == "X" || write == "x")
=======
	string lines = "";
	if (part == 1)
>>>>>>> 40107b0f24d896f0b814b390fcd354a280ec9090
	{
		cout << "Your previous entries:" << endl;
		while (getline(key_read, lines))
			cout << lines << endl;
	}
<<<<<<< HEAD
	else
	{
		key << write << endl;
		entry << write << endl;
	}
	system("CLS");
	string note;
	cout << "to cancel enter X" << endl;
	cout << "begin your entry:" << endl;
	getline(cin, note);
	if (note == "X" || note == "x")
	{
		menu();
	}
	else
	{
		entry << note << endl;
	}
	entry << " " << endl;
=======
	
	else 
	{
		string exit = "";
		int parts = 0;
		while (getline(editing, lines))
		{
			if (lines == look)
			{
				cout << "to return, enter" << endl;
				cout << lines << endl;
				parts++;
			}
			else if (parts == 1)
			{
				cout << lines << endl;
				cin >> exit;
			}
		}
	}
	return "";
>>>>>>> 40107b0f24d896f0b814b390fcd354a280ec9090
}
void helper() 
{
	int choice = menu();
	system("CLS");
	if (choice == 1)
	{
		cin.ignore();
		string title = entry_part(1);
		string note = entry_part(2);
		if (cancel(title))
		{
			helper();
		}
		else if (cancel(note))
		{
			helper();
		}
		if (note != "" || title != "")
		{
			entry << title << endl;
			key << title << endl;
			entry << note << endl;
		}
		note.clear();
		title.clear();
	}
	else if (choice == 2) 
	{
		string user_choice;
		read(1, user_choice);
		cout << "enter entry name to read" << endl;
		cin >> user_choice;
		string exit = read(2, user_choice);
		if (cancel(exit))
			helper();
	}
}

int main()
{
	string passcode;
	while (passcode != password)
	{
		passcode = login();
	}
	while (true)
	{
		helper();
	}
}