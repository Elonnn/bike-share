#include<iostream>
#include <cmath>
#include"Bike.h"

using namespace std;


bool Bike::unlock() //解锁单车，如果单车空闲，则解锁成功并占用。否则解锁失败。
{
	if (!occupied) { occupied = 1; return 1; }
	else return 0;
}

int Bike::lock()//对单车上锁，如果单车在使用中，则上锁成功并解除占用，返回累计费用并对累计里程清零；否则上锁失败，返回 - 1.
{
	if (!occupied)  return -1;
	else
	{
		occupied = 0;
		int cost = compute_cost();
		distance = 0;
		return cost;
	}
}

int Bike:: move_to(int destination_x, int destination_y)//单车从当前位置骑行到（destination_x , destination_y），输出“from x, y to destination_x, dextination_y”, 并更新单车中的位置信息和里程数！！（少写这半句话坑死人啊）最后返回这段骑行过程的累计距离。
{
	cout << "from " << x << "," << y << " to " << destination_x << "," << destination_y << endl;
	int dist = abs(x - destination_x) + abs(y - destination_y);
	x = destination_x;
	y = destination_y;
	distance += dist;
	return dist;
}