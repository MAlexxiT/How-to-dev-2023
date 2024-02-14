Sorting methods are fundamental while constructing software, usually, there are built-in sorting functions in every programming language, but sometimes programmers implement their own, either out of an absolute and specific necessity or to sharpen their programming skills.

Today you will implement an elimination sort named after a specific authoritarian
leader. You will be given a list of integers, then you have to iterate through the list eliminating all the elements that are smaller than their predecessor, this process will be repeated until the resulting array is sorted.
# Input
The first line of the input file contains an integer $N$ $(1 \le N\le 1000)$ indicating the size of the list you will be given.

The second and last line will contain $N$ integers $L_{i}$ ($0 \le L_{i} \le 1000$) separated by a space.

# Output
Print the resulting list after sorting using elimination sort. Whitespaces must separate each element of said list.

# Examples

||input
6
1 2 3 4 5 6
||output
1 2 3 4 5 6
||input
6
8 4 4 10 5 11
||output
8 10 11
||end

#Note
Consider the second testcase:
With the original array $[8,4,4,10,5,11]$, the algorithm will behave as follows

 - During the first pass the first 4 and 5 are eliminated from the array, resulting in $[8,4,10,11]$. The array is still unsorted, as 8 is greater than 4.
 - On the second pass the remaining 4 is eliminated from the array, resulting in $[8,10,11]$. The array is now sorted, which means no further passes are required.


 