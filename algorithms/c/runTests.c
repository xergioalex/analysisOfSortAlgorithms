#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Test sort algorithms in C
 *
 * @param argc => number of command line arguments
 * @param argv => String array of command line arguments
 */
int main (int argc, char *argv[]) {
    int language = 0, algorithm = 0, size = 0, increaseSize = 10, increaseSizeAux = 1;

    char algorithmText[50], program[200];

    system("rm -rf ../../outputs && mkdir ../../outputs");

    for (language = 0; language <= 5; language++) {

        for (increaseSize = 10, increaseSizeAux = 1, size = 10; size <= 1000000; size += increaseSize) {
            if (increaseSizeAux % 10 == 0) {
                increaseSizeAux = 1;
                increaseSize = increaseSize * 10;
            }

            for (algorithm = 0; algorithm < 7; algorithm++) {
                strcpy(algorithmText, (algorithm == 0)? "bubbleSort": (algorithm == 1)? "countingSort": (algorithm == 2)? "heapSort": (algorithm == 3)? "insertionSort": (algorithm == 4)? "mergeSort": (algorithm == 5)? "quickSort": "selectionSort");

                sprintf(program, "gcc benchmark.c -o benchmark.out && ./benchmark.out %s %d", algorithmText, size);

                // Run program
                system(program);
                system("sudo sync && free -m && sudo sysctl -w vm.drop_caches=3");
            }

            increaseSizeAux++;

        }

    }

    return 0;
}