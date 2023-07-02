#include <algorithm>
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <bits/stdc++.h>
 
using namespace std;

int size = 50000;
long long int quickSortCounter = 0;

void generate2(int arr[], int begin, int end)
  {
    int count = end - begin;
    if(count < 3)
      return;
    int middle = begin + (count - 1) / 2;
    generate2(arr, begin, middle);
    swap(arr[begin], arr[middle]);
    generate2(arr, ++middle, end);
  }


long long int countSortMax = 0;

void countSort(int arr[], int size, int counts[]){
    for(int i=0; i<10001; i++){
        counts[i] = 0;
    }
    for(int i=0; i<size; i++){
        countSortMax++;
        counts[arr[i]]++;
    }
     int j=0;
    for(int i=0; i<size; i++){
      if(j<10001){
      while(counts[j] == 0 ){
            if(j<10000){
            j++;
            }
            else{
                break;
            }
        }
        if(j<10001){
        arr[i] = j;
        j++;
        }
    }
    }
}

long long int heapCounter = 0;
void heapify(int arr[], int n, int i)
{
    int largest = i; 
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2
 
    heapCounter +=2;
    if (l < n && arr[l] > arr[largest])
        largest = l;
 
    if (r < n && arr[r] > arr[largest])
        largest = r;
 
    if (largest != i) {
        swap(arr[i], arr[largest]);
 
        heapify(arr, n, largest);
    }
}
 
void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
 
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}
 void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}


void printArray(int array[], int size) {
  int i;
  for (i = 0; i < size; i++)
    cout << array[i] << " ";
  cout << endl;
}

int partition(int array[], int low, int high) {
    int pivot = array[low];
    int start = low;
    int end = high;

    while(start<end){
        quickSortCounter++;
        while(array[start]<= pivot ){
            if(start <= high){
            quickSortCounter++;
            start++;
            }else{
                break;
            }
        }
        quickSortCounter++;
        while(array[end] > pivot){
            if(end >= low){
            quickSortCounter++;
            end--;
            }else{
                break;
            }
        }
        if(start < end){
            swap(array[start], array[end]);
        }
    }
    swap(array[low], array[end]);
    return end;
}


void quickSort(int arr[], int low, int high)
{
    while (low < high)
    {
        int pi = partition(arr, low, high);
 
        if (pi - low < high - pi)
        {
            quickSort(arr, low, pi - 1);
            low = pi + 1;
        }
        else
        {
            quickSort(arr, pi + 1, high);
            high = pi - 1;
        }
    }
}


int getMedian(int arr[],int left,int right){
        int center = (left+right)/2;
         
        if(arr[left] > arr[center])
            swap(arr[left],arr[center]);
         
        if(arr[left] > arr[right])
            swap(arr[left], arr[right]);
         
        if(arr[center] > arr[right])
            swap(arr[center], arr[right]);
         
        swap(arr[center],arr[left]);
        return arr[right];
    }

void quickSortMedianOfThree(int arr[], int low, int high)
{
    while (low < high)
    {
        
        getMedian(arr,low,high);
        int pi = partition(arr, low, high);
        if (pi - low < high - pi)
        {
            quickSortMedianOfThree(arr, low, pi - 1);
            low = pi + 1;
        }
        else
        {
            quickSortMedianOfThree(arr, pi + 1, high);
            high = pi - 1;
        }
    }
}

long long int mergeCounter = 0;
void merge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0;
    int j = 0;
    int k = l;
 
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            mergeCounter++;
            arr[k] = L[i];
            i++;
        }
        else {
            mergeCounter++;
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(int arr[],int l,int r){
    if(l>=r){
        return;
    }
    int m =l+ (r-l)/2;
    mergeSort(arr,l,m);
    mergeSort(arr,m+1,r);
    merge(arr,l,m,r);
}
 
long long int insertionSortCounter = 0;
 bool control = false;
void insertionSort(int arr[], int n)

{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        insertionSortCounter++;
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
            insertionSortCounter++;
        }
        arr[j + 1] = key;
    }
}
long long int binarySearchCounter = 0;
long long int binaryInsertionCounter = 0;
int binarySearch(int arr[], int temp,
                 int start, int end)
{
    while (start <= end) {
			int mid = start + (end - start) / 2;
			if (temp < arr[mid]) {
                binarySearchCounter++;
				end = mid - 1;
			} else {
                binarySearchCounter++;
				start = mid + 1;
			}
		}
		return start;
	}

void binaryInsertionSort(int a[], int n)
{
    int i, loc, j, k, selected;
 
    for (i = 1; i < n; ++i)
    {
        j = i - 1;
        selected = a[i];
        loc = binarySearch(a, selected, 0, j);
        while (j >= loc)
        {
            binaryInsertionCounter++;
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = selected;
    }
}


int *copyArray;
static void tempArray(int arr[], int size)
{
    copyArray = new int[size];
    for (int i = 0; i < size; i++)
    {
        copyArray[i] = arr[i];
    }
}

      
int *sortedArray;
static void sortArray(int arr[]){
    sortedArray = new int[size];
    for(int i=0 ; i<size; i++){
        sortedArray[i] = arr[i];
    }
    sort(sortedArray, sortedArray + size);
}

int *reverseSortedArray;
static void reverseSortArray(int arr[]){
    reverseSortedArray = new int[size];
    for(int i=0 ; i<size; i++){
        reverseSortedArray[i] = arr[i];
    }
    sort(reverseSortedArray, reverseSortedArray + size, greater<int>());
}

int *duplicateArray;
static void duplicArray(){
    duplicateArray = new int[size];
    for(int i=0; i<size; i++){
        duplicateArray[i] = 1;
    }  
}

int *distinctArr;
static void distinctArray(){
    distinctArr = new int[size];
    int randArr[10000];
    int y=1;
    for(int i=0;i<10000;i++){
        randArr[i] = y++; 
    }
    srand(time(0));
    for(int i=0; i<size; i++){
        int r = i + rand() % (10000 - i);
        distinctArr[i] = randArr[r];
        randArr[r] = randArr[i]; 
    }
}



double mergeSortTimer(int *array){
    auto start = chrono::high_resolution_clock::now();
  
    // unsync the I/O of C and C++.
    ios_base::sync_with_stdio(false);
  
    mergeSort(array, 0, size-1);
  
    auto end = chrono::high_resolution_clock::now();
  
    // Calculating total time taken by the program.
    double time_taken = 
      chrono::duration_cast<chrono::nanoseconds>(end - start).count();
  
    time_taken *= 1e-9;
  
    return time_taken;

}

double heapSortTimer(int *array){
    auto start = chrono::high_resolution_clock::now();
  
    // unsync the I/O of C and C++.
    ios_base::sync_with_stdio(false);
  
    heapSort(array, size);
  
    auto end = chrono::high_resolution_clock::now();
  
    // Calculating total time taken by the program.
    double time_taken = 
      chrono::duration_cast<chrono::nanoseconds>(end - start).count();
  
    time_taken *= 1e-9;
  
    return time_taken;

}

double quickSortTimer(int *array){
    auto start = chrono::high_resolution_clock::now();
  
    // unsync the I/O of C and C++.
    ios_base::sync_with_stdio(false);
  
    quickSort(array, 0, size-1);
  
    auto end = chrono::high_resolution_clock::now();
  
    // Calculating total time taken by the program.
    double time_taken = 
      chrono::duration_cast<chrono::nanoseconds>(end - start).count();
  
    time_taken *= 1e-9;
  
    return time_taken;
}

double medianQuickSortTimer(int *array){
    auto start = chrono::high_resolution_clock::now();
  
    // unsync the I/O of C and C++.
    ios_base::sync_with_stdio(false);
  
    quickSortMedianOfThree(array, 0, size-1);
  
    auto end = chrono::high_resolution_clock::now();
  
    // Calculating total time taken by the program.
    double time_taken = 
      chrono::duration_cast<chrono::nanoseconds>(end - start).count();
  
    time_taken *= 1e-9;
  
    return time_taken;
}


double countSortTimer(int *array, int *s, int size){
    auto start = chrono::high_resolution_clock::now();
  
    // unsync the I/O of C and C++.
    ios_base::sync_with_stdio(false);
  
    countSort(array,size,s);
  
    auto end = chrono::high_resolution_clock::now();
  
    // Calculating total time taken by the program.
    double time_taken = 
      chrono::duration_cast<chrono::nanoseconds>(end - start).count();
  
    time_taken *= 1e-9;
  
    return time_taken;

}

double insertionSortTimer(int *array){
    auto start = chrono::high_resolution_clock::now();
  
    // unsync the I/O of C and C++.
    ios_base::sync_with_stdio(false);
  
    insertionSort(array, size);
  
    auto end = chrono::high_resolution_clock::now();
  
    // Calculating total time taken by the program.
    double time_taken = 
      chrono::duration_cast<chrono::nanoseconds>(end - start).count();
  
    time_taken *= 1e-9;
  
    return time_taken;
}

double binaryInsertionSortTimer(int *array){
    auto start = chrono::high_resolution_clock::now();
  
    // unsync the I/O of C and C++.
    ios_base::sync_with_stdio(false);
  
    binaryInsertionSort(array,size);
  
    auto end = chrono::high_resolution_clock::now();
  
    // Calculating total time taken by the program.
    double time_taken = 
      chrono::duration_cast<chrono::nanoseconds>(end - start).count();
  
    time_taken *= 1e-9;
  
    return time_taken;
}

int main() {
    cout << size << endl;
  int *data2 = new int[size];
  int *data1 = new int[size];
  int *data3 = new int[size];
  int *data4 = new int[size];
  int *data5 = new int[size];

  srand(time(0));
  for(int i=0; i<size; i++){
      data2[i] = (rand() % 10000) + 1;
  }
  for(int i=0; i<size; i++){
      data1[i] = (rand() % 10000) + 1;
  }
   for(int i=0; i<size; i++){
      data3[i] = (rand() % 10000) + 1;
  }
  for(int i=0; i<size; i++){
      data4[i] = (rand() % 10000) + 1;
  }
  for(int i=0; i<size; i++){
      data5[i] = (rand() % 10000) + 1;
  }




    cout<<"MERGE SORT"<<endl;
    double distinctSecond = 0;
    double sum = 0;
    int counter = 0;
    mergeCounter = 0;
    sortArray(data1);
    double sortedSecond = mergeSortTimer(sortedArray);
    cout<<"sorted merge " << mergeCounter <<endl;
    reverseSortArray(data1);
    mergeCounter = 0;
    double reverseSortedSecond = mergeSortTimer(reverseSortedArray);
    cout<<"reverse sorted merge " << mergeCounter <<endl;
    duplicArray();
    mergeCounter = 0;
    double duplicateSecond = mergeSortTimer(duplicateArray);
    cout<<"duplicate merge " << mergeCounter <<endl;
    if(size<10001){
    distinctArray();
    mergeCounter = 0;
    double distinctSecond = mergeSortTimer(distinctArr);
    cout<<"distinct merge " << mergeCounter<<endl;
    }


    mergeCounter = 0;
    tempArray(data1, size);
    double x = mergeSortTimer(copyArray);
    
    if(x !=0){
        sum += x;
        counter++;
    }
    tempArray(data2, size);
    x = mergeSortTimer(copyArray);
    if(x !=0){
        sum += x;
        counter++;
    }
    tempArray(data3, size);
    x = mergeSortTimer(copyArray);
    if(x !=0){
        sum += x;
        counter++;
    }
    tempArray(data4, size);
    x = mergeSortTimer(copyArray);
    if(x !=0){
        sum += x;
        counter++;
    }
    tempArray(data5, size);
    x = mergeSortTimer(copyArray);
    if(x !=0){
        sum += x;
        counter++;
    }
    if(counter == 0){
        counter = 1;
    }

    cout<<"average merge " << mergeCounter/5 <<endl;
    cout << "\naverage merge sort time " <<sum/counter<<endl;
    cout << "sorted second " << sortedSecond<<endl;
    cout << "reverse sorted second " << reverseSortedSecond<<endl;
    cout << "duplicate second " << duplicateSecond<<endl;
    cout << "\n" << endl;    




sum = 0;
counter = 0;
    cout<< "HEAP SORT"<<endl;
    heapCounter = 0;
    sortArray(data1);
    sortedSecond = heapSortTimer(sortedArray);
    cout<<"sorted heap " << heapCounter<<endl;
    reverseSortArray(data1);
    heapCounter = 0;
    reverseSortedSecond = heapSortTimer(reverseSortedArray);
    cout<<"reverse sorted heap " << heapCounter<<endl;
    duplicArray();
    heapCounter = 0;
    duplicateSecond = heapSortTimer(duplicateArray);
    cout<<"duplicate heap " << heapCounter<<endl;
    if(size<10001){
    distinctArray();
    heapCounter = 0;
    distinctSecond = heapSortTimer(distinctArr);
    cout<<"distinct heap " << heapCounter<<endl;
    }

    heapCounter = 0;
    tempArray(data1, size);
    x = heapSortTimer(copyArray);
     if(x !=0){
        sum += x;
        counter++;
    }
   
    tempArray(data2, size);
    x = heapSortTimer(copyArray);
     if(x !=0){
        sum += x;
        counter++;
    }

    tempArray(data3, size);
    x = heapSortTimer(copyArray);
     if(x !=0){
        sum += x;
        counter++;
    }

    tempArray(data4, size);
     x = heapSortTimer(copyArray);
     if(x !=0){
        sum += x;
        counter++;
    }
    tempArray(data5, size);
    x = heapSortTimer(copyArray);
     if(x !=0){
        sum += x;
        counter++;
    }
    if(counter == 0){
        counter = 1;
    }
    cout<<"average heap " << heapCounter/5<<endl;
    cout << "\naverage heap sort time " <<sum/counter<<endl;
    cout << "sorted second " << sortedSecond<<endl;
    cout << "reverse sorted second " << reverseSortedSecond<<endl;
    cout << "duplicate second " << duplicateSecond<<endl;







    sum = 0;
    counter = 0;
    cout << "\n" << endl;
    cout<<"MEDIAN QUICK SORT"<<endl;
   sortArray(data1);
   quickSortCounter = 0;
    sortedSecond = medianQuickSortTimer(sortedArray);
    cout<<"sorted median quick sort " << quickSortCounter<<endl;
    reverseSortArray(data1);
    quickSortCounter = 0;
    reverseSortedSecond = medianQuickSortTimer(reverseSortedArray);
    cout<<"reverse sorted median quick sort " << quickSortCounter<<endl;
    duplicArray();
    quickSortCounter = 0;
    duplicateSecond = medianQuickSortTimer(duplicateArray);
    cout<<"duplicate median quick sort " << quickSortCounter<<endl;
    if(size<10001){
    distinctArray();
    quickSortCounter = 0;
    
    quickSortCounter=0;
    distinctSecond = medianQuickSortTimer(distinctArr);
    cout<<"distinct median quick sort " << quickSortCounter<<endl;
    }
    
    quickSortCounter = 0;
    tempArray(data1, size);
    x = medianQuickSortTimer(copyArray);
     if(x !=0){
        sum += x;
        counter++;
    }
    tempArray(data2, size);
    x = medianQuickSortTimer(copyArray);
     if(x !=0){
        sum += x;
        counter++;
    }

    tempArray(data3, size);
    x = medianQuickSortTimer(copyArray);
     if(x !=0){
        sum += x;
        counter++;
    }

    tempArray(data4, size);
     x = medianQuickSortTimer(copyArray);
     if(x !=0){
        sum += x;
        counter++;
    }
    tempArray(data5, size);
    x = medianQuickSortTimer(copyArray);
     if(x !=0){
        sum += x;
        counter++;
    }
    if(counter == 0){
        counter = 1;
    }
    cout<<"average median quick sort " << quickSortCounter/5<<endl;
    cout << "\naverage median quick Sort time " <<sum/counter<<endl;
     cout << "sorted second " << sortedSecond<<endl;
    cout << "reverse sorted second " << reverseSortedSecond<<endl;
    cout << "duplicate second " << duplicateSecond<<endl;

   
   
   
  int *bestArray = new int[size];
  double bestQuick = 0;
    sum = 0;
    counter = 0;
   cout << "\n" << endl;
   cout<<"QUICK SORT"<<endl;
    quickSortCounter = 0;
    sortArray(data1);
   quickSortCounter = 0;
    sortedSecond = quickSortTimer(sortedArray);
    cout<<"sorted quick sort " << quickSortCounter<<endl;
    reverseSortArray(data1);
    quickSortCounter =0;
    reverseSortedSecond = quickSortTimer(reverseSortedArray);
    cout<<"reverse sorted quick sort " << quickSortCounter << endl;
    duplicArray();
    quickSortCounter = 0;
    duplicateSecond = quickSortTimer(duplicateArray);
   cout<<"duplicate quick sort " <<quickSortCounter <<endl;
   if(size<10001){
    distinctArray();
    for(int m=0; m<size; m++){
        bestArray[m] = distinctArr[m];
    }

    sort(bestArray, bestArray + size);
   generate2(bestArray,0,size-1);
    quickSortCounter = 0;
    bestQuick = quickSortTimer(bestArray);
   cout<<"best quick sort "<<quickSortCounter<<endl;
    quickSortCounter = 0;
    distinctSecond = quickSortTimer(distinctArr);
    cout<<"distinct quick sort " << quickSortCounter<<endl;
   }

    quickSortCounter = 0;
    tempArray(data1, size);
    x = quickSortTimer(copyArray);
     if(x !=0){
        sum += x;
        counter++;
    }
   
    tempArray(data2, size);
    x = quickSortTimer(copyArray);
     if(x !=0){
        sum += x;
        counter++;
    }

    tempArray(data3, size);
    x = quickSortTimer(copyArray);
     if(x !=0){
        sum += x;
        counter++;
    }

    tempArray(data4, size);
     x = quickSortTimer(copyArray);
     if(x !=0){
        sum += x;
        counter++;
    }
    tempArray(data5, size);
    x = quickSortTimer(copyArray);
     if(x !=0){
        sum += x;
        counter++;
    }
    if(counter == 0){
        counter = 1;
    }
    cout<<"average quick sort " << quickSortCounter / 5<<endl;
    cout << "\naverage quick Sort time " <<sum/counter<<endl;
     cout << "sorted second " << sortedSecond<<endl;
   cout << "reverse sorted second " << reverseSortedSecond<<endl;
    cout << "duplicate second " << duplicateSecond<<endl;
    cout <<"best quick sort time" << bestQuick<<endl;
    






sum = 0;
counter = 0;
cout << "\n" << endl;
cout<<"INSERTION SORT"<<endl;
sortArray(data1);
    insertionSortCounter = 0;
    sortedSecond = insertionSortTimer(sortedArray);
    cout << "sorted insertion counter " << insertionSortCounter << endl;
    
    insertionSortCounter = 0;
    
    reverseSortArray(data1);
    reverseSortedSecond = insertionSortTimer(reverseSortedArray);
    cout << "reverse sorted insertion counter " << insertionSortCounter << endl;
    
    insertionSortCounter = 0;
    duplicArray();
    duplicateSecond = insertionSortTimer(duplicateArray);
    cout << "duplicate insertion counter " << insertionSortCounter << endl;
    if(size<10001){
    distinctArray();
    insertionSortCounter = 0;
   
    distinctSecond = insertionSortTimer(distinctArr);
    cout<<"distinct insertion sort " << insertionSortCounter<<endl;
    }
    insertionSortCounter = 0;
    tempArray(data1, size);
    x = insertionSortTimer(copyArray);
     if(x !=0){
        sum += x;
        counter++;
    }
    tempArray(data2, size);
    x = insertionSortTimer(copyArray);
     if(x !=0){
        sum += x;
        counter++;
    }
    tempArray(data3, size);
    x = insertionSortTimer(copyArray);
     if(x !=0){
        sum += x;
        counter++;
    }
    tempArray(data4, size);
     x = insertionSortTimer(copyArray);
     if(x !=0){
        sum += x;
        counter++;
    }
    tempArray(data5, size);
    x = insertionSortTimer(copyArray);
     if(x !=0){
        sum += x;
        counter++;
    }
    if(counter == 0){
        counter = 1;
    }
    cout << "average insertion counter " << insertionSortCounter/5 << endl;
    cout << "\naverage insertion Sort time " <<sum/counter<<endl;
     cout << "sorted second " << sortedSecond<<endl;
    cout << "reverse sorted second " << reverseSortedSecond<<endl;
    cout << "duplicate second " << duplicateSecond<<endl;






sum = 0;
counter = 0;
cout << "\n" << endl;
cout<<"BINARY INSERTION"<<endl;    
    sortArray(data1);
    binaryInsertionCounter = 0;
    binarySearchCounter = 0;
    sortedSecond = binaryInsertionSortTimer(sortedArray);
    cout <<"sorted binary insertion " << std::max(binarySearchCounter,binaryInsertionCounter)<<endl;
   
    reverseSortArray(data1);
    binaryInsertionCounter = 0;
    binarySearchCounter = 0;
    reverseSortedSecond = binaryInsertionSortTimer(reverseSortedArray);
    cout <<"reverse sorted binary insertion " << std::max(binarySearchCounter,binaryInsertionCounter)<<endl;
   
    duplicArray();
    binaryInsertionCounter = 0;
    binarySearchCounter = 0;
    duplicateSecond = binaryInsertionSortTimer(duplicateArray);
    cout <<"duplicate binary insertion " << std::max(binarySearchCounter,binaryInsertionCounter)<<endl;
    if(size<10001){
    distinctArray();
    binaryInsertionCounter = 0;
    binarySearchCounter = 0;
    
    distinctSecond = binaryInsertionSortTimer(distinctArr);
    cout<<"distinct binary insertion sort " << std::max(binarySearchCounter,binaryInsertionCounter)<<endl;
    }
    binaryInsertionCounter = 0;
    binarySearchCounter = 0;
    tempArray(data1, size);
    x = binaryInsertionSortTimer(copyArray);
     
     if(x !=0){
        sum += x;
        counter++;
    }
   
    tempArray(data2, size);
    x = binaryInsertionSortTimer(copyArray);
     if(x !=0){
        sum += x;
        counter++;
    }

    tempArray(data3, size);
    x = binaryInsertionSortTimer(copyArray);
     if(x !=0){
        sum += x;
        counter++;
    }

    tempArray(data4, size);
     x = binaryInsertionSortTimer(copyArray);
     if(x !=0){
        sum += x;
        counter++;
    }
    tempArray(data5, size);
    x = binaryInsertionSortTimer(copyArray);
     if(x !=0){
        sum += x;
        counter++;
    }
    if(counter == 0){
        counter = 1;
    }
    cout<<"average binary insertion sort counter " << std::max(binarySearchCounter,binaryInsertionCounter)/5<<endl;
    cout << "\naverage binary insertion Sort time " <<sum/counter<<endl;
     cout << "sorted second " << sortedSecond<<endl;
    cout << "reverse sorted second " << reverseSortedSecond<<endl;
    cout << "duplicate second " << duplicateSecond<<endl;




int *count = new int[10001];
sum = 0;
counter = 0;
cout << "\n" << endl;
cout<<"COUNT SORT"<<endl;
countSortMax = 0;
    sortArray(data1);
   
    sortedSecond = countSortTimer(sortedArray,count,size);
    cout <<"sorted count " <<countSortMax  <<endl;
    reverseSortArray(data1);
    countSortMax = 0;
    reverseSortedSecond = countSortTimer(reverseSortedArray, count, size);
    cout <<"reverse sorted count " << countSortMax<<endl;
    duplicArray();
    countSortMax = 0;
    duplicateSecond = countSortTimer(duplicateArray, count, size);
    cout <<"duplicate count " << countSortMax<<endl;
    
    if(size<10001){
    distinctArray();
    countSortMax = 0;
    distinctSecond = countSortTimer(distinctArr,count,size);
    cout<<"distinct count sort " << countSortMax<<endl;
    }
    tempArray(data1,size);
    countSortMax = 0;
    x = countSortTimer(copyArray,count,size);
    
     if(x !=0){
        sum += x;
        counter++;
    }
    tempArray(data2,size);
    x = countSortTimer(copyArray,count,size);
     if(x !=0){
        sum += x;
        counter++;
    }

    tempArray(data3,size);
    x = countSortTimer(copyArray,count,size);
     if(x !=0){
        sum += x;
        counter++;
    }

    tempArray(data4,size);
     x = countSortTimer(copyArray,count,size);
     if(x !=0){
        sum += x;
        counter++;
    }
    tempArray(data5,size);
    x = countSortTimer(copyArray,count,size);
     if(x !=0){
        sum += x;
        counter++;
    }
    if(counter == 0){
        counter = 1;
    }
    cout<<"average count " <<countSortMax/5<<endl;
    cout << "\naverage count Sort time " <<sum/counter<<endl;
     cout << "sorted second " << sortedSecond<<endl;
    cout << "reverse sorted second " << reverseSortedSecond<<endl;
    cout << "duplicate second " << duplicateSecond<<endl;




cout << "\n" << endl;
}