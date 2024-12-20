#include "linkedList.h"

#include "stdlib.h"

ListNode *create_node(void *data)
{
    ListNode *new_node = malloc(sizeof(ListNode));
    if (new_node == NULL)
    {
        return NULL;
    }
    new_node->data = data;
    new_node->next = NULL;

    return new_node;
}

void insert_head(LinkedList *list, void *data)
{
    ListNode *new_node = create_node(data);
    new_node->next = list->head;
    list->head = new_node;
}

void insert_tail(LinkedList *list, void *data)
{
    ListNode *new_node = create_node(data);

    if (list->head == NULL)
    {
        list->head = new_node;
        return;
    }

    ListNode *current = list->head;
    while (current->next!= NULL)
    {
        current = current->next;
    }
    current->next = new_node;
}

void insert_node(LinkedList *list, void *data, int index)
{
    if (index <= 0)
    {
        insert_head(list, data);
        return;
    }
    ListNode *new_node = create_node(data);
    ListNode *current = list->head;
    int i = 0;
    while (current->next != NULL && i < index - 1)
    {
        current = current->next;
        i++;
    }
    new_node->next = current->next;
    current->next = new_node;
}

void delete_node(LinkedList *list, void *data)
{
    if (list->head == NULL)
    {
        return;
    }

    if (list->head->data == data)
    {
        ListNode *tmp = list->head;
        list->head = list->head->next;
        free(tmp);
        return;
    }
    ListNode *current = list->head;
    while (current->next != NULL && current->next->data != data)
    {
        current = current->next;
    }
    if (current->next == NULL)
    {
        return;
    }
    ListNode *tmp = current->next;
    current->next = current->next->next;
    free(tmp);
    return;
}
void delete_node_index(LinkedList *list, int index);

LinkedList *create_list()
{
    LinkedList *list = malloc(sizeof(LinkedList));
    if (list == NULL)
    {
        return NULL;
    }
    
    list->print_func = NULL;
    list->head = NULL;
    return list;
}

void reverse_list(LinkedList *list)
{
    list = list;
}

void clear_list(LinkedList *list)
{
    ListNode *current = list->head;
    while (current!= NULL)
    {
        ListNode *tmp = current;
        current = current->next;
        free(tmp);
    }
    list->head = NULL;
}