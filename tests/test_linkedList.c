#include <criterion/criterion.h>
#include "../src/linkedList/linkedList.h"

Test(linkedList, test_create_node) {
    LinkedList *linkedList = create_list();
    cr_assert_not_null(linkedList, "list should not be empty");
    cr_assert_null(linkedList->head, "head should be empty");
    cr_assert_null(linkedList->print_func, "print function sould be set to null");
    free(linkedList);
}

Test(linkedList, test_insert_head) {
    LinkedList *linkedList = create_list();

    int data = 5;
    insert_head(linkedList, (void *)&data);
    ListNode *head = linkedList->head;
    cr_assert_not_null(head, "head should not be empty");
    cr_assert_null(head->next, "next should be empty");
    cr_assert_eq(*(int *)head->data, 5, "data should be equal to 5");
    free(linkedList);
}

Test(LinkedList, test_insert_head2) {
    LinkedList *list = create_list();
    int data1 = 1, data2 = 2;

    insert_head(list, &data1);
    cr_assert_not_null(list->head, "The list head should not be NULL.");
    cr_assert_eq(*(int *)list->head->data, 1, "The list head data should be 1.");

    insert_head(list, &data2);
    cr_assert_eq(*(int *)list->head->data, 2, "The new head should have data 2.");

    clear_list(list);
    free(list);
}

Test(linkedList, test_insert_tail) {
    LinkedList *linkedList = create_list();
    int data = 5;

    insert_tail(linkedList, (void *)&data);
    ListNode *head = linkedList->head;
    cr_assert_not_null(head, "head should not be empty");
    cr_assert_null(head->next, "next should be empty");
    cr_assert_eq(*(int *)head->data, 5, "data should be equal to 5");
    free(linkedList);
}

Test(LinkedList, test_insert_tail2) {
    LinkedList *list = create_list();
    int data1 = 1, data2 = 2;

    insert_tail(list, &data1);
    cr_assert_not_null(list->head, "The list head should not be NULL.");
    cr_assert_eq(*(int *)list->head->data, 1, "The list head data should be 1.");

    insert_tail(list, &data2);
    cr_assert_not_null(list->head->next, "The second element should not be NULL.");
    cr_assert_eq(*(int *)list->head->next->data, 2, "The second element's data should be 2.");

    clear_list(list);
    free(list);
}

Test(linkedList, test_insert_from) {
    LinkedList *linkedList = create_list();

    int data = 5;
    insert_node(linkedList, (void *)&data, 0);

    ListNode *head = linkedList->head;
    cr_assert_not_null(head, "head should not be empty");
    cr_assert_null(head->next, "next should be empty");
    cr_assert_eq(*(int *)head->data, 5, "data should be equal to 5");
    free(linkedList);
}

Test(LinkedList, test_delete_node) {
    LinkedList *list = create_list();
    int data1 = 1, data2 = 2;

    insert_head(list, &data1);
    insert_head(list, &data2);

    delete_node(list, &data1);
    cr_assert_not_null(list->head, "The list should not be empty after deletion.");
    cr_assert_eq(*(int *)list->head->data, 2, "The list head should have data 2.");

    delete_node(list, &data2);
    cr_assert_null(list->head, "The list should be empty after all elements are deleted.");

    free(list);
}

Test(LinkedList, test_reverse_list) {
    LinkedList *list = create_list();
    int data1 = 1, data2 = 2, data3 = 3;

    insert_tail(list, &data1);
    insert_tail(list, &data2);
    insert_tail(list, &data3);

    reverse_list(list);

    cr_assert_eq(*(int *)list->head->data, 3, "The reversed list head should have data 3.");
    cr_assert_eq(*(int *)list->head->next->data, 2, "The second element should have data 2.");
    cr_assert_eq(*(int *)list->head->next->next->data, 1, "The third element should have data 1.");

    clear_list(list);
    free(list);
}