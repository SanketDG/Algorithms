#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* link;
};

typedef struct Node Node;

Node* start = NULL;

void insert_begin(int data)
{
    Node* new = (Node*)malloc(sizeof(Node));
    if ( start == NULL )
    {
        new -> data = data;
        new -> link = NULL;
        start = new;
    }
    else
    {
        new -> data = data;
        new -> link = start;
        start = new;
    }
}

void insert_end(int data)
{
    Node* ptr;
    ptr = start;
    Node* new = (Node*)malloc(sizeof(Node));
    new -> data = data;
    new -> link = NULL;
    if (start == NULL) {
        start = new;
    }
    else {
        while(ptr->link != NULL) {
            ptr = ptr->link;
        }
        ptr -> link = new;
    }
}

void insert_any_position(int data, int key)
{
    Node* new = (Node*)malloc(sizeof(Node));
    Node* ptr;
    ptr = start;
    while((ptr -> data != key) && (ptr != NULL))
    {
        ptr = ptr -> link;
    }
    if (ptr == NULL)
    {
        printf("key not found\n");
    }
    else
    {
        new -> link = ptr -> link;
        new -> data = data;
        ptr -> link = new;
    }
}


int delete_begin()
{
    Node* ptr;
    ptr = start;
    if(start == NULL) {
        printf("Linked List empty. Deletion not possible.\n");
        return ;
    }
    else {
        start = start -> link;
        ptr -> link = NULL;
        return ptr -> data;
    }
}

int delete_end()
{
    Node* ptr;
    ptr = start;
    if (ptr == NULL) {
        printf("list is empty. deletion not possible");
        return ;
    }
    else {

        while(ptr -> link != NULL)
        {
            if(ptr->link->link == NULL)
            {
                int del =  ptr->link->data;
                ptr->link = NULL;
                return del;
            }
            ptr = ptr->link;
        }
        ptr->link = NULL;
        return ptr->data;

   }
}

int delete_any_position(int key)
{
    Node* ptr;
    Node* ptr1;
    ptr = start;
    while(ptr != NULL)
    {
        if(ptr->data != key)
        {
            ptr1 = ptr;
            ptr = ptr -> link;
        }
        else
        {
            ptr1 -> link = ptr -> link;
            return ptr->data;
        }
    }
}

void display()
{
    Node* ptr;
    ptr = start;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr -> link;
    }
    printf("\n");
}

int count()
{
    Node* ptr;
    ptr = start;
    int c;

    c = 0;


    while(ptr != NULL) {
        c++;
        ptr = ptr -> link;
    }

    printf("Count : %d\n", c);
}

void sort()
{
    Node* ptr;
    int flag = 0, temp;

    do {
        ptr = start;
        flag = 0;
        while(ptr->link != NULL)
        {
            if(ptr->link->data < ptr->data)
            {
                temp = ptr->link->data;
                ptr->link->data = ptr->data;
                ptr->data = temp;
                flag = 1;
            }
            ptr = ptr->link;
        }
    }
    while(flag == 1);
}


int main(void)
{
    printf("<-- Linked list -->\n");


    insert_begin(10);
    insert_begin(9);
    insert_begin(5);
    insert_begin(40);
    insert_any_position(60, 5);
    insert_end(20);

    int del = delete_end(20);
    int del1 = delete_any_position(5);

    count();

    sort();

    display();
}