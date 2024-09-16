# CPP Module09 - ex02 \[Ford-Johnson Sort\]

The Ford-Johnson sort, also known as merge-insertion sort, is a comparison-based algorithm focused on minimizing the number of comparisons during sorting. Its primary goal is to reduce comparison count compared to traditional sorting methods.　

## Usage
```bash
make
./PmergeMe <positive integer sequence>
```
```c
/*Debug mode*/
make debug

/*Launch with sort check*/
make check
```
   
To generate random number sets for test   
[Random Integer Set Generator](https://www.random.org/integer-sets/)   

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
<img width="818" alt="insert2" src="https://github.com/user-attachments/assets/aee296f3-aa34-4b4a-946b-996e7307d03a">
<img width="818" alt="insert3" src="https://github.com/user-attachments/assets/e7f5f3f5-a94c-48b5-9e17-61b6aed81adf">   
<img width="818" alt="insert4" src="https://github.com/user-attachments/assets/e6a3addd-5960-4bbc-9ad9-cf0046c1095d">   

---
#### Explanation step by step:  
Before sort   
![step0](https://github.com/user-attachments/assets/1283130d-f2cb-4615-9668-192805b4dc12)

Sorting   
![step1](https://github.com/user-attachments/assets/2d10b1a3-a58f-48d6-a8a3-a4e34d3d5500)
![step2](https://github.com/user-attachments/assets/d138a51a-4635-40de-b24a-96574d7bc6d4)
![step3](https://github.com/user-attachments/assets/6cf98108-8903-40b8-81b4-17dd608f0ea7)
![step4](https://github.com/user-attachments/assets/f60d4166-6d21-4e54-b49c-837057b67adc)

Soerted   
<img alt="fordjohnson8" src="https://github.com/user-attachments/assets/66361ebe-2c89-4ff2-89ad-96e86598424b">
   
---
Overview   
<img alt="fordjohnson" src="https://github.com/user-attachments/assets/40d4a005-682e-4a20-8d0f-eca29b18b467">
