# CPP Module09 - ex02 \[Ford-Johnson Sort\]

The Ford-Johnson sort, also known as merge-insertion sort, is a comparison-based algorithm focused on minimizing the number of comparisons during sorting. Its primary goal is to reduce comparison count compared to traditional sorting methods.　　　

## Algorithm

> - Group the elements of X into ⌊n/2⌋ pairs of elements, arbitrarily, leaving one element unpaired if there is an odd number of elements.
> - Perform \[n/2\] comparisons, one per pair, to determine the larger of the two elements in each pair.
> - Recursively sort the \[n/2\] larger elements from each pair, creating a sorted sequence S of \[n/2\] of the input elements, in ascending order.
> - Insert at the start of S the element that was paired with the first and smallest element of S.
> - Insert the remaining \[n/2\]−1 elements of X ∖S into S, one at a time, with a specially chosen insertion ordering using Jacobsthal number. Use binary search in subsequences of S to determine the position at which each element should be inserted.
>
>　_Source: Wikipedia, [Ford–Johnson algorithm](https://en.wikipedia.org/wiki/Ford%E2%80%93Johnson_algorithm)_

### Recursively:  sort by pair
In my code, instead of creating a separate sorted sequence S, I directly sort sub-groups within the original sequence.   
I compare and swap elements within these sub-groups based on pairs. For each pair of blocks, if the elements in one block are larger than those in the corresponding block, I swap the entire blocks.   

Example with this sequence of 21 elements   
`[ 20 13 10 4 6 2 7 15 5 9 11 18 29 8 1 19 23 16 14 27 12 ]`   
   
<img width="869" alt="fordjohnson1" src="https://github.com/user-attachments/assets/792d76e9-0954-4f70-a431-284a0f5318d6">
   
<img width="869" alt="fordjohnson2" src="https://github.com/user-attachments/assets/8763339c-e77c-4bd8-ab07-0539b4be745d">
   
<img width="869" alt="fordjohnson3" src="https://github.com/user-attachments/assets/d46fc2db-cdca-41ac-a7d1-ac32d6f3d3c2">
   
<img width="832" alt="fordjohnson4" src="https://github.com/user-attachments/assets/e302f3c8-ed11-4d43-aabb-c52ccb69ba20">

### Recursively: Split to Main chain and Pend & Binary Search insert
`main chain` : Push the first pair \[smaller, larger\], then larger one of each pair.   
`pend` : Push smaller one ofeach pair, then the straggler if there is one.   

Push the elements in `pend` one by one using __Binary Search__.   
The range for binary search is determined as following:   
- If the element to be inserted is greater than the last inserted element, we set the start position to the next place of the last inserted element. The end position is  set to the position of larger one of its pair.
- Otherwise, the range is set from the beginning of mainChain to the last inserted element.

Using the sorted main chain, we rebuild the sequence while incorporating other elements from the groups.
   
<img width="670" alt="insert1" src="https://github.com/user-attachments/assets/843e78ad-f1da-4f29-8f15-8bbf63ac67a4">   
<img width="866" alt="insert_2" src="https://github.com/user-attachments/assets/f2e0bfb5-6456-4530-b971-4d043c7e5ec1">   
<img width="818" alt="insert2" src="https://github.com/user-attachments/assets/e7f5f3f5-a94c-48b5-9e17-61b6aed81adf">   
<img width="818" alt="insert3" src="https://github.com/user-attachments/assets/e6a3addd-5960-4bbc-9ad9-cf0046c1095d">   

---
#### Explanation step by step:  
Split to Main chain and Pend   
<img width="721" alt="fordjohnson5" src="https://github.com/user-attachments/assets/2f81c13a-f1dc-4224-bc08-6e3626d07656">   

Binary Search insert   
<img width="384" alt="fordjohnson6" src="https://github.com/user-attachments/assets/7b927cc7-6184-45b1-adf9-e73734192fc0">
<img width="487" alt="fordjohnson7" src="https://github.com/user-attachments/assets/cb78f98b-1a7c-4791-9b59-cea6d5295067">

Soerted   
<img width="629" alt="fordjohnson8" src="https://github.com/user-attachments/assets/fa2afda6-c4c5-47fd-9ae5-ecd57e40b35a">


---
<img width="866" alt="fordjohnson" src="https://github.com/user-attachments/assets/5d6102fc-98de-4566-9809-cc098ef14506">
