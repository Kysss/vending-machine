#include "VendingMachine.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*VendingMachine:: VendingMachine(){
	*q = 0;
	*d = 0;
	*n = 0;
	*v = 0;
	*c = false;
}*/

void VendingMachine::initializeVM(int* q, int* d, int* n, int* v, bool* c){
	
	this->q = q;
	this->d = d;
	this->n = n;
	this->v = v;
	this->c = c;
	 
}

void VendingMachine::printCurrentState(){
	
	cout << "q: " << *q  << ", " <<
	"d: " << *d << ", " << " n: " << *n << ", " <<
	"value: " << *v << ", cancel: " << *c << endl;
	
}

void VendingMachine::stateTransition(vector<string>* inputs){

	if(*c==true){
		subtractChange();
	}

	int numOfCoffee = getNumOfCoffee(*v);

	*v = *v - (numOfCoffee)*100;
	*c = false;

	for(int i = 0; i < inputs->size(); i++){
		
		if(inputs->at(i) == "q"){
			(*q)++;
			*v = *v + 25;
			//break;
		}else if (inputs->at(i) == "d"){
			(*d)++;
			*v = *v + 10;
			//break;
		}else if (inputs->at(i) == "n"){
			(*n)++;
			*v = *v + 5;
			//break;
		}else if (inputs->at(i) == "c"){
			*c = true;
			//break;
		}else{
			
		}
	}
	//delete numOfCoffee;
	printCurrentState();
}

int VendingMachine::getNumOfCoffee(int value){
	int n = 0;
	int reminder = 0;
	if(value%100 < 100){
		reminder = value%100;
		n = (value-reminder)/100;
	}
	return n;
}

vector<string> VendingMachine::produceOutput(){
	vector<string> output;
	if(*c == true){
		output = produceChange();
	}else if(*v >= 100){
		int numberOfCoffee = getNumOfCoffee(*v);
		for(int i = 0; i < numberOfCoffee; i ++){
			output.push_back("Coffee"); 
		}
	}
	if(output.size() == 0 ){
		output.push_back("Nothing");
		return output;
	}else{
		return output;
	}
}

void VendingMachine::produceAndPrintOutput(){
	vector<string> output = produceOutput();
	string pOut = "{";

	for(int i = 0; i < output.size(); i++){
		if( i == output.size() - 1){
			pOut = pOut + output.at(i);
		}else{
			pOut = pOut + output.at(i) + ",";
		}
	}
	pOut = pOut + "}";
	
	cout << "Output:" << pOut;
}

vector<string> VendingMachine::produceChange(){

	vector<string> change;
	int vLeft = *v;
	int nQ = 0;
	int nD = 0;
	int nN = 0;

	while((vLeft)/25 > 0 && *q - nQ > 0){

		(nQ) ++;
		vLeft = vLeft -25;
	}
	while(vLeft/10 > 0 && *d - nD > 0){

		(nD)++;
		vLeft = vLeft -10;
	}
	while(vLeft/5 > 0 && *n - nN > 0){

		(nN)++;
		vLeft = vLeft - 5;
	}
	
	if(vLeft == 5 && *d-nD >=3 && nQ > 0){
		nQ--;
		nD = nD +3;
		vLeft = vLeft-5;
	}
	//try{
		
		if(vLeft > 0) {
			cout << "Should be an exception. Throwing at produceChange()" << endl;
			//throw VMException();
		}else{
			if((nQ+nD+nN) == 0 ){
			change.push_back("Nothing");
			}else{
			for(int i = 0; i < nQ; i++){
				change.push_back("q");
			}
			for(int i = nQ; i < nQ+nD; i++){
				change.push_back("d");
			}
			for(int i = nQ+nD; i < change.size(); i++){
				change.push_back("n");
			}
			}
		}
	//}catch(VMException& e){
	//	cout << e.what() << "\n Throwing at produceChange";
	//}

	return change;
}
void VendingMachine::subtractChange(){

	int vLeft = *v;
	int nQ = 0;
	int nD = 0;
	int nN = 0;
	while(vLeft / 25 > 0 && *q - nQ > 0){
		nQ  = nQ + 1;
		vLeft = vLeft - 25;
	}
	while(vLeft /10 > 0 && *d - nD > 0){
		nD = nD + 1;
		vLeft = vLeft - 10;
	}
	while(vLeft / 5 >0 && *n - nN > 0){
		nN = nN +1;
		vLeft = vLeft - 5;
	}
	if(vLeft == 5 && *d - nD >= 3 && nQ > 0 ){
		cout << "There is 5 cents left" << endl;
		nQ = nQ - 1;
		nD= nD + 3;
		vLeft = vLeft - 5 ;
	}
	
	//try{
		if(vLeft != 0 ){
			cout << "Should be an exception. Throwing at subtractChange()" << endl;
			//throw exception();
		}else{
			*q = *q - nQ;
			*d = *d - nD;
			*n = *n - nN;
			*v = false;
		}
	//}catch(Exception){
		
	//}

}








