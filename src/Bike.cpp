#include<iostream>
#include <cmath>
#include"Bike.h"

using namespace std;


bool Bike::unlock() //��������������������У�������ɹ���ռ�á��������ʧ�ܡ�
{
	if (!occupied) { occupied = 1; return 1; }
	else return 0;
}

int Bike::lock()//�Ե������������������ʹ���У��������ɹ������ռ�ã������ۼƷ��ò����ۼ�������㣻��������ʧ�ܣ����� - 1.
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

int Bike:: move_to(int destination_x, int destination_y)//�����ӵ�ǰλ�����е���destination_x , destination_y���������from x, y to destination_x, dextination_y��, �����µ����е�λ����Ϣ���������������д���仰�����˰�����󷵻�������й��̵��ۼƾ��롣
{
	cout << "from " << x << "," << y << " to " << destination_x << "," << destination_y << endl;
	int dist = abs(x - destination_x) + abs(y - destination_y);
	x = destination_x;
	y = destination_y;
	distance += dist;
	return dist;
}