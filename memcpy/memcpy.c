#include "memalign.h"
#include <string.h>

int main(int argc, char *argv[])
{
	const char src[50] = "http://www.github.com";
	char dest[50];

	//memcpy(dest, src, strlen(src) + 1);
	memcpy(dest, src, sizeof(src));
	printf("dest = %s\n", dest);
	return 0;
}
