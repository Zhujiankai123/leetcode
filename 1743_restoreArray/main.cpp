#include <iostream>
#include <vector>
#include <map>
#include <unordered_set>
#include <set>
#include <unordered_map>
using namespace std;

/*
 * 存在一个由 n 个不同元素组成的整数数组 nums ，但你已经记不清具体内容。好在你还记得 nums 中的每一对相邻元素。
 * 给你一个二维整数数组 adjacentPairs ，大小为 n - 1 ，其中每个 adjacentPairs[i] = [ui, vi] 表示元素 ui 和 vi 在 nums 中相邻。
 *
 * 题目数据保证所有由元素 nums[i] 和 nums[i+1] 组成的相邻元素对都存在于 adjacentPairs 中，存在形式可能是 [nums[i], nums[i+1]] ，也可能是 [nums[i+1], nums[i]] 。这些相邻元素对可以 按任意顺序 出现。
 * 返回 原始数组 nums 。如果存在多种解答，返回 其中任意一个 即可。
 */
class Solution {
/**
 * 执行结果：通过
 * 执行用时：704 ms, 在所有 C++ 提交中击败了50.34%的用户
 * 内存消耗：117.5 MB, 在所有 C++ 提交中击败了42.28%的用户
 */
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int,vector<int>> m = {};
        vector<int> res = {};
        unordered_set<int> is_used;

        for (int i = 0; i < adjacentPairs.size(); ++i) {
            int v0 = adjacentPairs[i][0];
            int v1 = adjacentPairs[i][1];

            if (m.find(v0) == m.end()) {// 当前查找表不存在v0为键的数据
                m[v0] = vector<int>();
                m[v0].push_back(v1);
            }
            else // 已经存在以v0为键的数据了
                m[v0].push_back(v1);


            if (m.find(v1) == m.end()) {// 当前查找表不存在v0为键的数据
                m[v1] = vector<int>();
                m[v1].push_back(v0);
            }
            else // 已经存在以v0为键的数据了
                m[v1].push_back(v0);
        }

        // 获取一个端点
        for(auto &i: m){ // pair(int,vector<int>)
            if (i.second.size()==1){
                res.push_back(i.first);
                is_used.insert(i.first);
                break;
            }
        }

        while (res.size() != m.size()){
            // 获取与res最后一个元素相连接的元素
            int f = m[res.back()].front();
            int b = m[res.back()].back();
            if (f==b) {
                res.push_back(f);
                is_used.insert(f);
            }
            else{
                if (is_used.find(f) == is_used.end()){
                    res.push_back(f);
                    is_used.insert(f);
                }
                else{
                    res.push_back(b);
                    is_used.insert(b);
                }
            }
        }
        return res;
    }
};


int main() {
//    int arr[3][2] = {2,1,3,4,3,2}; //输入：adjacentPairs = [[2,1],[3,4],[3,2]] 输出：[1,2,3,4]
    int arr[3][2] = {4,-2,1,4,-3,1};
    vector<vector<int>> adjacentPairs;
    for (auto & i : arr) {
            adjacentPairs.emplace_back(i,i+2);
        }
    vector<int> res = Solution().restoreArray(adjacentPairs);
    for(int s : res)
        cout<<s<<" ";

}
