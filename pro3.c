#include <stdio.h>

typedef struct _node
{
	char data;
	struct _node *next; 
} node;


node *exchange(node *head)
{
	node dummy_node;
	dummy_node.next = head;
	node *fast = head, *slow = &dummy_node;
	node *last = &dummy_node;

	// fast遍历每个节点，slow指向当前最后一个数字节点，last指向当前节点的上一个节点
	while (fast != NULL)
	{
		if (fast->data >= '0' && fast->data <= '9')
		{
			if (last == slow)
			{
				// 如果前面全都是数字节点，则没有必要交换
				last = fast;
			}
			else
			{
				// 将fast所指节点插入到slow后面并更新slow
				last->next = fast->next;
				fast->next = slow->next;
				slow->next = fast;
			}
			// 更新slow
			slow = fast;
		}
		else
		{
			last = fast;
		}
		fast = last->next;
	}

	return dummy_node.next;
}

int main(int argc, char const *argv[])
{
	node *head; 
	


	
	
	return 0;
}
