// demo2.cpp: 定义控制台应用程序的入口点。
//


#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include<vector> 
using namespace std;



int main()
{
	ofstream fout("Coordinates.txt");     //创建一个data.txt的文件存地图灰度大于0的坐标

	vector<int> vecIntA;//所有地图数据
	vector<int> vecIntB;//大于0的坐标
	int *arr = new int[608 * 480];
	int *arr1 = arr;
	ifstream infile("data.txt");
	if (!infile.is_open())
	{
		cout << "Error opening file"; exit(1);
	}
	int count = 0;
	while (!infile.eof())
	{
		infile >> *arr1;
		arr1++;
		//++count;
	}
	int *arr2 = arr;

	//将地图数据存储到vector中
	for (int i = 0; i < 480; i++) {
		int k = i * 608;
		for (int j = 0; j < 608; j++)
		{
			vecIntA.push_back(*(arr2 + k + j));

			//将大于0的地图坐标放入vectorB中
			if (*(arr2 + k + j) > 0) {
				vecIntB.push_back(k + j);
			}
		}
	}
	int vectorACount = vecIntA.size();
	for (int i = 0; i < vectorACount; i++)
	{
		if (vecIntA[i] > 0) {
			vecIntA[i] = 1;
		}
		fout << vecIntA[i] << endl;  //将变量的值写入文件
	}

	int vectorBCount = vecIntB.size();
	cout << vectorBCount << endl;
	//
	for (int i = 0; i<vectorBCount; i++)
	{
		int my = vecIntB[i] / 608;
		int mx = vecIntB[i] - (my * 608);
		//fout << mx << endl;  //将变量的值写入文件
		//fout << my << endl;  //将变量的值写入文件

		//cout << "mx: " << mx << "\t";
		//cout << "my: " << my << endl;
	}
	fout.close();
	//system("pause");
    return 0;
}

