#include <iostream>
#include <vector>

using namespace std;
/*
 * 给你两个有序整数数组nums1 和 nums2，请你将 nums2 合并到nums1中，使 nums1 成为一个有序数组。
 * 初始化nums1 和 nums2 的元素数量分别为m 和 n 。你可以假设nums1 的空间大小等于m + n，这样它就有足够的空间保存来自 nums2 的元素。
 *
 * 关键词：给定两个数组，这两个数组是有序的，要求将nums2的内容合并到nums，并保证有序性。默认提供的nums1长度足够大
 */
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        assert(m + n == nums1.size());

        vector<int> nums1_tmp;
        for (int i = 0; i < m; ++i) {
            nums1_tmp.push_back(nums1[i]);
        }
/*
        cout<<endl<<"nums1_tmp:"<<endl;
        for (int num:nums1_tmp)
            cout<<num<<" ";
*/
        // 使用归并排序将nums1_tmp与nums2两个数组归并到nums1中
        int cnt = 0;
        int cn2 = 0;
        int cn1 = 0;

        //
        while (cn1 < m + n ){
//            cout<<"cn1= "<<cn1<<",cnt1= "<<cnt<<",cn2= "<<cn2<<endl;
            if (cnt<m && (cn2 == n || nums1_tmp[cnt] <= nums2[cn2])) {
                    nums1[cn1++] = nums1_tmp[cnt];
                    cnt++;
                }

            else if(cnt == m || nums1_tmp[cnt] > nums2[cn2]){
                    nums1[cn1++] = nums2[cn2];
                    cn2++;
                }
        }
    }
};

int main() {
    int arr1[] = {1,2,4,5,6,0};
    int arr2[] = {3};

//    int arr1[] = {1,2,3,0,0,0};
//    int arr2[] = {2,5,6};

//    int arr1[] = {1};
//    int arr2[] = {};

//    int arr1[] = {4,5,6,0,0,0};
//    int arr2[] = {1,2,3};

//    int arr1[] = {6,0};
//    int arr2[] = {1};

//    int arr1[] = {1,0};
//    int arr2[] = {2};

//    int arr1[] = {0};
//    int arr2[] = {1};

//    int arr1[] = {4,0,0,0,0,0};
//    int arr2[] = {1,2,3,5,6};
    vector<int> nums1(arr1,arr1+sizeof(arr1)/sizeof(int));
    vector<int> nums2(arr2,arr2+sizeof(arr2)/sizeof(int));

    cout<<endl<<"nums1:"<<endl;
    for (int num:nums1)
        cout<<num<<" ";
    cout<<endl<<"nums2:"<<endl;
    for (int num:nums2)
        cout<<num<<" ";

    Solution().merge(nums1,5,nums2,1);

    cout<<endl<<endl<<"after merge"<<endl;
    cout<<endl<<"nums1:"<<endl;
    for (int num:nums1)
        cout<<num<<" ";
    cout<<endl<<"nums2:"<<endl;
    for (int num:nums2)
        cout<<num<<" ";
}
