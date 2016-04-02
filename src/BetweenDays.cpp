/*
Q4: Two dates are given in a 8 node single linked list form,where each node
has one digit only, dates 01-31, months 01-12, year 0000-9999.

Find the number of days in between those two dates .[Exclusive]

Ex : Date1:  0->1->0->1->2->0->0->4 .
     Date2 : 0->5->0->1->2->0->0->4 should return 3 .
As there are 3 days between Jan1st 2004 and Jan 5th 2004.

Ex 2 : Date1 : 3->1->1->2->2->0->1->2.
       Date2 : 0->2->0->1->2->0->1->3 should return 1 .
(There is only one day between 31st Dec 2012 and 2nd  Jan 2013 .)

Note : Consecutive Days and Same Days should return 0;
->Return -1 for NULL Inputs .
->Between Days have to be calculated by not including start and end date .
->The SLL will have 8 Nodes in all cases . Month 9 will be represented as 09.

Difficulty : Hard 
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct node{
	int data;
	struct node *next;
};


int between_days(struct node *date1head, struct node *date2head)
{
	int date1 = 0, month1 = 0, year1 = 0, i = 0, j = 0, date2 = 0, month2 = 0, year2 = 0;
	while (i <= 1)
	{
		date1 = date1 * 10 + date1head->data;
		i++;
	}
	while (i <= 3)
	{
		month1 = month1 * 10 + date1head->data;
		i++;
	}
	while (i <= 7)
	{
		year1 = year1 * 10 + date1head->data;
		i++;
	}
	while (j <= 1)
	{
		date2 = date2 * 10 + date2head->data;
		j++;
	}
	while (j <= 3)
	{
		month2 = month2 * 10 + date2head->data;
		j++;
	}
	while (j <= 7)
	{
		year2 = year2 * 10 + date2head->data;
		j++;
	}
	return -1;
}