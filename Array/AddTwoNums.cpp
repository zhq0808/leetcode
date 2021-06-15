/*
 * @descripttion: leetcode 1.两数之和
 * @param: 
 * @return: 
 */
#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
vector<int> twoSum(vector<int> &nums, int target)
{
    vector<int> index;
    if (nums.size() < 0)
    {
        return index;
    }
    for (int i = 0; i < nums.size() - 1; i++)
    {
        for (int j = i + 1; j < nums.size(); j++) //注意符号是< 不是 <=
        {
           if (nums[i] + nums[j] == target)
            {
                index.push_back(i);
                index.push_back(j);
            }
        }
    }
    return index;
}
int main()
{
    vector<int> arr;
    vector<int> result;
    int size;
    cout<<"数组大小："<<endl;
    cin>>size;
    int num; 
    cout<<"数组中元素："<<endl;
    for(int i = 0; i < size; i++){
        cin>>num;
        arr.push_back(num);
    }
    int target;
    cout<<"目标和："<<endl;
    cin>>target;
    result = twoSum(arr, target);
    cout<<"最终结果："<<endl;
    for(int i = 0; i < 2; i++){
        cout<<result[i]<<" ";
    }
    cout<<endl;
}