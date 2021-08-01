#include <iostream>
#include <map>

/**
 * 给你一个字符串 time ，格式为 hh:mm（小时：分钟），其中某几位数字被隐藏（用 ? 表示）。
 * 有效的时间为 00:00 到 23:59 之间的所有时间，包括 00:00 和 23:59 。
 * 替换time 中隐藏的数字，返回你可以得到的最晚有效时间。
 *
 */
using namespace std;

class Solution {
public:
    string maximumTime(string time) {
        if (time[0] == '?')
            time[0] = (time[1] !='?' && time[1]> '3' ? '1' : '2');
        if (time[1] == '?')
            time[1] = (time[0] == '2' ? '3' : '9');
        if (time[3] == '?')
            time[3] = '5';
        if (time[4] == '?')
            time[4] = '9';
        return time;
    }
};


class Solution1 {
public:
    string maximumTime(string time) {
        map<char,char> hour1;
        map<char,char> hour2;
        map<char,char> minute1;
        map<char,char> minute2;
        string res = time;

        for (int i = 0; i < 3; ++i) {
            if(i<2)
                hour1[i+'0'] = '9';
            else
                hour1['2'] = '3';
        }

        for (int i = 0; i < 10; ++i) {
            if (i<=3)
                hour2[i+'0'] = '2';
            else
                hour2[i+'0'] = '1';
        }

        for (int i = 0; i < 6; ++i) {
            minute1[i+'0'] = '9';
        }

        for (int i = 0; i <= 9; ++i) {
            minute2[i+'0'] = '5';
        }

        //
       if (time[0] == '?' && time[1] == '?'){
           res[0] = '2';
           res[1] = '3';
       }

       if (time[3] == '?' && time[4] == '?'){
           res[3] = '5';
           res[4] = '9';
       }
        for (int i = 0; i < time.size();++i) {
            if (time[i] == '?'){
                continue;
            }
            else{
                res[i] = time[i];
                if (i == 0 && time[1] =='?')
                    res[1] = hour1[time[i]];
                else if (i == 1 && time[0] =='?')
                    res[0] = hour2[time[i]];
                else if (i == 3 && time[4] =='?')
                    res[4] = minute1[time[i]];
                else if (i == 4 && time[3] =='?')
                    res[3] = minute2[time[i]];
                else res[2] = ':';
            }
        }

        return res;
    }
};

int main() {
//    string time = "2?:?0"; // 输出："23:50"
//    string time = "0?:3?"; // 输出："09:39"
    string time = "1?:22"; // 输出："19:22"

    string res = Solution().maximumTime(time);
    cout<<res;

}
