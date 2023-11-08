#include <stdio.h>
#include <stdlib.h>

// A node in the linked list
struct node {
    int data;
    struct node *next;
    struct node *child;
};

// Function to restructure the linked list
struct node* restructure(struct node *head) {
    struct node *new_head = NULL;
    struct node *new_tail = NULL;
    struct node *cur = head;

    while (cur != NULL) {
        // Add the current node to the new linked list
        if (new_head == NULL) {
            new_head = cur;
            new_tail = cur;
        } else {
            new_tail->next = cur;
            new_tail = cur;
        }

        // Add the child linked list to the new linked list
        if (cur->child != NULL) {
            struct node *child = cur->child;
            while (child != NULL) {
                new_tail->next = child;
                new_tail = child;
                child = child->next;
            }
        }

        // Move to the next node in the original linked list
        cur = cur->next;
    }

    // Set the child pointers of all nodes to NULL
    cur = new_head;
    while (cur != NULL) {
        cur->child = NULL;
        cur = cur->next;
    }

    return new_head;
}

// Function to print the linked list
void print_list(struct node *head) {
    struct node *cur = head;
    while (cur != NULL) {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("\n");
}

// Driver code
int main() {
    struct node *head = NULL;

    // Create the linked list
    head = insert_node(head, 1);
    head = insert_node(head, 2);
    head = insert_node(head, 3);
    head->child = insert_node(head->child, 4);
    head->child->next = insert_node(head->child, 5);