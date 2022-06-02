#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    struct node *next;
    int data;
} node_t;

node_t *insert_node(node_t *head,int val);
void delete_node(node_t *head,node_t *node);
void print_node(node_t *head);

int main(int argc, char const *argv[])
{
    node_t *head = NULL;
    head =  (node_t*)malloc(sizeof(node_t));
    head->data = 1;
    head->next = NULL;
    node_t *cur = NULL;
    cur = insert_node(head,2);
    cur = insert_node(head,3);
    print_node(head);
    delete_node(head,head);
    print_node(head);
}

node_t *insert_node(node_t *head,int val){
    node_t *current = head;
    while (current->next !=NULL)
    {
        current = current->next;
    }
    current->next = (node_t*)malloc(sizeof(node_t));
    current->next->data = val;
    current->next->next = NULL;
    return current->next;
}

void delete_node(node_t *head,node_t *node)
{
    if(node == head){
         head = head->next;
    }
    else
    {
        node_t *tmp = head;
        while (tmp->next!=node)
        {
              tmp = tmp->next;
        }
        tmp->next = node->next;
    }
    //free(node);
   
}

void print_node(node_t *head){
    node_t *current = head;
    while (current!=NULL)
    {
        printf("%d\n",current->data);
        current = current->next;
    }   
}

