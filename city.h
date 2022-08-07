#pragma once
#pragma once
#include<iostream>
#include<string>
#include <vector>
#include <fstream>
#include <iomanip>

using namespace std;

class city {
public:
	string name;
	string phonenum;
	vector<float> max;
	vector<float> min;
	vector<float> aver;
	vector<float> capacity;//½µÓêÁ¿
	float predictedtemperature;
	float foresee();//ÆøÎÂÔ¤²â



};
