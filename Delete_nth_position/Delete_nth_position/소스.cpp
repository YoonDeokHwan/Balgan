#include<stdio.h>
#include<stdlib.h>

struct Node {
	int data;
	struct Node* next;
};
struct Node* head;
void Insert(int data, int n)
{
	Node* temp1 = new Node();
	temp1->data = data;
	temp1->next = NULL;
	if (n == 1) {
		temp1->next = head;
		head = temp1;
		return;
	}
	Node* temp2 = head;
	for (int i = 0; i < n - 2; i++)
	{
		temp2 = temp2->next;
	}
	temp1->next = temp2->next;
	temp2->next = temp1;

}
void Print() {
	struct Node* temp = head;
	printf("List is: ");
	while (temp != NULL) {
		printf(" %d", temp->data);
		temp = temp->next;
	}
	printf("\n");
}
void Delete(int n)
{
	struct Node* temp1 = head;
	if (n == 1) {
		head = temp1->next;
		free(temp1);
		return;
	}
	int i;
	for (i = 0; i < n - 2; i++) {
		temp1 = temp1->next;
	}
	struct Node* temp2 = temp1->next;
	temp1->next = temp2->next;
	free(temp2);
}
int main() {
	head = NULL;
	Insert(2,1);
	Insert(4, 1);
	Insert(6, 1);
	Insert(5, 1);
	Print();
	int n;
	printf("Enter a position\n");
	scanf_s("%d", &n, sizeof(n));
	Delete(n);
	Print();
}