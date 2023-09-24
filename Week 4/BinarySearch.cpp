#include <iostream>
#include <vector>
using namespace std;

void print(vector<int> &nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
}

int bs(vector<int>& nums, int x){
    int size = nums.size();
    cout<<endl<<size<<endl;
    int start = 0;
    int end = size;

    while (start <= end)
    {
        int mid = start + (end - start);
        if(nums[mid] == x){
            return mid;
        }else if (nums[mid] < x)
        {
            start = mid + 1;
        }else{
            end = mid -1;
        }
    }
    return -1;
}

int main()
{
    vector<int> nums = {3, 5, 67, 3, 3, 2, 67, 8, 86, 53, 5, 6};
    print(nums);
    cout<<"thenumber is located at index : "<<bs(nums, 6)<<endl;
}