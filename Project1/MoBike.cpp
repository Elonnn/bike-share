#include "MoBike.h"
#include <iostream>

using namespace std;


MoBike::MoBike(const char* id, const char* elock_id, int location_x, int location_y, int comfort_rating) //MoBike 构造函数，参数列表各字段依次表示：单车编号，电子锁编号，起始位置横坐标，纵坐标，舒适度
{
	serial = id;
	x = location_x;
	y = location_y;
	comfort = comfort_rating;
	occupied = 0;
	distance = 0;

	elock = elock_id;
}

bool MoBike::unlock() //解锁单车，如果单车空闲，则解锁成功并占用。否则解锁失败。
{
	if (!occupied) {
		occupied = 1;
		cout << "unlock " << serial << " " << elock << endl;
		return 1;
	}
	else {
		cout << "fail to unlock " << serial << " " << elock << endl;
		return 0;
	}
}

int MoBike::lock()//对单车上锁，如果单车在使用中，则上锁成功并解除占用，返回累计费用并对累计里程清零；否则上锁失败，返回 - 1.
{
	if (!occupied)  {
		cout << serial << " " << elock << " has been locked" << endl;
		return -1;
	}
	else
	{
		cout << "lock " << serial << " " << elock << endl;

		occupied = 0;
		int cost = compute_cost();
		distance = 0;
		return cost;
	}
}

int MoBike::compute_cost()//根据累计骑行距离计算费用，并返回该费用。不同的单车计费方式不同（具体见下文说明）
{
	int cost = (distance + 24) / 25 * 2 - 5;
	if (cost >= 0)
		return cost;
	else
		return 0;
}

