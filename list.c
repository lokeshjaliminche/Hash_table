#include <stdio.h>
#include <stdlib.h>
#include "list.h"

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

    while (temp)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

