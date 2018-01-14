struct node
{
    int data;
    struct node *next;
};


struct node *insert(struct node *head, int data);


struct node *delete(struct node *head, int data);


void display(struct node *head);
