
#include <stdio.h>
#include "list_head.h"

typedef struct person_s{
	int age;
	int weight;
	struct list_head list;
}person_t;

int main(int argc, char* argv[])
{
	person_t *tmp;
	struct list_head *pos, *n;
	int age_i, weight_j;

	/* 定义并初始化一个链表头 */
	person_t person_head;
	INIT_LIST_HEAD(&person_head.list);
	
	for(age_i = 10, weight_j = 35; age_i < 40; age_i += 5, weight_j += 5){
		tmp =(person_t*)malloc(sizeof(person_t));
		tmp->age = age_i;
		tmp->weight = weight_j;
		/* 把这个节点链接到链表后面 
		 * 这里因为每次的节点都是加在person_head的后面，所以先加进来的节点就在链表里的最后面
		 * 打印的时候看到的顺序就是先加进来的就在最后面打印
		 */ 
		list_add(&(tmp->list), &(person_head.list)); 
	}

	/* 下面把这个链表中各个节点的值打印出来*/
	printf("\n");
	printf("print the list\n");
	list_for_each(pos, &person_head.list){
		tmp = list_entry(pos, person_t, list); /* 取得pos所在结构指针 */
		printf("age:%d,  weight: %d \n", tmp->age, tmp->weight);
	}
	printf("\n");
	/* 删除节点，age20 */
	printf("print list after delete a node which age is 20\n");
	list_for_each_safe(pos, n, &person_head.list){
		tmp = list_entry(pos, person_t, list);
		if(tmp->age == 20){
			list_del_init(pos);
			free(tmp);
		}
	}

	list_for_each(pos, &person_head.list){
		tmp = list_entry(pos, person_t, list);
		printf("age:%d,  weight: %d \n", tmp->age, tmp->weight);
	}

	list_for_each_safe(pos, n, &person_head.list){
		tmp = list_entry(pos, person_t, list);
		list_del_init(pos);
		free(tmp);
	}
	return 0; /* 释放资源 */
}
