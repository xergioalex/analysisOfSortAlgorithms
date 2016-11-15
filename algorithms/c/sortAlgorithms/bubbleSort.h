void bubbleSort (int size, int *numbers) {
    int i, j, tmp;
    for (i = 0 ; i < size - 1; i++) {
        for (j = 0 ; j < size - i - 1; j++) {
          if (numbers[j] > numbers[j+1]) {
            swap(j, j+1, numbers);
          }
        }
    }
}