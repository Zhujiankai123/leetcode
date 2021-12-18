#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<int> memo;
    int climb1(int n){
        // 方法1: 仅使用递归
        // 执行结果：超出时间限制
        // 最后执行的输入：44
        if(n == 0 || n == 1)
            return 1;

        return climb1(n-1) // 每次只能爬1阶或2阶，即爬n阶的方法数等于爬n-1阶(从n-1爬1阶到第n阶)的方法数
                +climb1(n-2);  // 加上爬n-2阶(从n-2阶爬2阶到第n阶)
    }

    int climb2(int n){
        // 方法2: 使用递归+记忆化搜索
        // 执行结果：通过
        //执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
        //内存消耗：6 MB, 在所有 C++ 提交中击败了26.15%的用户
        if (n == 0 || n == 1){
            memo[n] = 1;
            return 1;
        }

        memo[n-1] = memo[n-1] == -1 ? climb2(n-1) : memo[n-1];
        memo[n-2] = memo[n-2] == -1 ? climb2(n-2) : memo[n-2];
        memo[n] = memo[n-1] + memo[n-2];
        return memo[n];
    }

    int climb3(int n){
        // 方法2: 使用递归+记忆化搜索,在本层循环只记录memo[n]的值
        // 执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
        //内存消耗：6.1 MB, 在所有 C++ 提交中击败了12.37%的用户
        if (n == 0 || n == 1){
            memo[n] = 1;
            return 1;
        }
        memo[n] = (memo[n] == -1 ? climb3(n-1) + climb3(n-2) : memo[n]);
        return memo[n];
    }

    int climb4(int n){
        // 方法3:自底向上，使用动态规划的方式处理
        // 执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
        // 内存消耗：6.1 MB, 在所有 C++ 提交中击败了17.82%的用户
        memo[0] = 1;
        memo[1] = 1;

        for (int i = 2; i < n+1; ++i) {
            memo[i] = memo[i-1] + memo[i-2];
        }
        return memo[n];
    }
public:
    int climbStairs(int n) {
        memo = vector<int>(n+1,-1);
        return climb4(n);
    }
};

int main() {
    int n =2;
    std::cout <<Solution().climbStairs(n)<<std::endl;
    return 0;
}
