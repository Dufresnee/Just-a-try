#include"user.h"
#include"city.h"
extern vector<float> max;
extern vector<float> min;
extern vector<float> aver;
extern vector<float> capacity;//降雨量




void user::cityadd() {
	city newcity;
    int i;
    float a;
    cout << "请输入电话区号:" << endl;
    cin >> newcity.phonenum;
    cout << "请输入城市名称:"<<endl;
    cin >> newcity.name;
    cout << "请输入近三十天最低气温:";
    for (i = 0; i < 30; i++) {
        cin >> a;
        newcity.min.push_back(a);
    }
    cout << "请输入近三十天平均气温:";
    for (i = 0; i < 30; i++) {
        cin >> a;
        newcity.aver.push_back(a);
    }
    cout << "请输入近三十天最高气温:";
    for (i = 0; i < 30; i++) {
        cin >> a;
        newcity.max.push_back(a);
    }
    cout << "请输入近三十天降水量:";
    for (i = 0; i < 30; i++) {
        cin >> a;
        newcity.capacity.push_back(a);
    }
    usercity.push_back(newcity);
    cout << "输入完毕" << endl << "按任意键继续";
    fflush(stdin);
    getchar();

}


void user::citymodify() {
    string b;
    int n = 0;
    size_t i;
    float a;
    cout << "请输入你要修改的城市名称或者电话区号";
    cin >> b;
    bool j = false;
    for (i = 0; i < usercity.size(); i++) {
        if (b == usercity[i].name || b == usercity[i].phonenum) {
            n = i;
            j = true;
            break;
        }
    }
    if (!j) {
        cout << "未找到该城市" << endl;
        cout << endl << "按任意键继续";
        return;
    }
    else
    {
        cout << "请输入城市名称:" << endl;
        cin >> usercity[n].name;
        cout << "请输入电话区号:";
        cin >> usercity[n].phonenum;
        cout << "请输入近三十天城市天气最低气温:";
        for (i = 0; i < 30; i++) {
            cin >> a;
            usercity[n].min.push_back(a);
        }
        cout << "请输入近三十天城市天气平均气温:";
        for (i = 0; i < 30; i++) {
            cin >> a;
            usercity[n].aver.push_back(a);
        }
        cout << "请输入近三十天城市天气最高气温:";
        for (i = 0; i < 30; i++) {
            cin >> a;
            usercity[n].max.push_back(a);
        }
        cout << "请输入近三十天城市降水量:";
        for (i = 0; i < 30; i++) {
            cin >> a;
            usercity[n].capacity.push_back(a);
        }
        cout << "修改完毕" << endl << "按任意键继续";
        fflush(stdin);
        getchar();
    }

}


void user::citydelete() {
    string b;
    int n = 0;
    size_t i;
    char a;
    cout << "请输入你要删除的城市名称或者电话区号";
    cin >> b;
    bool j = false;
    for (i = 0; i < usercity.size(); i++) {
        if (b == usercity[i].name || b == usercity[i].phonenum) {
            n = i;
            j = true;
            break;
        }
    }
    if (!j) {
        cout << "未找到该城市" << endl;
        return;
    }
    else {
        cout << "你却要删除该城市数据吗(Y/N)?" << endl;
        cin >> a;
        if (a == 'Y' || a == 'y') {
            usercity.erase(usercity.begin() + n);
            cout << "删除完毕";
        }
        else if (a == 'N' || a == 'n')
            cout << "删除取消";
        fflush(stdin);
        getchar();
    }

}


void user::cityoutput() {
    size_t i, j;
    for (i = 0; i < usercity.size(); i++) {
        cout << "--------------------------------------------" << endl;
        cout << "|" << setw(9) << usercity[i].name << "|" << setw(9) << usercity[i].phonenum << "|" << endl;
        cout << "--------------------------------------------" << endl;

        cout << endl << "|" << "近三十天最低气温" << endl;
        for (j = 0; j < 30; j++) {
            cout << setw(4) << usercity[i].min[j] << " ";
        }
        cout << endl << "|" << "近三十天平均气温" << endl;
        for (j = 0; j < 30; j++) {
            cout << setw(4) << usercity[i].aver[j] << " ";
        }
        cout << endl << "|" << "近三十天最高气温" << endl;
        for (j = 0; j < 30; j++) {
            cout << setw(4) << usercity[i].max[j] << " ";
        }
        cout << endl << "|" << "近三十天降水量" << endl;
        for (j = 0; j < 30; j++) {
            cout << setw(4) << usercity[i].capacity[j] << " ";
        }
        cout << endl << "|" << "预测平均气温" << endl;
        cout << usercity[i].predictedtemperature;
    }
    cout << endl << "按任意键继续" << endl;
    fflush(stdin);
    getchar();


}


void user::usersave() {
    size_t i, j;
    ofstream write;
    write.open("userdata.txt", ios::app);
    if (!write) {
        cerr << "open error!" << endl;
        exit(1);
    }

    write << name << " " << password << " " << cityname << " " << phone << " ";
    write << "\n";
    write.close();

    write.open("citydata.txt", ios::app);
    if (!write) {
        cerr << "open error!" << endl;
        exit(1);
    }

    write << name << " " << password << " " << cityname << " " << phone << " ";
    for (i = 0; i < usercity.size(); i++) {
        for (j = 0; j < usercity.size(); j++) {
            write << usercity[i].name << " " << usercity[i].phonenum << " ";
        }
    }
    for (i = 0; i < usercity.size(); i++) {
        for (j = 0; j < 30; j++) {
            write << usercity[i].min[j] << " ";
        }
    }
    for (i = 0; i < usercity.size(); i++) {
        for (j = 0; j < 30; j++) {
            write << usercity[i].aver[j] << " ";
        }
    }
    for (i = 0; i < usercity.size(); i++) {
        for (j = 0; j < 30; j++) {
            write << usercity[i].max[j] << " ";
        }
    }
    for (i = 0; i < usercity.size(); i++) {
        for (j = 0; j < 30; j++) {
            write << usercity[i].capacity[j] << " ";
        }
    }
    write << "\n";
    write.close();

    write.open("name.txt", ios::app);
    if (!write) {
        cerr << "open error!" << endl;
        exit(1);
    }

    write << name<<" "<<password;
    write << "\n";
    write.close();


    write.open("password.txt", ios::app);
    if (!write) {
        cerr << "open error!" << endl;
        exit(1);
    }

    write << password ;
    write << "\n";
    write.close();
    cout << "已保存，按任意键继续" << endl;
    fflush(stdin);
    getchar();

}



void user::readFrom(const char filename[])
{
    ifstream inFile;
    inFile.open(filename);
    inFile >> name >>password ;
    inFile.close();
}

istream& operator>>(istream& input, user& s)
{
    cout << "输入用户数据：" << endl;
    cout << "用户名：";
    input >> s.name;
    cout << "密码：";
    input >> s.password;
    return input;


}

