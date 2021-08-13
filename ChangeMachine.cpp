/*
Author: Adrian Unkeles
Date: 7/30/2021
Project: Code assessment for CEL
*/


#include "pch.h"
#include <iostream>
#include <cmath>
#include <string>

using namespace std;


// definitions for the class member functions declared in changeMachine.h
ChangeMachine::denominations ChangeMachine::calculateCount()
{
	float testVal = inputAmount;
	int counter = 0;
	for (; testVal != int(testVal); ++counter)
	{
		testVal *= 10;
	}
	
	// Invalid input conditions
	if (counter > 2)							// error condition where inputAmount has too many significant digits following the decimal
	{
		std::cout << "Too many decimal places, smallest denomination is pennies!" << endl;
		memset(&count, 0, sizeof(denominations));
		shouldPrint = false;
		return count;
	}
	else if (inputAmount < 0)					// condition where inputAmount is not valid (negative)
	{
		std::cout << "Invalid (negative) dollar amount" << endl;
		memset(&count, 0, sizeof(denominations));
		shouldPrint = false;
		return count;
	}
	
	
	inputAmount *= 100;

	// calculate the amount of each denomination starting with the largest
	// so as to require the fewest amount of bills
	count.hundred_dollar = floor(inputAmount / 10000);
	inputAmount -= count.hundred_dollar * 10000;
	count.fifty_dollar = floor(inputAmount / 5000);
	inputAmount -= count.fifty_dollar * 5000;
	count.twenty_dollar = floor(inputAmount / 2000);
	inputAmount -= count.twenty_dollar * 2000;
	count.ten_dollar = floor(inputAmount / 1000);
	inputAmount -= count.ten_dollar * 1000;
	count.five_dollar = floor(inputAmount / 500);
	inputAmount -= count.five_dollar * 500;
	count.two_dollar = floor(inputAmount / 200);
	inputAmount -= count.two_dollar * 200;
	count.one_dollar = floor(inputAmount / 100);
	inputAmount -= count.one_dollar * 100;

	// same idea for coins
	count.fiftypiece = floor(inputAmount / 50);
	inputAmount -= count.fiftypiece*50;
	count.quarter = floor(inputAmount / 25);
	inputAmount -= count.quarter*25;
	count.dime = floor(inputAmount / 10);
	inputAmount -= count.dime*10;
	count.nickel = floor(inputAmount / 5);
	inputAmount -= count.nickel*5;
	count.penny = floor(inputAmount);

	shouldPrint = true;
	return count;
}

// readout of the bills and coins the user should receive
void ChangeMachine::printDenominations()
{
	std::cout << "Your change is:" << endl;
	
	// readout of the denominations, with an eye for grammatical syntax 
	std::cout << count.hundred_dollar << " hundred dollar " << ((count.hundred_dollar > 1 || count.hundred_dollar == 0) ? "bills" : "bill") << endl;
	std::cout << count.fifty_dollar << " fifty dollar " << ((count.fifty_dollar > 1 || count.fifty_dollar == 0) ? "bills" : "bill") << endl;
	std::cout << count.twenty_dollar << " twenty dollar " << ((count.twenty_dollar > 1 || count.twenty_dollar == 0) ? "bills" : "bill") << endl;
	std::cout << count.ten_dollar << " ten dollar " << ((count.ten_dollar > 1 || count.ten_dollar == 0) ? "bills" : "bill") << endl;
	std::cout << count.five_dollar << " five dollar " << ((count.five_dollar > 1 || count.five_dollar == 0) ? "bills" : "bill") << endl;
	std::cout << count.two_dollar << " two dollar " << ((count.two_dollar > 1 || count.two_dollar == 0) ? "bills" : "bill") << endl;
	std::cout << count.one_dollar << " one dollar " << ((count.one_dollar > 1 || count.one_dollar == 0) ? "bills" : "bill") << endl;

	// and readout of the coins, again checking for grammar
	std::cout << count.fiftypiece << " half dollar" << ((count.fiftypiece == 0) ? " coins" : " coin") << endl;
	std::cout << count.quarter << ((count.quarter == 0) ? " quarters" : " quarter") << endl;
	std::cout << count.dime << ((count.dime > 1 || count.dime == 0) ? " dimes" : " dime") << endl;
	std::cout << count.nickel << ((count.nickel == 0) ? " nickels" : " nickel") << endl;
	std::cout << count.penny << ((count.penny > 1 || count.penny == 0) ? " pennies" : " penny") << endl;

	return;
}

// reset the register after calculating the bills returned to the user
void ChangeMachine::resetRegister()
{
	memset(&count, 0, sizeof(denominations));
	return;
}


int main()
{
	std::cout << "Hello! Please enjoy using this Change-calculating Machine!" << endl;
	std::cout << "Please input a dollar and cents amount" << endl;
	std::cout << "Enter 0 to exit" << endl;
	
	float dollarAmount;

	std::cin >> dollarAmount;

	// doing a input format validity check here to take advantage of cin status flags
	while (cin.fail())
	{
		// clear the error and ignore other characters up until a newline (expecting less than 100 characters typed in...)
		cin.clear();
		cin.ignore(100, 10);
		std::cout << "Not a valid dollar amount, please type in #.## format" << endl;
		std::cout << "Please input a dollar and cents amount" << endl;
		std::cout << "Enter 0 to exit" << endl;
		std::cin >> dollarAmount;
	}

	// keep calculating change until exit condition met
	while (dollarAmount != 0)
	{
		ChangeMachine changeDrawer(dollarAmount);

		changeDrawer.calculateCount();
		
		// do not print out the denominations if the value was negative or had too many significant digits after the decimal place
		if(changeDrawer.shouldPrint)
			changeDrawer.printDenominations();

		changeDrawer.resetRegister();

		std::cout << "Please input a dollar and cents amount" << endl;
		std::cout << "Enter 0 to exit" << endl;
		std::cin >> dollarAmount;

		// again check for invalid input format
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(100, 10);
			std::cout << "Not a valid dollar amount, please type in #.## format" << endl;
			std::cout << "Please input a dollar and cents amount" << endl;
			std::cout << "Enter 0 to exit" << endl;
			std::cin >> dollarAmount;
		}

	}

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
