#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "helpers.h"
#include "sortAlgorithms.h"

// Read numbers from file and store it in array in memory
void readNumbersFromFile (int size, int *numbers) {
    int i = 0;
    char filename[] = "../../numbers/numbers.txt";
    char str[1000];

    FILE *file;
    file = fopen(filename, "r");
    if (file) {
        while (i < size && fscanf(file, "%s", str) != EOF) {
            numbers[i] = atoi(str);
            i++;
        }
        fclose(file);
    }
}

void printLog(char text[300]) {
    // printf("%s\n", text);
    char filename[300];
    sprintf(filename, "../../outputs/filename.log");
    escribirArchivo(filename, text);
}

void printResult(char *algorithm, int size, double timeSpent) {
    char filename[300];
    sprintf(filename, "../../outputs/C_%s.csv", algorithm);
    char log[300];
    sprintf(log, "%d, %f", size, timeSpent);
    escribirArchivo(filename, log);
}

// Run sort algorithm
void runSortAlgorithm (char *algorithm, int size, int *numbers) {
    int *arrTmp1;
    int *arrTmp2;
    int arrTmp1Allocated = 0, arrTmp2Allocated = 0;
    char log[300];

    sprintf(log, "----------------------------------------------------------------"); printLog(log);
    sprintf(log, "Language C"); printLog(log);
    sprintf(log, "Algorithm: %s", algorithm); printLog(log);
    sprintf(log, "Size of array: %d", size); printLog(log);

    // Get init time
    clock_t timeStart, timeEnd;
    double timeSpent = (double)(timeEnd - timeStart) / CLOCKS_PER_SEC;

    // Sort algorithm
    if (strcmp(algorithm, "bubbleSort") == 0) {
        timeStart = clock();
        bubbleSort(size, numbers);
    } else if (strcmp(algorithm, "selectionSort") == 0) {
        timeStart = clock();
        selectionSort(size, numbers);
    } else if (strcmp(algorithm, "insertionSort") == 0) {
        timeStart = clock();
        insertionSort(size, numbers);
    } else if (strcmp(algorithm, "mergeSort") == 0) {
        arrTmp1Allocated = 1;

        arrTmp1 = (int*) malloc(sizeof(int) * size);
        timeStart = clock();
        mergeSort(numbers, size, arrTmp1);
    } else if (strcmp(algorithm, "heapSort") == 0) {
        timeStart = clock();
        heapSort(numbers, size);
    } else if (strcmp(algorithm, "quickSort") == 0) {
        timeStart = clock();
        quickSort(0, size, numbers);
    } else if (strcmp(algorithm, "countingSort") == 0) {
        // arrTmp1Allocated = 1, arrTmp2Allocated = 1;

        timeStart = clock();
        countingSort(numbers, size, arrTmp1, arrTmp2);
    }

    timeEnd = clock();
    timeSpent = (double)(timeEnd - timeStart) / CLOCKS_PER_SEC;

    sprintf(log, "The algorithm task has taken  %f seconds", timeSpent); printLog(log);
    printResult(algorithm, size, timeSpent);

    // printArray(size, numbers);

    // Free memory
    if (arrTmp1Allocated == 1) { free(arrTmp1); }
    if (arrTmp2Allocated == 1) { free(arrTmp2); }
}

/**
 * Benchmarking of sort algorithms in C
 *
 * Run this code from command line as below:
 * $ gcc benchmark.c -o benchmark.out && ./benchmark.out arg1 arg2 arg3...
 *
 * arg1, arg2 => Are the type(name) of algorithm and the numbers of elements to test
 *
 * @param argc => number of command line arguments
 * @param argv => String array of command line arguments
 */
int main (int argc, char *argv[]) {
    char *algorithm;
    if (argc < 2) {
        printf("----------------------------------------------------------------\n");
        printf("At least two params are expected");
    } else {
        algorithm = argv[1];
        int size = atoi(argv[2]);
        int *numbers = (int*) malloc(sizeof(int) * size);

        // Read numbers from file
        readNumbersFromFile(size, numbers);

        // Run sort algorithm
        runSortAlgorithm(algorithm, size, numbers);

        free(numbers);
    }

    return 0;
}