#pragma once
#include "libs.h"
#include "total_balances.h"
#include "deposit.h"
using namespace std;

int ReadNumberInRange(int From, int To, string Message = "ENTER NUMBER");
void QuickWithdrawFun(int WithdrawValue) {
	vector <sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);
	WithdrawClientByAccountNumber(CurrentClient.AccountNumber, vClients, WithdrawValue);
}

void QuickWithdraw() {
	cout << "====================================================" << endl;
	cout << "\t\tMain Menue Screen\n";
	cout << "====================================================" << endl;
	for (int i = 1; i <= 10; i++)
	{
		printf("\t[%1d] %1d", i, i * 100);
		if (i % 3 == 0)	cout << endl;
	}
	cout << "\n====================================================" << endl;
	int WithdrawValue = 100 * ReadNumberInRange(1, 10, "Choose what do you want to do? [1 to 10]? ");
	QuickWithdrawFun(WithdrawValue);
}