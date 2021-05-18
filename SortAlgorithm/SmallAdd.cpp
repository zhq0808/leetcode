/*
 * @descripttion: 
 * @param: 
 * @return: 
 */
/*
 * @descripttion: 小和问题
 * @param: 
 * @return: 
 */
#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
/**
 * @desc: 
 * @param {int} index
 * @return {*}
 */
int addSum(int indexLeft, int indexRight){
    if(indexLeft == indexRight){
        return 0; //如果序列只有一个数，则返回最小和为0
    }
    
    return addSum(indexLeft, indexRight - 1) + addSum(indexLeft, indexRight);
}

int getSum(int indexLeft, int indexRight, vector<int> arr){
    if(indexLeft == indexRight){
        return 0;
    }
    if(indexLeft == indexRight - 1){ //如果是两个数
        if(arr[indexLeft] < arr[indexRight]){
            return arr[indexLeft];
        }else{
            return 0;
        }
    }
    return getSum(indexLeft, indexRight - 1, arr) + getSum(indexLeft, indexRight, arr);
}
int main(){
    
}
