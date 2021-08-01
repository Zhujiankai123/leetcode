//
// Created by michealki on 2021/7/27.
//

#ifndef INC_215_FINDKTHLARGEST_QUICKSORT_H
#define INC_215_FINDKTHLARGEST_QUICKSORT_H
#include <iostream>
#include <vector>
using namespace std;
namespace one_ways{
    int __partition(vector<int> &nums, int l, int r){
        swap(nums[l], nums[(rand()%(r-l+1))+l]);
        int v = nums[l]; // pivot元素值

        int lt = l; // 在每一次for循环遍历中，保证nums[l+1, lt]中都是小于v的元素 , nums[lt+1, i-1]都是大于等于v的元素

        for (int i = l+1; i <= r; ++i) {
            if (nums[i] < v){
                swap(nums[lt+1],nums[i]);
                lt++;
            }
        }

        swap(nums[l], nums[lt]);
        return lt;
    }

    void __sort(vector<int> &nums, int l, int r){
        // 递归到底
        if (l >= r)
            return;

        int p = __partition(nums, l ,r);
        __sort(nums, l, p-1); // 对pivot左边部分进行快速排序操作
        __sort(nums, p+1, r); // 对pivot右边部分进行快速排序操作
    }

    void sort(vector<int> &nums){
        srand((unsigned)time(NULL));
        __sort(nums, 0, nums.size()-1);
    }
}

namespace two_ways{
    int __partition(vector<int> &nums, int l, int r){
        swap(nums[l], nums[(rand()%(r-l+1))+l]);
        int v= nums[l];

        int i = l+1; // 在循环中，保证nums[l+1,i-1]都是小于等于v的元素
        int j = r; // 在循环中，保证nums[j+1,r]都是大于等于v的元素
        while (i<=j){
            while (nums[i] < v && i <= r){ // 从左往右找到第一个大于等于v的元素
                i++;
            }
            while (nums[j] > v && j >= l){ // 从右往左找到第一个小于等于v的元素
                j--;
            }
            if (i>j) break;

            swap(nums[i],nums[j]); // 找到后交换i、j两个位置
            i++;
            j--;
        }
        swap(nums[l], nums[j]);
        return j;
    }

    void __sort(vector<int> &nums, int l, int r){
        // 递归到底
        if (l >= r)
            return;

        int p = __partition(nums, l, r);
        __sort(nums, l, p-1); // 对pivot左边的进行排序
        __sort(nums, p+1, r); // 对pivot右边的进行排序
    }
    void sort(vector<int> &nums){
        srand((unsigned)time(NULL));
        __sort(nums, 0, nums.size()-1);
    }

}

namespace three_ways{
    int* __partition(vector<int> &nums, int l, int r){
        swap(nums[l], nums[(rand()%(r-l+1))+l]);
        int v = nums[l];

        int lt = l; // 在每一次循环中，使得[l+1,lt]中的元素都小于v (在每一次循环中，使得[lt+1,i-1]中的元素都等于v)
        int gt = r; // 在每一次循环中，使得[gt+1,r]中的元素都大于v

        for (int i = l+1; i <= gt; ++i) {
            if (nums[i] < v){
                swap(nums[lt+1],nums[i]);
                lt++;
            }
            else if (nums[i] > v){
                swap(nums[i], nums[gt]);
                gt--;
                i--; // 原来gt位置的元素尚未被查看到，交换后需要让i减1，使得下一轮循环时能看到这个元素
            }
            else{}// nums[i] == v
        }
        swap(nums[l], nums[lt]);
        int p_arr[] = {lt,gt};
        return p_arr;
    }

    void __sort(vector<int> &nums, int l,int r){
        // 递归到底
        if (l>=r) return;

        int* p =  __partition(nums, l, r);
        int lt = p[0]-1;
        int gt = p[1]+1;
        __sort(nums, l, lt); // 对pivot左边元素进行排序
        __sort(nums, gt, r); // 对pivot右边元素进行排序
    }

    void sort(vector<int> &nums){
        srand((unsigned)time(NULL));
        __sort(nums, 0, nums.size()-1);
    }
};
#endif //INC_215_FINDKTHLARGEST_QUICKSORT_H
