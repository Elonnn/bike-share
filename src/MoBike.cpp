#include "MoBike.h"
#include <iostream>

using namespace std;


MoBike::MoBike(const char* id, const char* elock_id, int location_x, int location_y, int comfort_rating) //MoBike ���캯���������б���ֶ����α�ʾ��������ţ���������ţ���ʼλ�ú����꣬�����꣬���ʶ�
{
	serial = id;
	x = location_x;
	y = location_y;
	comfort = comfort_rating;
	occupied = 0;
	distance = 0;

	elock = elock_id;
}

bool MoBike::unlock() //��������������������У�������ɹ���ռ�á��������ʧ�ܡ�
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

int MoBike::lock()//�Ե������������������ʹ���У��������ɹ������ռ�ã������ۼƷ��ò����ۼ�������㣻��������ʧ�ܣ����� - 1.
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

int MoBike::compute_cost()//�����ۼ����о��������ã������ظ÷��á���ͬ�ĵ����Ʒѷ�ʽ��ͬ�����������˵����
{
	int cost = (distance + 24) / 25 * 2 - 5;
	if (cost >= 0)
		return cost;
	else
		return 0;
}

