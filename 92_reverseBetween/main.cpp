#include <iostream>

using namespace std;

/*
 * 给你单链表的头指针 head 和两个整数left 和 right ，其中left <= right 。
 * 请你反转从位置 left 到位置 right 的链表节点，返回 反转后的链表 。
 */
struct ListNode {
 int val;
 ListNode *next;
 ListNode() : val(0), next(nullptr) {}
 ListNode(int x) : val(x), next(nullptr) {}
 ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        // 注意left和right的索引是从1开始的
        ListNode* dummyNode = new ListNode(0);
        dummyNode->next = head;
        ListNode* pre = dummyNode;
        for (int i = 0; i < left-1; ++i) {
            pre = pre->next;
        }
        ListNode* cur = pre->next;
        ListNode* next;
        int cnt = 0;
        while (cnt <= right - left && cur->next){
            next = cur->next->next;
            

        }
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
