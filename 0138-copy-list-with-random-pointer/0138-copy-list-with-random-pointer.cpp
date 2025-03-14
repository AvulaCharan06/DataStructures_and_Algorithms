/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    void InsertNodes(Node* head){
        Node* temp = head;
        while(temp != NULL){
            Node* nexNode = temp->next;
            Node* copyNode = new Node(temp->val);
            copyNode->next = nexNode;
            temp->next = copyNode;
            temp = nexNode;
        }
    }
    void connectRandom(Node* head){
        Node* temp = head;
        while(temp != NULL){
           Node* copyNode = temp->next;
           if(temp->random){
            copyNode->random = temp->random->next;
           }else{
             copyNode->random = NULL;
           }
           temp = temp->next->next;
        }
    }
   
Node* getCopyList(Node* head){
     Node* dummyNode = new Node(-1);
     Node* res = dummyNode;
     Node* temp = head;
    while(temp != NULL){
         res->next = temp->next;
         res = res->next;

         temp->next = temp->next->next;
         temp = temp->next;
       }
       return dummyNode->next;
    }
    Node* copyRandomList(Node* head) {
       InsertNodes(head);
       connectRandom(head);
       return getCopyList(head);
    }
};