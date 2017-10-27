#include <iostream>
#include <string>
#include "VendingMachine.h"
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> parse_user_command(string input){
	istringstream input_stream(input);
    string buffer;
    vector<string> separated;

    while (input_stream >> buffer)
    {
        separated.push_back(buffer);
    }

    return separated;
}
int main(){
	int quarterint;
		int nickelint;
		int dimeint;
		int valueint;

		int* quarterint1 ;
		int* nickelint1;
		int* dimeint1 ;
		int* valueint1 ;
	cout << "Hello World!" << endl;
	cout << "A VendingMachine has been created." << endl;
	VendingMachine* vm = new VendingMachine();
	cout << "============================================== " <<endl;
	cout << "Please enter the number of q,n,d,v, and whether the cancel button is pressed (0 or 1)" << endl;
	bool notready = true;
	while(notready){
		cout << "Enter q n d v first." << endl;
		string quarters; 
		string nickels;
		string dimes;
		string values;
		
		bool* cancel = new bool();
		
		cin >> quarters >> nickels >> dimes >> values;
		
		string* quarter = &quarters;
		string* nickel = &nickels;
		string* dime = &dimes;
		string* value = &values;
		
		//cout << "quarter:" << *quarter << endl;

		
		cout << "Now enter cancel setting. 0 or 1" << endl;
		string cancelstrings;
		cin >> cancelstrings;
		string* cancelstring = &cancelstrings;
		if(*cancelstring == "1"){
			*cancel = true;
		}else{
			*cancel = false;
		}
		
		quarterint = stoi(*quarter);
		nickelint = stoi(*nickel);
		dimeint = stoi(*dime);
		valueint = stoi(*value);

		quarterint1 = &quarterint;
		nickelint1 = &nickelint;
		dimeint1 = &dimeint;
		valueint1 = &valueint;

		
		vm->initializeVM(quarterint1, nickelint1, dimeint1, 
		valueint1, cancel);
		notready = false;
		
	}
	cout << "Initial state : " <<endl;
	vm->printCurrentState(); 
	cout << "============================================== " <<endl;
	
	//bool runbool = true;
	bool run = true;
	while(run){
		cout << "Enter inputs separated by a white space. " <<endl;
		cout << "Available inputs : q n d c w " << endl;
		string commandstring; 
		string* command;
		vector<string>input;
		vector<string>*inputs;
		if(getline(cin, commandstring)){
			command = &commandstring;
			input = parse_user_command(*command);
			inputs = &input;
			//cout<< "input size:" << inputs->size() << endl;
		}
	
		if(inputs->size()== 1 && inputs->at(0) == "quit"){
			
			cout << "terminated" << endl;
			
			delete vm;
			run = false;
		}else if (inputs->size()==1 && inputs->at(0)=="check"){
			
			vm->printCurrentState();
		}else{
			bool valid = false;
			for(int i = 0; i < inputs->size(); i ++){
				
				string token = inputs->at(i);
				
				if(token=="q" || token == "n" || token == "d" || token == "c" 
				|| token == "w"){
					valid = true;
				}else{
					valid = false;
					break;
				}
			}
			
			if(valid){
				vm->produceAndPrintOutput();
				cout << endl;
				vm->stateTransition(inputs);
				
			}else{
				cout << "Input invalid. Please try again." << endl;
			}
			
			
		}
		
	}
	
	//return 0;
}
