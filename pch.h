/*
Author: Adrian Unkeles
Date: 7/30/2021
Header file for the ChangeMachine project
*/

#ifndef PCH_H
#define PCH_H

// structured the ChangeMachine as a class with member variables and functions
// member variables are private so as to only be visible within the class
// member functions declared before main()

class ChangeMachine
{
	// this struct and member functions are public
	public:
		bool shouldPrint;

		struct denominations
		{
			// common coin currency
			int penny;
			int nickel;
			int dime;
			int quarter;
			int fiftypiece;
			// common paper currency
			int one_dollar;
			int two_dollar;
			int five_dollar;
			int ten_dollar;
			int twenty_dollar;
			int fifty_dollar;
			int hundred_dollar;
		};

		denominations calculateCount();
		void printDenominations();
		void resetRegister();

		ChangeMachine(float inputValue)
		{
			inputAmount = inputValue;
		}

	// member variables to the class are private
	private:
		float inputAmount;
		denominations count;
		

};

#endif //PCH_H
