void selectionSort (int size, int *numbers) {
	int i, j, minInd, temp;
	for (i = 0; i < size - 1; i++) {
        minInd = i;
        for(j = i + 1; j < size; j++) {
            if(numbers[j] < numbers[minInd]) {
                minInd = j;
            }
        }
        swap(minInd, i, numbers);
    }
}