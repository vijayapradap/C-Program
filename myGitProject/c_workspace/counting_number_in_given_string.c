#include <stdio.h>

int main()
{
    char *data = "8342154832553515130254862121545022";
    
    int out[10] = {0};
    
    for(int i=0; i<10; i++)
        printf("%d ", i);
    printf("\n");
    
    for(int i=0; i<10; i++) {
        for(int j=0; data[j] != '\0'; j++) {
            if (i == (data[j] - 0x30))
                out[i]++;
        }
        printf("%d ", out[i]);
    }

    return 0;
}
