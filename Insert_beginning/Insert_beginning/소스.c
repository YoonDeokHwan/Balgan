//Linked List: Inserting a node at beginning
#include<stdlib.h>
#include<stdio.h>

struct Node {
	int data;
	struct Node* next;
};
struct Node* head;//global variable, can be accessed anywhere
void Insert(int x) {
	struct Node* temp = malloc(sizeof(struct Node));
	temp->data = x;
	temp->next = NULL;
	head = temp;
	if (head != NULL) temp->next = head;
	head = temp;
}
void Print() {
	struct Node* temp = head;
	printf("List is+ ");
	while (temp != NULL) {
		printf(" %d", temp->data);
		temp = temp->next;
	}
	printf("\n");
}
int main() {
	head = NULL;//empty list
	printf("How many numbers?\n");
	int n, i, x;
	scanf_s("%d", &n);
	for (i=0; i < n; i++) {
		printf("Enter the number \n");
		scanf_s("%d", &x);
		Insert(x);
		Print(); 
		
	}
}