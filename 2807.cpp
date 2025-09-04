// LeetCode 2807. Insert Greatest Common Divisors in Linked List
#include <bits/stdc++.h>
using namespace std;

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
    ListNode *insertGreatestCommonDivisors(ListNode *head)
    {
        if (!head || !head->next)
        {
            return head;
        }
        ListNode *prev = head;
        ListNode *curr = head->next;
        while (curr)
        {
            int g = gcd(prev->val, curr->val);
            ListNode *newnode = new ListNode(g, curr);
            prev->next = newnode;
            prev = curr;
            curr = curr->next;
        }
        return head;
    }

private:
    int gcd(int a, int b)
    {
        while (b != 0)
        {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
};