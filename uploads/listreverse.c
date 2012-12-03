#include <stdio.h>

struct node {
    int value;
    struct node* next;
};

void reverse(struct node* head);
void tailreverse(struct node* head, struct node* newhead);
struct node * reverse_recursion(struct node * head);

void print_list(struct node const* head);

int main(void)
{
    struct node a = { 0, NULL },
                b = { 1, &a },
                c = { 2, &b }; // c(2) -> b(1) -> a(0) -> NULL
    print_list(&c);
    reverse(&c); // changed to a(0) -> b(1) -> c(2) -> NULL
    print_list(&a);
    return 0;
}

void print_list(struct node const* head)
{
    printf("[");
    for (; NULL != head; head = head->next) {
        printf(" %d", head->value);
    }
    printf(" ]\n");
}

struct node** _reverse(struct node* n)
{
    if (NULL != n->next)
        *_reverse(n->next) = n;
    return &(n->next);
}

void reverse(struct node* head)
{
    if (NULL != head) {
        /**_reverse(head) = NULL;*/
        reverse_recursion(head);
    }
}

struct node * reverse_recursion(struct node* head) {
   if (head->next != NULL) {
       /* code */
       struct node * tail = head;
       head = reverse_recursion(head->next);
       tail->next->next = tail;
       tail->next = NULL;
   }
   return head;
}

struct node *reverse_norecursion(struct node* head) {
    struct node * newhead = NULL;
    struct node * p;

    while (head != NULL) {
        /* code */
        p = head;
        head = head->next;
        p->next = NULL;
        newhead = p;
    }
    return newhead;
}
