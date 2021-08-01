#include <iostream>
#include <unordered_set>

using namespace std;

/*
 * 编写一个函数，以字符串作为输入，反转该字符串中的元音字母。
 */
class Solution {
public:
    string reverseVowels(string s) {
        if (s.length() == 0)
            return s;

        unordered_set<char> vowelsSet = {'a','e','i','o','u','A','E','I','O','U'};
        int l = 0;
        int r = s.length()-1;
        while (l<r){
            while (l<r && vowelsSet.find(s.at(l)) == vowelsSet.end())
                l++;
            while (l<r && vowelsSet.find(s.at(r)) == vowelsSet.end())
                r--;
            if (l<r){
                swap(s.at(l++),s.at(r--));
            }
        }
        return s;
    }
};

int main() {
//    string s = "hello"; // 输出："holle"
//    string s = "leetcode"; // 输出："leotcede"
    string s = " ";
    string res = Solution().reverseVowels(s);
    cout<<res;
}
