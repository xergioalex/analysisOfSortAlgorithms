// To heapify a subtree rooted with node i which is
// an index in arr[]. n is size of heap
void heapify (int *numbers, int size, int i) {
    int largest = i;  // Initialize largest as root
    int l = 2*i + 1;  // left = 2*i + 1
    int r = 2*i + 2;  // right = 2*i + 2
    int tmp;

    // If left child is larger than root
    if (l < size && numbers[l] > numbers[largest]) {
        largest = l;
    }

    // If right child is larger than largest so far
    if (r < size && numbers[r] > numbers[largest]) {
        largest = r;
    }

    // If largest is not root
    if (largest != i) {
        swap(i, largest, numbers);

        // Recursively heapify the affected sub-tree
        heapify(numbers, size, largest);
    }
}

// main function to do heap sort
void heapSort (int *numbers, int size) {
    int i, tmp;
    // Build heap (rearrange array)
    for (i = size / 2 - 1; i >= 0; i--) {
        heapify(numbers, size, i);
    }

    // One by one extract an element from heap
    for (i = size-1; i >= 0; i--) {
        // Move current root to end
        swap(0, i, numbers);

        // call max heapify on the reduced heap
        heapify(numbers, i, 0);
    }
}