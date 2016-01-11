/*
OVERVIEW: Merge two sorted linked lists.
E.g.: 1->3->5 and 2->4, output is 1->2->3->4->5.

INPUTS: Two sorted linked lists.

OUTPUT: Return merged sorted linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

struct node * merge2LinkedLists(struct node *start1, struct node *start2) {
	struct node *temp1, *temp2,*temp;
	if ((start1 == NULL&&start2 == NULL) || start2 == NULL)
		return start1;
	if (start1 == NULL)
		return start2;
	temp1 = start1;
	temp2 = start2;
	if (start2->num <= start1->num)
	{                                       //insertion before start1

		if (start2->next != NULL)
		{
			for (temp = start2; temp->next->num <= start1->num;)
			{
				temp = temp->next;
				if (temp->next == NULL)
					break;
			}
			temp2 = temp->next;
			temp->next = start1;
			temp1 = start1;
			start1 = start2;
		}
		else
		{
			start2->next = start1;
			start1 = start2;
			temp2 = NULL;
		}
	}
	for (; temp1->next != NULL&&temp2 != NULL;)       //insertion at middle positions
	{
		if ((temp1->next)->num >= temp2->num)
		{
			temp = temp1->next;
			temp1->next = temp2;
			temp2 = temp2->next;
			(temp1->next)->next = temp;
			temp1 = temp1->next;
		}
		else
			temp1 = temp1->next;
	}
	if (temp1->next == NULL)          //merging at last
		temp1->next = temp2;
	return start1;

	
}
