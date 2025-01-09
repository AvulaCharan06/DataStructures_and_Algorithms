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
    ListNode* findNthNode(ListNode* head, int k){
      int cnt =1;
      ListNode* temp = head;
      while(temp != NULL){        
         if(cnt == k) break;
         cnt++;
         
         temp = temp->next;
      }
      return temp;
   }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL) return head;
         ListNode* tail = head;
         int len =1;
         while(tail->next != NULL){
            len++;
            tail = tail->next;
         }
         if(k % len == 0) return head;
         k = k % len;
         
         tail->next = head;
         ListNode* newtail = findNthNode(head, len-k);
         head = newtail->next;
         newtail->next = nullptr;

         return head;

    }
};