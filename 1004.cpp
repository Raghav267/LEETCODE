#include <bits/stdc++.h>
using namespace std;

int longestSubarray(vector<int> &nums, int k)
{
    int n = nums.size();
    int zero = 0;
    int maxLen = 0;
    int left = 0, right = 0;
    for (right = 0; right < n; right++)
    {
        if (nums[right] == 0)
            zero++;

        while (zero > k)
        {
            if (nums[left] == 0)
            {
                zero--;
            }
            left++;
        }
        maxLen = max(maxLen, right - left + 1);
    }

    return maxLen;
}
int main()
{
    vector<int> nums = {1, 1, 1, 1, 1, 1, 0};
    int k = 2;
    cout << longestSubarray(nums, k) << endl; // Output will be 5
    return 0;
}
