#include <bits/stdc++.h>
using namespace std;

int longestSubarray(vector<int> &nums)
{
    int n = nums.size();
    int zero = 0;
    int maxLen = 0;
    int left = 0, right = 0;
    for (right = 0; right < n; right++)
    {
        if (nums[right] == 0)
            zero++;

        while (zero > 1)
        {
            if (nums[left] == 0)
            {
                zero--;
            }
            left++;
        }
        maxLen = max(maxLen, right - left);
    }

    return maxLen;
}
int main()
{
    vector<int> nums = {1, 1, 1, 1, 1, 1, 0};
    cout << longestSubarray(nums) << endl; // Output will be 5
    return 0;
}
