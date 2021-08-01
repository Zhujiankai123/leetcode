#include <iostream>
#include <vector>

using namespace std;
/*
 * 给你一个二维整数数组ranges和两个整数left和right。每个ranges[i] = [starti, endi]表示一个从starti到endi的闭区间。
 * 如果闭区间[left, right]内每个整数都被ranges中至少一个区间覆盖，那么请你返回true，否则返回false。
 * 已知区间 ranges[i] = [starti, endi] ，如果整数 x 满足 starti <= x <= endi，那么我们称整数x被覆盖了。
 *
 * 提示：
 * 1 <= ranges.length <= 50
 * 1 <= starti <= endi <= 50
 * 1 <= left <= right <= 50
 *
 *
 * 分析: 提供一个二维数组，数组的整体范围是1到50之间，二维数组中每个数组都代表1~50之间的一个闭区间范围
 *      给定一个指定的区间[left,right],如果区间内每一个元素都在二维数组范围内，返回true，否则返回false
 */

class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        int full_range[51] = {0};
        for(vector<int> sub_range: ranges){
//            cout<<sub_range.front()<<", "<<sub_range.back()<<endl;
            for (int i = sub_range.front(); i <= sub_range.back(); ++i) {
                full_range[i] = 1;
            }
        }

        for (int i = left; i <= right; ++i) {
            if (full_range[i] == 0)
                return false;
        }
        return true;
    }
};


int main() {
    int arr[3][2] = {1,2,3,4,5,6};
    vector<vector<int>> ranges;
    for (int i = 0; i < 3; ++i) {
        ranges.emplace_back(arr[i],arr[i]+2);
    }

    bool res = Solution().isCovered(ranges,2,5);
    cout<<res<<endl;
}
