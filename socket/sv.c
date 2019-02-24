#include "sock.h"

int main()
{
	struct sockaddr_un addr;
	int sfd, cfd;
	ssize_t num_read;
	char buf[BUF_SIZE];

	sfd = socket(AF_UNIX, SOCK_STREAM, 0);
	if(sfd == -1)
	  printf("sv socket error! sfd == -1 !\n");
	if(remove(SV_SOCK_PATH) == -1)
	  printf("sv socket error!SV_SOCK_PATH == -1 !\n");


}
