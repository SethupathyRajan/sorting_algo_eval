void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}



void bubblesort(int arr[],int size){
    for(int i = 0 ; i < size ; i++){
        for(int j = 0 ; j < size-1 ; j++){
            if(arr[j] > arr[j + 1])
                swap(&arr[j],&arr[j+1]);
        }
    }

}

void selectionSort(int arr[],int size){
    for(int i = 0 ; i < size - 1 ; i++){
        int min_ind = i;
        for(int j = i+1 ; j < size  ; j++){
            if(arr[min_ind] > arr[j]){
                min_ind = j;
            }

        }
         if(min_ind != i){
            swap(&arr[i],&arr[min_ind]);
        }
    }
}


void InsertionSort(int arr[],int size){
    int i,j;
    for(i = 0;i < size;i++){
        int temp = arr[i];
        for(j = i;j>0 && temp<arr[j-1];j--){
            arr[j] = arr[j -1];
        }
        arr[j]=temp;
    }
}

void ShellSort(int arr[],int size){
    for(int gap = size/2 ; gap > 0;gap /=2){
        for(int i = gap;i < size;i++){
            int temp = arr[i];
            int j = i;
            while(j>=gap && temp<arr[j -gap]){
                arr[j] = arr[j -gap];
                j -= gap;
            }
            arr[j] = temp;
        }
    }
}

void quicksort(int arr[],int start,int end){
    if (start >= end)
        return;
    int pivotIndex = start + rand() % (end - start + 1);
    swap(&arr[pivotIndex], &arr[end]);
    int pivot = partition(arr, start, end);
    quicksort(arr, start, pivot - 1);
    quicksort(arr, pivot + 1, end);
}

int partition(int arr[],int start,int end){
    int pivot = arr[end];
    int j = start - 1;

    for(int i = start;i < end ;i++){
        if(arr[i]<pivot){
            j++;
            swap(&arr[j],&arr[i]);
        }
    }
    j++;
    swap(&arr[j],&arr[end]);

    return j;
}



void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int leftArr[n1], rightArr[n2];

    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}
