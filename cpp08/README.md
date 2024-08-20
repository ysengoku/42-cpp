# CPP Module08 (on working)

## Containers

### STL containers

#### Sequence containers  
> Data structures which can be accessed sequentially  
`vector` `list` `deque`  
`array` `forward_list` (since C++11)  

#### Associative containers 
> Sorted data structures that can be quickly searched  
`set` `multiset` `map` `multimap`  

#### Unordered associative containers (since C++11)
> Unsorted (hashed) data structures that can be quickly searched
`unordered_set` `unordered_multiset` `unordered_map` `unordered_multimap`

#### Container adaptors
> Container adaptors provide a different interface for sequential containers.   
`stack` `queue` `priority_queue`

[cppreference.com/w/cpp/container](https://en.cppreference.com/w/cpp/container)

### std::list

```cpp
#include <list>
#include <iostream>

int main(void) {
    /* Create an empty list */
	std::list< int > test;

    /* Add elements to the list */
	test.push_back(1);
	test.push_back(2);
	test.push_back(3);
	test.push_back(4);
	test.push_front(5);
        // push_back: Add an element to the end of the list
        // push_front: Insert an element to the beginning of the list

    /* Print the elements of the list using iterator */
	for (std::list< int >::iterator it = test.begin(); it != test.end(); ++it)
		std::cout << *it << ' ';
        std::cout << std::endl;
}

// Output
// 5 1 2 3 4 
```
#### Reference:
- [cppreference.com](https://en.cppreference.com/w/cpp/container/list)
  
### std::vector
```cpp
#include <vector>
#include <iostream>

int main(void) {
	/* Create an empty vector */
	std::vector< int > test;

	/* Add elements to the end of the vector */
	test.push_back(1);
	test.push_back(2);
	test.push_back(3);
	test.push_back(4);
	test.push_back(5);

	/* Print elements using operator[] */
	for (size_t i = 0; i < test.size(); i++)
		std::cout << test[i] << ' ';
	std::cout << std::endl;

	/* Update the value of an element using 'at()' function */
	test.at(3) = 42;
	for (size_t i = 0; i < test.size(); i++)
		std::cout << test.at(i) << ' ';
	std::cout << std::endl;
}

// Output
// 1 2 3 4 5 
// 1 2 3 42 5
```
#### Reference:
- [cppreference.com](https://en.cppreference.com/w/cpp/container/vector)


### std::stack

Stack is a container adoptor with LIFO (Last-in First-out) structure.


### std::deque

A `deque` is a dynamic container that stores elements in a way similar to a vector but allows efficient insertions and deletions at both ends by internally managing multiple fixed-size arrays.  
Its iterators are specifically designed to handle this unique structure, which are essentially dynamic arrays of fixed-size arrays.  

```cpp
// Visual representation of a deque's internal structure
[fixed-size array][fixed-size array][fixed-size array]...
```
  
Performance Comparison of deque, vector, and list iterators  
| Feature | std::deque | std::vector | std::list |
|---|---|---|---|
| Random Access | Yes | Yes | No |
| Insertion/Deletion (beginning) | Efficient | Inefficient | Efficient |
| Insertion/Deletion (end) | Efficient | Efficient | Efficient |
| Insertion/Deletion (middle) | Efficient | Inefficient | Efficient |
| Memory Contiguity | Not necessarily | Yes | No |


### map

## Algorithms

### Iterators

#### Operations

```cpp
begin()

end()

advance()

next()

prev()
```
Iterators can be used for following containers  
`std::list` `std::vector` `std::map` `std::set`  
`std::array` `std::unordered_map` `std::unordered_set`

#### References

[Introduction to Iterators in C++](https://www.geeksforgeeks.org/introduction-iterators-c/)
[Iterators in C++ STL](https://www.geeksforgeeks.org/iterators-c-stl/)
[ゼロから学ぶ C++ - イテレータ](https://rinatz.github.io/cpp-book/ch03-08-iterators/)

### std::find

```cpp
template< class InputIt, class T >
InputIt find( InputIt first, InputIt last, const T& value );

// Parameters
// first: Iterator pointing to the beginning of the range to be searched
// last: Iterator pointing to one past the end of the range to be searched
// value: The value to be searched for
```
The function `std::find` returns an iterator pointing to the first occurance of `value` in the range.
If there is no element equal to `value` is found, it returns `last`. 

Example:
```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main(void) {
    std::vector< int > arr = {1, 2, 3, 4, 5};
    std::vector< int >::iterator it = std::find(arr.begin(), arr.end(), 3);
    if (it != arr.end()) {
        std::cout << "Found 3 at index: " << it - arr.begin() << std::endl;
    } else {
        std::cout << "3 not found" << std::endl;
    }
    return 0;
}

// Output
// Found 3 at index: 2
```

### sort

### std::min_element / std::max_element

### std::distance
