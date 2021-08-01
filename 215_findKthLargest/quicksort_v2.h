//
// Created by michealki on 2021/7/27.
// 两路快排
//

#ifndef INC_215_FINDKTHLARGEST_QUICKSORT_V2_H
#define INC_215_FINDKTHLARGEST_QUICKSORT_V2_H
#include <iostream>
#include <vector>

using namespace std;

class quicksort_v2{
public:
    void sort(vector<int> &nums){
        srand(time(NULL));
        __sort(nums, 0, nums.size()-1);
    }

private:
    void __sort(vector<int> &nums, int l, int r){
        if (l >= r) // 递归到底
            return;

        int pivot = __partition(nums, l, r);
        int l0 = l;
        int r0 = pivot - 1;
        int l1 = pivot + 1;
        int r1 = r;

        __sort(nums, l0, r0);
        __sort(nums, l1, r1);
    }
    int __partition(vector<int> &nums, int l,int r){
        // 随机化pivot值
        int tmp_p = rand()%(r-l+1)+l;
        swap(nums[tmp_p], nums[l]);
        int v = nums[l];

        int i = l + 1; // 使得数组nums[l+1,i-1]中的元素都是小于等于v的
        int j = r; // 使得数组nums[j+1,r]中的元素都是大于等于v的

        while (i<=j){
            while (nums[i] < v && i <= r) // 从左往右找到第一个大于等于v的元素
                i++;
            while (nums[j] > v && j >= l) // 从右往左找到第一个小于等于v的元素
                j--;

            if (i>j) break;

            swap(nums[i],nums[j]); // 找到后交换两个元素的位置
            i++;
            j--;
        }
        swap(nums[j],nums[l]); // 将pivot元素放到对应位置
        return j; // 返回pivot索引
    }
};

#endif //INC_215_FINDKTHLARGEST_QUICKSORT_V2_H
