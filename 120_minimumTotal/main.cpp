#include <iostream>
#include <vector>
using namespace std;

/*
 *
 * 给定一个三角形 triangle ，找出自顶向下的最小路径和。
 * 每一步只能移动到下一行中相邻的结点上。
 * 相邻的结点 在这里指的是 下标 与 上一层结点下标 相同或者等于 上一层结点下标 + 1 的两个结点。
 * 也就是说，如果正位于当前行的下标 i ，那么下一步可以移动到下一行的下标 i 或 i + 1 。
 */

class Solution_v1 {
private:
    vector<vector<int>> memo; // 记录从triangle[i][j]到最下底层的最短路径和录
    int findMinimum(vector<vector<int>>& triangle, int i, int j){
        // 寻找triangle这个三角形数组中，从triangle[i][j]到最下底层的最短路径和
        if (i == triangle.size()-1){
            memo[i][j] = triangle[i][j];
            return memo[i][j];
        }

        if (memo[i][j] == INT32_MAX)
            memo[i][j] = triangle[i][j] + min(findMinimum(triangle, i+1, j),
                     findMinimum(triangle, i+1, j+1)
                     );

        return memo[i][j];
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        // 状态转义方程:
        // minimumWays[i] = min( minimumWays[i+1][j], minimumWays[i+1][j+1] ) + value[i][j]
        memo = triangle;
        for (int i = 0; i < memo.size(); ++i) {
            for (int j = 0; j < memo[i].size(); ++j) {
                memo[i][j] = INT32_MAX;
            }
        }
        return findMinimum(triangle, 0,0);
    }
};


class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        // 自底向上+ O(n) 的额外空间（n 为三角形的总行数）
        int dims = triangle.size();
        assert(dims == triangle[dims-1].size());

        vector<int> memo;
        memo = triangle[dims-1];

        int i = dims - 1;
        while (i > 0){
            // 计算由第n-1层与当前n层最短路径数组所组成的路径和
            for (int j = 0; j < i; ++j) {
                memo[j] = min(memo[j],memo[j+1]) + triangle[i-1][j];
            }
            i--;
        }
        return memo[0];
    }
};


int main() {
    vector<vector<int>> v = {{2},{3,4},{6,5,7},{4,1,8,3}};
//    vector<vector<int>> v = {{-10}};
    cout<<Solution().minimumTotal(v)<<endl;
    return 0;
}
