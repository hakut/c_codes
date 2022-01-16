/**
 * @file task1.c
 * @author Mehmet Samet HAKUT (msamet.hakut@protonmail.com)
 * @brief This program creates two linked lists and inserts random integers between 0 and 50 to list 1.
 * For list 2 program inserts random integers between 0 and 100. After these operations are done
 * program merges those two lists in one list and prints them.
 * 
 * @version 0.1
 * @date 2021-12-31
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdio.h>
#include <stdlib.h>

/* Linked list struct definition */
struct  ListNode{
    int data;
    struct ListNode *next;  
};

/* type definition to stop us from keep typing struct ListNode
instead just List */
typedef struct ListNode List;


/**
 * @brief Inserts the specified value to the argument linked list
 * 
 * @param start starting node of linked list
 * @param value value that will be inserted
 */
void insert(List **start, int value);
/**
 * @brief Creates random integers between 0 to 50 and inserts 5 of those values
 * to specified list and prints the list
 * 
 * @param start starting node of linked list
 */
void insert_to_list1(List **start);
/**
 * @brief Creates random integers between 0 to 100 and inserts 5 of those values
 * to specified list and prints the list
 * 
 * @param start starting node of linked list
 */
void insert_to_list2(List **start);
/**
 * @brief Merges two linked list and prints them
 * 
 * @param list1 linked list number 1
 * @param list2 linked list number 2
 */
void merge_list(List* list1, List* list2);

/**
 * @brief Creates two linked list. Inserts 5 random integers to each of them.
 * Merges them and prints them.
 * 
 * @return int 
 */
int main()
{
    List* list1 = NULL; // Linked list definitions
    List* list2 = NULL;

    insert_to_list1(&list1);    //  Calling functions
    insert_to_list2(&list2);

    merge_list(list1,list2);

    return 0;
}

void insert_to_list1(List **start)
{
    int i,j;
    /*  In a for loop we create random integer between 0 and 50
    and insert them to the list we create in main function for 5 times. */
    for(j = 0 ; j < 5 ; j++) {
        i = rand()%51;  //  Random integer between 0 to 50
        insert(start,i);
    }
    List* print_list = *start;
    printf("List 1 : ");
    while(print_list != NULL) {
        printf("%d -> ",print_list->data);
        print_list = print_list->next;
    }
    puts("NULL");
}
void insert_to_list2(List **start)
{
    int i,j;
    /*  In a for loop we create random integer between 0 and 100
    and insert them to the list we create in main function for 5 times. */
    for(j = 0 ; j < 5 ; j++) {
        i = rand()%101; //  Random integers between 0 to 100
        insert(start,i);
    }
    List* print_list = *start;
    printf("List 2 : ");
    while(print_list != NULL) {
        printf("%d -> ",print_list->data);
        print_list = print_list->next;
    }
    puts("NULL");
}

void insert(List **start, int value)
{
    List* new;  //  Node definitions
    List* previous = NULL;  //  For start previous node is NULL
    List* current = *start; // Our current node is start node and initially that also NULL

    new = malloc(sizeof(List *));   //  Memory allocation for our new node
    if(new != NULL){     // If we could allocate space from memory then assign value to new node value and NULL to the node pointer
        new->data = value;
        new->next = NULL;
    }


    /* If we have a value already and new value greater than the current node value
    assign current node as previous node and assign current next to the current.
    So, basically we shift through our linked list until we find a value lesser than
    our current node value */
    while( current != NULL && value > current->data ) {
        previous = current;
        current = current->next;
    }
    /*  If previous node is NULL that means we do not have any element in the list
    since we know that while statement shifts through list so previous shouldn't be NULL
    by now. In that case we assign new->next to start node of our linked list which is already NULL
    and our starting node becomes new node. */
    if( previous == NULL ) {
        new->next = *start;
        *start = new;
    }
    /* If we already have a value and the new value is lesser than current node data
    we assign previous next to new node and new node next to current which breaks linked list
    and places the new node in the middle somewhere. If that isn't the case that means our list has
    reached to the end which now shows NULL in that case previous next is NULL and current also NULL
    which means previous next is new node and new next is current which is NULL. Long story short
    new node added to the end of the list.  */
    else {
        previous->next = new;

        new->next = current;
    }

}

void merge_list(List *list1, List *list2)
{
    List* merged_list = NULL;   //  Merged list definition

    /*  We cycle through our list until list 1 is NULL.
    And if list 1 data greater than list2 data we insert lesser value
    to the merged list. Otherwise, we insert list1 data to the list.
    But we should consider that all of the lesser values in the list2.
    In that case we should consider the list2 != NULL.
    */
    while(list1 != NULL) {
        if(list2 != NULL && list1->data > list2->data) {
            insert(&merged_list,list2->data);
            list2 = list2->next;
        }
        else {
            insert(&merged_list,list1->data);
            list1 = list1->next;
        }
    }

    /*  If we have reached the end of the list 1 and list 2 still has elements
    Than we insert them one by one to the merged list since they are already in order.
    */
    while(list2 != NULL) {
        insert(&merged_list,list2->data);
        list2 = list2->next;
    }

    /*  Finally we print the merged list to see the result */
    printf("Merged List is : ");
    while (merged_list != NULL) {
        printf("%d -> ",merged_list->data);
        merged_list = merged_list->next;
    }
    puts("NULL");
}