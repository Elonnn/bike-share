#ifndef BIKESYSTEM_H
#define BIKESYSTEM_H

#include <iostream>
#include <cstdlib>
#include "Bike.h"
#include <cstring>

#define INIT_CAP 1000
using namespace std;

class BikeSystem
{
private:
	Bike** bikes; // Bike*���͵����飬����ÿ���ָ�򵥳����͵�ָ��
	int size; // ���������������Ҳ�����bikes�����±�Ϊ[0, size-1]��Χ�ڲ�ѯ
	int capability; // ϵͳ���֧�ֵĵ�������
	int incremental; // ÿ�ζ�̬����ĵ������ڴ棩����
public:
	/**
	* @brief �ӵ����б��в������������ġ�����ġ���ǰδ��ռ�õĵ���
	* 		����������1. ����û��ռ��
	*              2. ���������ʶȲ�С��acceptive_comfort_rating
	* 		�ɹ��ҵ��������"���� selected ����id"���Ҳ����������"���� found no bikes available"
	* @param user_name ִ�в��ҵ����������û���ʶ�����֣�
	* @param start_x �û�����λ�ú�����x
	* @param start_y �û�����λ��������y
	* @param acceptive_comfort_rating ���Խ��ܵ���С�������ʶ�
	* @return ����������������ĵ�����bikes�����е��±꣺
	* 				1. ����ж���������������ĵ������򷵻ؾ��������
	* 				2. �����������ĵ����ж������򷵻����ʶ���ߵ�
	*              3. ���������������ͬ���򷵻���bikes�������±���С��
	*              4. û�ҵ����� -1
	*/
	int search(const char* user_name, int start_x, int start_y, int acceptive_comfort_rating) const;

	/**
	* @brief ������������������Bike��unlock����
	* @param bike_indicator �����������ڵ��������е��±�
	* @return �����ɹ�����true������ʧ�ܷ���false
	*/
	bool unlock_bike(int bike_indicator);

	/**
	* @brief ���м�¼������Bike��move_to����
	* @param bike_indicator �����������ڵ��������е��±�
	* @param destination_x �յ������
	* @param destination_y �յ�������
	* @return ��ǰ�����ۻ������
	*/
	int ride_record(int bike_indicator, int destination_x, int destination_y);

	/**
	* @brief ���н�������������������������Bike��lock��������ʱ������Ϊ����״̬���ۻ����������
	* @param bike_indicator �����������ڵ��������е��±�
	* @return �����ɹ�������ۻ�����������ۻ����ò����أ�����ʧ�ܷ���0
	*/
	int lock_bike(int bike_indicator);

	/**
	* @brief Ĭ�Ϲ��캯������ʼ�������б�
	*/
	BikeSystem();

	/**
	* @brief ������ϵͳ����ӵ���
	* @param bike
	*/
	void add(Bike* bike);

	/**
	* @brief �ͷ�bike_list����ռ�
	* @param bike_list Bike*���͵�����
	*/
	void release(Bike** bike_list, int num);

	/**
	* @brief �����������ͷſռ�  ��Ϊ����������Դ�ˣ�����Ҫ����������Bike�಻��Ҫ�Զ�����������
	*/
	~BikeSystem();
};

#endif // BIKESYSTEM_H