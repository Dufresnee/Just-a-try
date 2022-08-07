#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include"city.h"

using namespace std;

class user {

public:
	string name;//用户名
	string cityname;//城市名
	string phone;//手机号
	string password;//密码
	void cityadd();//城市添加
	void citymodify();//城市修改
	void citydelete();//城市删除
	void cityoutput();//打印功能：以表格形式打印用户全部城市信息。
	void usersave();//信息（用户）保存
	void readFrom(const char filename[]);//信息读取

	vector <city> usercity;
	friend istream& operator>>(istream&, user&);


	user(string name1,  string password1,string phone1, string cityname1) {
		name1 = name;
		password1 = password;
		phone1 = phone;
		cityname1 = cityname;
	}


};
