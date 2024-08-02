(On working)
# CPP Module04

## Subtype polymorphism 
In object-oriented programming,__subtype polymorphism__, is a concept that allows objects of different classes to be treated as objects of a common superclass. It enables a single function or method to operate on objects of different types in a way that each type can provide its own implementation of the method.  
  
Example
```cpp
// Base class
class Animal {
    public:
      [...]
      virtual void makeSound( void ) const; // Set it 'virtual' so that dirived classes can override the function.

    protected:
      std::string  _type;
};

// Derived classes
class  Dog : public Animal {
    public:
      [...]
      void makeSound( void ) const; // Dog has its own 'makeSound'
};

class  Cat : public Animal {
    public:
      [...]
      void makeSound( void ) const; // Cat has its own 'makeSound'
};
```

## Deep copy
Deep copy creates a new object copying the content of the source object.  
The copied object is independant of the original one. Even if we modify a value of attribute of the copy or delete it, there is no impact on the original one.  
  
Example
```cpp
#include <iotream>
#include <string>

class Book {
    public:
	Book(const std::string& title);
	Book(Book const& src);
	Book& operator=(Book const& rhs);
	~Book(void) {}

	void displayTitle(void) const;

    private:
	std::sring _title;
	Book(void) {}
};

class Library {
    public:
	Library(const nsigned int& size);
	Library(Library const& src); // This should do 'Deep copy'
	Library& operator=(Library const& rhs); // This should do 'Deep copy'
	~Library(void);

	void addBook(Book const& book);
	void showLibrary(void);

    private:
	Book* _books;
	unsigned int _size;
	unsigned int _count;
	Library(void) {}
};

// Book class definition
Book::Book(const std::string& title) : _title(title) {}
Book::Book(Book const& src) : _title(src._title) {}
Book& Book::operator=(Book const& rhs) {
	if (this != &rhs)
		_title = rhs._title;
	return (*this);
}

void Book::displayTitile(void) const {
	std::cout << _title << std::endl;
}

// Library class definitoin
Library::Library((const unsigned int& size) : _size(size), _count(0) {
	_books = new Book[_size];
}

Library::Library(Library const& src) : _size(src._size), _count(src._count) {
	books = new Book[_size]; // Allocate new memory
	for (int i = 0; i < _size; i++)
		_books[i] = src._books[i]; // Copy each Book
}

Library& Library::operator=(Library const& rhs) {
	if (this == &rhs)
		return *this; // Handle self assignment
	delete _books[]; // Free old memory
	_size = rhs._size; // Update _size
	_count = rhs._count; // Update _count
	_books = new Book(_size); // Allocate new memory
	for (int i = 0; i < _size; i++)
		books[i] = rhs._books[i]; // Copy each Book
	return *this;
}

Library::~Library(void) {
	delete[] books; // Free allocated memory
}

void Library::addBook(std::string title) {
	if (_count == _size) {
		std::cout << "Library is full. You cannot add a new book." << std::endl;
		return ;
	}
	_books[_count]._title = title;
	_count++;
}

void Library::showLibrary(void) {
	for (int i = 0; i < _size; i++) {
		std::cout << "[" << i + 1 << "] ";
		_books[i].displayTitle();
}

int main() {
    Library myLibrary(3); // Create a library with a capacity of 3 books

    // Add books to the library
    myLibrary.addBook("The Great Gatsby");
    myLibrary.addBook("1984");
    myLibrary.addBook("To Kill a Mockingbird");

    std::cout << "Current library collection:\n";
    myLibrary.showLibrary(); // Display current books in the library

    // Attempt to add another book (should fail as the library is full)
    myLibrary.addBook("Pride and Prejudice");

    // Create a copy of the library using the copy constructor
    Library copyLibrary = myLibrary;
    std::cout << "\nCopy of the library collection:\n";
    copyLibrary.showLibrary(); // Show the copied library

    // Modify the original library
    myLibrary.addBook("The Catcher in the Rye");
    std::cout << "\nOriginal library after adding a new book:\n";
    myLibrary.showLibrary();

    std::cout << "\nCopied library should remain unchanged:\n";
    copyLibrary.showLibrary(); // Show the copied library to demonstrate deep copy

    return 0;
}
```

## Abstract class
Abstract class is a base class which is not instantiable.
To create an abstruct class, we put 

## Interface
Interface is a pure abstruct class which has only pure virtual methodes.

```c++
// Virtual methode
virtual void  methode();

// Pure virtual methode
virtual void methode() = 0;
```

## References

[Subtyping - Wikipedia](https://en.wikipedia.org/wiki/Subtyping)
[Zenn: C++ クラス継承とポリモーフィズム](https://zenn.dev/rt3mis10/articles/2d9f5e8bcc06a7)
