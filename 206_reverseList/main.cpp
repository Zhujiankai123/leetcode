#include <iostream>


// 定义Node节点
struct ListNode {
  int val; // Node节点有一个val值
  ListNode *next; //Node节点有一个next指针指向下一个节点
  ListNode() : val(0), next(nullptr) {} // 空构造方法,val和next都为空(0)
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = nullptr;
        ListNode* cur = head;

        while (cur){
            ListNode* next = cur->next;

            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
};

int main() {
    // before
    int head[5] = {1,2,3,4,5};
    ListNode* listNodeHead = new ListNode();
    ListNode* cur = listNodeHead;

    for(int x:head){
        cur->next = new ListNode(x);
        cur = cur->next;
    }

    // reverse
    Solution solution;
    ListNode* newHead = solution.reverseList(listNodeHead);

    // print
    cur = newHead;
    while (cur->next != nullptr){
        std::cout<<cur->val;
        cur = cur->next;
    }

    // after
    cur = listNodeHead->next;
    while(cur!= nullptr){
        ListNode* nextNode = cur->next;
        delete cur;
        cur = nextNode;
    }
    listNodeHead->next = nullptr;
    delete newHead;
}
