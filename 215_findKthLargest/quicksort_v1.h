//
// Created by michealki on 2021/7/26.
// 快速排序
//

#ifndef INC_215_FINDKTHLARGEST_QUICKSORT_V1_H
#define INC_215_FINDKTHLARGEST_QUICKSORT_V1_H
#include <iostream>
#include <vector>

using namespace std;
class quickSort_v1{
public:
    void sort(vector<int> &nums){
        srand((unsigned)time(NULL)); // 设置随机数种子
        __sort(nums, 0, nums.size()-1);
        for(int n:nums){
            cout<<n<<" ";
        }
        cout<<endl;
    }
private:
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


#endif //INC_215_FINDKTHLARGEST_QUICKSORT_V1_H
