 #bike-share

> 利用C++模拟实现一个对共享单车的管理系统。设计实现代表系统的 BikeSystem 类，表示所有单车基类的 Bike 类，以及OfoBike、MoBike 两个派生类。集成开发环境为vs2017。

###一、Bike 类

表示共享单车的 Bike 基类，具有如下的属性:

| 属性              | 类型   | 说明                    |
| :-------------- | :--- | :-------------------- |
| 单车编号：serial     | 字符串  | 如“MoBike001”          |
| 占用标识：occupied   | 布尔型  | 表示当前单车是否被占用，初始 false  |
| 使用累计里程：distance | 整型   | 单车解锁到下一次上锁期间的累计路程     |
| 当前位置横坐：x        | 整型   | 当前单车所在位置横坐标，范围[0,100] |
| 当前位置纵坐：y        | 整型   | 当前单车所在位置纵坐标，范围[0,100] |
| 舒适度：comfort     | 整型   | 单车的舒适度，范围[1,10]       |

Bike 类接口如下：

- bool unlock(); //解锁单车，如果单车空闲，则解锁成功并占用。否则解锁失败。
- int lock(); //对单车上锁，如果单车在使用中，则上锁成功并解除占用，返回累计费用并对累计里程清零；否则上锁失败，返回-1.
- int move_to(int destination_x, int destination_y); //单车从当前位置骑行到（destination_x , destination_y），输出“from x,y to destination_x,dextination_y”,并更新单车中的位置信息。最后返回这段骑行过程的累计距离。
- int compute_cost(); //根据累计骑行距离计算费用，并返回该费用。不同的单车计费方式不同（具体见下文说明）

### 二、 OfoBike类

Bike 的派生类 OfoBike具有如下的构造函数：
```
OfoBike::OfoBike(const char* id, int location_x, int location_y, int comfort_rating); 
参数列表各字段依次表示：单车编号，起始位置横坐标，纵坐标，舒适度
```

| 方法           | 情况   | 操作细节                                     |
| :----------- | :--- | :--------------------------------------- |
| unlock       | 操作成功 | 打印“unlock 单车编号”，返回 true                  |
|              | 操作失败 | 打印“fail to unlock 单车编号”，返回 false         |
| lock         | 操作成功 | 打印 “lock 单车编号”，返回费用                      |
|              | 操作失败 | 打印 “单车编号 has been locked”，返回-1           |
| compute_cost |      | Ofo 车速为 21 单位长度/小时，骑行时间向上取整，费用 2 元/小时，同时由于 OfoBike 骑行优惠，可以减免 7 元 |

### 三、 MoBike类

Bike 的派生类MoBike附带额外的电子锁编号属性，类型为字符串（如“MoBike_elock_003”）， MoBike具有如下的构造函数：

```
MoBike::MoBike(const char* id, const char* elock_id, int location_x, int location_y, int comfort_rating); 
参数列表各字段依次表示：单车编号，电子锁编号，起始位置横坐标，纵坐标，舒适度
```

| 方法           | 情况   | 操作细节                                     |
| :----------- | :--- | :--------------------------------------- |
| unlock       | 操作成功 | 打印“unlock 单车编号 电子锁编号”返回 true             |
|              | 操作失败 | 打印“fail to unlock 单车编号 电子锁编号”返回 false    |
| lock         | 操作成功 | 单车解锁到下一次上锁期间的累计路程                        |
|              | 操作失败 | 打印 “lock 单车编号 电子锁编号”，返回费用                |
| compute_cost |      | MoBike 车速为 25 单位长度/小时，骑行时间向上取整，费用 2 元/小时，同时由于 MoBike 骑行优惠，可以减免 5 元 |

### 四、 BikeSystem类

 BikeSystem 类统一管理以上涉及的共享单车类，具有以下的属性和接口：

- Bike** bikes; //单车列表，是一个 Bike类型的指针数组。

- int size; //系统当前的单车数量。

- Int capacity; //系统最大支持的单车数量

- int BikeSystem::search (const char* user_name, int start_x, int start_y, int acceptable_comfort_rating);//从成员 bikes 数组中找到满足条件的单车，查找成功则返回单车在数组中的下标，失败则返回-1，查找条件

  单车无人使用，且舒适度大于等于 acceptable_comfort_rating，如果有多个满足条件的单车，返回距离
  （start_x,start_y）近的；如果有多辆满足，返回舒适度最高的；如果上述条件都相同，返回在 bikes 数组中下标最小的。 查找成功，则输出“用户名 selected 单车编号”；失败则输出 “用户名 found no bikes available”