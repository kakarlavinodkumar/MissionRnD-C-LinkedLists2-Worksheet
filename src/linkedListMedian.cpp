/*
OVERVIEW: Given a single sorted linked list find the median element of the single linked list.
Median is the middle element.
E.g.: 1->2->3->4->5, output is 3.

INPUTS: A sorted linked list.

OUTPUT: Return median of the linked list elements.

ERROR CASES: Return -1 for error cases.

NOTES: If length is even, return average of middle pair of numbers.
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

int linkedListMedian(struct node *head) {
	struct node *temp1, *temp2;
	if (head == NULL)
		return -1;
	for (temp1 = temp2 = head;; temp1 = temp1->next, temp2 = (temp2->next)->next)
	{
		if (temp2->next == NULL)
			return temp1->num;
		if ((temp2->next)->next == NULL)
			return (temp1->num+ (temp1->next)->num) / 2;
	}
}
