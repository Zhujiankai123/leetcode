#include <iostream>
#include <vector>
#include "quicksort.h"
#include "SortTestHelper.h"
using namespace std;


/*
 * 给定整数数组 nums 和整数 k，请返回数组中第 k 个最大的元素。
 * 请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。
 */

class Solution1 { // 全排序 执行用时: 16 ms
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums);
        return nums[nums.size()-k];
    }
private:
    void sort(vector<int> &nums){
        srand((unsigned)time(NULL)); // 设置随机数种子
        __sort(nums, 0, nums.size()-1);
        for(int n:nums){
            cout<<n<<" ";
        }
        cout<<endl;
    }
    int __partition(vector<int> &nums, int l, int r){ // 对nums[l:r]进行partition操作，返回partition后的v值
        int tmp_p = rand()%(r-l+1)+l;
        swap(nums[tmp_p],nums[l]);

        int v = nums[l]; // 使用第一个元素作为pivot元素
        int pivot = l; // 使得nums[l:r]中[l+1,pivot]都是小于元素v，[pivot+1,r]都是大于等于元素v

        for (int i = l+1; i <= r; ++i) {
            if (nums[i] < v && i != pivot){
                swap(nums[pivot+1],nums[i]);
                pivot++;
            }
        }
        swap(nums[l],nums[pivot]);
        return pivot;
    }

    void __sort(vector<int> &nums, int l, int r){ // 对nums[l:r]进行快排
        // 递归到底
        if (l>=r)
            return;

        int pivot = __partition(nums, l, r); // 返回partition操作后的v值
        int l0 = l;
        int r0 = pivot-1;
        int l1 = pivot+1;
        int r1 = r;

        __sort(nums, l0, r0);
        __sort(nums, l1, r1);
    }


};

class Solution2 { // 快排加二分法 执行用时: 8 ms
    int indexOfKValue;
    int res = -1;
public:
    int findKthLargest(vector<int> &nums, int k){
        srand((unsigned)time(NULL));
        indexOfKValue = nums.size()-k;

        __sortSubArray(nums, 0, nums.size()-1);
        return res;
    }

private:
    void __sortSubArray(vector<int> &nums, int l, int r) {
        if (l >= r) {
            res = nums[r];
            return;
        }
        int p = __partition(nums, l, r);
        if (p == indexOfKValue) { // 已经找到了第k大的元素
            res = nums[p];
            return;
        }

        if (p > indexOfKValue) // 第k大的元素在p的左侧
            __sortSubArray(nums, l, p - 1);
        else // 第k大的元素在p的右侧
            __sortSubArray(nums, p + 1, r);
    }

    int __partition(vector<int> &nums, int l, int r){
        swap(nums[l], nums[(rand()%(r-l+1))+l]);
        int v = nums[l];

        int lt = l; // 在每轮for循环中，保证nums[l+1, lt]都是小于v的元素，nums[lt+1,i-1]都是大于等于v的元素
        for (int i = l+1; i <= r; ++i) {
            if (nums[i] < v){
                swap(nums[i], nums[lt+1]);
                lt++;
            }
        }
        swap(nums[l], nums[lt]);
        return lt;
    }
};

class Solution{ // 三路快排加二分法 执行用时： 4 ms
    int res = -1;
    int indexOfKValue;
public:
    int findKthLargest(vector<int> &nums, int k) {
        srand((unsigned)time(NULL));
        indexOfKValue = nums.size() - k;
        __sortSubArray(nums, 0, nums.size()-1);
        return res;
    }

private:
    void __sortSubArray(vector<int> &nums, int l, int r){
        if (l>=r){
            res = nums[r];
            return;
        }

        int *p = __partition(nums, l, r); // nums[l,p[0]-1]中的元素都小于pivot,nums[p[0],p[1]]中的元素都等于pivot,nums[p[1]+1,r]都大于pivot
        if (p[0] <= indexOfKValue && indexOfKValue <= p[1]){ // pivot元素就是第k大的
            res = nums[p[0]];
            return;
        }
        if (p[0] > indexOfKValue){ // 第k大的元素在左边的子数组中
            __sortSubArray(nums, l, p[0]-1);
        }
        else{ // 第k大的元素在右侧的子数组中
            __sortSubArray(nums,p[1]+1,r);
        }
    }

    int* __partition(vector<int> &nums, int l, int r){
        swap(nums[l], nums[rand()%(r-l+1)+l]);
        int v = nums[l];

        int lt = l; // 在每一轮for循环中，保证nums[l+1,lt]都是小于v的,nums[lt+1,i-1]都是等于v的
        int gt = r; // 在每一轮for循环中，保证nums[gt+1,r]都是大于v的

        for (int i = l+1; i <= gt; ++i) {
            if (nums[i] < v){
                swap(nums[i], nums[lt+1]);
                lt++;
            }
            else if (nums[i] > v){
                swap(nums[i], nums[gt]);
                gt--;
                i--; // 原来gt位置的元素是还没有被查看过的元素，交换后需要i—-，使得下一轮循环中能正常看到这个元素
            }
            else {
                // nums[i] == v
            }
        }
        swap(nums[l],nums[lt]);
        int *p = new int[2];
        p[0] = lt;
        p[1] = gt;
        return p;
    }
};

int main() {

//    int arr[] = {3,2,1,5,6,4}; // 输出: 5
//    int k =2;
//    int arr[] = {3,2,3,1,2,4,5,5,6}; // 输出: 4
//    int k = 4;

//    vector<int> nums(arr,arr+sizeof(arr)/sizeof(int));
//    cout<<Solution().findKthLargest(nums,k);




/*quick-sort test*/
    int n = 1000000;
    int *arr = SortTestHelper::generateRandomArray(n,0,INT32_MAX);
    int *dup_arr = SortTestHelper::generateRandomArray(n,0,10);
    int *ordered_arr = SortTestHelper::generateNearlyOrderedArray(n,10);
    vector<int> nums(arr,arr+n);
    vector<int> nums_dup(dup_arr,dup_arr+n);
    vector<int> nums_ordered(ordered_arr,ordered_arr+n);

    // 普通快速排序，仅适用于重复元素较少的情况
    cout<<endl;
    SortTestHelper::testSort("单路快排",one_ways::sort,nums);           // 耗时: 0.457416s
    SortTestHelper::testSort("单路快排",one_ways::sort,nums_ordered);   // 耗时: 0.245314s
    SortTestHelper::testSort("单路快排",one_ways::sort,nums_dup);       // 耗时: 18.6023s 存在大量重复元素的数组
//    SortTestHelper::testSort("单路快排",one_ways::sort,nums_ordered);   // 近乎有序的情况下不使用随机交换pivot进行优化，会退化为O(n2): 耗时: 89.0393s

    // 两路快排
    // 双路快排将等于v的元素平均分配到左右两部分区域中，避免退化到O(n2)
    cout<<endl;
    SortTestHelper::testSort("两路快排",two_ways::sort,nums);           // 耗时: 0.308886s
    SortTestHelper::testSort("两路快排",two_ways::sort,nums_ordered);   // 耗时: 0.150543s
    SortTestHelper::testSort("两路快排",two_ways::sort,nums_dup);       // 耗时: 0.203404s

    // 三路快排
    // 对重复元素放在了一起，partition后将不再关注重复的那部分元素，在处理包含大量重复元素的排序时效率更高
    cout<<endl;
    SortTestHelper::testSort("三路快排",three_ways::sort,nums);         // 耗时: 0.587858s
    SortTestHelper::testSort("三路快排",three_ways::sort,nums_ordered); // 耗时: 0.525084s
    SortTestHelper::testSort("三路快排",three_ways::sort,nums_dup);     // 耗时: 0.059836s


}
