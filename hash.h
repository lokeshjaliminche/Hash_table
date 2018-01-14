#define HASHMAP 10

struct node *hash_table[HASHMAP];

int hash(int data);

void display_hash(void);

struct node *insert_hash(int data);

