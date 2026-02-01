// Leetcode 382: Linked List Random Node
#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr){} 
    ListNode(int x) : val(x), next(nullptr){} 
    ListNode(int x, ListNode *next) : val(x), next(next){}
};

class Solution
{
private:
    ListNode *head;
    vector<int> vals;

public:
    Solution(ListNode *head)
    {
        while (head)
        {
            vals.push_back(head->val);
            head = head->next;
        }
    }

    int getRandom()
    {
        int idx = rand() % vals.size();
        return vals[idx];
    }
};
