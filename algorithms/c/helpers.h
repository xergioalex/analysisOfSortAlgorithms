void printArray (int size, int *arr) {
	int i;
	for (i = 0; i < size; i++) {
   		printf("%d ", arr[i]);
   		if (i < size - 1) {
            printf(" ");
        }
	}
	printf("\n");
}

void swap (int i, int j, int *arr) {
   int tmp = arr[i];
   arr[i] = arr[j];
   arr[j] = tmp;
}

void escribirArchivo (char filename[140], char text[300]) {
    FILE *file;
    file = fopen(filename, "a");
    if (file) {
        fprintf(file, "%s\n", text);
        fclose(file);
    }
}