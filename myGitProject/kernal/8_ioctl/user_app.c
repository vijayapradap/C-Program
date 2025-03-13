#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>

#define WD_VALUE _IOW('a', 'a', uint32_t *)
#define RD_VALUE _IOR('b', 'b', uint32_t *)

int main(void) {
    int fd = open("/dev/my_ioctl", O_RDWR);
    if (fd < 0) {
        printf("unable to open the device\n");
        return -1;
    }
    uint32_t value = 1254, output = 0;
    ioctl(fd, WD_VALUE, (uint32_t*) &value);
    printf("value written successfully : %d\n", value);

    ioctl(fd, RD_VALUE, (uint32_t*) &output);
    printf("read value from kernel is : %d\n", output);
    close(fd);
    return 0;
}