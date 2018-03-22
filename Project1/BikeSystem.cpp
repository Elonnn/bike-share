#include "BikeSystem.h"
#include <iostream>
#include <vector>
#include<algorithm>
#include<cmath>
using namespace std;

int BikeSystem::search(const char *user_name, int start_x, int start_y, int acceptive_comfort_rating) const {
	//请在此输入实现，请不要更改其余已有api
	struct Bk
	{
		Bike* b;
		int dist;
		int index;
	};

	vector<Bk> satis;
	for (int i = 0; i < size; ++i)
		if (bikes[i]->comfort >= acceptive_comfort_rating&&bikes[i]->occupied == 0)
		satis.push_back({ bikes[i], 0, i });

	if (satis.size() == 0)
	{
		cout << user_name << " found no bikes available" << endl;
		return -1;
	}
	else
	{
		for_each(satis.begin(), satis.end(), [=](Bk &p){p.dist = abs(p.b->x - start_x) + abs(p.b->y - start_y); });
		sort(satis.begin(), satis.end(), [](Bk a1, Bk a2)->bool {return a1.dist < a2.dist || (a1.dist == a2.dist&&a1.b->comfort > a2.b->comfort) || (a1.dist == a2.dist&&a1.b->comfort == a2.b->comfort&&a1.index<a2.index); });	//简记为a1排在前面的理由是什么

		cout << user_name << " selected " << satis[0].b->serial << endl;
		return satis[0].index;
	}

	return 0;
}

BikeSystem::BikeSystem(){
	this->capability = INIT_CAP;
	this->bikes = new Bike*[this->capability];
	this->size = 0;
	this->incremental = this->capability / 2;
	for (int i = 0; i < this->capability; ++i){
		this->bikes[i] = nullptr;
	}
}

BikeSystem::~BikeSystem() {
	release(this->bikes, this->size);
}

bool BikeSystem::unlock_bike(int bike_indicator) {
	if (bike_indicator >= this->size || this->bikes[bike_indicator] == NULL){
		cerr << "fail to unlock with bike indicator " << bike_indicator << endl;
		return false;
	}
	return this->bikes[bike_indicator]->unlock();
}

int BikeSystem::ride_record(int bike_indicator, int destination_x, int destination_y) {
	if (bike_indicator >= this->size || this->bikes[bike_indicator] == NULL){
		cerr << "fail to ride with bike indicator " << bike_indicator << endl;
		return 0;
	}
	return this->bikes[bike_indicator]->move_to(destination_x, destination_y);
}

int BikeSystem::lock_bike(int bike_indicator) {
	if (bike_indicator >= this->size || this->bikes[bike_indicator] == NULL){
		cerr << "fail to lock with bike indicator " << bike_indicator << endl;
		return 0;
	}
	return this->bikes[bike_indicator]->lock();
}

void BikeSystem::add(Bike *bike) {
	if (this->size == this->capability){ // realloc
		cout << "realloc" << endl;
		this->capability += this->incremental;
		if (INIT_CAP / this->incremental < 8) {
			this->incremental /= 2;
			if (this->incremental < 1) this->incremental = 1;
		}
		Bike** new_bikes = new Bike*[this->capability];
		memcpy(new_bikes, this->bikes, this->size * sizeof(Bike*));
		for (int i = this->size; i < this->capability; ++i){
			new_bikes[i] = nullptr;
		}
		delete[]this->bikes;
		this->bikes = new_bikes;
	}
	this->bikes[this->size] = bike;
	++this->size;
}
void BikeSystem::release(Bike **bike_list, int num) {
	if (bike_list == nullptr){
		return;
	}
	for (int i = 0; i < num; ++i){
		if (bike_list[i] != nullptr){
			delete bike_list[i];
		}
	}
	delete[]bike_list;
	bike_list = nullptr;
}