#include<iostream>
#include<vector>
using namespace std;

void selectionSort(vector<int>& nums){
    int size = nums.size();
    for (int  i = 0; i < size-1; i++)
    {
        int minNum = i;
        for (int  j = i + 1 ; j < size; j++)
        {
            if (nums[j] < nums[minNum])
            {
                minNum = j;
            }
            
        }
        swap(nums[i],nums[minNum]);
    }
    
}

int main(){
    vector<int> nums = {3,5,67,3,3,2,67,8,86,53,5,6};

    selectionSort(nums);

    for (int i = 0; i < nums.size(); i++)
    {
        cout<<nums[i]<<" ";
    }
}