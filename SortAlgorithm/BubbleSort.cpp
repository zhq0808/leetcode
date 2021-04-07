#include <iostream>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <iterator>
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
 * 算法名：冒泡排序（指针数组）
 * 过程：从0到N-1依次比较相邻两个数的大小，如果arr[i]>arr[j]交换相邻的两个数，使得最大的数放置在N-1位置出
 */
int* bubbleSortInt(int arr[], int size){
    for(int i = size - 1; i >=0; i--){
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
int* getRanDomArr(int size, int value){
    //为什么这里不能直接写 int arr[size]; 因为返回值为int* ，如果说直接使用int arr[size]后，那么返回值的时候就有问题
    //int arr[size] 为局部变量，在函数结束的时候会释放其内存，所有不能去局部变量的*（地址）。但是可以取值，取值就是调用拷贝函数。
    int *arr = new int[size];   
    for(int i = 0; i < size; i++){
        //使用减法这样就可以产生负数
        int var1 = rand()%value;
        int var2 = rand()%value;
        arr[i] = var1 - var2;
    }
    return arr;
}


/**
 * 算法名：判断两个数组是否相等
 */
bool compareTwoArr(int arr1[], int arr2[], int size){
    for(int i = 0; i < size; i++){
        if(arr1[i] != arr2[i]){
            return false;
        }
    }
    return true;
}

/**
 * @desc: 打印数组
 * @param {int} arr
 * @param {int} size
 * @return {*}
 */
void printArr(int arr[], int size){
    //int arr_size = getArrSize(arr);
    for(int i = 0; i < size; i++){    
        cout<< arr[i] <<" ";
    }
    cout<<endl;  
}

/**
 * 算法名：复制一个数据
 */
int* copyArr(int arr[], int size){
    int *newArr = new int[size];
    //如果在函数内部用malloc申请空间的话，在return的时候空间是否就被释放了？
    for(int i = 0; i < size; i++){
        newArr[i] = arr[i];
    }
    return newArr;
}

int main(){
    int testTimes;
    cin>>testTimes;
    while(testTimes--){
        int size = 10;
        int value = 50000;
        //生成随机数组
        int* testArr = getRanDomArr(size, value);
        //printArr(testArr,size);
        //复制随机数组
        int* newArr = copyArr(testArr, size);
        //printArr(newArr,size);
        int* newArr1 = copyArr(testArr, size);
        //printArr(newArr1,size);
        int* newArr2 = copyArr(testArr, size);
        //printArr(newArr2,size);
        delete testArr;
        //使用冒泡排序
        int* bubbleSortResult = bubbleSortInt(newArr1, size);
        //使用系统自带算法
        sort(newArr,newArr + size);
        //比较数组
        if(!compareTwoArr(bubbleSortResult,newArr,size)){
            cout<<"------------err-----------"<<endl;
            cout<<"正确结果："<<endl;
            printArr(newArr,size);
            cout<<"排序算法结果："<<endl;
            printArr(bubbleSortResult,size);
            break; //如果结果不对，则跳出循环，结束测试
        }else{
            cout<<"------------nice-----------"<<endl;
            cout<<"原数组："<<endl;
            printArr(newArr2,size);
            cout<<"排序算法结果："<<endl;
            printArr(bubbleSortResult,size); 
            cout<<"正确结果："<<endl;
            printArr(newArr,size);
        }
    } 

    return 0;
}


