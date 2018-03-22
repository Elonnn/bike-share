#ifndef BIKE_H
#define BIKE_H

#include <iostream>
#include <string>

using namespace std;

class Bike
{
	friend class BikeSystem;

//protected:
public:

	string serial;
	bool occupied;
	int distance;
	int x;
	int y;
	int comfort;

	virtual bool unlock(); //解锁单车，如果单车空闲，则解锁成功并占用。否则解锁失败。
	virtual int lock();//对单车上锁，如果单车在使用中，则上锁成功并解除占用，返回累计费用并对累计里程清零；否则上锁失败，返回 - 1.
	int move_to(int destination_x, int destination_y);//单车从当前位置骑行到（destination_x , destination_y），输出“from x, y to destination_x, dextination_y”, 并更新单车中的位置信息。最后返回这段骑行过程的累计距离。
	virtual int compute_cost() = 0;//根据累计骑行距离计算费用，并返回该费用。不同的单车计费方式不同（具体见下文说明）

};

#endif // BIKE_H