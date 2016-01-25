 
/*
 * Name: Xavier Cho
 * Class: CSCE A311 - Data Structures & Algorithms
 * Instructor: Dr. Martin Cenek
 * Date: October 24, 2015
 * Homework #: 4
 * 
 This code provides quickSort, merge_sort, selection sort and insertion sort. and how they manage how time complexity works for every element of n that goes into each sorting algorithm, 
 in the results you will see how many times each algorithm has swaped elements and compared elements from the different test files given we can see the difference of each performance of each algorithm
 showing what is the best tool for when.has two static counters.
 
CppAdvancedCourse- https://www.youtube.com/channel/UCGIBubNVg6c6nf6D3ulkhBA
CS50- https://www.youtube.com/channel/UCcabW7890RKJzL968QWEykA

 helped with a better concept of stack, linked lists polymorphism, modulation & etiquette(via how to write sexy code)
*/
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

const int size = 10;  // static counter to control how many words need to be processed        HERE IS WHERE YOU CHANGE THE SIZE ACCORDING TO THE NUMBER OF WORDS IN THE TEXT FILE
static double compare_counter = 0; // counter to count  comparisons  for each algorithm of n    
static double swap_counter = 0;// counter to count seaps  for each algorithm  of n

void selectSort(string array[], int size){ 
 int position_of_min;
 string hold;

 for(int i=0; i < size-1; i++){
  position_of_min = i;//set position_of_min to the current index of the array
		
  for(int j=i+1; j < size; j++){

   if(array[j]<array[position_of_min]){//position_of_min will keep track of the index that the min is in, this is needed when swaps occurs
	compare_counter++;
    position_of_min=j;
   }
  }
   
  if(position_of_min != i){//if position_of_min no longer equals i than a smaller value must have been found,a swap must happen
   swap_counter++;
   hold = array[i];
   array[i] = array[position_of_min];
   array[position_of_min] = hold;
  }
 }
}

/*  implementation of quick sort with recursion */
void swap(string* a, string* b){//  swaps two elements
 swap_counter++;                                                                
 string t = *a;
 *a = *b;
 *b = t;
}
 
/*  takes last element as a pivot, places the pivot element at its
   correct position in the sorted array or behind the wall, then it places all smaller elements than the pivot
   to the left of pivot & anything bigger goes to right of pivot ,explains lines 65-67*/
int partition (string array[], int l, int h){
 string x = array[h];    // pivot
 int i = (l - 1);  // Index of smaller element
 for (int j = l; j <= h- 1; j++){
   if (array[j] <= x){           
    i++;   
    swap(&array[i], &array[j]);  
  }
 }
  swap(&array[i + 1], &array[h]);  
  return (i + 1);
}
 
void quickSort(string array[], int l, int h){ /* array[] == array to be sorted, l==low/Starting index, h==Ending index */																		
 if (l < h){ 
  compare_counter++;																			  
  int p = partition(array, l, h); /* Partitioning index */
  quickSort(array, l, p - 1);
  quickSort(array, p + 1, h);
 }
}

void merge(string array[], int l, int m, int r){
 int i, j, k;
 int n1 = m - l + 1;
 int n2 =  r - m;
 /* creates hold/temp arrays */
 string L[n1], R[n2];
 
 for(i = 0; i < n1; i++){ /* Copy data to temp array data in L array and R array */   //compares left and right array 
  swap_counter++;
  L[i] = array[l + i];
 }
		
 for(j = 0; j < n2; j++){
  swap_counter++;                                                                             
  R[j] = array[m + 1+ j];
 }
		
 /* Merge the temp arrays back into  1 array*/
 i = 0;
 j = 0;
 k = l;
 while (i < n1 && j < n2){
  compare_counter++;   //comparisons             
  if (L[i] <= R[j]){
   array[k] = L[i];
   i++;
  }
 else{
   array[k] = R[j];
   j++;
  }
   k++;	
 }
 
 while (i < n1){ /* Copy the remaining elements of L array */
 array[k] = L[i];
 i++;
 k++;
 }
 
 while (j < n2){/* Copy the remaining elements of R array */
 array[k] = R[j];
 j++;
 k++;
 }
}
 
/* creates a left and right temp arrays to later be merged into 1 sorted array */
void merge_sort(string array[], int l, int r){
 if (l < r){
  int m = l+(r-l)/2; // but avoids overflow for large l and h, basically creates the middle (l+r/2)
  merge_sort(array, l, m);
  merge_sort(array, m+1, r);
  merge(array, l, m, r);
 }
}

void insertionSort(string array[], int size){
 for(int i = 1; i < size; i++){  // arrray[i] is element to insert                           
  compare_counter++;   //compares

  for(int j=i; j > 0; j--){		
   if(array[j] < array[j - 1]){// checks to see if  j index is <  j-1 if it is then it swaps
	swap_counter++;//swaps
    swap(array[j], array[j - 1]);
   }
   else break;
  }
 }
}

void another_arrayay(string _myarray[], string _copyarray[]){//copies the current arrayay to another arrayay that will later use to manipulte the elements 
 for(int i=0; i<size; i++){
 _copyarray[i] = _myarray[i];
 }
}

int main(){
 ifstream infile;//initiates infile
 ofstream outfile;//initiates outfile
 outfile.open("results.txt");                     //check this file every time you change the txt file that your infile is opening to get the most recent results 
 infile.open("10.txt");                          // CHANGE YOUR TXT FILE HERE IN ORDER FOR THE PROGRAM TO WORK and get the results from each file
 string my_array[size];
 string copy_array[size];
 string current_word;
 for(int i=0; i<size; i++){
  infile >> current_word;
  for(int i = 0; i < current_word.length(); i++){
   current_word[i] = tolower(current_word[i]);
  }
   my_array[i] = current_word;
 }

 for(int i = 0; i < size ; ++i){   
  infile >> my_array[i];
  outfile << my_array[i];
  outfile << "\n";
 }

 outfile << "\n===========================================================================================================================================================\n";
 outfile<< "								▲▲▲▲▲▲UNSORTED arrayAY▲▲▲▲▲▲ \n" ;
 outfile<< "								     	  (above) " ;
 outfile << "\n===========================================================================================================================================================\n";
	
 outfile << "\n===========================================================================================================================================================\n";
 outfile<< "							 	 ▼▼▼▼▼▼SORTED arrayAY▼▼▼▼▼ \n" ;
 outfile<< "								     	  (below) " ;
 outfile << "\n===========================================================================================================================================================\n";
 another_arrayay(my_array,copy_array);
	
  insertionSort(copy_array,size);
   //selectSort(copy_array,size);
  //merge_sort(copy_array,0,size-1);
  //quickSort(copy_array, 0, size-1);  //HERE IS WHERE YOU UNCOMMENT THE FUNCTIONS THEN BUILD TO SEE RESULTS 
                                         

 for(int i = 0; i < size; ++i){
  infile >> my_array[i];
  outfile << copy_array[i];
  
  outfile << "\n";
 }
		
 outfile << "\n===========================================================================================================================================================\n";	
 outfile << "comparisons: "<< compare_counter<< "\n";
 outfile << "swaps: " << swap_counter << "\n";
 outfile << "\n===========================================================================================================================================================\n";
 infile.close();
 outfile.close();

}
