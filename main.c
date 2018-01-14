#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};


struct node *insert(struct node *head, int data)
{
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->data = data;
    node->next = NULL;

    if (head == NULL)
    {
        head = node;
        return head;
    }
    else
    {
        struct node *temp = head;
        while(temp->next)
        {
            temp = temp->next;
        }
        temp->next = node;
        return head;
    }
}

struct node *delete(struct node *head, int data)
{
    struct node *temp = head;
    struct node *tempd = NULL;
    struct node *prev  = NULL;
    while(temp)
    {
        if (temp->data == data)
        {
            tempd = temp;
            if(prev)
                prev->next = temp->next;
            else
                head = temp->next;

            break;
        }
        prev = temp;
        temp = temp->next;
    }
    free(tempd);
    return head;
}

void display(struct node *head)
{
    struct node *temp;
    temp = head;

    printf("list\n");
    while (temp)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

int main()
{
    struct node *head = NULL;
    head = insert(head, 10);
    head = insert(head, 11);
    head = insert(head, 12);
    head = insert(head, 13);
    head = insert(head, 14);
    display(head);
    head = delete(head, 14);
    display(head);
}
