#include <bits/stdc++.h>
using namespace std;
int minimax(vector<int> nums, int left, int right, unordered_map<string, int> &memo)
{
    if (left > right)
        return 0;
    string key = to_string(left) + "," + to_string(right);

    if (memo.count(key))
    {
        return memo[key];
    }

    int pickLeft = nums[left] - minimax(nums, left + 1, right, memo);
    int pickRight = nums[right] - minimax(nums, left, right - 1, memo);

    int res = max(pickLeft, pickRight);
    memo[key] = res;

    return memo[key];
}
bool predictTheWinner(vector<int> &nums)
{
    unordered_map<string, int> memo;
    int scoreDifference = minimax(nums, 0, nums.size() - 1, memo);
    return scoreDifference >= 0;
}
int main()
{
    vector<int> nums = {1, 5, 233, 7};
    cout << predictTheWinner(nums);
    return 0;
}