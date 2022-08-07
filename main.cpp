#include"admin.h"
#include"user.h"
#include"city.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <istream>
#include <iomanip>
#include<sstream>//使用string流


using namespace std;
admin ope("admin", "admin");
extern vector<user> users;
extern vector<city> usercity;

void _admin();
void userl(int a);

int userlogin1(vector<user> users);


int main()
{
    int  b;
    void userlogin();
    void _admin();
    void userl(int);
     void a1();
     void colormenu();

 A:   cout << "                      天气管理与预测系统" << endl;
    cout << "          ---------------------------------------------" << endl;
    cout << "          |                                           |" << endl;
    cout << "          |     1.管理员登录                          |" << endl;
    cout << "          |     2.用户登录                            |" << endl;
    cout << "          |     3.更换皮肤                            |" << endl;
    cout << "          |     0.退出系统                            |" << endl;
    cout << "          |                                           |" << endl;
    cout << "          ---------------------------------------------" << endl;
    cout << "请输入您想要执行的指令:" << endl;
    cin >> b;
    switch (b) {
    case 1: {
        userlogin();
    }
    case 2:
    {   int c;
        c = userlogin1(users);
        if (c = 0) { goto A; }
        else userl(c);
    }
    case 3: colormenu();
        goto A;
    break;

    default:
        exit(0);
    }
    return 0;
}

void userlogin()
{
    string a, b;
    int n=0;
    size_t i;
    cout << "请输入用户名" << endl;
    cin >> a;
    cout << "请输入密码" << endl;
    cin >> b;
    if (a == "admin" && b == "admin") {
        _admin();

    }

}

void _admin()
{
    int a;
    cout << "管理员登陆" << endl;
A:  cout << endl;
    cout << "          -----------------------------------------------------------------------" << endl;
    cout << "          |     1.用户添加                                                      |" << endl;
    cout << "          |     2.用户修改                                                      |" << endl;
    cout << "          |     3.用户删除                                                      |" << endl;
    cout << "          |     4.用户查看                                                      |" << endl;
    cout << "          |     0.返回上一级                                                    |" << endl;
    cout << "          -----------------------------------------------------------------------" << endl;
    cout << "请输入您想要执行的指令:";
    cin >> a;
    switch (a) {
    case 0:
        main();
    case 1:
        ope.useradd();
        goto A;
    case 2:
        ope.usermodify();
        goto A;
    case 3:
        ope.userdelete();
        goto A;
    case 4:
        ope.useroutput();
        goto A;
    default:
        cout << "请核对后重新输入指令~";
        goto A;
    }
}


int userlogin1(vector<user> users)
{
    string a, b;
    int n = 0;
    size_t i;
C:  cout << "请输入用户名" << endl;
    cin >> a;
    cout << "请输入密码" << endl;
    cin >> b;

        bool j = false;
        for (i = 0; i < 3; i++) {
            if ((a == users[i].name && b == users[i].password)) {
                n = i;
                j = true;
                break;
            }
            if ((a != users[i].name && b == users[i].password) ) {
                cout << "未找到该用户" << endl;
                cout << endl << "请重新输入" << endl;
                goto C;
            }
            if ((a == users[i].name && b != users[i].password)) {
                cout << "密码错误" << endl;
                cout << endl << "请重新输入" << endl;
                goto C;
            }
        }




    return n;
}






void userl(int a)
{
    int ins;
    cout << "用户登陆" << endl;
B:  cout << endl;
    cout << "        -----------------------------------------------------------------------------------" << endl;
    cout << "        |     1.城市添加                                                                  |" << endl;
    cout << "        |     2.城市修改                                                                  |" << endl;
    cout << "        |     3.城市删除                                                                  |" << endl;
    cout << "        |     4.天气预测                                                                  |" << endl;
    cout << "        |     5.打印功能                                                                  |" << endl;
    cout << "        |     6.信息保存                                                                  |" << endl;
    cout << "        |     0.返回上一级                                                                |" << endl;
    cout << "        -----------------------------------------------------------------------------------" << endl;
    cout << "请输入您想要执行的指令:";
    cin >> ins;
    switch (ins) {
    case 0:
        main();
    case 1:
        users[a].cityadd();
        goto B;
    case 2:
        users[a].citymodify();
        goto B;
    case 3:
        users[a].citydelete();
        goto B;
    case 4:
    {
        string b;
        int n = 0;
        size_t i = 0;
        bool j = false;
    D:           cout << "请输入你要预测的城市名称或电话区号";
        cin >> b;
        for (i = 0; i < users[a].name.size(); i++) {
            if (b == users[a].usercity[i].name || b == users[a].usercity[i].phonenum) {
                n = i;
                j = true;
                break;
            }
        }
        if (!j) {
            cout << "未找到该城市" << endl;
            cout << endl << "请重新输入" << endl;
            goto D;
        }
        else {
            users[a].usercity[n].predictedtemperature = users[a].usercity[n].foresee();
            goto B;
        }
    }
    case 5:
        users[a].cityoutput();
        goto B;
    case 6:
        users[a].usersave();
        goto B;
    default:
        cout << "请核对后重新输入指令~";
        goto B;
    }
}

void colormenu()
{
    string key;
    int m;
    cout << "\n\n";
    cout << "\t|———请选择一下您的主题颜色—|\n";
    cout << "\t|--------1.蓝底黑字------------|\n";
    cout << "\t|--------2.蓝底青字------------|\n";
    cout << "\t|--------3.黑底黄字------------|\n";
    cout << "\t|--------4.绿底红字------------|\n";
    cout << "\t|--------5.白底紫字------------|\n";
    cout << "\t|--------6.白底黑字------------|\n";
    cout << "\t|———————————————|\n";
    cout << "\n请输入你喜欢的颜色1~6:\n";
    m = 1;
    cin >> key;
    if (key.length() == 1)
        switch (key[0])
        {
        case '1':
            system("color 10");
            break;
        case '2':
            system("color 1a");
            break;
        case '3':
            system("color 06");
            break;
        case '4':
            system("color 24");
            break;
        case '5':
            system("color 75");
            break;
        case '6':
            system("color 70");
            break;
        default:
            printf("输入错误!\n");
            break;
        }
    else
        cout << "输入错误！" << endl;
}
