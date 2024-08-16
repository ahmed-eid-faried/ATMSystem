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
int ReadWithdrawValue(string Message, int multiply);
double ReadDoubleNumber(string Message);
bool DepositClientByAccountNumber(string AccountNumber, vector<sClient>& vClients, double DepositValue);
bool WithdrawClientByAccountNumber(string AccountNumber, vector<sClient>& vClients, double WithdrawValue) {

	return DepositClientByAccountNumber(AccountNumber, vClients, -1 * WithdrawValue);
}
void WithdrawFun() {
	vector <sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);
	int WithdrawValue = ReadWithdrawValue("Enter an amount of multiple of ", 10);
	WithdrawClientByAccountNumber(CurrentClient.AccountNumber, vClients, WithdrawValue);
}
void Withdraw() {
	cout << "====================================================" << endl;
	cout << "\t\tWithdraw Client\n";
	cout << "====================================================" << endl;
	WithdrawFun();
}