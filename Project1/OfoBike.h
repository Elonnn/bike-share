#ifndef OFOBIKE_H
#define OFOBIKE_H

#include <iostream>
#include <string>
#include"Bike.h"

using namespace std;

class OfoBike:public Bike
{

public:
	OfoBike(const char* id, int location_x, int location_y, int comfort_rating); // OfoBike 构造函数，参数列表各字段依次表示：单车编号，起始位置横坐标，纵坐标，舒适度

	bool unlock(); //解锁单车，如果单车空闲，则解锁成功并占用。否则解锁失败。
	int lock();//对单车上锁，如果单车在使用中，则上锁成功并解除占用，返回累计费用并对累计里程清零；否则上锁失败，返回 - 1.

	int compute_cost();//根据累计骑行距离计算费用，并返回该费用。不同的单车计费方式不同（具体见下文说明）

};

#endif
