#include <bits/stdc++.h>
using namespace std;
// we are using memoziation
unordered_map<string, vector<int>> memo;
vector<int> diffWaysToCompute(string expression)
{
    // base case
    if (memo.count(expression))
    {
        return memo[expression];
    }

    vector<int> res;
    for (int i = 0; i < expression.length(); i++)
    {
        char ch = expression[i];

        if (ch == '+' || ch == '-' || ch == '*')
        {
            vector<int> left = diffWaysToCompute(expression.substr(0, i));
            vector<int> right = diffWaysToCompute(expression.substr(i + 1));

            for (int leftval : left)
            {
                for (int rightval : right)
                {
                    if (ch == '+')
                    {
                        res.push_back(leftval + rightval);
                    }
                    else if (ch == '-')
                    {
                        res.push_back(leftval - rightval);
                    }
                    else if (ch == '*')
                    {
                        res.push_back(leftval * rightval);
                    }
                }
            }
        }
    }
    if (res.empty())
    {
        res.push_back(stoi(expression));
    }
    // recursive case
    memo[expression] = res;
    return res;
}
int main()
{
    string expression = "2*3-4*5";
    vector<int> ans = diffWaysToCompute(expression);
    for (auto val : ans)
        cout << val << " ";
    return 0;
}