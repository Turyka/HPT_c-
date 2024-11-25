#include <iostream>
#include "vektor.h"
#include "komplex.h"

int main() {
	vektor<int> v;
	v.push_back(3);
	v.push_back(1);
	v.push_back(5);
	v.push_back(3);
	v.push_back(9);
	// �RJA KI A VEKTOR ELEMEIT ITERATOR HASZN�LAT�VAL
	std::cout << "Vektor" << std::endl;
	vektor<int>::Iterator vek;
	for (vek = v.begin(); vek != v.end(); vek++)
		std::cout << *vek << std::endl;
	std::cout << std::endl;

	vektor<komplex> v2;
	v2.push_back(komplex());
	v2.push_back(komplex(1.2));
	v2.push_back(komplex(0, -2));
	v2.push_back(komplex(-3, 1.6));
	v2.push_back(komplex(-2, -2));
	v2.push_back(komplex(7, 0.1));
	// �RJA KI A VEKTOR ELEMEIT REVERSEITERATOR HASZN�LAT�VAL

	
	std::cout << "Revektor" << std::endl;
	vektor<komplex>::ReverseIterator rev_vek_it = v2.rbegin();
	for (; rev_vek_it != v2.rend(); ++rev_vek_it) {
		std::cout << *rev_vek_it << std::endl;
	}

	std::cout << std::endl;
	std::system("pause");
}
