void insertionSort (int size, int *numbers) {
	int i, j, tmp;

	for (i = 1 ; i < size; i++) {
        j = i;

        while (j > 0 && numbers[j] < numbers[j-1]) {
            swap(j, j-1, numbers);

            j--;
        }
    }
}