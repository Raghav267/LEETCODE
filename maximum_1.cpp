#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int maxCount = 0;
    if (arr[0] == 1)
        maxCount++;
    int inn = maxCount;

    for (int i = 1; i < n; i++)
    {
        if (arr[i] == 1)
        {
            if (arr[i - 1] == 1)
            {
                inn++;
                maxCount = max(maxCount, inn);
            }
            else
            {
                inn = 1;
            }
        }
    }
    cout << maxCount;
    return 0;
}