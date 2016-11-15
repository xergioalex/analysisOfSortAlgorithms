int partition(int left, int right, int pivot, int *numbers) {
   int leftPointer = left -1;
   int rightPointer = right;

   while (1) {
      while (numbers[++leftPointer] < pivot) {
         //do nothing
      }

      while (rightPointer > 0 && numbers[--rightPointer] > pivot) {
         //do nothing
      }

      if (leftPointer >= rightPointer) {
         break;
      } else {
         // printf(" item swapped :%d,%d\n", numbers[leftPointer],numbers[rightPointer]);
         swap(leftPointer,rightPointer, numbers);
      }
   }

   // printf(" pivot swapped :%d,%d\n", numbers[leftPointer],numbers[right]);
   swap(leftPointer, right, numbers);
   // printf("Updated Array: ");
   // display();
   return leftPointer;
}

void quickSort(int left, int right, int *numbers) {
   if(right - left <= 0) {
      return;
   } else {
      int pivot = numbers[right];
      int partitionPoint = partition(left, right, pivot, numbers);
      quickSort(left, partitionPoint-1, numbers);
      quickSort(partitionPoint+1, right, numbers);
   }
}