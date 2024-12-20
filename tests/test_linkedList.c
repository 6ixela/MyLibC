#include <criterion/criterion.h>
#include "../src/linkedList/linkedList.h"

Test(linkedList, test_create_node) {
    LinkedList *linkedList = create_list();
    cr_assert_not_null(linkedList, "list should not be empty");
    cr_assert_null(linkedList->head, "head should be empty");
    cr_assert_null(linkedList->print_func, "print function sould be set to null");
}

Test(linkedList, test_insert_head) {
    LinkedList *linkedList = create_list();

    int data = 5;
    insert_head(linkedList, (void *)&data);
    ListNode *head = linkedList->head;
    cr_assert_not_null(head, "head should not be empty");
    cr_assert_null(head->next, "next should be empty");
    cr_assert_eq(*(int *)head->data, 5, "data should be equal to 5");
}

Test(linkedList, test_insert_node) {
    LinkedList *linkedList = create_list();
    int data = 5;

    insert_tail(linkedList, (void *)&data);
    ListNode *head = linkedList->head;
    cr_assert_not_null(head, "head should not be empty");
    cr_assert_null(head->next, "next should be empty");
    cr_assert_eq(*(int *)head->data, 5, "data should be equal to 5");
}

Test(linkedList, test_insert_from) {
    LinkedList *linkedList = create_list();

    int data = 5;
    insert_node(linkedList, (void *)&data, 0);

    ListNode *head = linkedList->head;
    cr_assert_not_null(head, "head should not be empty");
    cr_assert_null(head->next, "next should be empty");
    cr_assert_eq(*(int *)head->data, 5, "data should be equal to 5");
}