/*
 * @descripttion: 
 * @param: 
 * @return: 
 */
#include <iostream>
#include "LogrithmToolOfAarrySort.h"
using namespace std;
LogrithmToolOfAarrySort logrithm;
int* InsertSort(int arr[], int size){
    if(size <= 1){
      	return arr;
    }
  	for(int i = 1; i < size; i++){ //当前第i个数要往前插入，并且0～i上已经有序了
      for(int j = i - 1; j >= 0 && arr[j] > arr[j+1]; j--){
            swap(arr[j], arr[j+1]);  //为什么这里是j+1而不是i?因为在内层循环中j的值在--操作，i不变
      }
    }
    return arr;
}
int main(){
    int testTimes;
    cin>>testTimes;
    while (testTimes--)
        {
            int arrSize = 5;
            int arrValue = 10;
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
            int *sortResult = InsertSort(selfSortArr, arrSize);
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