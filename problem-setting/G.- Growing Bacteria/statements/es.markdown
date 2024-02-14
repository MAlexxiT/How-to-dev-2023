Scientists from the renowned UACJ led by professor Saul are studying a new kind of slow-reproducing bacterium that can have broad applications in the medical world. This particular bacterium reproduces by a variant of binary fission following a reproductive cycle.

In simpler terms, there are cells, each with its own clock starting at a certain value $t_{i}$. After a certain amount of time (x milliseconds), any cell with a clock value of x will create a new cell and reset its own clock to a new value $D$ while the new cell's clock will start at $2 \times D$.

For his next experiment, Saul needs at least $R$ cells of the slow-reproducing bacteria, as $R$ can be a huge number, and the bacteria is known for its slow reproduction cycle Saul asked you to write a program to tell him how many milliseconds he must wait for the number of bacteria to be greater than or equal to $R$.

 
#Input
The first line of input has three integers $N$,$R$ and $D$ ( $1 \le N \le 1000$, $0 \le R \le 10^{13}$, $1 \le D \le 10^{7}$ ), denoting the initial amount of bacterium Saul has, the amount he needs and the value a cell must restart its internal clock back to respectively.

The Second line contains $N$ integers $t_{1}$ $t_{2}$ $...$ $t_{n}$ separated by whitespaces indicating the initial internal clock value of each of the $N$ bacterium Saul has. For each integer $t_{i}$, $1 \le t_{i}\le D$ holds.

# Output
Print a single integer denoting the number of milliseconds Saul must wait in order to have at least $R$ cells of his slow-reproducing bacteria.

# Examples

||input
4 4 100
2 5 8 8
||output
0
||input
4 10 10000000
2 5 8 8
||output
10000005
||end