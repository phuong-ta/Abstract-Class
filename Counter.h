#pragma once

#include <iostream>
#include <vector>
#include <list>
#include <iterator>
#include <algorithm>
#include <ctime>
#include <string>
#include <cmath>
#include <memory>
using namespace std;
class Counter {
public:
	virtual void inc() = 0;
	virtual void dec() = 0;
	virtual operator int() = 0;
	virtual ~Counter() {};
};