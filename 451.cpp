/*
451. Sort Characters By Frequency ( Medium )

Given a string s, sort it in decreasing order based on the frequency of the characters. The frequency of a character is the number of times it appears in the string.
Return the sorted string. If there are multiple answers, return any of them.

Example 1:
Input: s = "tree"
Output: "eert"
Explanation: 'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.

Example 2:
Input: s = "cccaaa"
Output: "aaaccc"
Explanation: Both 'c' and 'a' appear three times, so both "cccaaa" and "aaaccc" are valid answers.
Note that "cacaca" is incorrect, as the same characters must be together.

Example 3:
Input: s = "Aabb"
Output: "bbAa"
Explanation: "bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.
 
Constraints:

1 <= s.length <= 5 * 105
s consists of uppercase and lowercase English letters and digits.
*/

#include<bits/stdc++.h>
using namespace std;

string frequencySort(string s) {
    unordered_map<char,int> m;
    int n=s.size();
    for(int i=0;i<n;i++) m[s[i]]++;
    vector<pair<int,char>> vp;
    for(auto it:m){
        vp.push_back({it.second,it.first});
    }
    s="";
    sort(vp.begin(),vp.end(),greater<pair<int, char>>());
    for(auto it: vp){
        while(it.first--) s+=it.second;
    }
    return s;
}

int main(){
    string s;
    cin>>s;
    cout<<frequencySort(s)<<endl;
    return 0;
}