/*
645. Set Mismatch ( Easy )

You have a set of integers s, which originally contains all the numbers from 1 to n. Unfortunately, due to some error, one of the numbers in s got duplicated to another number in the set, which results in repetition of one number and loss of another number.
You are given an integer array nums representing the data status of this set after the error.
Find the number that occurs twice and the number that is missing and return them in the form of an array.

Example 1:
Input: nums = [1,2,2,4]
Output: [2,3]

Example 2:
Input: nums = [1,1]
Output: [1,2]
 
Constraints:

2 <= nums.length <= 104
1 <= nums[i] <= 104
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> findErrorNums(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    int n=nums.size();
    vector<int> ans(2);
    vector<int> temp(n,-1);
    for(int i=0;i<n-1;i++){
        if(nums[i]==nums[i+1]){
            ans[0]=nums[i];
        } 
        temp[nums[i]-1]=0;
    }
    temp[nums[n-1]-1]=0;
    for(int i=0;i<n;i++){
        if(temp[i]==-1) ans[1]=i+1; 
    }
    return ans;
}

int main(){
    int n;cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    vector<int> ans(2);
    ans = findErrorNums(nums);
    cout<<ans[0]<<" "<<ans[1]<<endl;
    return 0;
}