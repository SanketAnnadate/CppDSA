#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void print(vector<int> &nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
}

void printVV(vector<vector<int>> &nums)
{
    cout << endl;
    for (int i = 0; i < nums.size(); i++)
    {
        vector<int> temp = nums[i];
        cout << temp[0] << " " << temp[1] << endl;
    }
}

bool custComp(int &a, int &b)
{
    return a < b; // for increasing order
    return a > b; // for decreasing order
}

bool custCompVV(vector<int>&a, vector<int>&b){
    return a[1] < b[1]; // sorting according to the indexs in the nested vector
}



int main()
{
    vector<int> nums = {3, 5, 67, 3, 3, 2, 67, 8, 86, 53, 5, 6};
    print(nums);
    // sort(nums.begin(), nums.end());
    sort(nums.begin(), nums.end(), custComp);
    cout << endl;
    print(nums);

    vector<vector<int>> vv;
    vector<int> v;

    vv.push_back({0, 5});
    vv.push_back({6, 88});
    vv.push_back({7, 9});
    vv.push_back({56, 4});
    vv.push_back({1, 6});

    printVV(vv);

    sort(vv.begin(), vv.end());
    sort(vv.begin(), vv.end(),custCompVV);

    printVV(vv);
}