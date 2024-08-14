#CPP Module08

## Containers
https://ja.cppreference.com/w/cpp/container
### list
### vector
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
- std::array
- std::vector
- std::map
- std::set
- std::unordered_map
- std::unordered_set

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
    std::vector<int> arr = {1, 2, 3, 4, 5};
    std::vector<int>::iterator it = std::find(arr.begin(), arr.end(), 3);
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
