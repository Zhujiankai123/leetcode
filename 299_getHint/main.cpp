#include <iostream>
#include <string>
#include <map>

/*
 * xA: 有x个数字的数值及所在位置都是正确的
 * yB: 有y个数字的数值正确，但是所在位置不正确
 */
using namespace std;
class Solution {
public:
    string getHint(string secret, string guess) {
        assert(secret.length() == guess.length());
        string res;
        int n = secret.length();
        int nums_of_a = 0;
        int nums_of_b = 0;
        map<char,int> s_map = map<char,int>();
        map<char,int> g_map = map<char,int>();

        for (int i = 0; i < n; ++i) {
            if (secret.at(i) == guess.at(i))
                nums_of_a ++;
            else{
                s_map[secret.at(i)]++;
                g_map[guess.at(i)]++;
            }
        }

        for (auto iter = g_map.begin();iter != g_map.end();iter++) {
            char c = iter->first;
            if (s_map[c] != 0){
                nums_of_b += min(s_map[c],g_map[c]);
            }
        }

        res = to_string(nums_of_a) + "A" + to_string(nums_of_b) + "B";
        return res;
    }
};

int main() {
    string secret = "1807";
    string guess = "7810";

    Solution solution = Solution();
    cout<<solution.getHint(secret,guess)<<endl;
}
