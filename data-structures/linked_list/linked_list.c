#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;

struct Node {
    int data;
    Node* link;
};

Node* start = NULL;

void insert_begin(int data)
{
    Node* new = (Node*)malloc(sizeof(Node));
    new -> data = data;
    if ( start == NULL )
    {
        new -> link = NULL;
        start = new;
    }
    else
    {
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
        printf("Key Not Found\n");
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
    Node* ptr1;
    ptr = start;
    int del;
    if (ptr == NULL) {
        printf("list is empty. deletion not possible");
        return ;
    }
    else {

        while(ptr -> link != NULL)
        {
           ptr1 = ptr;
           ptr = ptr -> link;
        }
        ptr1->link = NULL;
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

void reverse()
{
    Node *p1, *p2, *p3;
    p1 = start;
    p2 = NULL;
    while( p1 != NULL )
    {
        p3 = p2;
        p2 = p1;
        p1 = p1->link;
        p2->link = p3;
    }
    start = p2;
}

int main(void)
{
    printf("<-- Linked List -->\n");
    printf("1. Insert from beginning\n");
    printf("2. Insert at end\n");
    printf("3. Insert at any position\n");
    printf("4. Delete from beginning\n");
    printf("5. Delete at end\n");
    printf("6. Delete at any position\n");
    printf("7. Reverse\n");
    printf("8. Sort\n");
    printf("9. Count\n");
    printf("10. Display\n");
    while(1) {
        printf("\nEnter choice: ");
        scanf("%d", &x);

        switch(x) {
            case 1: printf("Enter data to insert: ");
                    scanf("%d", &data);
                    insert_begin(data);
                    break;
            case 2: printf("Enter data to insert: ");
                    scanf("%d", &data);
                    insert_end(data);
                    break;
            case 3: printf("Enter position to insert: ");
                    scanf("%d", &pos);
                    printf("Enter data to insert: ");
                    scanf("%d", &data);
                    insert_any_position(pos, data);
                    break;
            case 4: delete_begin();
                    break;
            case 5: delete_end();
                    break;
            case 6: delete_any_position();
                    break;
            case 7: reverse();
                    break;
            case 8: sort();
                    break;
            case 9: count();
                    break;
            case 10: display();
                     break;
            case default: print("Wrong choice:\n"); break;
        }
    }
}
