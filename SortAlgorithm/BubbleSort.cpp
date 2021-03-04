#include <iostream>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;

/**
 * 交换两个数的值
 */
void swap(int &num1, int& num2){
    int tmp = num1;
    num1 = num2;
    num2 = tmp;
}

/**
 * 获取数组的长度
 */
int getArrSize(int arr[]){
    return (int)sizeof(* arr)/(int)sizeof(arr[0]);
}

/**
 * 算法名：冒泡排序
 * 过程：从0到N-1依次比较相邻两个数的大小，如果arr[i]>arr[j]交换相邻的两个数，使得最大的数放置在N-1位置出
 */
void bubbleSort(vector<int> &arrTest){
    for(int i = arrTest.size() - 1; i >=0; i--){
        for(int j = 0; j < i; j++){
            if(arrTest[j] > arrTest[j+1]){
                swap(arrTest[j],arrTest[j+1]);
            }
        }
    }
}

/**
 * 算法名：冒泡排序（指针数组）
 * 过程：从0到N-1依次比较相邻两个数的大小，如果arr[i]>arr[j]交换相邻的两个数，使得最大的数放置在N-1位置出
 */
int* bubbleSortInt(int* arr){
    for(int i = getArrSize(arr); i >=0; i--){
        for(int j = 0; j < i; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
    return arr;
}

/**
 * 算法名：生成随机数组(min~max)
 */
int* getRanDomArr0(int size, int min, int max, int* arrRandom){
    //vector<int> arrRandom;
    for(int i = 0; i < size; i++){
        arrRandom[i] = (rand()%(max - min + 1))+min;
    }
    return arrRandom;
} 

/**
 * 算法名：生成随机数组(min~max)
 */
int* getRanDomArr(int size, int value, int* arrRandom){
    //vector<int> arrRandom;
    for(int i = 0; i < size; i++,arrRandom++){
        //使用减法这样就可以产生负数
        int var1 = rand()%value;
        int var2 = rand()%value;
        *arrRandom = var1 - var2;
    }
    return arrRandom;
}

/**
 * 算法名：判断两个数组是否相等
 */
bool compareTwoArr(int arr1[], int arr2[]){
    if((arr1 == nullptr && arr2 != nullptr) || (arr1 == nullptr && arr2 != nullptr)){
        return false;
    }

    int arr1_size = getArrSize(arr1);
    int arr2_size = getArrSize(arr2);

    if(arr1_size != arr2_size){
        return false;
    }

    for(int i = 0; i < arr1_size; i++){
        if(arr1[i] != arr2[i]){
            return false;
        }
    }
    return true;
}

/**
 * 算法名：生成随机数组(min~max)
 */
void printArr(int arr[]){
    int arr_size = getArrSize(arr);
    for(int i = 0; i < arr_size; i++){    
        cout<< arr[i] <<endl;
    }
}

/**
 * 算法名：复制一个数据
 */
int* copyArr(int arr[],int *newArr){
    //如果在函数内部用malloc申请空间的话，在return的时候空间是否就被释放了？
    for(int i = 0; i < getArrSize(arr); i++){
        newArr[i] = arr[i];
    }
    return newArr;
}


int main(){
    /* int times = 1;
    while(times--){
        cout<<"nice!!"<<endl;
        //生成随机数组
        int* testArr = nullptr;
        testArr = getRanDomArr(10, 10, testArr);
        //复制随机数组
        int* testArr1 = nullptr;
        testArr1 = copyArr(testArr, testArr1);
        int* testArr2 = nullptr;
        testArr2 = copyArr(testArr, testArr2);
        //使用冒泡排序
        int* bubbleSortResult = bubbleSortInt(testArr1);
        //使用系统自带算法
        sort(testArr2,testArr2 + getArrSize(testArr2));
        //比较数组
        if(!compareTwoArr(bubbleSortResult,testArr2)){
            printArr(bubbleSortResult);
            printf("/n");
        }else{
            cout<<"nice!!"<<endl;
        }
    }  */

    cout<<"nice!!"<<endl;
    //1. 随机生成一个数组
    int* testArr = nullptr;
    testArr = getRanDomArr(10, 10, testArr);
    //2. 输出数组
    printArr(testArr);
    //3. 排序
    int* sortArr =  bubbleSortInt(testArr);
    //2. 输出数组
    printArr(sortArr);

    return 0;
}


