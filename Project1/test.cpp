#include<iostream>

#include"BikeSystem.h"
#include"OfoBike.h"
#include"MoBike.h"


using namespace std;


int main()
{
	cout << "Initializing...\n";
	BikeSystem bike_system; //初始化单车系统，随后添加两个OfoBike和MoBike􄖖
	bike_system.add(new OfoBike("ofo05", 30, 60, 9));
	bike_system.add(new OfoBike("ofo06", 30, 60, 5));
	bike_system.add(new MoBike("Mo05","dfs", 30, 60, 4));
	bike_system.add(new MoBike("Mo06","dfs", 0, 60, 10));

	int idx1 = bike_system.search("xiaoming", 50, 50, 5); //查找成功，输出"xiaoming selected ofo05", 返回idx1=0
	int idx2 = bike_system.search("xiaohong", 50, 50, 9); //查找成功，输出"xiaohong selected ofo05", 返回idx2=0
	cout << "Xiaoming ";
	bike_system.unlock_bike(idx1); //解锁成功，输出"unlock ofo05"
	cout << "Xiaohong ";
	bike_system.unlock_bike(idx2); //解锁失败，输出"fail to unlock ofo05"

	cout << "\nXiaoming's route:\n";
	bike_system.ride_record(idx1, 100, 100); //输出"from 30,60 to 100,100"
	bike_system.ride_record(idx1, 100, 80); //输出"from 100,100 to 100,80"
	int cost = bike_system.lock_bike(idx1); //锁车成功，输出"lock ofo05"，返回 dist=7
	cout << "The total cost of xiaoming is " << cost << endl;
	return 0;
}

