#include <iostream>
#include <vector>
using namespace std;

/*
 * 给定一个含有n个正整数的数组和一个正整数 target 。
 * 找出该数组中满足其和 ≥ target 的长度最小的 连续子数组[numsl, numsl+1, ..., numsr-1, numsr] ，
 * 并返回其长度。如果不存在符合条件的子数组，返回 0 。
 */
class Solution0 {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int total = nums[0]; // 初始子数组的和为第一个元素的大小
        int minSubArrayLen = total > target ? 1 : 0; // 初始化最小连续子数组的长度

        // 开窗
        int l = 0;
        int r = 0;

        while (r<nums.size() && l <= r){

            if (total < target){
                r++;
                total = (r == nums.size())? total : total + nums[r];
            }
            else if (total > target){
                minSubArrayLen = (r - l +1 < minSubArrayLen || minSubArrayLen == 0) ? (r - l + 1) : minSubArrayLen;
                total = total - nums[l];
                l++;
            }
            else { // total == target
                minSubArrayLen = (r - l +1 < minSubArrayLen || minSubArrayLen == 0) ? (r - l + 1) : minSubArrayLen;
                r++;
                total = (r == nums.size())? total : total + nums[r];
            }
        }
        return minSubArrayLen;
    }
};

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int total = nums[0]; // 初始子数组的和为第一个元素的大小
        int minSubArrayLen = total > target ? 1 : nums.size()+1; // 初始化最小连续子数组的长度

        // 开窗
        int l = 0;
        int r = 0;
        while (l <= r && r < nums.size()){
            while (total < target && r < nums.size()){
                r++;
                if (r == nums.size())
                    break;
                total += nums[r];
            }
            while (total >= target && l <= r){
                minSubArrayLen = (r - l + 1 < minSubArrayLen) ? (r - l + 1) : minSubArrayLen;
                total -= nums[l];
                l++;
                if (l > r)
                    break;
            }
        }
        return minSubArrayLen == nums.size()+1 ? 0 : minSubArrayLen;
    }
};

int main() {

    // 输出：2
    // 解释：子数组 [4,3] 是该条件下的长度最小的子数组。
    int arr[] = {2,3,1,2,4,3};
    vector<int> nums(arr,arr+sizeof(arr)/sizeof(int));
    int target = 7;

    // 输出：0
//    int arr[] = {1,1,1,1,1,1,1,1};
//    vector<int> nums(arr,arr+sizeof(arr)/sizeof(int));
//    int target = 11;

    // 输出：1
//    int arr[] = {1,4,4};
//    vector<int> nums(arr,arr+sizeof(arr)/sizeof(int));
//    int target = 4;

    // 输出：3
//    int arr[] = {1,2,3,4,5};
//    int target = 11;
//    vector<int> nums(arr,arr+sizeof(arr)/sizeof(int));

    int res = Solution().minSubArrayLen(target, nums);
    cout<<res<<endl;

    cout<<nums[6]<<endl;
    cout<<endl;
}

