#pragma once
#include<iostream>
#include<string>
#include <vector>
#include <fstream>
#include <iomanip>

using namespace std;

class admin {
private:
	string name;
	string password;
	
public:
	admin(string a, string b)
	{
		name = a;
		password = b;
	}
	void useradd();//�û����
	void usermodify();//;�û��޸�
	void userdelete();//�û�ɾ��
	void useroutput();//�û��鿴
};
