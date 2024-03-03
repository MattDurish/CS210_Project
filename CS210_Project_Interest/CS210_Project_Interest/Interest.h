#ifndef INTEREST_H
#define INTEREST_H

class UserInterest {
	public:
		//default constructor
		UserInterest();

		//set functions
		void setOpenAmt(float t_openingAmt);
		void setMonthDep(float t_monthDep);
		void setYearlyInterest(int t_yearlyInterest);
		void setNumYears(int t_numYears);

		//get functions
		float getOpenAmt();
		float getMonthDep();
		int getYearlyInterest();
		int getNumYears();

		//experimental calculation segment to reduce code in main and other function
		/*
		float calcInterestNoMonthly();
		float calcInterestMonthly();
		float calcClosingBalanceNoMonthly();
		float calcClosingBalanceMonthly(); */

	private:
		float openingAmt;
		float monthDep;
		int yearlyInterest;
		int numYears;
};

#endif