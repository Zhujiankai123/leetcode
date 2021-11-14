#include <iostream>
#include <string>

using namespace std;
class Solution {
public:
    bool detectCapitalUse(string word) {
        int lower = 0;
        int upper = 0;
        for(char c: word){
            if (c < 'a')
                upper++;
            else
                lower++;
        }
        if (lower == 0 || upper == 0)
            return true;
        if (upper == 1 && word.at(0) < 'a')
            return true;
        return false;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
