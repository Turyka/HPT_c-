#include <thread>
#include <iostream>
#include <ctime>
#include <list>
#include <map>

// konvert f�ggv�ny k�sz�t�se
// param�tere a lista �s egy int->int f�ggv�ny
// a lista minden elem�n v�grehajtja a f�ggv�nyt �s be�rja a hely�re (p�ld�ul i = fv(i))
void konvert(std::list<int> &eredmenyek, std::function<int(int)> fv) {
	for(auto &i : eredmenyek)
		i = fv(i);
}

int Modusz(const std::list<int> &eredmenyek) {
	std::map<int, int> darab;
	for(auto i : eredmenyek) {
		darab[i]++;
	}
	auto max = darab.begin();
	for(auto it = darab.begin(); it != darab.end(); it++) {
		if(max->second < it->second)
			max = it;
	}
	return max->first;
}

int main() {
	srand(time(0));
	std::list<int> eredmenyek;
	for(unsigned int i = 0; i < 1000; i++)
		eredmenyek.push_back(rand() % 100);
	double modusz;
	// a Modusz f�ggv�ny elind�t�sa egy sz�lon
	// az eredm�ny a modusz v�ltoz�ba ker�lj�n
	std::thread t1([&modusz, &eredmenyek]() { modusz = Modusz(eredmenyek); });
	t1.join();

	std::cout << modusz;

	// a konvert f�ggv�ny megh�v�sa lambda f�ggv�ny seg�ts�g�vel
	// a lambda f�ggv�ny a p�ros sz�mokat ossza le 2-vel a p�ratlanokat szorozza meg 2-vel
	konvert(eredmenyek, [](int i) { return i % 2 == 0 ? i / 2 : i * 2; });
}