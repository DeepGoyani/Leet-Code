/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
     ListNode* temp=head;
     ListNode* tail=head;

     while(tail!=nullptr&&tail->next!=nullptr){
        temp=temp->next;
        tail=tail->next->next;


        if(temp==tail){
            return true;
        }
     }
     return false;
    }
};

