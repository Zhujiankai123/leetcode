#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
 * 给定两个字符串s和 p，找到s中所有p的异位词的子串，返回这些子串的起始索引。不考虑答案输出的顺序。
 * 异位词 指字母相同，但排列不同的字符串。
 */
class Solution {
    // OT
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        int l = 0;
        int r = p.length()-1;

        if (s.length()<p.length())
            return res;
        // 如果当前子串s[l,r]与p互为异位词的，则添加当前的起始索引l
        if (r - l + 1  == p.length() && isAnagrams(s.substr(l, r-l+1),p))
            res.push_back(l);

        while (r < s.length()-1){

            while (r < s.length()-1 && p.find(s.at(r+1)) == string::npos){
                // 如果下一个要遍历到的s的元素不是p中的元素，令整个数组前移1个单位
                l++;
                r++;
            }

            while (r < s.length()-1 && p.find(s.at(r+1)) != string::npos){
                // 如果下一个遍历到的s的元素是p中的元素，查看s[l+1,r+1]是否与p互为异位词
                // 如果当前子串s[l,r]与p互为异位词的，则添加当前的起始索引l
                l++;
                r++;
                if (r - l + 1  == p.length() && isAnagrams(s.substr(l, r-l+1),p))
                    res.push_back(l);
            }
        }
        return res;
    }

private:
    bool isAnagrams(string s1, string s2){
        assert(s1.length() == s2.length());
        unordered_map<char,int> map1;
        unordered_map<char,int> map2;
        for (int i = 0; i < s1.length(); ++i) {
            map1[s1.at(i)]++;
            map2[s2.at(i)]++;
        }
        for (auto & iter : map1) {
            if (map2.find(iter.first) == map2.end() || map2.at(iter.first) != iter.second)
                return false;
        }
        return true;
    }
};

int main() {

    /* 输出: [0,6]
     * 解释:
     * 起始索引等于 0 的子串是 "cba", 它是 "abc" 的异位词。
     * 起始索引等于 6 的子串是 "bac", 它是 "abc" 的异位词
     */
//    string s = "cbaebabacd";
//    string p = "abc";

//    string s = "abab" ;
//    string p = "ab";

//    string s = "aa";
//    string p = "bb";

    string s = "aaaaaaaaaa";
    string p = "aaaaaaaaaaaaa";
    vector<int> res = Solution().findAnagrams(s,p);
    for(int n : res)
        cout<<n<<" ";

}
