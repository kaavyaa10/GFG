/* structure for a node
class Node {
 public:
  int data;
  Node *next;

  Node(int x){
      data = x;
      next = NULL;
  }
}; */

class Solution {
  public:
    Node* sortedInsert(Node* head, int data) {
        // code here
        Node* node = new Node(data);
        Node* ptr = head;
        if(ptr->data>=node->data){
            while(ptr->next!=head){
                ptr=ptr->next;
            }
            node->next = head;
            ptr->next = node;
            head = node;
            return head;
        }
        while(ptr->next->data<node->data && ptr->next!=head){
            ptr = ptr->next;
        }
        node->next = ptr->next;
        ptr->next = node;
        return head;
    }
};