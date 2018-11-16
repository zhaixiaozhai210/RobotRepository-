#include <iostream>
#include <fstream>
#include <stdlib.h>
#include<vector>

using namespace std;


void saveCoordinates(vector<int> &vecIntB, const int *arr2);

void saveMapData(vector<int> &vecIntA, const int *arr2);

void obstacleCoordinate(std::vector<int> &vecIntB, int count);

void moreThanZero(vector<int> &vecIntA);

int main() {
    //ofstream fout("Coordinates.txt");     //创建一个data.txt的文件存地图灰度大于0的坐标

    vector<int> vecIntA;//所有地图数据
    vector<int> vecIntB;//大于0的坐标
    int *arr = new int[608 * 480];
    int *arr1 = arr;
    ifstream infile("data.txt");
    if (!infile.is_open()) {
        cout << "Error opening file";
        exit(1);
    }
    int count = 0;
    while (!infile.eof()) {
        infile >> *arr1;
        arr1++;
        //++count;
    }
    int *arr2 = arr;

    //将地图数据存储到vectorA中
    saveMapData(vecIntA, arr2);

    //将大于0的地图坐标放入vectorB中
    saveCoordinates(vecIntB, arr2);

    //将地图二值化处理，大于0的赋值为1
    moreThanZero(vecIntA);

    //角点检测
    int myCount = 0;
//    for (vector<int>::iterator iter = vecIntA.begin(); iter != vecIntA.end(); iter++) {
//        int k = 608;
//        int HarrisCount;
//        if (*iter == 1) {
//            HarrisCount = abs(*(iter + k) - *(iter + k - 1)) + abs(*(iter + k + 1) - *(iter + k)) + abs(*(iter + k + 2) - *(iter + k + 1))
//                          + abs(*(iter) - *(iter - 1)) + abs(*(iter + 1) - *(iter)) + abs(*(iter + 2) - *(iter + 1))
//                          + abs(*(iter - k) - *(iter - k - 1)) + abs(*(iter - k + 1) - *(iter - k)) + abs(*(iter - k + 2) - *(iter - k + 1));
//            if (HarrisCount >= 3){
//                cout<<myCount<<endl;
//            }
//        }
//        myCount++;
//    }

    for (int i = 0; i < 608 * 480; ++i) {
        int k = 608;
        int HarrisCount;
        if (vecIntA[i] == 1) {
            //right
            HarrisCount = abs(vecIntA[i + k] - vecIntA[i + k - 1]) +
                          abs(vecIntA[i + k + 1] - vecIntA[i + k]) +
                          abs(vecIntA[i + k + 2] - vecIntA[i + k + 1]) +
                          abs(vecIntA[i] - vecIntA[i - 1]) +
                          abs(vecIntA[i + 1] - vecIntA[i]) +
                          abs(vecIntA[i + 2] - vecIntA[i + 1]) +
                          abs(vecIntA[i - k] - vecIntA[i - k - 1]) +
                          abs(vecIntA[i - k + 1] - vecIntA[i - k]) +
                          abs(vecIntA[i - k + 2] - vecIntA[i - k + 1]);
            //right and top
            if (HarrisCount >= 3) {
                cout << myCount << endl;
            }
        }
        myCount++;
    }

    //打印障碍物坐标
    //obstacleCoordinate(vecIntB, count);

    //fout.close();
    return 0;
}

void moreThanZero(vector<int> &vecIntA) {
    for (vector<int>::iterator it = vecIntA.begin(); it != vecIntA.end(); it++) {
        if (*it > 0) {
            *it = 1;
        }
    }
}

void obstacleCoordinate(std::vector<int> &vecIntB, int count) {
    for (vector<int>::iterator it = vecIntB.begin(); it != vecIntB.end(); it++) {
        count++;
        int my = *it / 608;
        int mx = *it - (my * 608);
        cout << mx << "     ";
        cout << my << "     ";
        cout << endl;
    }
    cout << count << endl;
}

void saveMapData(vector<int> &vecIntA, const int *arr2) {
    for (int i = 0; i < 480; i++) {
        int k = i * 608;
        for (int j = 0; j < 608; j++) {
            vecIntA.push_back(*(arr2 + k + j));
        }
    }
}

void saveCoordinates(vector<int> &vecIntB, const int *arr2) {
    for (int i = 0; i < 480; i++) {
        int k = i * 608;
        for (int j = 0; j < 608; j++) {
            //将大于0的地图坐标放入vectorB中
            if (*(arr2 + k + j) > 0) {
                vecIntB.push_back(k + j);
            }
        }
    }
}