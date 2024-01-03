#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* rotateRight(ListNode* head, int k) 
{
    if(head==nullptr || head->next==nullptr)
        return head;
    ListNode *temp = head;
    int len=0;
    while(temp!=nullptr)
    {
        len++;
        temp = temp->next;
    }
    k%=len;
    if(k==0)
        return head;
    temp = head;
    for(int i=1;i<len-k;i++)
        temp = temp->next;
    ListNode *newHead = temp->next;
    temp->next = nullptr;
    temp = newHead;
    while(temp->next!=nullptr)
        temp = temp->next;
    temp->next = head; 
    return newHead;
}
ListNode* rR(ListNode* head, int k) 
{
    vector<int> v;
    ListNode *temp = head;
    while(temp!=nullptr)
    {
        v.push_back(temp->val);
        temp = temp->next;
    }
    int n = v.size();
    k%=n;
    if(k==0) return head;
    reverse(v.begin(),v.end());
    reverse(v.begin(),v.begin()+k);
    reverse(v.begin()+k,v.end());
    temp = head;
    for(int i=0;i<n;i++)
    {
        temp->val = v[i];
        temp = temp->next;
    }
    return head;
}
signed main()
{
    ListNode *head = new ListNode(1);
    ListNode *temp = head;
    for(int i=2;i<=5;i++)
    {
        temp->next = new ListNode(i);
        temp = temp->next;
    }
    temp = head;
    while(temp!=nullptr)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
    temp = rotateRight(head,2);
    while(temp!=nullptr)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}