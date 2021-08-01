//
// Created by michealki on 2021/7/27.
// 三路快排
//

#ifndef INC_215_FINDKTHLARGEST_QUICKSORT_V3_H
#define INC_215_FINDKTHLARGEST_QUICKSORT_V3_H

#include <iostream>
#include <vector>

using namespace std;
class quicksort_v3{
public:
    void sort(vector<int> &nums){
        srand((unsigned)time(NULL));
        __sort(nums, 0, nums.size()-1);
    }
private:
    void __sort(vector<int> &nums, int l, int r){
        if (l >= r)  // 递归到底
            return;

        int *p = __partition(nums, l , r);
        int l0 = l;
        int r0 = p[0]-1;
        int l1 = p[1]+1;
        int r1 = r;
        __sort(nums, l0, r0);
        __sort(nums, l1, r1);
    }

    int* __partition(vector<int> &nums, int l, int r){
        int tmp_p = rand() % (r - l + 1) + l;
        swap(nums[l], nums[tmp_p]);
        int v = nums[l];

        int gt = r; // nums[gt+1,r]都大于v
        int lt = l; // nums[l+1,lt]都小于v (nums[lt+1,i-1]都等于v)
        for (int i = l+1; i <= gt; ++i) {
            if (nums[i] < v){
                swap(nums[lt+1],nums[i]);
                lt++;
            }
            else if (nums[i] > v){
                swap(nums[gt],nums[i]);
                gt--;
                i--;
            }
            else {
                // nums[i] == v
                // i++
            }
        }

        swap(nums[lt],nums[l]);
        int *p = new int(2);
        p[0] = lt;
        p[1] = gt;
        return p;
    }
};

#endif //INC_215_FINDKTHLARGEST_QUICKSORT_V3_H
