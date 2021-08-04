#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = 0;
        int l = 0; // 从string[l,r)的子串都是不重复的元素
        unordered_set<char> substring;

        for (int r = 0; r < s.length();) {
            /*while (r < s.length() && substring.find(s.at(r)) == string::npos){*/
            while (r < s.length() && substring.find(s.at(r)) == substring.end()){
                // 当前考察的元素s[r]如果在子串中没有记录，将该字符加入到子串中
                /*substring += s.at(r);*/
                substring.insert(s.at(r));
                len = (r - l + 1 > len) ? (r - l + 1 ) : len;
                r++;
            }
            /*while (r < s.length() && l < r && substring.find(s.at(r)) != string::npos){*/
            while (r < s.length() && l < r && substring.find(s.at(r)) != substring.end()){
                // 当前考察的元素s[r]如果已经在子串中了，令左指针右移，直到不存在重复未知
                /*substring = substring.substr(1,substring.length()-1);*/
                substring.erase(s.at(l));
                l++;
            }
        }

        return len;
    }
};

int main() {
//    string s = ""; // 输出: 0
    string s = "abcabcbb"; // 输出: 3 解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
//    string s = "bbbbb"; // 输出: 1
//    string s = "pwwkew"; // 输出: 3
    int lens =  Solution().lengthOfLongestSubstring(s);
    cout<<lens;
}
