#pragma once
#include <initializer_list>
using namespace std;

class MinMax {
	int minimum, maximum;
public:
	//konstruktor in�cializ�l� list�val
	MinMax(const initializer_list<int> &l);

	int getMin() const { return minimum; }
	int getMax() const { return maximum; }
};
