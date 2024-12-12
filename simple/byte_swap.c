#include <stdio.h>
#include <stdint.h>

#ifdef UNION
union data {
	uint32_t bytes;
	struct {
		uint8_t byte[4];
	};
};

typedef union data un_data;

void swapbytes(uint32_t u32_data) {
	un_data output, afterswap;
	output.bytes = u32_data;
	
	printf("after swap : \n");
	for(int i=0, j=3; i<4; i++, j--) {
		afterswap.byte[j] = output.byte[i];
		printf("%x ",output.byte[i]);
	}
	printf("\noutput after swap : %x\n", afterswap.bytes);
}
#else

void swapbytes(uint32_t u32_data) {
    uint32_t output = 0, tmp = 0;

    tmp = (u32_data & 0xff);
#ifdef DEBUG
    printf("%d : tmp : %x\toutput : %x\n", __LINE__, tmp, output);
#endif
    tmp = tmp << 24;
    output = tmp;
#ifdef DEBUG
    printf("%d : tmp : %x\toutput : %x\n", __LINE__, tmp, output);
#endif
    tmp = (u32_data & 0xff00) >> 8;
#ifdef DEBUG
    printf("%d : tmp : %x\toutput : %x\n", __LINE__, tmp, output);
#endif
    tmp = tmp << 16;
    output |= tmp;
#ifdef DEBUG
    printf("%d : tmp : %x\toutput : %x\n", __LINE__, tmp, output);
#endif
    tmp = (u32_data & 0xff0000) >> 16;
#ifdef DEBUG
    printf("%d : tmp : %x\toutput : %x\n", __LINE__, tmp, output);
#endif
    tmp = tmp << 8;
    output |= tmp;
#ifdef DEBUG
    printf("%d : tmp : %x\toutput : %x\n", __LINE__, tmp, output);
#endif
    tmp = (u32_data & 0xff000000) >> 24;
    output |= tmp;
#ifdef DEBUG
    printf("%d : tmp : %x\toutput : %x\n", __LINE__, tmp, output);
#endif

	printf("output after swap : \n%x\n", output);
}

#endif

void simplified(uint32_t dd) {
    uint32_t output = 0;
    
    output |= (dd & 0xff) << 24;
    output |= ((dd & 0xff00) << 16) >> 8;
    output |= ((dd & 0xff0000) << 8) >> 16;
    output |= (dd & 0xff000000) >> 24;
	
    printf("simplifiled output after swap : \n%x\n", output);
}

uint32_t superSimplified(uint32_t dd) {
    uint32_t output = 0;

    while(dd > 0) {
        output = (output << 8) | (dd & 0xff);
        dd = dd >> 8;
    }
    return output;
}

int main() {
	uint32_t a = 0x12345678;
	printf("input before swap bytes : \n%x\n", a);
	swapbytes(a);

    simplified(a);

	a = 0x12345678;
    a = superSimplified(a);
	printf("input before swap bytes : \n%x\n", a);

	return 0;
}
