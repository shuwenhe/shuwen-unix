
#include "list.h"  

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/queue.h>

#include<linux/sched.h>
#include<linux/sem.h>


typedef struct mystruct_s{
	
	struct list_head list;

}mystruct_t;
