#include "Counter.h"

class LimitedCounter: public Counter {
	public:
		LimitedCounter(int initial, int limit);
		void inc() override;
		void dec() override;
		operator int() override;
	private:
		int initialValue, upperLimit;
};

LimitedCounter::LimitedCounter(int initial, int limit): initialValue(initial), upperLimit(limit){}

LimitedCounter::operator int(){
	return initialValue;
}
void LimitedCounter::inc(){
	if(initialValue>=upperLimit){
		initialValue = upperLimit;
	}else{
		initialValue+=1;
	}
}

void LimitedCounter::dec(){
	if(initialValue==0){
		initialValue =0;
	}else{
		initialValue-=1;
	}
}