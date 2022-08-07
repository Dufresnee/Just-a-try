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
	void useradd();//用户添加
	void usermodify();//;用户修改
	void userdelete();//用户删除
	void useroutput();//用户查看
};
