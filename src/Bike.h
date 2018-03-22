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

	virtual bool unlock(); //��������������������У�������ɹ���ռ�á��������ʧ�ܡ�
	virtual int lock();//�Ե������������������ʹ���У��������ɹ������ռ�ã������ۼƷ��ò����ۼ�������㣻��������ʧ�ܣ����� - 1.
	int move_to(int destination_x, int destination_y);//�����ӵ�ǰλ�����е���destination_x , destination_y���������from x, y to destination_x, dextination_y��, �����µ����е�λ����Ϣ����󷵻�������й��̵��ۼƾ��롣
	virtual int compute_cost() = 0;//�����ۼ����о��������ã������ظ÷��á���ͬ�ĵ����Ʒѷ�ʽ��ͬ�����������˵����

};

#endif // BIKE_H