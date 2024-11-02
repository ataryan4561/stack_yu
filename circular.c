#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node* next;
};
void Node_init(struct Node *wh,int ele)
{
    wh->data = ele;
    wh->next = NULL;
}
struct CircularLL
{
    struct Node* head;
    struct Node* tail;
    int siz;
    int max_ele;
};
void initilaize(struct CircularLL *l1,int max_ele)
{
    l1->head=NULL;
    l1->tail=NULL;
    l1->max_ele=max_ele;
    l1->siz=0;
}
void add_element(struct CircularLL *l1,int element)
{
    struct Node *n1 = (struct Node*)malloc(sizeof(struct Node));
    Node_init(n1,element);
    if(l1->head==NULL && l1->tail==NULL)
    {
        l1->head = n1;
        l1->tail = n1;
        l1->tail->next = l1->head;
        l1->siz+=1;
    }
    else if(l1->siz == l1->max_ele)
    {
        l1->tail->next = n1;
        n1->next = l1->head->next;
        struct Node *dele = l1->head;
        l1->head = l1->head->next;
        l1->tail = l1->tail->next;
        l1->tail->next = l1->head;
        free(dele);
    }
    else
    {
        l1->tail->next = n1;
        l1->tail = l1->tail->next;
        l1->tail->next = l1->head;
        l1->siz+=1;
    }
}
int delete_element(struct CircularLL *l1)
{
    if(l1->head==NULL)
        return -1;
    else 
    {
        if(l1->head->next==NULL)
        {
            l1->head = NULL;
            l1->tail = NULL;
        }
        l1->head = l1->head->next;
        l1->siz-=1;
        return 1;
    }
}
int main()
{
    struct CircularLL *l1 =(struct CircularLL*)malloc(sizeof(struct CircularLL));;
    initilaize(l1,5);
    printf("%d \n",l1->max_ele);
    add_element(l1,10);
    add_element(l1,14);
    add_element(l1,16);
    add_element(l1,19);
    add_element(l1,21);
    add_element(l1,23);
    add_element(l1,25);
    printf("%d \n",l1->siz);
    // display(l1);
    add_element(l1,27);
    printf("%d \n",delete_element(l1));
    // display(l1);
    printf("%d \n",l1->siz);
}