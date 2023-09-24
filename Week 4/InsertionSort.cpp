#include<iostream>
#include<vector>
using namespace std;

void insertionSort(vector<int>& nums){
    int size = nums.size();
    for (int i = 1; i < size; i++)
    {
        int temp = nums[i];
        int j = i-1;
        while (j>=0 && nums[j]> temp)
        {
            nums[j+1] = nums[j];
            j--;
        }
        nums[j+1] = temp;
    }
}

int main(){
    vector<int> nums = {3,5,67,3,3,2,67,8,86,53,5,6};

    insertionSort(nums);

    for (int i = 0; i < nums.size(); i++)
    {
        cout<<nums[i]<<" ";
    }
}