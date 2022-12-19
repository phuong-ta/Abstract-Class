#include "Counter.h"
#include "LimitedCounter.h"
#include "OverflowCounter.h"

void UseCounter(Counter& ctr, int num){
	int i;
	if(num>=0){
		for(i=0; i<num;i++){
			ctr.inc();
		}
	}else{
		for(i=0; i>num;i--){
			ctr.dec();
		}
	}
};

int main(int argc, char** argv) {
	LimitedCounter lc(0, 5);
	OverflowCounter oc(5, 9);

	cout << oc << endl;
	UseCounter(oc, 5);
	cout << oc << endl; // should display zero
	UseCounter(oc, -1);
	cout << oc << endl; // should display 9
	oc.dec();
	cout << oc << endl; // should display 8

	cout << lc << endl;
	lc.inc();
	cout << lc << endl;
	lc.dec();
	cout << lc << endl;
	for(int i = 0; i < 10; ++i) lc.inc();
	cout << lc << endl;
	UseCounter(lc, -9);
	cout << lc << endl;
	//  
	LimitedCounter lm(15,45);
	cout << lm << endl;
	UseCounter(lm, 10);
	for(int i = 0; i<21;i++){
		lm.dec();
		cout << lm << endl;
	}
	
	OverflowCounter om(15,20);
	cout << om << endl;
	UseCounter(om, -10);
	for(int i = 0; i<21;i++){
		om.dec();
		cout << om << endl;
	}
	
	//OverflowCounter om(2,12);
	
	
	return 0;
}
