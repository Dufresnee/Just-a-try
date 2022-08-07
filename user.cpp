#include"user.h"
#include"city.h"
extern vector<float> max;
extern vector<float> min;
extern vector<float> aver;
extern vector<float> capacity;//������




void user::cityadd() {
	city newcity;
    int i;
    float a;
    cout << "������绰����:" << endl;
    cin >> newcity.phonenum;
    cout << "�������������:"<<endl;
    cin >> newcity.name;
    cout << "���������ʮ���������:";
    for (i = 0; i < 30; i++) {
        cin >> a;
        newcity.min.push_back(a);
    }
    cout << "���������ʮ��ƽ������:";
    for (i = 0; i < 30; i++) {
        cin >> a;
        newcity.aver.push_back(a);
    }
    cout << "���������ʮ���������:";
    for (i = 0; i < 30; i++) {
        cin >> a;
        newcity.max.push_back(a);
    }
    cout << "���������ʮ�콵ˮ��:";
    for (i = 0; i < 30; i++) {
        cin >> a;
        newcity.capacity.push_back(a);
    }
    usercity.push_back(newcity);
    cout << "�������" << endl << "�����������";
    fflush(stdin);
    getchar();

}


void user::citymodify() {
    string b;
    int n = 0;
    size_t i;
    float a;
    cout << "��������Ҫ�޸ĵĳ������ƻ��ߵ绰����";
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
        cout << "δ�ҵ��ó���" << endl;
        cout << endl << "�����������";
        return;
    }
    else
    {
        cout << "�������������:" << endl;
        cin >> usercity[n].name;
        cout << "������绰����:";
        cin >> usercity[n].phonenum;
        cout << "���������ʮ����������������:";
        for (i = 0; i < 30; i++) {
            cin >> a;
            usercity[n].min.push_back(a);
        }
        cout << "���������ʮ���������ƽ������:";
        for (i = 0; i < 30; i++) {
            cin >> a;
            usercity[n].aver.push_back(a);
        }
        cout << "���������ʮ����������������:";
        for (i = 0; i < 30; i++) {
            cin >> a;
            usercity[n].max.push_back(a);
        }
        cout << "���������ʮ����н�ˮ��:";
        for (i = 0; i < 30; i++) {
            cin >> a;
            usercity[n].capacity.push_back(a);
        }
        cout << "�޸����" << endl << "�����������";
        fflush(stdin);
        getchar();
    }

}


void user::citydelete() {
    string b;
    int n = 0;
    size_t i;
    char a;
    cout << "��������Ҫɾ���ĳ������ƻ��ߵ绰����";
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
        cout << "δ�ҵ��ó���" << endl;
        return;
    }
    else {
        cout << "��ȴҪɾ���ó���������(Y/N)?" << endl;
        cin >> a;
        if (a == 'Y' || a == 'y') {
            usercity.erase(usercity.begin() + n);
            cout << "ɾ�����";
        }
        else if (a == 'N' || a == 'n')
            cout << "ɾ��ȡ��";
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

        cout << endl << "|" << "����ʮ���������" << endl;
        for (j = 0; j < 30; j++) {
            cout << setw(4) << usercity[i].min[j] << " ";
        }
        cout << endl << "|" << "����ʮ��ƽ������" << endl;
        for (j = 0; j < 30; j++) {
            cout << setw(4) << usercity[i].aver[j] << " ";
        }
        cout << endl << "|" << "����ʮ���������" << endl;
        for (j = 0; j < 30; j++) {
            cout << setw(4) << usercity[i].max[j] << " ";
        }
        cout << endl << "|" << "����ʮ�콵ˮ��" << endl;
        for (j = 0; j < 30; j++) {
            cout << setw(4) << usercity[i].capacity[j] << " ";
        }
        cout << endl << "|" << "Ԥ��ƽ������" << endl;
        cout << usercity[i].predictedtemperature;
    }
    cout << endl << "�����������" << endl;
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
    cout << "�ѱ��棬�����������" << endl;
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
    cout << "�����û����ݣ�" << endl;
    cout << "�û�����";
    input >> s.name;
    cout << "���룺";
    input >> s.password;
    return input;


}

