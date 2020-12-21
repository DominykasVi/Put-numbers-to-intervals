
#include <stdio.h>

int add_number() {
    int number;
    int return_code;
    while ((return_code = scanf("%d", &number) == 0) || (getchar() != '\n')) {
        scanf("%*[^\n]");
        printf("Enter a  valid number: ");
    }
    return number;

}


void find_min(int n, int *min, const int array[]) {

    for (int i = 1; i < n; ++i) {
        if (*min > array[i]) {
            *min = array[i];
        }
    }
}


void find_max(int n, int *max, const int array[]) {

    for (int i = 1; i < n; ++i) {
        if (*max < array[i]) {
            *max = array[i];
        }
    }
}


void bubbleSort(int array[], int n) {
    int i, j;
    for (i = 0; i < n - 1; ++i) {
        for (j = 0; j < n - i - 1; ++j) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}


void output_function(int *array, int n, int min, int max) {

    printf("First interval is: ");
    for (int i = 0; i < n; ++i) {
        if (array[i] >= min && (double) array[i] <= (min + (max - min) / 3)) {
            printf("%d ", *(array+i));
        }
    }
    printf("\n");

    printf("Second interval is: ");
    for (int i = 0; i < n; ++i) {
        if ((double) array[i] > (min + (max - min) / 3) && (double) array[i] < (min + (max - min) * 2 / 3)) {
            printf("%d ", array[i]);
        }
    }
    printf("\n");

    printf("Third interval is: ");
    for (int i = 0; i < n; ++i) {
        if ((double) array[i] >= (min + (max - min) * 2 / 3)) {
            printf("%d ", array[i]);
        }
    }
    printf("\n");
}


int main() {
    printf("Please enter how many numbers you wish to enter:\n");
    int n;
    n = add_number();

    int array[n];
    printf("Please enter %d numbers\n", n);
    for (int i = 0; i < n; ++i) {
        printf("Enter %d number: ", i + 1);
        array[i] = add_number();
    }

    int min = array[0], max = array[0];
    int *min_pointer, *max_pointer;
    min_pointer = &min;
    max_pointer = &max;
    find_min(n, min_pointer, array);
    find_max(n, max_pointer, array);
    bubbleSort(array, n);
    output_function(array, n, min, max);
}
