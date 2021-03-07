/*
 * @Author: your name
 * @Date: 2021-03-07 18:54:22
 * @LastEditTime: 2021-03-07 20:35:47
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /leetcode/SortAlgorithm/BubbleSortVector.cpp
 */
#include<iostream>
#include<stdio.h>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;

/**
 * 打印数组
 */
void printArr(vector<int> arr){
    for(int i = 0; i < arr.size(); i++){
        cout<< arr[i]<<" ";
    }
    cout<<endl;
}

/**
 * 获取随机数数组
*/
vector<int> getArr(int value, int length){
    vector<int> newArr;
    for(int i = 0; i < length; i++){
        int var1 = rand()%value;
        int var2 = rand()%value;
        newArr.push_back(var2 - var1);
    }
    return newArr;
}

/**
 * 拷贝一个数组
*/
vector<int> copyArr(vector<int> arr){
    vector<int> newArr;
    for(int i = 0; i < (int)arr.size(); i++){
        newArr.push_back(arr[i]);
    }
    return newArr;
}

/**
 * 交换两个数
 */
void swapNum(int &num1, int &num2){
    int tmp  = num1;
    num1 = num2;
    num2 = tmp;
}

/**
 * 冒泡排序
 */
void BubbleSort(vector<int> &arr){
    for(int i = (int)arr.size() - 1; i >= 0; i--){  //先遍历n个数，然后遍历n-1个数……
        for(int j = 0; j < i; j++){
            if(arr[j] > arr[j+1]){
                swapNum(arr[j], arr[j+1]);
            }
        }
    }
}

/**
 * 判断两个数组是否相等
 */
bool compArr(vector<int> arr1, vector<int> arr2){
    int size1 = arr1.size();
    int size2 = arr2.size();
    if(size2 != size1){
        return false;
    }
    for(int i = 0; i < size1; i++){
        if(arr1[i] != arr2[i]){
            return false;
        }
    }
    return true;
}


int main(){
    int testTimes;
    cin>>testTimes;
    while(testTimes--){
        //随机构造一个数组
        vector<int> testArr =  getArr(1000, 300); //vector可以直接赋值吗？
        //复制得到一个新的数组
        vector<int> newArr  = copyArr(testArr); 
        sort(newArr.begin(), newArr.end()); //使用自带方法排序

        //复制得到一个新的数组
        vector<int> newArr1  = copyArr(testArr); 
        BubbleSort(newArr1);  //自己写的冒泡排序

        if(!compArr(newArr, newArr1)){  //排序结果不一致
            cout<<"------------err-----------"<<endl;
            cout<<"正确结果："<<endl;
            printArr(newArr);
            cout<<"排序算法结果："<<endl;
            printArr(newArr1);
            break; //如果结果不对，则跳出循环，结束测试
        }else{
            cout<<"------------suc-----------"<<endl;
            cout<<"原数组："<<endl;
            printArr(testArr);
            cout<<"排序算法结果："<<endl;
            printArr(newArr1); 
        }
    }
    return 0;
}