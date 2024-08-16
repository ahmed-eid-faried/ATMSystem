#pragma once

#include "libs.h"
#include "total_balances.h"
#include "deposit.h"
#include "QuickWithdraw.h"
using namespace std;
void LoginScreen();
void ShowMainMenue();
void BackToMainMenue();
enum enMainMenueOptions {
	eQuickWithdraw = 1,
	eNormalWithdraw = 2,
	eDeposit = 3,
	eCheckBalance = 4,
	eExiting = 5,
};
int ReadNumberInRange(int From, int To, string Message) {
	int NUM;
	do {
		cout << Message << " FROM " << to_string(From) << " TO " << to_string(To) << ": ";
		cin >> NUM;
	} while (NUM < From || NUM > To);
	return NUM;
}
void Routing(enMainMenueOptions Option) {
	switch (Option)
	{
	case enMainMenueOptions::eQuickWithdraw:
		system("cls");
		QuickWithdraw();
		BackToMainMenue();
	case enMainMenueOptions::eNormalWithdraw:
		system("cls");
		Withdraw();
		BackToMainMenue();
	case enMainMenueOptions::eDeposit:
		system("cls");
		Deposit();
		BackToMainMenue();
	case enMainMenueOptions::eCheckBalance:
		system("cls");
		TotalBalances();
		BackToMainMenue();
	case enMainMenueOptions::eExiting:
		system("cls");
		LoginScreen();
		//Exiting();
	default:
		break;
	}
}
void ShowMainMenue() {
	cout << "====================================================" << endl;
	cout << "\t\tMain Menue Screen\n";
	cout << "====================================================" << endl;
	cout << "\t   [1] Quick Withdraw." << endl;
	cout << "\t   [2] Normal Withdraw." << endl;
	cout << "\t   [3] Deposit." << endl;
	cout << "\t   [4] Check Balance." << endl;
	cout << "\t   [5] Logout." << endl;
	cout << "====================================================" << endl;
	enMainMenueOptions Option = (enMainMenueOptions)ReadNumberInRange(1, 8, "Choose what do you want to do? [1 to 8]? ");
	Routing(Option);
}