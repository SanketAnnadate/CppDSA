#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
// Q.532 LC
int kDiff_1(vector<int> &arr, int s)
{
    set<pair<int, int>> ans;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr.size(); j++)
        {
            // int k = abs();
            if (i != j && arr[i] - arr[j] == s)
            {
                ans.insert({arr[i], arr[j]});
            }
        }
    }
    return ans.size();
}

int kDiff_2(vector<int> &nums, int k)
{
    set<pair<int, int>> ans;
    int i = 0;
    int j = 1;
    sort(nums.begin(), nums.end());
    while (j < nums.size())
    {
        int diff = nums[j] - nums[i];
        if (diff == k)
        {
            ans.insert({nums[i], nums[j]});
            i++;
            j++;
        }
        else if (diff > k)
        {
            i++;
        }
        else
        {
            j++;
        }
        if (i == j)
            j++;
    }
    return ans.size();
}

int bs(vector<int> &nums, int start, int k)
{
    int end = nums.size() - 1;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (nums[mid] == k)
        {
            return mid;
        }
        else if (nums[mid] > k)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return -1;
}

int kDiff_3(vector<int> &nums, int k)
{
    set<pair<int, int>> ans;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++)
    {
        if (bs(nums, i + 1, nums[i] + k) != -1)
        {
            ans.insert({nums[i], nums[i] + k});
        }
    }
    return ans.size();
}

int main()
{
    vector<int> nums = {1, 1, 3, 4, 6, 9};
    int kDiff = 2;
    cout << "K Diff : " << kDiff_1(nums, kDiff) << endl;
    cout << "K Diff : " << kDiff_2(nums, kDiff) << endl;
    cout << "K Diff : " << kDiff_3(nums, kDiff) << endl;
}