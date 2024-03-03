/*
*	Purpose:
*
*	[Date]	: February 18, 2024
*	[Author]: Matthew Durish
*/

#include <iostream>
#include <iomanip>
#include <stdexcept>
using namespace std;

#include "Interest.h"

void DisplayPrompt(UserInterest& t_userData) {
	//temporary variables for cin inputs, and to advance to reports
	float tempAmt;
	float tempDep;
	int tempInterest;
	int tempYears;
	string continuePrompt;

	//data input format, in order of what should be entered
	cout << "**********************************" << endl;
	cout << "********** Data Input ************" << endl;
	cout << "Initial Investment Amount: $";
	cin >> tempAmt;
	cout << "Monthly Deposit: $";
	cin >> tempDep;
	cout << "Annual Interest: %";
	cin >> tempInterest;
	cout << "Number of Years: ";
	cin >> tempYears;
	cout << "Press any key and hit enter to continue . . . ";
	cin >> continuePrompt;
	cout << endl; //for user spacing

	//catch errors if any negative values are entered
	if (tempAmt < 0) {
		throw runtime_error("Invalid Initial Investment");
	}
	if (tempDep < 0) {
		throw runtime_error("Invalid Monthly Deposit");
	}
	if (tempInterest < 0) {
		throw runtime_error("Invalid Annual Interest");
	}
	if (tempYears < 1) {
		throw runtime_error("Invalid Number of Years");
	}

	t_userData.setOpenAmt(tempAmt);
	t_userData.setMonthDep(tempDep);
	t_userData.setYearlyInterest(tempInterest);
	t_userData.setNumYears(tempYears);
}

void DisplayReportNoMonthlyDep(UserInterest& t_userData) {
	//opening report format
	cout << "==================================================================" << endl;
	cout << "|    Balance and Interest Without Additional Monthly Deposits    |" << endl;
	cout << "==================================================================" << endl;
	cout << "|   Year         Year End Balance     Year End Earned Interst    |" << endl;
	cout << "------------------------------------------------------------------" << endl;

	//initialize variales for calculations
	float tempTotalBalance = 0.00;
	float tempSumInterest = 0.00;
	float interestRate = t_userData.getYearlyInterest() / 100.00 / 12.00;
	float tempOpeningAmt = t_userData.getOpenAmt(); //temp variable to reset the opening amount for monthly deposit calculations

	//for every year
	for (int i = 1; i < t_userData.getNumYears() + 1; ++i) {
		cout << "      " << i << "                  $";

		//calculate the interest for all 12 months of the year
		for (int j = 1; j < 13; ++j) {
			tempSumInterest += t_userData.getOpenAmt() * interestRate; //calculate the interest earned for the year
			tempTotalBalance = t_userData.getOpenAmt() + (t_userData.getOpenAmt() * interestRate); //calculate the balance for the next month
			t_userData.setOpenAmt(tempTotalBalance); //set next month balance to be the opening amount
		}

		//to two decimal places, display the year-end balance
		cout << fixed << setprecision(2) << t_userData.getOpenAmt() << "                     $";
		//and display the interest accumulated for the year
		cout << fixed << setprecision(2) << tempSumInterest << "    " << endl;

		//at the end of each year, reset interest buildup
		tempSumInterest = 0.00;
	}

	//format to end report
	cout << "------------------------------------------------------------------" << endl;

	//in order to properly calculate with monthly deposit, opening amount needs to be original quantity entered by user
	t_userData.setOpenAmt(tempOpeningAmt);
}

void DisplayReportWithMonthlyDep(UserInterest& t_userData) {
	//opening report format
	cout << "==================================================================" << endl;
	cout << "|       Balance and Interest With Additional Monthly Deposits    |" << endl;
	cout << "==================================================================" << endl;
	cout << "|   Year         Year End Balance     Year End Earned Interst    |" << endl;
	cout << "------------------------------------------------------------------" << endl;

	//initialize variales for calculations
	float tempTotalBalance = 0.00;
	float tempSumInterest = 0.00;
	float interestRate = t_userData.getYearlyInterest() / 100.00 / 12.00;

	//for every year
	for (int i = 1; i < t_userData.getNumYears() + 1; ++i) {
		cout << "      " << i << "                  $";

		//calculate the interest for all 12 months of the year
		for (int j = 1; j < 13; ++j) {
			tempSumInterest += (t_userData.getOpenAmt() + t_userData.getMonthDep()) * interestRate; //calculate the interest earned for the year
			tempTotalBalance = (t_userData.getOpenAmt() + t_userData.getMonthDep()) + ((t_userData.getOpenAmt() + t_userData.getMonthDep()) * interestRate); //calculate the balance for the next month
			t_userData.setOpenAmt(tempTotalBalance); //set next month balance to be the opening amount
		}

		//to two decimal places, display the year-end balance
		cout << fixed << setprecision(2) << t_userData.getOpenAmt() << "                     $";
		//and display the interest accumulated for the year
		cout << fixed << setprecision(2) << tempSumInterest << "    " << endl;

		//at the end of each year, reset interest buildup
		tempSumInterest = 0.00;
	}

	//format to end report
	cout << "------------------------------------------------------------------" << endl;
}

int main() {
	UserInterest userData;
	char continuePrompt = 'a';

	
		while (continuePrompt != 'e') {
			try {
				//display screen function
				DisplayPrompt(userData);

				//report 1 display screen function
				DisplayReportNoMonthlyDep(userData);

				//report 2 display screen function
				DisplayReportWithMonthlyDep(userData);

				//determine if user wishes to try with new data
				cout << "Do you wish to try again with different data?" << endl;
				cout << "(Type 'e' to exit): "; //'e' is the exit requirement
				cin >> continuePrompt;
				cout << endl; //for user spacing
			}
			catch (runtime_error &excpt) {
				cout << excpt.what() << endl;
				cout << "Please try again." << endl << endl;
			}
		}


}