#include<stdio.h>
#include <stdlib.h>
#include "sort_list.h"
 
struct node *sort_list(struct node *head) {
    if (!head || !head->next_node) return head;
 
    struct node *sorted = NULL; // Start of the sorted linked list
 
    while (head) {
        struct node *current = head;
        head = head->next_node; // Advance the head
 
        if (!sorted || current < sorted) {
            // Insert at the beginning of the sorted list
            current->next_node = sorted;
            sorted = current;
        } else {
            // Find the correct position in the sorted list
            struct node *temp = sorted;
            while (temp->next_node && temp->next_node < current) {
                temp = temp->next_node;
            }
            // Insert the current node
            current->next_node = temp->next_node;
            temp->next_node = current;
        }
    }
 
    return sorted;
}