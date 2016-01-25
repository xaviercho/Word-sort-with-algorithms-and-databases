/*
 * Name: Xavier Cho
 * Class: CSCE A311 - Data Structures & Algorithms
 * Instructor: Dr. Martin Cenek
 * Date: October 24, 2015
 * Homework #: 4
 * 
/


To use this cpp file and get the results you want according to the homework, 
depending on what is listed in step 12 in hw4
 as stated in # 12 

" Repeat the above steps 1-11 for arrays of size 10, 50, 100, 1000 and 5000 strings.  
In addition, create test files that have the first 25%, 50% and 75% of words already sorted. 
Rerun the above steps and record the algorithms' runtimes (number of comparisons). "

**you have to USE ONE ALGORITHM AT A TIME or else the program won't work correctly (uncomment one algorithm then comment the other)
the commented calls for each algorithm are located on lines 194-197.

**each time you switch sizes 10, 50, 100, 1000 and 5000 strings (also labled via title of txt files)
change the static size located on line 23 or else the results for the compaisons and the swaps are invalid.

**also to change the txt file to try other files,change the intended file in the quotations in line 165.


for example:

goal: change infile "10.txt" to verfiy if the algorithm works best case (basically number 6 in the rubric)

step 1: verify the size is the same as the string in the file via checking the title of the txt file
step 2: uncomment ONE algorithm of your choosing on lines 194-197.
step 3: go to line  165 and change "10.txt" to "10alreadysorted" then compare results given from both execusions to show the best case being n*log(n) or close to it 
        

for example (for step 3)
insertion sort will have 

best case:
comparisons: 9
swaps: 0

ususal case(range from n*log(n) to n^2):

comparisons: 9
swaps: 29

from here you can tell that the best case if we look at the comparisons that theit compared 
it only from 0-9 or 10 which is n*log(n)


*note the txt files that just have percentages are out of 5000