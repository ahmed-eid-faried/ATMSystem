#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<iomanip>
#include "deposit.h"
#include "login.h"

using namespace std;
vector <sClient> LoadCleintsDataFromFile(string FileName);
string  ReadClientAccountNumber();
double ReadDoubleNumber(string Message);
bool DepositClientByAccountNumber(string AccountNumber, vector<sClient>& vClients, double DepositValue);
bool WithdrawClientByAccountNumber(string AccountNumber, vector<sClient>& vClients, double WithdrawValue) {
	return DepositClientByAccountNumber(AccountNumber, vClients, -1 * WithdrawValue);
}
void WithdrawFun() {
	vector <sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);
	double WithdrawValue = ReadDoubleNumber("ENTER YOUR Withdraw Value: ");
	WithdrawClientByAccountNumber(CurrentClient.AccountNumber, vClients, WithdrawValue);
}
void Withdraw() {
	cout << "====================================================" << endl;
	cout << "\t\tWithdraw Client\n";
	cout << "====================================================" << endl;
	WithdrawFun();
}