/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int getlen(ListNode*& head){
        if(head==NULL){
            return 0;
        }
        ListNode* curr= head;
        int count=0;
        while(curr!=NULL){
            count++;
            curr=curr->next;
        }
        return count;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL || head->next==NULL){
            return NULL;
        }
        int len=getlen(head);
        ListNode* prev = NULL;
        ListNode* curr = head;
        int x = len-n;
        if(x==0){
            head=head->next;
            return head;
        }
        while(x>0){
            prev=curr;
            curr=curr->next;
            x--;
        }
        prev->next = curr->next;
        return head;
    }
};