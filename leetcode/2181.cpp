
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *mergeNodes(ListNode *head)
    {
        ListNode *Modified_head = new ListNode(0);
        ListNode *curr = head->next;
        ListNode *mcurr = Modified_head;
        while(curr){
            if(curr->val != 0){
                mcurr->val += curr->val;
            }else{
                ListNode *newNode = new ListNode(0);
                mcurr->next = newNode;
                mcurr = newNode;
            }
            curr = curr->next;
        }
        return Modified_head;
    }
};