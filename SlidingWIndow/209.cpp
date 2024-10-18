#include <bits/stdc++.h>
using namespace std;

int minSubArrayLen(int target, vector<int> &nums)
{
    int curr = 0;
    int minSize = INT_MAX;
    int l = 0, r = 0;
    for (r = 0; r < nums.size(); r++)
    {
        curr += nums[r];
        if (curr >= target)
        {
            while (curr > target)
            {
                minSize = min(minSize, r - l + 1);
                curr = curr - nums[l];
                l++;
            }
        }
    }
    return minSize == INT_MAX ? 0 : minSize;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5};
    int target = 11;
    cout << minSubArrayLen(target, nums); // Output the result

    return 0;
}
