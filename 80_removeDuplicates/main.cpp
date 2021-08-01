#include <iostream>
#include <vector>

using namespace std;
/**
 * 给你一个有序数组 nums ，请你 原地 删除重复出现的元素，使每个元素 最多出现两次 ，返回删除后数组的新长度。
 * 不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。
 *
 * 关键字: 有序数组，原地操作，删除重复元素，每个重复元素最多可出现两次，返回新数组长度，数组通过引用方式进行修改
 */
class Solution_V1 {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        if (size <= 1)
            return size;

        int m = 0; //
        int n = 0; //

        for (int i = 1; i < size; ++i) {
            if (nums[i] != nums[m]){
               swap(nums[n+1],nums[i]);
               m = n = n+1;
            }
            else{
                if (n - m == 1){
                    n = m + 1;
                }
                if (n - m == 0){
                    swap(nums[n+1],nums[i]);
                    n++;
                }
            }
        }

        nums.resize(n+1);
        return n+1;
    }
};

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        if (size <= 1)
            return size;

        int last_index = 0;
        for (int i = 1; i < size; ++i) {
            if (nums[i] == nums[last_index]){
                if (last_index<1 || nums[last_index-1] != nums[i]) {
                    nums[last_index+1] = nums[i];
//                    swap(nums[last_index+1],nums[i]);
                    last_index +=1;
                }
            }
            else{
                nums[last_index+1] = nums[i];
//                swap(nums[last_index+1],nums[i]);
                last_index += 1;
            }

        }
        nums.resize(last_index+1);
        return last_index+1;
    }
};

int main() {
//    int arr[] = {0,0,1,1,1,1,2,3,3};
    int arr[] = {1,2};

    vector <int> nums(arr,arr+sizeof(arr)/sizeof(int));
    for (int num: nums){
        cout<<num<<" ";
    }

    cout<<endl;

    int res = Solution().removeDuplicates(nums);
    cout<<"去重后的数组长度为: "<<nums.size()<<endl;
    for (int num: nums){
        cout<<num<<" ";
    }
}
