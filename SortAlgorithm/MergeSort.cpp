/*
 * @descripttion: 
 * @param: 
 * @return: 
 */
/*
 * @descripttion: 
 * @param: 
 * @return: 
 */
#include<iostream>
#include<vector>
#include "LogrithmToolOfAarrySort.h"
LogrithmToolOfAarrySort logrithm;
using namespace std;
void merge(vector<int> &arr, int left, int mid, int right){
    //主要是merge进行排序，可以以最小的递归子问题进行尝试
    //比如排序 5，4，8，9，7.其中最小的递归子问题：5， 5跟自身比较还是5.
    //当left为0，right为1的时候，比较的就是5，4.  那么关键将5，4这两个子序列merge起来
    vector<int> arrTemp;
    int leftIndex = left; //左边数组的下标
    int rightIndex = mid + 1; //右边数组的下标
    while (leftIndex <= mid && rightIndex <= right) //不是||，而是&&
    {
        if(arr[leftIndex] <= arr[rightIndex]){
            arrTemp.push_back(arr[leftIndex]);
            leftIndex++;
        }
        if(arr[leftIndex] > arr[rightIndex]){
            arrTemp.push_back(arr[rightIndex]);
           rightIndex++;
        }
    }
    //两个必有且只有一个
    while(leftIndex <= mid){
        arrTemp.push_back(arr[leftIndex]);
        leftIndex++;
    }
    while(rightIndex <= right){
        arrTemp.push_back(arr[rightIndex]);
        rightIndex++;
    }
    for(int i = 0; i < arrTemp.size(); i++){ //注意赋值的时候，arrTemp是从0开始，而不是left开始
        arr[left+i] = arrTemp[i];
    }
}
//归并排序，主要是：子问题怎么合并
void sortProcess(vector<int> &arr, int left, int right){
    if(left == right){
        return ;
    }
    int mid = left + (right - left)/2; //错了，应该是(right + left) / 2
    sortProcess(arr, left, mid); //先排左边  T(N/2)
    sortProcess(arr, mid + 1, right); //再排右边  T(N/2)
    merge(arr, left, mid, right); //O(N)
}

vector<int> mergeSort(vector<int> arr){
    if(arr.size() <= 1){
        return arr;
    }
    sortProcess(arr, 0, arr.size() - 1);
    return arr;
}
int main(){
    int testTimes;
    cout<<"请输入比较次数"<<endl;
    cin>>testTimes;
    while (testTimes--)
        {
            int arrSize = 5;
            int arrValue = 10;
            //随机生成一个数组
            vector<int> originArr = logrithm.getArr(arrSize, arrValue);
            //复制随机数组,用于自定义算法排序
            vector<int> selfSortArr = logrithm.copyArr(originArr);
            //复制随机数组,用于系统自带算法排序
            vector<int> systemSortArr = logrithm.copyArr(originArr);
            //printArr(newArr1,size);
            vector<int> newArr2 = logrithm.copyArr(originArr);
            //因为是用new进行数组的初始化，因此需要delete掉
            //使用系统自带算法
            sort(systemSortArr.begin(), systemSortArr.end());
            logrithm.printArr(systemSortArr);
            vector<int> sortResult = mergeSort(selfSortArr);
            logrithm.printArr(sortResult);
            //比较数组
            if (!logrithm.compArr(sortResult, systemSortArr))
            {
                cout << "------------err-----------" << endl;
                cout << "原数组：" << endl;
                logrithm.printArr(newArr2);
                cout << "正确结果：" << endl;
                logrithm.printArr(systemSortArr);
                cout << "排序算法结果：" << endl;
                logrithm.printArr(sortResult);
                cout << "------------err-----------" << endl;
                break; //如果结果不对，则跳出循环，结束测试
            }
            else
            {
                cout << "------------nice-----------" << endl;
                cout << "原数组：" << endl;
                logrithm.printArr(newArr2);
                cout << "排序算法结果：" << endl;
                logrithm.printArr(sortResult);
                cout << "正确结果：" << endl;
                logrithm.printArr(systemSortArr);
                cout << "------------nice-----------" << endl;
            }
        }
    return 0;
}