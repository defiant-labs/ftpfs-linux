#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>

/*#define FTPMOUNT_DEBUG*/

int main(int argc, char **argv){
	char *user = NULL;
	char *pass = NULL;
	char *port = NULL;
	char *root = NULL;
	char *ip = NULL;
	char *c, *host;
	struct hostent *hst;
	struct in_addr addr;
	char buf[256];
	int i = 0;
	char cmd[1024];
	
	if(argc < 3 || argc > 4){
		fprintf(stderr, "Try this: %s [user[:pass]@]host_name[:port][/root_dir] mount_point [-o]\n", argv[0]);
		exit(-1);
	}

	host = argv[1];
	if(c = strchr(host, '@')){
		user = host;
		host = c + 1;
		*c = '\0';

		if(c = strchr(user, ':')){
			pass = c + 1;
			*c = '\0';
		}
	}

	if(c = strchr(host, '/')){
		root = c + 1;
		*c = '\0';
	}

	if(c = strchr(host, ':')){
		port = c + 1;
		*c = '\0';
	}

	if((hst = gethostbyname(host)) == NULL){
		fprintf(stderr, "DNS lookup failed!\n");
		exit(-1);
	}

	memcpy(&addr.s_addr,hst->h_addr_list[0], hst->h_length);
	ip = inet_ntoa(addr);

	if(user && !pass){
		printf("Please provide the FTP password for user %s:", user);
		system("stty -echo");
		do buf[i++] = getchar();
		while(buf[i - 1] != 10);
		buf[i - 1] = '\0';
		pass = buf;
		system("stty echo");
	}	
	
	sprintf(cmd, "mount -n -t ftpfs none %s -o ip=%s", argv[2], ip);
	if(user)
		sprintf(cmd, "%s,user=%s,pass=%s", cmd, user, pass);
	if(port)
		sprintf(cmd, "%s,port=%s", cmd, port);
	if(root)
		sprintf(cmd, "%s,root=/%s", cmd, root);
	if(argc > 3 && strcmp(argv[3], "-o") == 0)
		sprintf(cmd, "%s,own", cmd);
#ifdef FTPMOUNT_DEBUG
	printf("%s\n", cmd);
#endif
		
	return system(cmd);
}