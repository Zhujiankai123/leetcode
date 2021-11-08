#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
 * 给定m*n的全0矩阵，给定一个二维操作数组，数组中分别表示令哪些行列执行自增1
 * 例如操作数组[[2,2],[3,3]]表示先对i属于0~2，数组0~2的元素M[i,j]自增1，再对i属于0~3，数组0~3的元素M[i,j]自增1
 * 最终输出最大数值元素的数量
 *
 * 解:实际对最大元素数量有影响的，只有这个二维数组中最小的i和最小的j
 */
class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        // m 和 n 的范围是 [1,40000],不需要做m==0和n==0时的特殊处理

        if (ops.empty())
            return m*n;

        int min_i = INT32_MAX;
        int min_j = INT32_MAX;
        for (int i = 0; i < ops.size(); ++i) {
            min_i = min_i > ops[i][0] ? ops[i][0] : min_i;
            min_j = min_j > ops[i][1] ? ops[i][1] : min_j;
        }

        return min_i*min_j;
    }
};

int main() {
    int m,n;
    m = 3;
    n = 3;
    vector<vector<int>> operations = vector<vector<int>>({{2,2},{3,3}});
    Solution solution = Solution();
    cout<<solution.maxCount(m,n,operations)<<endl;

    return 0;
}
