#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 10

/* Struct to pass arguments to threads */
typedef struct {
    int *array;
    int start;
    int end;
    long sum;
} ThreadData;

/* Thread function to compute the sum of a portion of the array */
void *compute_sum(void *arg) {
    ThreadData *data = (ThreadData *)arg;
    data->sum = 0;
    for (int i = data->start; i < data->end; i++) {
        data->sum += data->array[i];
    }
    return NULL;
}

int main() {
    int n;
    printf("Enter the number of elements (greater than 1000): ");
    scanf("%d", &n);

    if (n <= 1000) {
        printf("Number of elements should be greater than 1000.\n");
        return 1;
    }

    /* Allocate memory for the array */
    int *array = (int *)malloc(n * sizeof(int));
    if (array == NULL) {
        perror("Failed to allocate memory");
        return 1;
    }

    /* Initialize the array with values */
    for (int i = 0; i < n; i++) {
        array[i] = i + 1; /* Example: array will have values 1 to n */
    }

    pthread_t threads[NUM_THREADS];
    ThreadData thread_data[NUM_THREADS];

    int elements_per_thread = n / NUM_THREADS;

    /* Create threads to compute the sum of portions of the array */
    for (int i = 0; i < NUM_THREADS; i++) {
        thread_data[i].array = array;
        thread_data[i].start = i * elements_per_thread;
        thread_data[i].end = (i == NUM_THREADS - 1) ? n : thread_data[i].start + elements_per_thread;
        if (pthread_create(&threads[i], NULL, compute_sum, &thread_data[i]) != 0) {
            perror("Failed to create thread");
            free(array);
            return 1;
        }
    }

    /* Wait for all threads to complete */
    long total_sum = 0;
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
        total_sum += thread_data[i].sum;
    }

    /* Print the total sum */
    printf("Total sum: %ld\n", total_sum);

    /* Clean up */
    free(array);
    return 0;
}

