#include "OfoBike.h"
#include <iostream>

using namespace std;

OfoBike::OfoBike(const char* id, int location_x, int location_y, int comfort_rating) // OfoBike ���캯���������б���ֶ����α�ʾ��������ţ���ʼλ�ú����꣬�����꣬���ʶ�
{
	serial = id;
	x = location_x;
	y = location_y;
	comfort = comfort_rating;
	occupied = 0;
	distance = 0;
}

bool OfoBike::unlock() //��������������������У�������ɹ���ռ�á��������ʧ�ܡ�
{
	if (!occupied) {
		occupied = 1;
		cout << "unlock " << serial << endl;
		return 1;
	}
	else {
		cout << "fail to unlock " << serial << endl;
		return 0;
	}
}

int OfoBike::lock()//�Ե������������������ʹ���У��������ɹ������ռ�ã������ۼƷ��ò����ۼ�������㣻��������ʧ�ܣ����� - 1.
{
	if (!occupied)  {
		cout << serial << " has been locked" << endl;
		return -1;
	}
	else{
		cout << "lock " << serial << endl;

		occupied = 0;
		int cost = compute_cost();
		distance = 0;
		return cost;
	}
}

int OfoBike::compute_cost()//�����ۼ����о��������ã������ظ÷��á���ͬ�ĵ����Ʒѷ�ʽ��ͬ�����������˵����
{
	int cost = (distance + 20) / 21 * 2 - 7;
	if (cost >= 0)
		return cost;
	else
		return 0;
}



