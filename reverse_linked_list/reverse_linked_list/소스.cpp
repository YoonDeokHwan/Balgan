#include<stdio.h>
#include<stdlib.h>

struct Node {
	int data;
	struct Node* next;
};
struct Node* head;
struct Node* Insert(struct Node* head , int data)
{
	struct Node* temp = new Node;
	temp->data = data;
	temp->next = NULL;
	
	if (head != NULL) temp->next = head;
	head = temp;
	return head;
}
void Print(Node* head) {
	printf("List is: ");
	while (head != NULL) {
		printf(" %d", head->data);
		head = head->next;
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
struct Node* Reverse(struct Node* head)
{
	struct Node* current, * prev, * next;
	current = head;
	prev = NULL;
	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	head = prev;
	return head;
}
int main() {
	struct Node* head = NULL;
	head = Insert(head, 2);
	head = Insert(head, 4); 
	head = Insert(head, 6);
	head = Insert(head, 8);
	Print(head);
	head = Reverse(head);
	Print(head);
}