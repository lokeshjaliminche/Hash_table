#include <stdio.h>
#include <stdlib.h>
#include "hash.h"
#include "list.h"

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

static void init(void)
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
