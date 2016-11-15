void merge (int *numbersA, int size, int mid, int *numbersB) {
   int i, j, k;
   numbersB = (int*) malloc(size * sizeof (int));

   for (i = 0, j = mid, k = 0; k < size; k++) {
        numbersB[k] = (j == size)? numbersA[i++]: (i == mid)? numbersA[j++]: (numbersA[j] < numbersA[i])? numbersA[j++]: numbersA[i++];
   }

   for (i = 0; i < size; i++) {
      numbersA[i] = numbersB[i];
   }
}

void mergeSort (int *numbersA, int size, int *numbersB) {
   if (size < 2) { return; }
   int mid = size / 2;
   mergeSort(numbersA, mid, numbersB);
   mergeSort(numbersA + mid, size - mid, numbersB);
   merge(numbersA, size, mid, numbersB);
}