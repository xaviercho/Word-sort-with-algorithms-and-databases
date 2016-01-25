
const int size = 5000;
static double QC1 = 0;
static double QC2 = 0;

void selectSort(string arr[], int size){ //pos_min is short for position of min
 int pos_min;
 string temp;

 for(int i=0; i < size-1; i++){
  pos_min = i;//set pos_min to the current index of array
		
  for(int j=i+1; j < size; j++){

   if(arr[j]<arr[pos_min]){//pos_min will keep track of the index that min is in, this is needed when a swap happens
	QC1++;
    pos_min=j;
   }
  }
   
  if(pos_min != i){//if pos_min no longer equals i than a smaller value must have been found, so a swap must occur
   QC2++;
   temp = arr[i];
   arr[i] = arr[pos_min];
   arr[pos_min] = temp;
  }
 }
}

/* A typical recursive implementation of quick sort */
// A utility function to swap two elements
void swap(string* a, string* b){
 QC2++;                                                                
 string t = *a;
 *a = *b;
 *b = t;
}
 
/* This function takes last element as pivot, places the pivot element at its
   correct position in sorted array, and places all smaller (smaller than pivot)
   to left of pivot and all greater elements to right of pivot */
int partition (string arr[], int l, int h){
 string x = arr[h];    // pivot
 int i = (l - 1);  // Index of smaller element
 for (int j = l; j <= h- 1; j++){
   if (arr[j] <= x){        // If current element is smaller than or equal to pivot         
    i++;    // increment index of smaller element
    swap(&arr[i], &arr[j]);  // Swap current element with index
  }
 }
  swap(&arr[i + 1], &arr[h]);  
  return (i + 1);
}
 
/* arr[] --> Array to be sorted, l  --> Starting index, h  --> Ending index */
void quickSort(string arr[], int l, int h){																									
 if (l < h){ 
  QC1++;																			  
  int p = partition(arr, l, h); /* Partitioning index */
  quickSort(arr, l, p - 1);
  quickSort(arr, p + 1, h);
 }
}

void merge(string arr[], int l, int m, int r){
 int i, j, k;
 int n1 = m - l + 1;
 int n2 =  r - m;
 /* create temp arrays */
 string L[n1], R[n2];
 /* Copy data to temp arrays L[] and R[] */   //compares left and right array 
 for(i = 0; i < n1; i++){
  QC2++;
  L[i] = arr[l + i];
 }
		
 for(j = 0; j < n2; j++){
  QC2++;                                                                             
  R[j] = arr[m + 1+ j];
 }
		
 /* Merge the temp arrays back into arr[l..r]*/
 i = 0;
 j = 0;
 k = l;
 while (i < n1 && j < n2){
  QC1++;                   //comparisons             
  if (L[i] <= R[j]){
   arr[k] = L[i];
   i++;
  }
 else{
   arr[k] = R[j];
   j++;
  }
   k++;	
 }
 
 while (i < n1){ /* Copy the remaining elements of L[], if there are any */
 arr[k] = L[i];
 i++;
 k++;
 }
 
 while (j < n2){/* Copy the remaining elements of R[], if there are any */
 arr[k] = R[j];
 j++;
 k++;
 }
}
 
/* l is for left index and r is right index of the sub-array
of arr to be sorted */
void merge_sort(string arr[], int l, int r){
 if (l < r){
  int m = l+(r-l)/2; //Same as (l+r)/2, but avoids overflow for large l and h
  merge_sort(arr, l, m);
  merge_sort(arr, m+1, r);
  merge(arr, l, m, r);
 }
}

void insertionSort(string arr[], int size){
 for(int i = 1; i < size; i++){  // ar[i] is element to insert                                      DONE!!!!
  QC1++;   //counter here   compare

  for(int j=i; j > 0; j--){		
   if(arr[j] < arr[j - 1]){
	QC2++;//counter here swap
    swap(arr[j], arr[j - 1]);
   }
   else break;
  }
 }
}

void another_array(string _myArray[], string _copyArray[]){
 for(int i=0; i<size; i++){
 _copyArray[i] = _myArray[i];
 }
}