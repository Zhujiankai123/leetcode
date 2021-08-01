#include <iostream>
#include <vector>

using namespace std;

/*
 * 给你 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点i,ai) 。
 * 在坐标内画 n 条垂直线，垂直线 i的两个端点分别为i,ai) 和 (i, 0)
 * 。找出其中的两条线，使得它们与x轴共同构成的容器可以容纳最多的水。
 * 说明：你不能倾斜容器。
 */

class Solution1 {
    // 思路：遍历
    // 53 / 60 个通过测试用例
    // 状态：超出时间限制
public:
    int maxArea(vector<int>& height) {
        int maxArea = __calculateArea(height, 0, height.size()-1);
        for (int l = 0; l < height.size(); ++l) {
            int r = height.size()-1;
            int tmp_r = r;
            while (l<tmp_r){
                while (height[tmp_r] < height[r] && l < tmp_r)
                    tmp_r--;
                if (__calculateArea(height, l , tmp_r) > maxArea && l < tmp_r){
                    maxArea = __calculateArea(height, l, tmp_r);
                    r = tmp_r;
                }
                tmp_r--;
            }
        }
        return maxArea;
    }

private:
    int __calculateArea(vector<int> &height, int l, int r){
        return min(height[l],height[r]) * (r-l);
    }
};


/*
 * 执行结果：通过
 * 执行用时：1212 ms, 在所有 C++ 提交中击败了5.14%的用户
 * 内存消耗：57.6 MB, 在所有 C++ 提交中击败了65.68%的用户
 */
class Solution2 {
    // 思路：由于最开始的r-l已经是最大值了，因此每次往中间遍历只会令r-l减小
    //      因此往中间遍历时，如果围住的空间更大，则意味着height[tmp_l]与height[tmp_r]一定有一个比之前的更大
public:
    int maxArea(vector<int>& height) {
        int l = 0;
        int r = height.size()-1;
        int max_area = __calculateArea(height, l, r);
        int iter_l = l;
        int iter_r = r;
        while (iter_l < r) {
            if (height[iter_l] < height[iter_r]){ // 左端点比右端点低
                int height_tmp = height[iter_l];
                while (height[iter_l] <= height_tmp && iter_l < iter_r)
                    iter_l++; // 往右找到一个比当前iter_l更高的点
            }

            while (iter_l < r && iter_r > l){
                int cur_area = __calculateArea(height, iter_l, iter_r);
                if (cur_area > max_area){
                    r = iter_r;
                    l = iter_l;
                    max_area = cur_area;
                }
                int height_tmp = height[iter_r];
                while (height[iter_r] <= height_tmp && iter_l < iter_r)
                    iter_r--; // 往左找到一个比当前iter_r更高的点

                if (iter_r == iter_l){
                    iter_r = r;
                    break;
                }
            }
            if (iter_l < r && height[iter_l] >= height[iter_r]) { // 左端点比右端点高
                int height_tmp = height[iter_l];
                while (height[iter_l] <= height_tmp && iter_l < iter_r)
                    iter_l++; // 往右找到一个比当前iter_l更高的点
                }
        }
        return max_area;
    }
private:
    int __calculateArea(vector<int> &height, int l, int r){
        return min(height[l],height[r]) * (r-l);
    }
};

class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0;
        int r = height.size()-1;
        int max_area = __calculateArea(height, l ,r);
//        int cur_area;
        int iter_l = l;
        int iter_r = r;
        while (iter_l < iter_r) {
            if (iter_l < iter_r && height[iter_l] < height[iter_r]) {
                while (iter_l < iter_r && height[iter_l] <= height[l])
                    iter_l++;
            }
            else if (iter_l < iter_r && height[iter_l] >= height[iter_r]) {
                while (iter_l < iter_r && height[iter_r] <= height[r])
                    iter_r--;
            }

            int cur_area = __calculateArea(height, iter_l, iter_r);
            if (cur_area > max_area) {
                l = iter_l;
                r = iter_r;
                max_area = cur_area;
            }
            else{
                if (height[iter_l] < height[iter_r])
                    iter_l++;
                else
                    iter_r--;
            }
        }
        return max_area;
    }
private:
    int __calculateArea(vector<int> &height, int l, int r){
        return min(height[l],height[r]) * (r-l);
    }
};


int main() {
//    int arr[] = {1,1}; // 输出：1
//    int arr[] = {1,8,6,2,5,4,8,3,7}; // 输出：49
//    int arr[] = {4,3,2,1,4}; // 输出：16
//    int arr[] = {1,2,1}; // 输出：2
    int arr[] = {2,3,4,5,18,17,6}; // 输出：17
//    int arr[] = {1}; // 输出0
//    int arr[] = {1,2,4,3}; // 输出4
//    int arr[] = {1,8,100,2,100,4,8,3,7}; // 输出200
//    int arr[] = {1,1000,1000,6,2,5,4,8,3,7}; // 输出1000
//    int arr[] = {4,4,2,11,0,11,5,11,13,8}; // 输出55
//    int arr[] = {10,9,8,7,6,5,4,3,2,1}; // 输出25
//    int arr[] = {1,2,3,4,5,6,7,8,9,10}; // 输出25
//    int arr[] = {1,3,2,5,25,24,5}; // 输出24
//    int arr[] = {1,8,6,2,5,4,8,3,7}; // 49
    vector<int> height(arr,arr+sizeof(arr)/sizeof(int));

    int res = Solution().maxArea(height);
    cout<<res<<endl;
}
