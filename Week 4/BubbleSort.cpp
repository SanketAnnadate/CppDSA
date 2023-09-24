#include<iostream>
#include<vector>
using namespace std;

void bubbleSort(vector<int>& nums){
    int size = nums.size();
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (nums[j] > nums[j+1])
            {
                swap(nums[j],nums[j+1]);
            }
            
        }
        
    }
    
}

int main(){
    vector<int> nums = {3,5,67,3,3,2,67,8,86,53,5,6};

    bubbleSort(nums);

    for (int i = 0; i < nums.size(); i++)
    {
        cout<<nums[i]<<" ";
    }
    
}