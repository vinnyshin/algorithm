//2017029870_신호중
#include <stdio.h>
#include <stdlib.h>

int 
main() {

   int numOfInt, rangeOfInt, numofQueryRange;
   scanf("%d %d %d", &numOfInt, &rangeOfInt, &numofQueryRange);

   int* a = (int*)malloc(sizeof(int)*numofQueryRange);
   int* b = (int*)malloc(sizeof(int)*numofQueryRange);
   int* c = (int*)malloc(sizeof(int)*rangeOfInt);
   
   int i = 0;
   
   for (i=0; i < numofQueryRange; i++) {
      scanf("%d %d", &a[i], &b[i]);
   }
   
   for (; i < rangeOfInt; i++) {
      c[i] = 0;
   }
   
   for (i = 0; i < numOfInt; i++) {
      int num = 0;
      scanf("%d", &num);
      c[num]++;
   }
   for (i = 0; i < rangeOfInt; i++) {
      c[i + 1] = c[i + 1] + c[i];
   }

   for (i = 0; i < numofQueryRange; i++) {
      printf("%d\n", c[b[i]] - c[a[i]-1]);
   }

   return 0;
}

