#include <iostream>
using namespace std;

#include "Interest.h"

//default constructor
UserInterest::UserInterest() {
	openingAmt = 0.00;
	monthDep = 0.00;
	yearlyInterest = 0;
	numYears = 0;
}

//set definitions
void UserInterest::setOpenAmt(float t_openingAmt) {
	openingAmt = t_openingAmt;
}
void UserInterest::setMonthDep(float t_monthDep) {
	monthDep = t_monthDep;
}
void UserInterest::setYearlyInterest(int t_yearlyInterest) {
	yearlyInterest = t_yearlyInterest;
}
void UserInterest::setNumYears(int t_numYears) {
	numYears = t_numYears;
}

//get definitions
float UserInterest::getOpenAmt() {
	return openingAmt;
}
float UserInterest::getMonthDep() {
	return monthDep;
}
int UserInterest::getYearlyInterest() {
	return yearlyInterest;
}
int UserInterest::getNumYears() {
	return numYears;
}

//experimental calculation segment to reduce code in main and other functions
/*amount of interest earned for the month
float UserInterest::calcInterestNoMonthly() {
	return openingAmt * ((yearlyInterest / 100) / 12);
}

//amount of interest earned for the month, including monthly deposit
float UserInterest::calcInterestMonthly() {
	return (openingAmt + monthDep) * ((yearlyInterest / 100) / 12);
}

//closing balance total for next month
float UserInterest::calcClosingBalanceNoMonthly() {
	return (openingAmt) + calcInterestNoMonthly();
}

//closing balance total for next month, including monthly deposit
float UserInterest::calcClosingBalanceMonthly() {
	return (openingAmt + monthDep) + calcInterestMonthly();
} */