#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct ListNode ListNode;
typedef void (*PrintFunc)(ListNode*);

struct ListNode
{
    void *data;
    ListNode *next;
};

typedef struct LinkedList
{
    PrintFunc print_func;
    ListNode *head;
} LinkedList;

ListNode *create_node(void *data);

void insert_head(LinkedList *list, void *data);
void insert_tail(LinkedList *list, void *data);
void insert_node(LinkedList *list, void *data, int index);

void delete_node(LinkedList *list, void *data);
void delete_node_index(LinkedList *list, int index);

LinkedList *create_list();

void reverse_list(LinkedList *list);

void clear_list(LinkedList *list);

#endif /* LINKED_LIST_H */