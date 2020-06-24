# Longest-common-subsequence-Algorithm

The longest common subsequence (LCS) problem is the problem of finding the longest subsequence common to all sequences in a set of sequences (often just two sequences).The longest common subsequence problem is a classic computer science problem, the basis of data comparison programs such as the diff utility, and has applications in computational linguistics and bioinformatics for DNA sequence alignment and pattern discovery. It is also widely used by revision control systems such as Git for reconciling multiple changes made to a revision-controlled collection of files.

Requirements: 
 
1. Write a C/C++ program to compute the longest common subsequence of two sequences in two different ways: 
 a. The elementary cost matrix method using Θ(mn) space.  
 
b. The LSIS method intended for use in sparse situations with relatively large “alphabets”:  
 
1. For each of the 256 alphabet symbols, determine the positions (descending order) where the symbol appears in the second sequence.  Do not do 256 passes over the second sequence!  (Think about counting sort . . .) 2. Produce an intermediate sequence by replacing each symbol in the first sequence by its positions from the second sequence. 3. Compute a LSIS of the intermediate sequence. 4. The sequence of values from the LSIS may be used as indexes to the second sequence to obtain an LCS. 
 
c. In all situations, the solution you find for both methods should be identical. 
 
2. The input for the two input sequences will be formatted as: 
 a. The first line of the input will be two values, m and n, giving the lengths of the two input sequences.  These will not exceed 25000. b. The next m lines will each contain a single integer in the range 0 . . . 255. c. A line with the value -1. d. The next n lines will each contain a single integer in the range 0 . . . 255. e. A line with the value -1. 
 
3. The output from your program should go to standard output, not a file: 
 
a. The first line should be the length of the LCS found by both methods. b. Each of the remaining lines should have one element of the LCS found by both methods. c. A single line with the value -1. d. Before emitting this output, your program should explictly check that the two methods (independently) produced the same result.  Do not print a result if they differ! e. The last line of your output should provide the CPU time for each method. 

Sample Input: 
 9 9 
 7 8 9 9 8 7 7 8 9 -1 
 7 7 8 8 6 9 8 7 9 -1 
 
 Sample Output: 
 6 
 7 8 9 8 7 9 -1 
