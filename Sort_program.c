#include <stdio.h>
#include <string.h>

int main(void) {
  int val[] = {9,8,7,4,5,6,3,2,1}, len;

  len = sizeof(val)/sizeof(val[0]);
  int i=0, j=0, a;

  for(i=0;i<len;i++) {
    for(j=i+1;j<len;j++) {
      if(val[j] < val[i]) {
        a = val[i];
        val[i] = val[j];
        val[j] = a;
      }
    }
  }

  for(i=0;i<len;i++) {
    printf("%d\n",val[i]);
  }

  return 0;
}
