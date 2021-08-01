#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution { // 对撞指针
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res;
        int l = 0; // 左指针
        int r = numbers.size()-1;  // 右指针
        while (numbers[l+(r-l)/2]+numbers[l] > target)
            r = l + (r-l)/2 - 1;
        while (numbers[r]+numbers[l+(r-l)/2] < target)
            l = l + (r-l)/2 + 1;

        while (numbers[l]+numbers[r] != target){
            if (numbers[r] > target - numbers[l]){
                 r--;
            }
            else if (numbers[r] < target - numbers[l]){
                l++;
            }
        }

        // numbers 的下标 从 1 开始计数
        res.push_back(l+1);
        res.push_back(r+1);
        // 你可以假设每个输入只对应唯一的答案，而且你不可以重复使用相同的元素。
        return res;
    }
};

int main(){
//    输入：numbers = [2,7,11,15], target = 9
//    输出：[1,2]
    int arr[] = {2,7,11,15};
    vector<int> numbers(arr,arr+sizeof(arr)/sizeof(int));
    int target = 9;

    vector<int> res = Solution().twoSum(numbers, target);
    for (int num: res){
        cout<<num<<" ";
    }
}

