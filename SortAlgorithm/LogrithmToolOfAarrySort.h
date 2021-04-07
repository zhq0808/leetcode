/*
 * @Author: your name
 * @Date: 2021-03-11 23:54:55
 * @LastEditTime: 2021-03-16 21:46:22
 * @LastEditors: Please set LastEditors
 * @Description: 
 * 抽象的定义对数器 
 * 用于数组排序的对数器，主要实现的功能：
 * （1）随机生成一个数组，支持数组指针生成，容器数组生成
 * （2）比较绝对正确的算法和自己写的算法的结果
 * （3）输出结果差异
 * @FilePath: /leetcode/SortAlgorithm/Logarithm.cpp
 */
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
class LogrithmToolOfAarrySort
{
public:
    //用于判断数组类型：0:指针数组 1:vector容器数组
    //不需要类型说明，调用函数的时候，这个相当于重载函数
    //int type;

    /**
     * @desc: 获取随机数组
     * @param {int} size
     * @param {int} value
     * @return {*}
     */
    int *getRanDomArr(int size, int value)
    {
        //为什么这里不能直接写 int arr[size]; 因为返回值为int* ，如果说直接使用int arr[size]后，那么返回值的时候就有问题
        //int arr[size] 为局部变量，在函数结束的时候会释放其内存，所有不能去局部变量的*（地址）。但是可以取值，取值就是调用拷贝函数。
        //但是这里用new去分配内存空间了，后续需要用free去释放内存空间
        int *arr = new int[size];
        for (int i = 0; i < size; i++)
        {
            //使用减法这样就可以产生负数
            int var1 = rand() % value;
            int var2 = rand() % value;
            arr[i] = var1 - var2;
        }
        return arr;
    }

    /**
    * @desc: 判断两个数组是否相等
    * @param {int} arr1
    * @param {int} arr2
    * @param {int} size
    * @return {*}
    */
    bool compareTwoArr(int arr1[], int arr2[], int size)
    {
        for (int i = 0; i < size; i++)
        {
            if (arr1[i] != arr2[i])
            {
                return false;
            }
        }
        return true;
    }

    /**
     * @desc: 交换两个数
     * @param {int} &num1
     * @param {int} &num2
     * @return {*}
     */
    void swap(int &num1, int &num2)
    {
        int tmp = num1;
        num1 = num2;
        num2 = tmp;
    }

    /**
     * @desc: 打印数组
     * @param {int} &num1
     * @param {int} &num2
     * @return {*}
     */
    void printArr(int arr[], int size)
    {
        //int arr_size = getArrSize(arr);
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    /**
     * @desc: 复制数组
     * @param {int} arr
     * @param {int} size
     * @return {*}
     */
    int *copyArr(int arr[], int size)
    {
        int *newArr = new int[size];
        //如果在函数内部用malloc申请空间的话，在return的时候空间是否就被释放了？
        for (int i = 0; i < size; i++)
        {
            newArr[i] = arr[i];
        }
        return newArr;
    }

    /**
     * @desc: 打印vector数据
     * @param {vector<int>} arr
     * @return {*}
     */
    void printArr(vector<int> arr)
    {
        for (int i = 0; i < (int)arr.size(); i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    /**
     * @desc: 获取数组
     * @param {int} value
     * @param {int} length
     * @return {*}
     */
    vector<int> getArr(int value, int length)
    {
        vector<int> newArr;
        for (int i = 0; i < length; i++)
        {
            int var1 = rand() % value;
            int var2 = rand() % value;
            newArr.push_back(var2 - var1);
        }
        return newArr;
    }

    /**
     * @desc: 拷贝数组
     * @param {vector<int>} arr
     * @return {*}
     */
    vector<int> copyArr(vector<int> arr)
    {
        vector<int> newArr;
        for (int i = 0; i < (int)arr.size(); i++)
        {
            newArr.push_back(arr[i]);
        }
        return newArr;
    }

    /**
     * @desc: 比较数组
     * @param {vector<int>arr1,vector<int>} arr2
     * @return {*}
     */
    bool compArr(vector<int> arr1, vector<int> arr2)
    {
        int size1 = arr1.size();
        int size2 = arr2.size();
        if (size2 != size1)
        {
            return false;
        }
        for (int i = 0; i < size1; i++)
        {
            if (arr1[i] != arr2[i])
            {
                return false;
            }
        }
        return true;
    }
};