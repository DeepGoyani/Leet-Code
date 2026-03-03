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
    int getlen(ListNode*&head){
        if(head==NULL){
            return 0;
        }
        ListNode* curr=head;
        int count=0;
        while(curr!=NULL){
            count++;
            curr=curr->next;
        }
        return count;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next == NULL){
            return head;
        }
        ListNode* temp = head;
        ListNode* prev = NULL;
        int x = getlen(head);
        k=k%x;
        if(k==0)
            return head;
        int y = x-k;
        while(y>0){
            prev = temp;
            temp = temp->next;
            y--;
        }
        if(prev->next!=NULL){
            prev->next =NULL;}
        ListNode* curr = temp;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next = head;
        return curr;
    }
};