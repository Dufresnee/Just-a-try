#include"city.h"
float city::foresee() {
    float t1 = 0, t2 = 0, t3 = 0, t4 = 0, a, b;

    for (size_t i = 0; i < aver.size(); i++)
    {
        t1 += i * i;
        t2 += i;
        t3 += i * aver[i];
        t4 += aver[i];
    }
    a = (t3 * aver.size() - t2 * t4) / (t1 * aver.size() - t2 * t2);
    b = (t1 * t4 - t2 * t3) / (t1 * aver.size() - t2 * t2);
    predictedtemperature = a * aver.size() + b;
    cout << "预测明天的平均气温为:" << predictedtemperature << endl;
    cout << "按任意键继续" << endl;
    return predictedtemperature;
    fflush(stdin);
    getchar();


}
