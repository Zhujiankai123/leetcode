#include <iostream>

using namespace std;

/*
 * 给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。
 * 说明：本题中，我们将空字符串定义为有效的回文串。
 */
class Solution {
public:
    bool isPalindrome(string s) {
        if (s.length() ==0)
            return true;

        int l = 0;
        int r = s.length()-1;
        while (l <= r){
            if (charTransfer(s[l]) == charTransfer(s[r])){
                l++;
                r--;
            }
            else {
                if (charTransfer(s[l]) == '\0')
                    l++; // 非字母和数字字符不做考虑
                else if (charTransfer(s[r]) == '\0')
                    r--;
                else // 非回文串
                    return false;
            }
        }
        return true;
    }

private:
    char charTransfer(char c){
        if (c>='0' && c<='9')
            return c;
        else if (c>='a' && c<='z')
            return c;
        else if (c>='A' && c<='Z')
            return c+('a'-'A');
        else
            return '\0';
    }
};

int main() {
//    string s =  "A man, a plan, a canal: Panama"; // 输出: true
    string s = "race a car"; //输出: false
    cout<<Solution().isPalindrome(s);
}
