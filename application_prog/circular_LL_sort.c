#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct node {
    char *name;
    int roll;
    struct node *next;
};

struct node *Head = NULL;

void insert(struct node **head, char *name, int roll) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->name = (char *)malloc(strlen(name) + 1);
    strcpy(newnode->name, name);
    newnode->roll = roll;

    if (*head == NULL) {
        *head = newnode;
        newnode->next = *head;  // circular
    } else {
        struct node *temp = *head;
        while (temp->next != *head)
            temp = temp->next;
        temp->next = newnode;
        newnode->next = *head;
    }
}

int getLength(struct node *head) {
    if (head == NULL) return 0;
    struct node *temp = head;
    int count = 1;
    while (temp->next != head) {
        count++;
        temp = temp->next;
    }
    return count;
}

void display(struct node *head) {
    if (head == NULL) return;
    struct node *temp = head;
    do {
        printf("%s %d\n", temp->name, temp->roll);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

void sort(struct node **head) {
    if (*head == NULL || (*head)->next == *head) return;

    int len = getLength(*head);

    for (int i = 0; i < len - 1; i++) {
        struct node *prev = NULL;
        struct node *curr = *head;
        int swapped = 0;

        for (int j = 0; j < len - 1; j++) {
            struct node *next = curr->next;

            if (strcasecmp(curr->name, next->name) > 0) {
                swapped = 1;

                // Swap curr and next
                if (curr == *head) {
                    // curr is head, special handling
                    struct node *tail = *head;
                    while (tail->next != *head)
                        tail = tail->next;

                    curr->next = next->next;
                    next->next = curr;
                    *head = next;
                    tail->next = *head;

                    prev = *head;
                } else {
                    // general swap
                    curr->next = next->next;
                    next->next = curr;
                    prev->next = next;
                    prev = next;
                }
            } else {
                prev = curr;
                curr = curr->next;
            }
        }

        if (!swapped)
            break;
    }
}

int main() {
    insert(&Head, "Naveen", 1);
    insert(&Head, "kumar", 2);
    insert(&Head, "Ajay", 3);
    insert(&Head, "bharath", 4);

    printf("Before sorting:\n");
    display(Head);

    sort(&Head);

    printf("After sorting:\n");
    display(Head);

    printf("Length: %d\n", getLength(Head));
    return 0;
}
