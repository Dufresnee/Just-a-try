#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include"city.h"

using namespace std;

class user {

public:
	string name;//�û���
	string cityname;//������
	string phone;//�ֻ���
	string password;//����
	void cityadd();//�������
	void citymodify();//�����޸�
	void citydelete();//����ɾ��
	void cityoutput();//��ӡ���ܣ��Ա����ʽ��ӡ�û�ȫ��������Ϣ��
	void usersave();//��Ϣ���û�������
	void readFrom(const char filename[]);//��Ϣ��ȡ

	vector <city> usercity;
	friend istream& operator>>(istream&, user&);


	user(string name1,  string password1,string phone1, string cityname1) {
		name1 = name;
		password1 = password;
		phone1 = phone;
		cityname1 = cityname;
	}


};
