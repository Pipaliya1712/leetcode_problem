/*
1239. Maximum Length of a Concatenated String with Unique Characters ( Medium )

You are given an array of strings arr. A string s is formed by the concatenation of a subsequence of arr that has unique characters.
Return the maximum possible length of s.
A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.

Example 1:
Input: arr = ["un","iq","ue"]
Output: 4
Explanation: All the valid concatenations are:
- ""
- "un"
- "iq"
- "ue"
- "uniq" ("un" + "iq")
- "ique" ("iq" + "ue")
Maximum length is 4.

Example 2:
Input: arr = ["cha","r","act","ers"]
Output: 6
Explanation: Possible longest valid concatenations are "chaers" ("cha" + "ers") and "acters" ("act" + "ers").

Example 3:
Input: arr = ["abcdefghijklmnopqrstuvwxyz"]
Output: 26
Explanation: The only string in arr has all 26 characters.
 
Constraints:

1 <= arr.length <= 16
1 <= arr[i].length <= 26
arr[i] contains only lowercase English letters.
*/

#include<bits/stdc++.h>
using namespace std;

bool hasCommon(string &s1, string& s2) {
    int arr[26] = {0};
    for(char &ch : s1) {
        if(arr[ch-'a'] > 0)
            return true;
        arr[ch-'a']++;
    }
    for(char &ch : s2) {
        if(arr[ch-'a'] > 0)
            return true;
    }
    return false;
}
unordered_map<string, int> mp;
int solve(int idx, vector<string>& arr, string temp, int n) {
    if(idx >= n)
        return temp.length();
    if(mp.find(temp) != mp.end())
        return mp[temp];
    int include = 0;
    int exclude = 0;
    if(hasCommon(arr[idx], temp)) {
        exclude = solve(idx+1, arr, temp, n);
    } else {
        exclude = solve(idx+1, arr, temp, n);
        temp += arr[idx];
        include = solve(idx+1, arr, temp, n);
    }
    return mp[temp] = max(include, exclude);
}
int maxLength(vector<string>& arr) {
    string temp = "";
    mp.clear();
    int n = arr.size();
    return solve(0, arr, temp, n);
}

int main(){
    int n;cin>>n;
    vector<string> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    cout<<maxLength(nums)<<endl;

    return 0;
}