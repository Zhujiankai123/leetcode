#include <iostream>
#include <vector>

using namespace std;

class Solution {
/**
* 给你一个数组 nums和一个值 val，你需要 原地 移除所有数值等于val的元素，并返回移除后数组的新长度。
* 不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并 原地 修改输入数组。
* 元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。
*/
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;  // [0,i)区间内都是不为val的元素
        for (int j = 0; j < nums.size(); ++j) {
            if (nums[j] != val){
                if (i == j)
                    i++;
                else
                    swap(nums[i++],nums[j]);
            }
        }

        nums.resize(i);
        return i;
    }
};

int main() {
/**
* 几种赋初值的方式:
* int nums1[] = {1,2,3,4};
* int nums2 = *new int[4]{1,2,3,4};
* int *nums3 = new int[4]{1,2,3,4};
*
* 将数组内容复制到vector的方式:
* 1. 使用构造方法，参数分别为数组的第一个元素的地址、数组最后一个元素的地址
*    由于c++数组没有length方法，因此需要通过sizeof(int数组)/sizeof(int类型)来获取长度
*    vector<int> vec = vector<int>(nums,nums+sizeof(num)/sizeof(int));
* 2. 遍历数组，将数组元素通过push_back依次放到vec向量的末尾
*    for(int i = 0;i<(sizeof(nums)/sizeof(int));i++){vec.push_back(nums[i]);}
*/

//    int arr[] = {3,2,2,3};
//    vector<int> nums = vector<int>(arr,arr+sizeof(arr)/sizeof(int));
    int arr[] = {0,1,2,2,3,0,4,2};
    vector<int> nums = vector<int>(arr,arr+sizeof(arr)/sizeof(int));

    // before delete
    for (int num : nums) {
        cout<<num<<" ";
    }

    cout<<endl;
    // delete
    Solution solution = Solution();
//    int res = solution.removeElement(nums,3);
    int res = solution.removeElement(nums,2);

    // after delete
    for (int num : nums) {
        cout<<num<<" ";
    }
    cout<<endl<<res;

    return 0;
}
