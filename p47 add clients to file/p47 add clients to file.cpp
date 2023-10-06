#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;


struct stAccount
{
	string Number;
	string pinCode;
	string name;
	string phone;
	double balance;
};

stAccount readClient()
{
	stAccount client;

	
	cout << "\nEnter Account Number? ";
	getline(cin>>ws, client.Number);

	cout << "Enter Name? ";
	getline(cin, client.name);

	cout << "Enter PinCode? ";
	getline(cin, client.pinCode);

	cout << "Enter Phone ";
	getline(cin, client.phone);

	cout << "Enter Account balance ";
	cin >> client.balance;

	return client;
}

string recordToLine(stAccount client, string delim)
{
	return client.Number + delim + client.pinCode
		+ delim + client.name + delim + client.phone
		+ delim + to_string(client.balance)+"\n";
}

void saveLineRecordToFile()
{
	stAccount client = readClient();
	string delim="#//#";
	fstream clientFile;

	clientFile.open("clientInfo.txt", ios::out | ios::app);

	if (clientFile.is_open())
	{
		clientFile << recordToLine(client, delim);
		clientFile.close();
	}

}
void addingNewClient()
{
	char addNew = 'y';

	
	while (addNew=='Y' || addNew == 'y')
	{
		system("cls");
		cout << "Adding new Client:\n";
		saveLineRecordToFile();
		cout << "\n\nClient added sucessfully, do you want to add more clients? ";
		cin >> addNew;
	}
}

int main()
{

	addingNewClient();

	return 0;

}