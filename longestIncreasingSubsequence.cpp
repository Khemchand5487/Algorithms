#include <bits/stdc++.h>

using namespace std;

//Longest Increasing subsequence in O(n*n) time complexity
int LIS(vector<int> arr, int n)
{
    vector<int> dp(n, 0);
    
    int curr, maxLen = 0;
    for(int i=0;i<n;i++)
    {
        curr = 0;
        for(int j=0;j<i;j++)
        {
            if(arr[j]< arr[i])
            {
                curr = max(curr, dp[j]);
            }
        }
        dp[i] = curr + 1;
        maxLen = max(dp[i], maxLen);
    }
    return maxLen;
}

//Longest Increasing subsequence in O(n*logn) time complexity
int LIS2(vector<int> arr, int n)
{
    vector<int> lis;
    lis.push_back(arr[0]);
    for(int i=1;i<n;i++)
    {
        auto idx = lower_bound(lis.begin(), lis.end(), arr[i]);
        if(idx == lis.end()) lis.push_back(arr[i]);
        else *idx = arr[i];
    }
    return lis.size();
}

int main()
{
    vector<int> arr = {10, 22, 9, 33, 21, 50, 41, 60};
    int n = arr.size();
    
    cout<<"Length of longest increasing subsequence: "<<LIS(arr, n)<<endl;
    cout<<"Length of longest increasing subsequence: "<<LIS2(arr, n)<<endl;

    return 0;
}
