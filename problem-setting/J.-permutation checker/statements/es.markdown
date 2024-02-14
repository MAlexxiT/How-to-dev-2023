Samantha is a young programmer who loved solving challenging problems. One day, while browsing through omegaUp, she stumbled upon an interesting problem.

The problem was to write a program that would determine whether a given list of numbers was a permutation or not. Samantha knew that a permutation was a sequence of distinct integers from 1 to $N$, where $N$ is the length of the sequence. She solved the problem in a matter of minutes, and now she wants you to give it a try. 

# Input
The first line of input has an integer $N$ ($1 \le N\le 100$), denoting the length of the list you will be given.
The Second line contains $N$ sorted integers $a_{1}$ $a_{2}$ $...$ $a_{n}$ separated by whitespaces indicating the elements of the list, such that each element is an integer between $1$ and $1000$ inclusive.

# Output

Output on a single line:

 - *YES* if the given list is a permutation.
 - *NO* otherwise.

# Examples

||input
1
1
||output
YES
||input
5
1 2 3 4 5
||output
YES
||input
5
1 3 4 5 5
||output
NO
||input
5
1 2 4 5 6
||output
NO
||end

