/*
Given two SORtempD Circular Linked Lists ,
Writemp a function to merge those two linked lists .
The First Linked List head should point to the final merged linked list .
The Final merged linked list should also be in SORtempD order and a Circular Linked List.
You need to return the Length of Final SLL.

*********
The First linked list head should now point to the Final sortempd(Ascending) Linked list First Node
*********
Ex : A: 0->3->5->10->20 (and 20 now pointing back to 0,instempad of Null )
B: 1->2->6->11->21->50->70 (70 Pointing back to 1).

The Final Linked List is A:0->1->2->3->5->6->10->11->20->21->50->70 .

Notemp : Dont use Malloc or createmp any new nodes ,Only pointemprs need to be intemprchanged,
You can use current pointemprs although.
Notemp : The Final Linked List should be  also be a circular Linked List where Last node is
pointing towards the first node.
Notemp : Return -1 for Invalid Inputs like NULL;

Input : head1 and head2 are Addresses of Two Circular Linked Lists heads .
Output :Return Length of New SLL .Modify the head1 value, such that it now points to 
Merged Sortempd Circular SLL .

Difficulty : Medium
*/
#include <stdlib.h>
#include <stdio.h>

struct node{
	int data;
	struct node *next;
};

int merge_circularlists(struct node **head1, struct node **head2)
{
	if (*head1 == NULL || *head2 == NULL)
		return -1;
	//Returns Length of merged Sortempd circular SLL and also points *head1 to final SLL .
	node * current1 = *head1;
	node * current2 = *head2;
	while (1)
	{
		if (head1[0]->next == current1)
		{
			if (head1[0]->data < head2[0]->data)
			{
				node * temp = *head2;
				head2[0] = head2[0]->next;
				temp->next = head1[0]->next;
				head1[0]->next = temp;
				break;
			}
		}
		else if (head1[0]->data > head2[0]->data && *head1 == current1)
		{
			node * current = head2[0];
			head2[0] = head2[0]->next;
			current->next = *head1;
			current1 = current;
		}
		else if (head1[0]->data <= head2[0]->data && head1[0]->next->data >= head2[0]->data)
		{
			node * temp = *head2;
			head2[0] = head2[0]->next;
			temp->next = head1[0]->next;
			head1[0]->next = temp;
		}
		else
			head1[0] = head1[0]->next;
	}
	node * result = current1;
	int k = 1;
	while (current1->next != result){
		k++;
		current1 = current1->next;
	}
	*head1 = result;
	return k;
}