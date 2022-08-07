#include"admin.h"
#include"user.h"
#include <fstream>
#include"city.h"


vector<user> users;
void a1() {
	user new1("123", "123", "110", "长沙");
	user new2("456", "456", "120", "武汉");
	user new3("789", "789", "130", "上海");

	users.push_back(new1);
	users.push_back(new2);
	users.push_back(new3);
}


void admin::useradd() {
	user newuser("0","0","0","0");
	cout << "请输入新用户的姓名" << endl;
	cin >> newuser.name;
	cout << "请输入新用户的密码" << endl;
	cin >> newuser.password;
	cout << "请输入新用户的手机号" << endl;
	cin >> newuser.phone;
	cout << "请输入新用户的城市信息" << endl;
	cin >> newuser.cityname;

	ofstream write;
	write.open("name.txt", ios::app);
	if (!write) {
		cerr << "open error!" << endl;
		exit(1);
	}

	write << newuser.name << " " << newuser.password;
	write << "\n";

	users.push_back(newuser);


	cout << "已输入该用户" << endl;
	write.close();

	fflush(stdin);
	getchar();
}


void admin::usermodify() {
	string a;
	int i = 0;
	int n;
	bool b = false;
	cout << "请输入你要修改的用户：" << endl;
	cin >> a;
	for (;;i++) {
		if (a == users[i].name) {
			n = i;
			b = true;
			break;
		}
	}
	if (!b ) {
		cout << "没有找到所要修改的用户：" << endl;
	}
	
	else {
		cout << "请输入用户的新姓名" << endl;
		cin >> users[n].name;
		cout << "请输入用户的新密码" << endl;
		cin >> users[n].password;
		cout << "请输入用户的新手机号" << endl;
		cin >> users[n].phone;
		cout << "请输入用户的新城市信息" << endl;
		cin >> users[n].cityname;
		cout << "已输入该用户，按任意键继续" << endl;
		fflush(stdin);
		getchar();
	}
}


void admin::userdelete() {
	string a;
	cout << "请输入你要删除的用户名" << endl;
	cin >> a;
	int n,i;
	bool b = false;
	for (i=0;; i++) {
		if (a == users[i].name) {
			n = i;
			b = true;
			break;
		}
	}
	if (!b) {
		cout << "没有找到所要修改的用户" << endl;
	}
	else {
		cout << "你却要删除该用户数据吗(Y/N)?" << endl;
		char c;
		cin >> c;
		if (c == 'Y' || c == 'y') {
			users.erase(users.begin() + n);
			cout << "删除完毕";
		}
		else if (c == 'N' || c == 'n')
			cout << "删除取消";
		fflush(stdin);
		getchar();
	}

}


void admin::useroutput() {
	int n;
	size_t i;
	string b;
	bool j = false;
	cout << "请输入你要查看信息的用户名";
	cin >> b;
	for (i = 0; i < users.size(); i++) {
		if (b == users[i].name) {
			n = i;
			j = true;
			break;
		}
	}
	if (!j) {
		cout << "未找到该用户" << endl;
		return;
	}
	else {
		cout << "用户名：" << endl << users[n].name << endl;
		cout << "密码：" << endl << users[n].password << endl;
		cout << "城市名：" << endl << users[n].cityname << endl;
		cout << "手机号：" << endl << users[n].phone << endl;
		users[n].cityoutput();
		cout << "查看完成" << endl;
		fflush(stdin);
		getchar();
	}
}

