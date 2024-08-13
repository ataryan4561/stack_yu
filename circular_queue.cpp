#include<bits/stdc++.h>
#include<iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node* next;
    Node()
    {
        this->next = nullptr;
    }
    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
    ~Node()
    {
        
    }
};
class Queue
{
    public:
    Node* head;
    Node* tail;
    int size_of_queue;
    int vari=0;
    Queue()
    {
        this->head = nullptr;
        this->tail = nullptr;
        this->size_of_queue=0;
    }
    Queue(int size)
    {
        this->head = nullptr;
        this->tail = nullptr;
        this->size_of_queue=size;
    }
    ~Queue()
    {
        while(head!=nullptr)
        {
            Node* t = head;
            head=head->next;
            t->next = NULL;
            delete t;
            vari--;
        }
    }
    void push_at_end(int data)
    {
        Node* new_node = new Node(data);
        if(!head)
        {
            head = new_node;
            tail = new_node;
            tail->next = head;
            vari++;
        }
        else if(vari<this->size_of_queue) 
        {
            tail->next = new_node;
            tail = new_node;
            tail->next=head;
            vari++;
        }
        else
        {
            tail->next = new_node;
            new_node->next = head->next;
            head = head->next;
            tail=tail->next;
        }
    }
    void pop_at_start()
    {
        if(!head)
        {
            cout<<"No element"<<endl;
        }
        else if(vari<this->size_of_queue)
        {
            head = head->next;
            vari--;
        }
        else
        {
            tail->next = NULL;
            head=head->next;
            vari--;
        }
    }
    int front()
    {
        return head->data;
    }
    void print_()
    {
        Node* run = head;
        int si = this->size_of_queue;
        while(si>0 && run)
        {
            cout<<run->data<<" ";
            run=run->next;
            si--;
        }
        cout<<endl;
    }
};
int main()
{
    Queue* s1 = new Queue(5);
    s1->push_at_end(10);
    s1->push_at_end(11);
    s1->push_at_end(13);
    s1->push_at_end(15);
    s1->push_at_end(16);
    cout<<s1->front()<<endl;
    s1->print_();
    s1->pop_at_start();
    s1->pop_at_start();
    s1->print_();
    cout<<s1->front()<<endl;
    s1->push_at_end(17);
    s1->push_at_end(19);
    s1->push_at_end(21);
    s1->push_at_end(31);
    cout<<s1->front()<<endl;
    s1->pop_at_start();
    cout<<s1->front()<<endl;
    s1->print_();
    delete s1;
}