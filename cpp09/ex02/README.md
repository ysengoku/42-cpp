#CPP Module09 ex02 - Ford-Johnson Sort
(On working)


## Algorithm

- Group the elements of X into ⌊n/2⌋ pairs of elements, arbitrarily, leaving one element unpaired if there is an odd number of elements.
- Perform \[n/2\] comparisons, one per pair, to determine the larger of the two elements in each pair.
- Recursively sort the \[n/2\] larger elements from each pair, creating a sorted sequence S of \[n/2\] of the input elements, in ascending order.
- Insert at the start of S the element that was paired with the first and smallest element of S.
- Insert the remaining \[n/2\]−1 elements of X ∖S into S, one at a time, with a specially chosen insertion ordering using Jacobsthal number. Use binary search in subsequences of S to determine the position at which each element should be inserted.

### Recursive sort by pair

<img width="869" alt="fordjohnson1" src="https://github.com/user-attachments/assets/792d76e9-0954-4f70-a431-284a0f5318d6">
   
<img width="869" alt="fordjohnson2" src="https://github.com/user-attachments/assets/8763339c-e77c-4bd8-ab07-0539b4be745d">
   
<img width="869" alt="fordjohnson3" src="https://github.com/user-attachments/assets/d46fc2db-cdca-41ac-a7d1-ac32d6f3d3c2">
   
<img width="832" alt="fordjohnson4" src="https://github.com/user-attachments/assets/e302f3c8-ed11-4d43-aabb-c52ccb69ba20">

### Split to Main chain and Pend
`main chain` : Push the first pair \[smaller, larger\], then larger one of each pair.   
`pend` : Push smaller one ofeach pair, then the straggler if there is one.

<img width="721" alt="fordjohnson5" src="https://github.com/user-attachments/assets/2f81c13a-f1dc-4224-bc08-6e3626d07656">   

### Binary Search insert
Push the elements in `pend` one by one using __Binary Search__. The range of search is determined by the position of larger one of its pair.   

<img width="384" alt="fordjohnson6" src="https://github.com/user-attachments/assets/7b927cc7-6184-45b1-adf9-e73734192fc0">
   
<img width="487" alt="fordjohnson7" src="https://github.com/user-attachments/assets/cb78f98b-1a7c-4791-9b59-cea6d5295067">
   
<img width="629" alt="fordjohnson8" src="https://github.com/user-attachments/assets/fa2afda6-c4c5-47fd-9ae5-ecd57e40b35a">
   

Recursively sort   

<img width="681" alt="fordjohnson9" src="https://github.com/user-attachments/assets/1c2c939b-d54e-4c11-bb03-254b580c1273">   
   
<img width="562" alt="fordjohnson10" src="https://github.com/user-attachments/assets/6a874832-ea76-4105-9105-ec675aa73a86">   

--------------------------
<img width="562" alt="fordjohnson11" src="https://github.com/user-attachments/assets/73f329c2-a421-43e6-81e4-04ecddee5957">

<img width="600" alt="fordjohnson12" src="https://github.com/user-attachments/assets/06044cae-e2b9-49c5-a00c-df0b2fea1601">
----------------------

<img width="866" alt="fordjohnson" src="https://github.com/user-attachments/assets/5d6102fc-98de-4566-9809-cc098ef14506">
