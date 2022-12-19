#include "Counter.h"

class OverflowCounter: public Counter {
	public:
		OverflowCounter(int initial, int limit);
		void inc() override;
		void dec() override;
		operator int() override;
	private:
		int initialValue, upperLimit;
};

OverflowCounter::OverflowCounter(int initial, int limit):initialValue(initial), upperLimit(limit){ }
OverflowCounter::operator int(){
	return initialValue;
}
void OverflowCounter::inc(){
	if(initialValue>=upperLimit){
		initialValue =0;
	}else{
		initialValue+=1;
	}
}

void OverflowCounter::dec(){
	if(initialValue<=0){
		initialValue =upperLimit;
	}else{
		initialValue-=1;
	}
}