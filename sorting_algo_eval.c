#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "all_algos.h"


void writeCSV(const char *filename, const char *algo_name, int array_size, double exec_time) {
    FILE *file = fopen(filename, "a");
    if (file == NULL) {
        printf("Error opening CSV file.\n");
        return;
    }

    fprintf(file, "%s,%d,%.6lf\n", algo_name, array_size, exec_time);

    fclose(file);
}

int* readArray(const char *filename, int *size) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return NULL;
    }

    int capacity = 100;
    int *array = (int *)malloc(capacity * sizeof(int));
    int count = 0;

    while (fscanf(file, "%d", &array[count]) == 1) {
        count++;
        if (count >= capacity) {
            capacity *= 2;
            array = (int *)realloc(array, capacity * sizeof(int));
        }
    }

    fclose(file);

    *size = count;
    return array;
}



int main(){
    printf("Sorting Algorithm Evaluation\n");
    printf("Arrays Sizes:100,250,500,750,1000,2000,4000\n");
    printf("The Algos:Bubble,Insertion,Merge,Quick,Shell and Selection\n");
    printf("Start\n\n");
    int size;int arr_size[] = {100,250,500,750,1000,2000,4000};int choice;
    int *array = NULL;int *cpyarray = NULL;
    struct timespec start,end;
    double cpu_time;double time_taken;
    for(int i = 0;i < 7;i++){
    switch(arr_size[i]){
        case 100:array = readArray("array_100.txt",&size);break;
        case 250:array = readArray("array_250.txt",&size);break;
        case 500:array = readArray("array_500.txt",&size);break;
        case 750:array = readArray("array_750.txt",&size);break;
        case 1000:array = readArray("array_1000.txt",&size);break;
        case 2000:array = readArray("array_2000.txt",&size);break;
        case 4000:array = readArray("array_4000.txt",&size);break;
    }
    for(choice = 1; choice < 7;choice++){
    switch(choice){
    case 1:

    cpyarray = (int *)malloc(size * sizeof(int));
    memcpy(cpyarray,array,size * sizeof(int));

    clock_gettime(CLOCK_MONOTONIC, &start);
    bubblesort(cpyarray,size);
    clock_gettime(CLOCK_MONOTONIC, &end);


    time_taken = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e6;
    cpu_time = time_taken / size;


    printf("Bubble Sort %d size %.6lf ms\n",arr_size[i],cpu_time);
    writeCSV("all_algos_eval.csv","Bubble Sort",arr_size[i],cpu_time);
    free(cpyarray);
    break;

    case 2:

    cpyarray = (int *)malloc(size * sizeof(int));
    memcpy(cpyarray,array,size * sizeof(int));

    clock_gettime(CLOCK_MONOTONIC, &start);
    InsertionSort(cpyarray,size);
    clock_gettime(CLOCK_MONOTONIC, &end);


    time_taken = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e6;
    cpu_time = time_taken / size;


     printf("Insertion Sort %d size %.6lf ms\n",arr_size[i],cpu_time);
    writeCSV("all_algos_eval.csv","Insertion Sort",arr_size[i],cpu_time);
    free(cpyarray);
    break;

    case 3:
    cpyarray = (int *)malloc(size * sizeof(int));
    memcpy(cpyarray,array,size * sizeof(int));

    clock_gettime(CLOCK_MONOTONIC, &start);
    selectionSort(cpyarray,size);
    clock_gettime(CLOCK_MONOTONIC, &end);


    time_taken = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e6;
    cpu_time = time_taken / size;


     printf("Selection Sort %d size %.6lf ms\n",arr_size[i],cpu_time);
    writeCSV("all_algos_eval.csv","Selection Sort",arr_size[i],cpu_time);
    free(cpyarray);
    break;

    case 4:
    cpyarray = (int *)malloc(size * sizeof(int));
    memcpy(cpyarray,array,size * sizeof(int));


    clock_gettime(CLOCK_MONOTONIC, &start);
    ShellSort(cpyarray,size);
    clock_gettime(CLOCK_MONOTONIC, &end);


    time_taken = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e6;
    cpu_time = time_taken / size;


     printf("Shell Sort %d size %.6lf ms\n",arr_size[i],cpu_time);
    writeCSV("all_algos_eval.csv","Shell Sort",arr_size[i],cpu_time);
    free(cpyarray);
    break;

    case 5:
    cpyarray = (int *)malloc(size * sizeof(int));
    memcpy(cpyarray,array,size * sizeof(int));

    clock_gettime(CLOCK_MONOTONIC, &start);
    mergeSort(cpyarray,0,size - 1);
    clock_gettime(CLOCK_MONOTONIC, &end);


    time_taken = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e6;
    cpu_time = time_taken / size;


     printf("Merge Sort %d size %.6lf ms\n",arr_size[i],cpu_time);
    writeCSV("all_algos_eval.csv","Merge Sort",arr_size[i],cpu_time);
    free(cpyarray);
    break;

    case 6:
    clock_gettime(CLOCK_MONOTONIC, &start);
    quicksort(array,0,size - 1);
    clock_gettime(CLOCK_MONOTONIC, &end);


    time_taken = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e6;
    cpu_time = time_taken / size;


     printf("Quick Sort %d size %.6lf ms\n",arr_size[i],cpu_time);
    writeCSV("all_algos_eval.csv","Quick Sort",arr_size[i],cpu_time);
    break;


    }
    }
    }
    printf("\n\n");
    printf("Exiting the Program..");
    free(array);
}

