#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

// OT
using namespace std;

class Solution {
public:
    int findMinStep(string board, string hand) {
        //1 <= board.length <= 16
        //1 <= hand.length <= 5
        // 从你手上的彩球中选出 任意一颗 ，然后将其插入桌面上那一排球中：两球之间或这一排球的任一端。

        int min_step = hand.length()+1;
        // 遍历board，如果board[i]==board[i+1],则合并
        string board_new;
        for (int i = 0; i < board.length(); ++i) {
            if (i != board.length()-1 && board.at(i) == board.at(i+1)){
                board_new += (board.at(i) + ('a' - 'A'));
                i++;
            }
            else
                board_new += board.at(i);
        }

        unordered_map<string,vector<string>> mem; // k: 从hand中已插入的字符 v: 插入后board的情况
        vector<string> vec = vector<string>();
        vec.push_back(board_new);
        mem[""] = vec;
        min_step = recursionClean(hand, "", mem,min_step);
        return min_step > hand.length() ? -1 : min_step;
    }

    int recursionClean(string in_hand, string off_hand, unordered_map<string,vector<string>> &mem,int minstep){
        // in_hand: 当前手牌
        // off_hand: 已打出去的牌
        // board: 当前牌桌上可能的牌型
        if (in_hand.length() == 0) {
            for (string s: mem[off_hand]) {
                if (s.length() == 0)
                    return minstep > off_hand.length() ? off_hand.length() : minstep;
            }
            return minstep;
        }
        for (int i = 0; i < in_hand.length(); ++i) {
            for (string s: mem[off_hand]){
               if (s.length() == 0)
                   return minstep > off_hand.length() ? off_hand.length() : minstep;
                // 将in_hand.at(i)依次插入到s的各个位置，返回移除连续同色球后的字符串数组
                vector<string> tmp = insertChar(s, in_hand.at(i));
                if (mem[off_hand+in_hand.at(i)].empty())
                    mem[off_hand+in_hand.at(i)] = tmp;
                else {
                    mem[off_hand+in_hand.at(i)].insert(
                            mem[off_hand+in_hand.at(i)].end(),
                            tmp.begin(),
                            tmp.end()
                            );
                }
            }
             int steps = recursionClean(in_hand.substr(0,i)+in_hand.substr(i+1),
                           off_hand+in_hand.at(i),
                           mem,minstep);
            minstep = minstep > steps ? steps : minstep;
        }
        mem.erase(off_hand);
        return minstep;
    }

    vector<string> insertChar(string s, char c){
        // 向字符串s中各个位置插入字符c，返回移除掉同色球、合并同色球(相同大写字母)的结果
        vector<string> res = vector<string>();
        for (int i = 0; i <= s.length(); ++i) {
            string new_s = s.substr(0,i) + c + s.substr(i);
            res.push_back(reduceString(new_s));
        }
        return res;
    }

    string reduceString(string s){
        // 如果是两个相同字符(大写),则合并为一个小写字符
        // 如果是两个相同字符(一大一小，或两小)，则删除这两个字符
        if (s.length() < 2)
            return s;

        string new_s;
        int i = 0; // new_s pointer
        while (i < s.length()-1){
            if (s.at(i) == s.at(i+1) && s.at(i)< 'a') {
                new_s += (s.at(i) + 'a' - 'A');
                i += 2;
                continue;
            }
            if (s.at(i) == s.at(i+1) && s.at(i) > 'a') {
                i += 2;
                continue;
            }
            if (abs(s.at(i) - s.at(i+1)) == ('a' - 'A')){
                i += 2;
                continue;
            }
            new_s += s.at(i);
            i++;
        }
        if (i == s.length()-1)
            new_s += s.at(i);

        if (s == new_s)
            return s;
        string tmp_s = reduceString(new_s);
        return (new_s == tmp_s ? new_s : tmp_s);
    }
};


int main() {

    string board , hand;
//    board = "WWRRBBWW";
//    hand = "WRBRW";
//    board = "BB", hand = "B";
//    board = "RBYYBBRRB", hand = "YRBGB";
//    board = "G", hand = "GGGGG";
//    board = "WWRRBBWW", hand = "RB";
//    board = "WWGWGW";
//    hand = "GWW";
//    board = "WRRBBW";
//    hand = "RB";
    board = "R";
    hand = "RR";
    Solution solution = Solution();
    cout<<solution.findMinStep(board,hand)<<endl;
};
