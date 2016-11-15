void countingSortMain (int *numbers, int k, int size, int *B, int *C) {
    int i, j, indexB = 0;
    B = (int*) malloc(sizeof(int) * (size + 1));
    C = (int*) calloc((k + 1), sizeof(int));

    for (i = 0; i < size; i++) {
        C[numbers[i]] = C[numbers[i]] + 1;
    }

    for (i=0; i <= k; ++i) {
        for(j=0; j < C[i]; ++j) {
            B[indexB] = i;
            indexB++;
        }
    }

    free(B);
    free(C);
    // printArray(size, B);
}

void countingSort (int *numbers, int size, int *B, int *C) {
    int i, k;
    for (i = 0; i < size; i++) {
        if (numbers[i] > k) {
            k = numbers[i];
        }
    }
    countingSortMain(numbers, k, size, B, C);
}