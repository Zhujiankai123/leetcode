#include <iostream>
#include <vector>
using namespace std;

class SolutionOT {
    // OT
public:
    string minWindow(string s, string t) {
        /*
         * 寻找s中可以覆盖t中所有字符的最小子串
         * 当t中字符有重复时，s中符合题意的子串应当是对应字符的重复数量大于等于t中的重复数量
         */
        string res = s;
        int vec_size = 'z' - 'A' + 1;
        int s_len = s.length();
        int counts = 0;
        vector<int> s_vec(vec_size,0);
        vector<int> t_vec(vec_size,0);
        for(char c: t)
            t_vec[c-'A']++;

        int l = 0;
        for (int r = 0; r < s_len; ++r) {

            while (r < s_len && (s_vec[s[r]-'A'] < t_vec[s[r]-'A'])){
                if ( t_vec[s[r]-'A'] == 0 && !__containT(s_vec,t_vec)) {
                    r++;
                    continue;
                }
                s_vec[s[r++]-'A']++;
                counts++;
            }

            // 当前s[r]字符在子串s[l,r)中的数量已经可以比t中该字符等于t中的数量了
            // 判断此时子串s[l,r)是否能够覆盖t中所有字符
            if (counts >= t.length() && __containT(s_vec, t_vec)){
                while (l<r && (
                        t.find(s[l]) == string::npos  // s[l]不是t中的字符
                        || (s_vec[s[l]-'A'] > t_vec[s[l]-'A']) // 或者此时子串s[l,r)中s[l]字符的数量已经足够覆盖t
                )){
                    if (t.find(s[l]) != string::npos)
                        counts--;
                    s_vec[s[l++]-'A']--;
                }
                res = (res.size() > (r-l)) ? s.substr(l, r - l) : res;
            }
            if (t.find(s[r]) != string::npos)
                r--;
        }
        return __containT(s_vec, t_vec) ? res : "";
    }

private:
    bool __containT(vector<int> &s_vec, vector<int> &t_vec){
        // 判断t_vec中所有元素是否都包含在s_vec中
        for (int i = 0; i < t_vec.size(); ++i) {
            if (t_vec[i] == 0) continue;
            if (s_vec[i]<t_vec[i])
                return false;
        }
        return true;
    }
};

class Solution {
public:
    string minWindow(string s, string t) {
        int s_len = s.length();
        string res = string();

        vector<int> s_vec('z'-'A'+1,0);
        vector<int> t_vec('z'-'A'+1,0);
        string t_set = __initTVec(t, t_vec);

        int l = 0;
        for (int r = 0; r < s_len; ++r) {
            while (r < s_len){
                s_vec[s.at(r) - 'A']++;
                if (t_vec[s.at(r) - 'A'] != 0 && __contained(s_vec,t_vec,t_set)){
                    res = res.length() > r - l + 1 || res.length() == 0 ? s.substr(l, r - l + 1) : res;
                    break;
                }
                r++;
            }
            r = r > s_len-1 ? s_len-1 : r;

            while (l<=r && __contained(s_vec,t_vec,t_set)){
                res = res.length() > r - l + 1 ? s.substr(l, r - l + 1) : res;
                s_vec[s.at(l++) - 'A'] --;
            }
        }
        return res;
    }

private:
    string __initTVec(string &t, vector<int> &vec){
        string t_set = string();
        for(char c: t){
            if (vec[c-'A'] ==0 )
                t_set += c;
            vec[c-'A']++;
        }
        return t_set;
    }
    bool __contained(vector<int> &s_vec, vector<int> &t_vec,string &t_set){
        // 查看当前s_vec是否覆盖了t_vec中的所有元素
        for(char c : t_set){
            if (s_vec[c-'A'] < t_vec[c-'A'])
                return false;
        }
        return true;
    }
};

int main() {
    string s = "aaaaaaaaaaaabbbbbcdd";
    string t = "abcdd";

//    string s = "ADOBECODEBANC";
//    string t = "ABC";

//    string s = "a";
//    string t = "a";

//    string s = "a";
//    string t = "aa";

//    string s = "ab";
//    string t=  "a";

//    string s = "cabefgecdaecf";
//    string t= "cae";

//    string s = "ab";
//    string t = "b";

//    string s = "bba";
//    string t = "ab";

//    string s = "acbbaca";
//    string t = "aba";
    string res = Solution().minWindow(s,t);
    cout<<res;
    cout<<endl;
}
