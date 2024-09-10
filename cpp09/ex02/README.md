Group the elements of X into ⌊n/2⌋ pairs of elements, arbitrarily, leaving one element unpaired if there is an odd number of elements.

Perform \[n/2\] comparisons, one per pair, to determine the larger of the two elements in each pair.

Recursively sort the \[n/2\] larger elements from each pair, creating a sorted sequence 
S of \[n/2\] of the input elements, in ascending order.

Insert at the start of S the element that was paired with the first and smallest element of S.

Insert the remaining \[n/2\]−1 elements of X ∖S into S, one at a time, with a specially chosen insertion ordering using Jacobsthal number. Use binary search in subsequences of S to determine the position at which each element should be inserted.
