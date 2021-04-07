/*
 * @Author: your name
 * @Date: 2021-03-11 23:52:48
 * @LastEditTime: 2021-03-16 21:47:35
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /leetcode/SortAlgorithm/SelectSort.cpp
 */
#include<iostream>
#include "LogrithmToolOfAarrySort.h"
using namespace std;
LogrithmToolOfAarrySort logrithm;
int* SelectSort(int arr[], int size){
    for(int i = size - 1; i >= 0; i--){
        for(int j = 0; j <= i; j++){
            if(arr[j] > arr[i] ){
                logrithm.swap(arr[j],arr[i]);
            }
        }
    }
    return arr;
}
int main(){
    int testTimes;
    cin>>testTimes;
    while (testTimes--)
        {
            int arrSize = 1000;
            int arrValue = 10000000;
            //随机生成一个数组
            int *originArr = logrithm.getRanDomArr(arrSize, arrValue);
            //复制随机数组,用于自定义算法排序
            int *selfSortArr = logrithm.copyArr(originArr, arrSize);
            //复制随机数组,用于系统自带算法排序
            int *systemSortArr = logrithm.copyArr(originArr, arrSize);
            //printArr(newArr1,size);
            int *newArr2 = logrithm.copyArr(originArr, arrSize);
            //因为是用new进行数组的初始化，因此需要delete掉
            delete originArr;
            //使用系统自带算法
            sort(systemSortArr, systemSortArr + arrSize);
            int *sortResult = SelectSort(selfSortArr, arrSize);
            //比较数组
            if (!logrithm.compareTwoArr(sortResult, systemSortArr, arrSize))
            {
                cout << "------------err-----------" << endl;
                cout << "原数组：" << endl;
                logrithm.printArr(newArr2, arrSize);
                cout << "正确结果：" << endl;
                logrithm.printArr(systemSortArr, arrSize);
                cout << "排序算法结果：" << endl;
                logrithm.printArr(sortResult, arrSize);
                cout << "------------err-----------" << endl;
                break; //如果结果不对，则跳出循环，结束测试
            }
            else
            {
                cout << "------------nice-----------" << endl;
                cout << "原数组：" << endl;
                logrithm.printArr(newArr2, arrSize);
                cout << "排序算法结果：" << endl;
                logrithm.printArr(sortResult, arrSize);
                cout << "正确结果：" << endl;
                logrithm.printArr(systemSortArr, arrSize);
                cout << "------------nice-----------" << endl;
            }
        }
    return 0;
}