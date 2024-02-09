/*
368. Largest Divisible Subset ( Medium )
Given a set of distinct positive integers nums, return the largest subset answer such that every pair (answer[i], answer[j]) of elements in this subset satisfies:
answer[i] % answer[j] == 0, or
answer[j] % answer[i] == 0
If there are multiple solutions, return any of them.

Example 1:
Input: nums = [1,2,3]
Output: [1,2]
Explanation: [1,3] is also accepted.

Example 2:
Input: nums = [1,2,4,8]
Output: [1,2,4,8]
 
Constraints:

1 <= nums.length <= 1000
1 <= nums[i] <= 2 * 109
All the integers in nums are unique.
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> largestDivisibleSubset(vector<int>& nums) {
    if (nums.size() == 0) return {};
    sort(nums.begin(), nums.end());
    vector<int> dp(nums.size(), 1); 
    vector<int> prev_index(nums.size(), -1);
    int maxi = 0;
    for (int i = 1; i < nums.size(); i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
                prev_index[i] = j;
                if (dp[i] > dp[maxi]) {
                    maxi = i; 
                }
            }
        }
    }
    vector<int> result;
    while (maxi >= 0) {
        result.push_back(nums[maxi]);
        maxi = prev_index[maxi];
    }
    reverse(result.begin(), result.end());
    return result;
}

int main(){
    int n;cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++) cin>>nums[i];
    vector<int> ans;
    ans = largestDivisibleSubset(nums);
    for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
    cout<<endl;
    return 0;
}