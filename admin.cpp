#include"admin.h"
#include"user.h"
#include <fstream>
#include"city.h"


vector<user> users;
void a1() {
	user new1("123", "123", "110", "��ɳ");
	user new2("456", "456", "120", "�人");
	user new3("789", "789", "130", "�Ϻ�");

	users.push_back(new1);
	users.push_back(new2);
	users.push_back(new3);
}


void admin::useradd() {
	user newuser("0","0","0","0");
	cout << "���������û�������" << endl;
	cin >> newuser.name;
	cout << "���������û�������" << endl;
	cin >> newuser.password;
	cout << "���������û����ֻ���" << endl;
	cin >> newuser.phone;
	cout << "���������û��ĳ�����Ϣ" << endl;
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


	cout << "��������û�" << endl;
	write.close();

	fflush(stdin);
	getchar();
}


void admin::usermodify() {
	string a;
	int i = 0;
	int n;
	bool b = false;
	cout << "��������Ҫ�޸ĵ��û���" << endl;
	cin >> a;
	for (;;i++) {
		if (a == users[i].name) {
			n = i;
			b = true;
			break;
		}
	}
	if (!b ) {
		cout << "û���ҵ���Ҫ�޸ĵ��û���" << endl;
	}
	
	else {
		cout << "�������û���������" << endl;
		cin >> users[n].name;
		cout << "�������û���������" << endl;
		cin >> users[n].password;
		cout << "�������û������ֻ���" << endl;
		cin >> users[n].phone;
		cout << "�������û����³�����Ϣ" << endl;
		cin >> users[n].cityname;
		cout << "��������û��������������" << endl;
		fflush(stdin);
		getchar();
	}
}


void admin::userdelete() {
	string a;
	cout << "��������Ҫɾ�����û���" << endl;
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
		cout << "û���ҵ���Ҫ�޸ĵ��û�" << endl;
	}
	else {
		cout << "��ȴҪɾ�����û�������(Y/N)?" << endl;
		char c;
		cin >> c;
		if (c == 'Y' || c == 'y') {
			users.erase(users.begin() + n);
			cout << "ɾ�����";
		}
		else if (c == 'N' || c == 'n')
			cout << "ɾ��ȡ��";
		fflush(stdin);
		getchar();
	}

}


void admin::useroutput() {
	int n;
	size_t i;
	string b;
	bool j = false;
	cout << "��������Ҫ�鿴��Ϣ���û���";
	cin >> b;
	for (i = 0; i < users.size(); i++) {
		if (b == users[i].name) {
			n = i;
			j = true;
			break;
		}
	}
	if (!j) {
		cout << "δ�ҵ����û�" << endl;
		return;
	}
	else {
		cout << "�û�����" << endl << users[n].name << endl;
		cout << "���룺" << endl << users[n].password << endl;
		cout << "��������" << endl << users[n].cityname << endl;
		cout << "�ֻ��ţ�" << endl << users[n].phone << endl;
		users[n].cityoutput();
		cout << "�鿴���" << endl;
		fflush(stdin);
		getchar();
	}
}

