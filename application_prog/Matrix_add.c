#include<stdio.h>
#include<stdlib.h>
#define ROW 3
#define COLUMN 3

struct matrix {
int row_index;
int col_index;
int data;
struct matrix * next;
};
struct matrix*headA=NULL;
struct matrix*headB=NULL;

void insert_at_end(struct matrix **head, int row, int col, int data) {
struct matrix *new_node = (struct matrix *)malloc(sizeof(struct matrix));
new_node->row_index = row;
new_node->col_index = col;
new_node->data = data;
new_node->next = NULL;

if (*head == NULL) {
*head = new_node;
return;
}

struct matrix *temp = *head;
while (temp->next != NULL) {
temp = temp->next;
}
temp->next = new_node;
}

void add_matrices(struct matrix *headA, struct matrix *headB) {
struct matrix *tempA = headA;
struct matrix *tempB = headB;

printf("Result of A + B:\n");
while (tempA != NULL && tempB != NULL) {
if (tempA->row_index == tempB->row_index &&
       tempA->col_index == tempB->col_index) {
int sum = tempA->data + tempB->data;
printf("Position (%d,%d) = %d\n",
      tempA->row_index, tempA->col_index, sum);
// Only add once per match
}
tempB = tempB->next;
tempA = tempA->next;
}
}

int main() {
int rows_A, cols_A;
int rows_B, cols_B;

printf("Enter number of rows and columns for Matrix A: ");
scanf("%d %d", &rows_A, &cols_A);

printf("Enter number of rows and columns for Matrix B: ");
scanf("%d %d", &rows_B, &cols_B);

if (rows_A != rows_B || cols_A != cols_B) {
printf("Dimensions do not match.\n");
return 1;
}

// Input for Matrix A
printf("Enter elements for Matrix A:\n");
for (int i = 0; i < rows_A; i++) {
for (int j = 0; j < cols_A; j++) {
int val;
printf("A[%d][%d] = ", i, j);
scanf("%d", &val);
insert_at_end(&headA, i, j, val);
}
}

// Input for Matrix B
printf("Enter elements for Matrix B:\n");
for (int i = 0; i < rows_B; i++) {
for (int j = 0; j < cols_B; j++) {
int val;
printf("B[%d][%d] = ", i, j);
scanf("%d", &val);
insert_at_end(&headB, i, j, val);
}
}
add_matrices(headA,headB);
return 0;
}


