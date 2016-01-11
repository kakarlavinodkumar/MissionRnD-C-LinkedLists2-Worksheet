/*
OVERVIEW: Given a single linked list insert a new node at every Kth node with value K.
E.g.: 1->2->3->4->5, k = 2, 1->2->2->3->4->2->5

INPUTS: A linked list and Value of K.

OUTPUT: Insert a new node at every Kth node with value K.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
};

struct node * insertAtEveryKthNode(struct node *head, int k) {
	int count;
	struct node *temp,*newnode;
	if (k <= 0 )
		return NULL;
	for (temp = head, count = 1; temp != NULL; temp = temp->next, count++)
	{
		if (count%k == 0)
		{
			newnode = (struct node*)malloc(sizeof(struct node));
			newnode->num = k;
			newnode->next = temp->next;
			temp->next = newnode;
			if (temp->next == NULL)
				break;
			temp = temp->next;
		}
	}
	return head;
}
