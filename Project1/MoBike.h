#ifndef MOBIKE_H
#define MOBIKE_H

#include <iostream>
#include <string>
#include"Bike.h"

using namespace std;

class MoBike :public Bike
{
	string elock;

public:
	MoBike(const char* id, const char* elock_id, int location_x, int location_y, int comfort_rating); //MoBike ���캯���������б���ֶ����α�ʾ��������ţ���������ţ���ʼλ�ú����꣬�����꣬���ʶ�
	bool unlock(); //��������������������У�������ɹ���ռ�á��������ʧ�ܡ�
	int lock();//�Ե������������������ʹ���У��������ɹ������ռ�ã������ۼƷ��ò����ۼ�������㣻��������ʧ�ܣ����� - 1.
	int compute_cost();//�����ۼ����о��������ã������ظ÷��á���ͬ�ĵ����Ʒѷ�ʽ��ͬ�����������˵����

};

#endif