#include <iostream>
#include <vector>

using namespace std;


class Solution {
private:
    vector<int> memo;
public:
    int minPathSum(vector<vector<int>>& grid) {
    /*
     * m x n 网格 grid
     * m == grid.length
     * n == grid[i].length
     * 0 <= grid[i][j] <= 100
     * 1 <= m, n <= 200
     */
        int m = grid.size();
        int n = grid[0].size();
        memo = grid[m-1];
        for (int i = m-1; i >= 0; i--) {
            for (int j = n-1; j >=0 ; j--) {
                // right: 从grid[i][j+1]到右下角的最短距离
                // down: 从grid[i+1][j]到右下角的最短距离
                if (i == m-1 && j == n-1) continue;
                int right = (j == n-1 ? INT32_MAX : memo[j+1]);
                int down = (i == m-1 ? INT32_MAX: memo[j]);
                memo[j] = min(right, down) + grid[i][j];
            }
        }
        return memo[0];
    }
};

int main() {

    vector<vector<int>> grid;
//    grid = {{1,3,1},{1,5,1},{4,2,1}};
    grid = {{1,2,3},{4,5,6}};
    cout<<Solution().minPathSum(grid)<<endl;
    return 0;
}
