#include <iostream>
#include <vector>


/**
* 给定一个包含红色、白色和蓝色，一共n 个元素的数组，原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。
* 此题中，我们使用整数 0、1 和 2 分别表示红色、白色和蓝色。
*
* 关键词: 共计n个元素的无序数组，元素只存在0、1、2三种情况，重新排序使得按012的顺序排序。要求原地排序
*/

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int size = nums.size();

        int r0 = -1; // 使得[0,r0]范围内的元素都是0
        int l2 = size; // 使得[l2,size-1]范围内的元素都是2

        for (int i = 0; i < l2; ++i) {
            if (nums[i] == 0)
                swap(nums[++r0],nums[i]);
            if(nums[i] == 2)
                swap(nums[--l2], nums[i--]);
        }
    }
};

int main() {
//    int arr[] = {2,0,2,1,1,0};
    int arr[] = {1,2,0};
//    int arr[] = {2,0,1};
//    int arr[] = {0};
//    int arr[] = {1};
//    int arr[] = {};
    vector<int> nums(arr,arr+sizeof(arr)/sizeof(int));

    for (int num:nums)
        cout<<num<<" ";

    cout<<endl;
    Solution().sortColors(nums);

    for (int num: nums)
        cout<<num<<" ";

}
