#include <iostream>
#include <vector>

using namespace std;
/**
 * 给你一个有序数组 nums ，请你 原地 删除重复出现的元素，使每个元素 只出现一次 ，返回删除后数组的新长度。
 * 不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。
 *
 * 关键字: 有序数组，原地操作，删除重复元素，返回删除后的长度，操作数组的引用
 */
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        if (size <= 1){
            return size;
        }

        int m = 0; // 满足[0,m]为不存在重复元素
        for (int i = 0; i < size; ++i) {
//            if (nums[m] == nums[size-1] && i!= size-1)
//                break;
            if (nums[i] != nums[m])
                if (i == m+1) // 避免出现自己和自己交换
                    m++;
                else {
                    swap(nums[i], nums[m + 1]);
                    m++;
                }
        }

        nums.resize(m+1);
        return m+1;
    }
};

int main() {
    int arr[] = {0,0,1,1,1,2,2,3,3,4};
    vector<int> nums(arr,arr+sizeof(arr)/sizeof(int));

    for(int num: nums){
        cout<<num<<" ";
    }

    cout<<endl;

    int res = Solution().removeDuplicates(nums);
    cout<<"剔除重复元素后的数组长度为: "<<res<<endl;
    for(int num: nums){
        cout<<num<<" ";
    }
}
