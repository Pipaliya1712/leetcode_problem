/*
49. Group Anagrams ( Medium )

Given an array of strings strs, group the anagrams together. You can return the answer in any order.
An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

Example 1:
Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

Example 2:
Input: strs = [""]
Output: [[""]]

Example 3:
Input: strs = ["a"]
Output: [["a"]]
 
Constraints:

1 <= strs.length <= 104
0 <= strs[i].length <= 100
strs[i] consists of lowercase English letters.
*/

#include<bits/stdc++.h>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {

    vector<vector<string>> ans;
    unordered_map<string,vector<string>> m;

    for(int i=0;i<strs.size();i++){
        string temp=strs[i];
        sort(temp.begin(),temp.end());
        m[temp].push_back(strs[i]);
    }
    for(auto it = m.begin();it!=m.end();it++){
        ans.push_back(it->second);
    }
    return ans;
}

int main(){
    int n;cin>>n;
    vector<string> strs(n);
    for(int i=0;i<n;i++) cin>>strs[i];
    vector<vector<string>> ans;
    ans=groupAnagrams(strs);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}