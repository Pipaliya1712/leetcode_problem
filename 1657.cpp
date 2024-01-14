/*
1657. Determine if Two Strings Are Close ( Medium )

Two strings are considered close if you can attain one from the other using the following operations:
Operation 1: Swap any two existing characters.
For example, abcde -> aecdb
Operation 2: Transform every occurrence of one existing character into another existing character, and do the same with the other character.
For example, aacabb -> bbcbaa (all a's turn into b's, and all b's turn into a's)
You can use the operations on either string as many times as necessary.
Given two strings, word1 and word2, return true if word1 and word2 are close, and false otherwise.

Example 1:
Input: word1 = "abc", word2 = "bca"
Output: true
Explanation: You can attain word2 from word1 in 2 operations.
Apply Operation 1: "abc" -> "acb"
Apply Operation 1: "acb" -> "bca"

Example 2:
Input: word1 = "a", word2 = "aa"
Output: false
Explanation: It is impossible to attain word2 from word1, or vice versa, in any number of operations.

Example 3:
Input: word1 = "cabbba", word2 = "abbccc"
Output: true
Explanation: You can attain word2 from word1 in 3 operations.
Apply Operation 1: "cabbba" -> "caabbb"
Apply Operation 2: "caabbb" -> "baaccc"
Apply Operation 2: "baaccc" -> "abbccc"
 

Constraints:

1 <= word1.length, word2.length <= 105
word1 and word2 contain only lowercase English letters.
*/
#include<bits/stdc++.h>
using namespace std;

bool closeStrings(string word1, string word2) {
    if(word1.size()!=word2.size()) return false;
    sort(word1.begin(),word1.end());
    sort(word2.begin(),word2.end());
    vector<char> v1,v2;
    int t1=1,t2=1;
    vector<int> i1,i2;
    v1.push_back(word1[0]);
    v2.push_back(word2[0]);
    for(int i=1;i<word1.size();i++){
        if(word1[i]!=word1[i-1]) {
            v1.push_back(word1[i]);    
            i1.push_back(t1);
            t1=1;
        }
        else{
            t1++;
        }
        if(word2[i]!=word2[i-1]){
            v2.push_back(word2[i]);
            i2.push_back(t2);
            t2=1;
        }
        else{
            t2++;
        } 
    }
    i1.push_back(t1);
    i2.push_back(t2);
    if(v1!=v2) return false;
    sort(i1.begin(),i1.end());
    sort(i2.begin(),i2.end());
    if(i1!=i2) return false;
    return true;
}

int main(){
    string word1,word2;
    cin>>word1>>word2;
    cout<< closeStrings(word1,word2) <<endl; 
    return 0;
}