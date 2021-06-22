#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "include/systemd/sd-daemon.h"

int main(int argc, char ** argv)
{
	printf("systemd watchdog test\n");
	sd_notify(0, "READY=1\n"
		     "STATUS=main loop running...\n");

	int kicks=0;
    char message[50];
    while(1) {
		sleep(1);
		printf("kick dog\n");
        kicks++;
        sprintf(message,"WATCHDOG=1\nSTATUS=%d kicks...\n", kicks);
		sd_notify(0, message);
        
        if (random() % 20 == 0)
        {
            sprintf(message,"WATCHDOG=1\nSTATUS=%d and no more kicks!\n", kicks);
            sd_notify(0, message);
            while(1);
        }
	}
}
