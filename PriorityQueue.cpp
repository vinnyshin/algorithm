// 2017030255_신호중
#include <stdio.h>
#include <stdlib.h>

int option, size = 0, bSize = 0;
int *a = (int*)malloc(sizeof(int) * 1000000);
int *b = (int*)malloc(sizeof(int) * 1000000);

void Swap(int *x, int *y) {
   int temp;
   temp = *x;
   *x = *y;
   *y = temp;
}

void Max_heapify(int arr[], int integer) {
   int index;
   if (integer > size / 2 - 1)
      return;
   if (integer == size / 2 - 1) {
      if (integer * 2 + 2 == size - 1) {
         index = arr[integer * 2 + 1] > arr[integer * 2 + 2] ? integer * 2 + 1 : integer * 2 + 2;
      }
      else {
         index = integer * 2 + 1;
      }
   }
   else {
      index = arr[integer * 2 + 1] > arr[integer * 2 + 2] ? integer * 2 + 1 : integer * 2 + 2;
   }
   if (arr[integer] < arr[index]) {
      Swap(&arr[integer], &arr[index]);
   }
   Max_heapify(arr, index);
}

int main()
{
   while (true) {
      option;
      scanf("%d", &option);
      if (option == 0) {
         for (int integer = 0; integer < bSize; integer++)
            printf("%d ", b[integer]);
         printf("\n");

         for (int integer = 0; integer < size; integer++)
            printf("%d ", a[integer]);

         return 0;
      }
      else if (option == 1) {
         scanf("%d", &a[size++]);
         for (int integer = size / 2 - 1; integer > -1; integer = (integer-1)/2) {
            Max_heapify(a, integer);
            if (integer == 0)
               break;
         }
         
      }
      else if (option == 2) {
         b[bSize++] = a[0];
         Swap(&a[0], &a[size-- - 1]);
         Max_heapify(a, 0);
      }
      else if (option == 3) {
         int index, x;
         scanf("%d %d", &index, &x);
         Swap(&a[index - 1], &x);

         if (index - 1 > size / 2 - 1) {
            for (int integer = index / 2 - 1; ; integer = (integer - 1) / 2) {
               Max_heapify(a, integer);
               if (integer == 0)
                  break;
            }
         }
         else {
            for (int integer = index-1; ; integer = (integer-1)/2) {
               Max_heapify(a, integer);
               if (integer == 0)
                  break;
            }
         }
         
      }

   }
   return 0;
}