/*
387. First Unique Character in a String ( Easy )

Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1. 

Example 1:
Input: s = "leetcode"
Output: 0

Example 2:
Input: s = "loveleetcode"
Output: 2

Example 3:
Input: s = "aabb"
Output: -1
 
Constraints:

1 <= s.length <= 105
s consists of only lowercase English letters.
*/

#include<bits/stdc++.h>
using namespace std;

int firstUniqChar(string s) {
    unordered_map <char,int> mp;
    int n=s.size();
    mp[s[0]]=-1;
    for(int i=1;i<n;i++){
        if(mp.find(s[i])==mp.end()) mp[s[i]] = i;
        else{
            mp[s[i]]=0;
        }
    }
    int ans=INT_MAX;
    for(auto a:mp){
        if(a.second!=0){
            if(a.second==-1) ans=0;
            else ans=min(a.second,ans);
        } 
    }
    return ans==INT_MAX? -1 : ans;
}

int main(){
    string s;cin>>s;
    cout<<firstUniqChar(s)<<endl;
    return 0;
}