#include "minmaxavg.h"

//a MinMax konstruktor�t is meg kell h�vni              |
//														V
MinMaxAvg::MinMaxAvg(const initializer_list<int> &l) : MinMax(l) {
	atlag = 0.0;
	for (auto i : l) {
		atlag += i;
	}
	atlag /= l.size();
}
