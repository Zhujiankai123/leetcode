#include <iostream>
#include <string>
#include <vector>

using namespace std;
/*
 * 给定一个包含 [0, n] 中 n 个数的数组 nums ，找出 [0, n] 这个范围内没有出现在数组中的那个数。
 */
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();

        int res = n;
        for (int i = 0; i < n; ++i) {
            res = res ^ nums[i] ^ i;
        }
        return res;
    }
};

int main() {
    int arr[] = {3,0,1};
    vector<int> nums(arr, arr + sizeof(arr)/sizeof(int));
    Solution solution = Solution();
    solution.missingNumber(nums);

    cout<<endl;
}
