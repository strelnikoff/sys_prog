#include <sys/stat.h>
#include <stdio.h>

#define FIFO_FILE "MYFIFO"

void main(void)
{
    FILE *fp;
    char readbuf[80];
    umask(0);
    mknod(FIFO_FILE, S_IFIFO|0666, 0);
    while(1)
    {
        fp = fopen(FIFO_FILE, "r");
        fgets(readbuf, 80, fp);
        printf("Received string: %s\n", readbuf);
        fclose(fp);
    }

}