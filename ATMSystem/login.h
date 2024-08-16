#pragma once
#include <iostream>
#include "libs.h"
#include <vector> 
using namespace std;


void ShowMainMenue();

bool FindClientByAccountNumberAndPinCode(vector<string>& vFile, string AccountNumber, string PinCode) {
	for (string& Line : vFile) {
		if (!Line.empty())
		{
			sClient Client = ConvertLinetoRecord(Line, Seperator);
			if ((Client.AccountNumber == AccountNumber) && (Client.PinCode == PinCode)) {
				CurrentClient = Client;
				return true;
			}
		}
	}
	return false; 
}

bool CheckPinCode(string AccountNumber, string PinCode) {
	vector<string> vFile;
	DataFromFileToVector(ClientsFileName, vFile);
	return FindClientByAccountNumberAndPinCode(vFile, AccountNumber, PinCode);
}

void Login() {
	bool IsFinsh = false;
	bool Invalid = false;
	while (!IsFinsh)
	{
		system("cls");
		cout << "========================================================" << endl;
		cout << "                         Login                          " << endl;
		cout << "========================================================" << endl;
		if (Invalid) { cout << "\nClient AccountNumber Or PinCode is Not Correct!" << endl << endl; }
		string AccountNumber = ReadString("Enter your AccountNumber    : ");
		string PinCode = ReadString("Enter your PinCode: ");
		if (CheckPinCode(AccountNumber, PinCode)) {
			IsFinsh = true;
		}
		else {
			Invalid = true;
		}
	};
	system("cls");
	ShowMainMenue();
}
void LoginScreen() {

	Login();
	cout << "========================================================" << endl;
	cout << "========================================================" << endl;
}