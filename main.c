
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/ioctl.h>
#include <linux/types.h>
#include <linux/watchdog.h>

int fd;

int main(int argc, char ** argv)
{
	printf("systemd watchdog test\n");

    fd = open("/dev/watchdog", O_WRONLY);
    
    int dummy;
    
	while(1) {
		sleep(1);
		printf("kick dog\n");
        ioctl(fd, WDIOC_KEEPALIVE, &dummy);
	}
}

