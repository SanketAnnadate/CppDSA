#include <iostream>
#include <vector>
using namespace std;
// 658. Find K Closest Elements

vector<int> findKClosestElements_1(vector<int> &arr, int k, int x)
{
    int l = 0;
    int h = arr.size() - 1;

    while (h - l >= k)
    {
        if (x - arr[l] < arr[h] - x || x - arr[l] == arr[h] - x)
        {
            h--;
        }
        else
        {
            l++;
        }
    }
    return vector<int>(arr.begin() + l, arr.begin() + h + 1);
}

int bs(vector<int>& nums, int k){
    int l = 0;
    int h = nums.size() - 1;
    int ans = h;;
    while (l<=h)
    {
        int mid = (l+h)/2;
        if(nums[mid] >= k){
            ans = mid;
            h = mid - 1;
        }else if (nums[mid] < k)
        {
            l = mid + 1;
        }else{
            h = mid -1;
        }
    }
    return ans;
}

vector<int> findKClosestElements_2(vector<int>& nums, int k, int x) {
    int h = bs(nums,x);
    int l = h-1;
    while (k--)
    {
        if (h >= nums.size())
        {
            l--;
        }else if (l < 0)
        {
            h++;
        }else if (x - nums[l] < nums[h] - x || x - nums[l] == nums[h] - x)
        {
            l--;
        }else{
            h++;
        } 
    }
    return vector<int>(nums.begin() + l +1, nums.begin() + h );
}

int main()
{
    vector<int> nums = {1, 1, 3, 4, 6, 9};
    vector<int> ans = findKClosestElements_1(nums, 3, 4);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    cout<<endl;

    vector<int> ans2 = findKClosestElements_2(nums, 3, 4);
    for (int i = 0; i < ans2.size(); i++)
    {
        cout << ans2[i] << " ";
    }
    
}