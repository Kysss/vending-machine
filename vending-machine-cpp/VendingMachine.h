#ifndef VENDINGMACHINE_H
#define VENDINGMACHINE_H

using namespace std;
#include <string>
#include <vector>
#include <iostream>

class VendingMachine{
	public:
		int* q;
		int* d;
		int* n;
		int* v;
		bool* c;
		//VendingMachine(); //remove if not define any
		void initializeVM(int* q, int* d, int* n, int* v, bool* c);
		void printCurrentState();
		void stateTransition(vector<string>* inputs);
		int getNumOfCoffee(int value);
		vector<string> produceOutput();
		void produceAndPrintOutput();
		vector<string> produceChange();
		void subtractChange();
};





#endif