#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
	int data;
	struct node * next;
}Node,*Nodelist;


void printfList( Nodelist head )
{
	Nodelist iter;
	iter = head;
	while(iter)
	{
		printf("%d   ", iter->data);
		iter = iter->next;
	}
	printf("\n");
}


bool isListExistLoop( Nodelist head )
{
	Nodelist slow = head;
	Nodelist fast = head;

	while(fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;

		if(slow == fast)
		{
			// exist loop
			break;
		}
	}

	if(fast != NULL && fast->next != NULL)
	{
		printf("list have loop \n");
		return true;
	}
	else
	{
		printf("list dont have loop \n");
		return false;
	}
}


int main()
{
	Nodelist head = NULL;
	Nodelist tail = NULL;
	Nodelist new  = NULL;
	Nodelist threeNode = NULL;     // 环的入口节点

	// 开辟头节点
	head = (Nodelist)malloc(sizeof(Node));
	head->data = 0;
	tail = head;
	tail->next = NULL;


	int i = 1;
	for(i = 1; i <= 7;i++)
	{
		new = (Nodelist)malloc(sizeof(Node));
		new->data = i;
		new->next = NULL;

		if(i == 3)
		{
			threeNode = new;  // 记录环的入口
		}

		tail->next = new;
		tail = new;
	}


	printfList(head);

	isListExistLoop(head);

	// 将链表改为环链表，把最后一个元素指向第三个元素
	tail->next = threeNode;

	isListExistLoop(head);

	return 0;
}






















