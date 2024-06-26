/*
1074. Number of Submatrices That Sum to Target ( Hard )

Given a matrix and a target, return the number of non-empty submatrices that sum to target.
A submatrix x1, y1, x2, y2 is the set of all cells matrix[x][y] with x1 <= x <= x2 and y1 <= y <= y2.
Two submatrices (x1, y1, x2, y2) and (x1', y1', x2', y2') are different if they have some coordinate that is different: for example, if x1 != x1'.

Example 1:
Input: matrix = [[0,1,0],[1,1,1],[0,1,0]], target = 0
Output: 4
Explanation: The four 1x1 submatrices that only contain 0.

Example 2:
Input: matrix = [[1,-1],[-1,1]], target = 0
Output: 5
Explanation: The two 1x2 submatrices, plus the two 2x1 submatrices, plus the 2x2 submatrix.

Example 3:
Input: matrix = [[904]], target = 0
Output: 0

Constraints:

1 <= matrix.length <= 100
1 <= matrix[0].length <= 100
-1000 <= matrix[i] <= 1000
-10^8 <= target <= 10^8
*/

#include<bits/stdc++.h>
using namespace std;

int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
    int m = matrix.size();
    int n = matrix[0].size();
    for (int row = 0; row < m; row++) {
        for (int col = 1; col < n; col++) {
            matrix[row][col] += matrix[row][col - 1];
        }
    }
    int count = 0;
    for (int c1 = 0; c1 < n; c1++) {
        for (int c2 = c1; c2 < n; c2++) {
            std::unordered_map<int, int> map;
            map[0] = 1;
            int sum = 0;
            for (int row = 0; row < m; row++) {
                sum += matrix[row][c2] - (c1 > 0 ? matrix[row][c1 - 1] : 0);
                count += map[sum - target];
                map[sum]++;
            }
        }
    }
    return count;
}

int main(){
    int n;
    cin>>n;
    int target;
    cin>>target;
    vector<vector<int>> matrix(n, vector<int> (n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>matrix[i][j];
        }
    }
    cout<<numSubmatrixSumTarget(matrix,target)<<endl;
    return 0;
}