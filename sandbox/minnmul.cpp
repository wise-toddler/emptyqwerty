#include <bits/stdc++.h>
using namespace std;

// make doubly linked list
struct Node {
    int data;
    Node* next;
    Node* prev;
};
struct dll
{
    Node* head;
    Node* tail;
};
struct cuscmp {
    bool operator()(Node* a, Node* b) {
        return a->data < b->data;
    }
};
int main() {
    // [45,17,34,27,12,22]
    vector<int> arr = {45,17,34,27,12,22};
    // convert array to doubly linked list
    dll* list = new dll();
    list->head = new Node();
    list->head->data = arr[0];
    list->head->prev = NULL;
    list->head->next = NULL;
    list->tail = list->head;
    for(int i = 1; i < arr.size(); i++) {
        Node* temp = new Node();
        temp->data = arr[i];
        temp->prev = list->tail;
        temp->next = NULL;
        list->tail->next = temp;
        list->tail = temp;
    }
    // make a pq and insert all the elements ans sort them acc to the value
    priority_queue<Node*, vector<Node*>, cuscmp> pq;
    Node* temp = list->head;
    temp=temp->next;
    while(temp != list->tail) 
    {
        pq.push(temp);
        temp = temp->next;
    }
    int score = 0;
    while(pq.size())
    {
        Node* a = pq.top(); pq.pop();
        score += a->data*(a->prev->data)*(a->next->data);
        // delete a from the list
        Node* prev = a->prev;   
        Node* next = a->next;
        prev->next = next;
        next->prev = prev;
    }
    cout << score << endl;
    return 0;
}
