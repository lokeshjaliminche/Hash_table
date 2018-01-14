#include <stdio.h>
#include <stdlib.h>
#define HASHMAP 10

struct node
{
    int data;
    struct node *next;
};

struct node *hash_table[HASHMAP];

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

int hash(int data)
{
    int key = data % HASHMAP;
}
struct node *insert_hash(int data)
{
    int key = hash(data);
    hash_table[key] = insert(hash_table[key], data);
}

void display_hash()
{
    for (int i = 0; i < HASHMAP; i++)
    {
        printf("for key %d\n", i);
        display(hash_table[i]);
    }

}
void init(void)
{
    for (int i = 0; i < HASHMAP; i++)
    {
        hash_table[i] = NULL;
    }
}
int main()
{
    init();
    insert_hash(10);
    insert_hash(10);
    insert_hash(10);
    insert_hash(11);
    insert_hash(12);
    insert_hash(13);
    insert_hash(14);
    display_hash();
}
