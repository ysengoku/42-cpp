# CPP Module02 

## ex00: Orthodox Canonical Form
In C++ class design, the Orthodox Canonical Form refers to a set of guidelines and practices related to the implementation of specific member functions in a class.   
4 functions that must be implemented are:   
- A default constructor  
- A copy constructor
- A copy assignment operator overload
- A destructor


:small_orange_diamond: Default constructor  
Initializes an object with default values or initializes all member variables appropriately when no arguments are provided.  
  
:small_orange_diamond: Copy constructor  
Constructs a new object as a copy of an existing object of the same class  
  
:small_orange_diamond: Copy assignment operator overload  
Assigns the contents of one object to another existing object of the same class. It should properly handle self-assignment and release any resources held by the target object before copying.  
  
:small_orange_diamond: Destructor   
Cleans up resources allocated by the object when it is destroyed.  

Example:
```cpp
class	Fixed
{
	public:
		/* Default constructor */
		Fixed( void );
		/* Copy constructor */
		Fixed( const Fixed& src );
		/* Copy assignment operator */	
		Fixed& operator=( const Fixed& rhs ); 
		/* Destructor */
		~Fixed( void );

		/* Member functions */
		int	getRawBits( void ) const;
		void	setRawBits( int const raw );

	private:
		int               _rawBits;
		static const int  _fractionalBits = 8; 
};
```

## ex01: Fixed-point number class

We'll impliment a functional Fixed-Point class in adding:  
- Constructor
  - A constructor that takes a constant integer as a parameter
  - A constructor that takes a constant floating-point number as a parameter
- Methods to convert fixed-point values back to float or int
  - A member function `float toFloat( void ) const;`
  - A member function `int toInt( void ) const;`
- An overload of the insertion («) operator  

The fractional bits is set to 8 for consistent precision.  

### :small_orange_diamond: Constructor that converts integers to fixed-point values
This constructor initializes a Fixed object using an integer n, shifting n left by _fractionalBits to represent it as a fixed-point number.
```cpp
Fixed::Fixed( const int n )
	: _rawBits(n << Fixed::_fractionalBits)
{
	std::cout << YELLOW << "Int constructor called" << RESET << std::endl;
}
```

#### :point_right: Left Bit Shifting (<<)
This operator shifts the bits of a number `n` to the left by a specified number `_fractionalBits` of positions.  
In binary arithmetic, left shifting a number is equivalent to multiplying it by 2 raised to the power of the number of positions shifted.  

Example:  
`n << 1` shifts n left by 1 bit. (multiplying n by 2)  
`n << 2` shifts n left by 2 bits. (multiplying n by 2^2)  
`n << 8` shifts n left by 8 bits. (multiplying n by 2^8)  

```
== Example with int 5 ==
1. In binary, 5 is represented as 101.
2. Shifting 101 left by 8 positions results in 10100000000.
3. Converting 10100000000 from binary to decimal gives 1280.
4. Therefore, 5 << 8 equals 1280.
```
<img width="70%" alt="bit_shift" src="https://github.com/ysengoku/42-cpp/assets/130462445/d02e6793-f5c9-469d-b130-1087aec12b27">

### :small_orange_diamond: Constructor that converts floats to fixed-point values
This constructor initializes a Fixed object using a floating-point number `n`, converting it into a fixed-point representation stored in _rawBits.  
```cpp
Fixed::Fixed( const float n )
	: _rawBits(roundf(n * (1 << Fixed::_fractionalBits)))
{
	std::cout << YELLOW << "Float constructor called" << RESET << std::endl;
}
```

#### :point_right: Round and Scale Operation
The expression `roundf(n * (1 << Fixed::_fractionalBits))` performs the following operations:  

1. Calculate scaling factor for Left Bit Shifting (<<):  
  Because we cannot use bit shift operators for floats, we should use a Scaling Factor instead `1 << Fixed::_fractionalBits`

2. Multiplication with Floating-Point Number (n):  
  Multiplie the floating-point number `n` by the scaling factor.   This step ensures that n is converted to a fixed-point format with Fixed::_fractionalBits fractional bits.

3. Rounding (roundf()):  
  roundf() rounds the result of `n * (1 << Fixed::_fractionalBits)` to the nearest integer value.   Rounding is crucial to ensure accurate representation of the floating-point value n within the fixed-point format.

```
== Example with float 5.25 ==
1. Scaling Factor: 256 (1 << 8)
2. Scaled Value: 5.25 * 256 = 1344.0
3. Rounded Value: roundf(1344.0) = 1344
```

#### :small_orange_diamond: Member function to convert fixed-point values back to int
The fixed-point value is stored in `_rawBits` with the number of fractional bits `_fractionalBits`.  
To retrieve the integer part from `_rawBits`, we right shift it by `_fractionalBits`. This operation removes the fractional part, converting the fixed-point value back to an integer.  
```cpp
int	Fixed::toInt( void ) const
{
	return (this->_rawBits >> Fixed::_fractionalBits);
}
```

#### :small_orange_diamond: Member function to convert fixed-point values back to float
As we cannot do direct bit shifting with floats, we divide `_rawBits` by the scaling factor `1 << Fixed::_fractionalBits` to convert the fixed-point value back to a float  
```cpp
float	Fixed::toFloat( void ) const
{
	return (static_cast<float>(_rawBits) / (1 << Fixed::_fractionalBits));
}
```

#### :small_orange_diamond: Overload of the insertion («) operator 
The insertion operator `<<` is used to send output to streams like `std::cout`. 
By overloading this operator, we make it convenient to output Fixed objects directly, converting them to their floating-point representation before printing.
```cpp
std::ostream &operator<<(std::ostream& os, const Fixed& fixed)
// Parameters:
// std::ostream& os: The output stream where the data will be sent.
// const Fixed& fixed: The Fixed object to be outputted.
{
	// Convert the Fixed object's value to a float and sends it to the output stream.
	os << fixed.toFloat();

	// Return the same std::ostream object, allowing further insertion operations on the same stream in a single statement.
	// This enables expressions like std::cout << obj1 << obj2; to work seamlessly by chaining multiple insertion operations.
	return (os);
}
```

## ex02: Operator overload
Add following public overload member functions to the class `Fixed`:
- 6 comparison operators: >, <, >=, <=, == and !=.
- 4 arithmetic operators: +, -, *, and /.
- 4 increment/decrement (pre-increment and post-increment, pre-decrement and post-decrement) operators
- 4 static member function (min/max)
	- `min` that returns a reference to the smallest of two fixed-point number references
 	- `min` that returns a reference to the smallest of two constant fixed-point number references
  	- `max` that returns a reference to the largest of two fixed-point number references
  	- `max` that returns a reference to the largest of two constant fixed-point number references.	

### :small_orange_diamond: Comaprison operators
```cpp
bool	operator>( const Fixed& rhs ) const;
bool	operator<( const Fixed& rhs ) const;
bool	operator>=( const Fixed& rhs ) const;
bool	operator<=( const Fixed& rhs ) const;
bool	operator==( const Fixed& rhs ) const;
bool	operator!=( const Fixed& rhs ) const;
```
Comaprison operators are quite simple. They compare the fixed-point values `_rawBits` of the left-hand side `this`and the right-hand side `rhs`, then return the result (true or false).

### :small_orange_diamond: Arithmetic operators
```cpp
Fixed	operator+( const Fixed& rhs ) const;
Fixed	operator-( const Fixed& rhs ) const;
Fixed	operator*( const Fixed& rhs ) const;
Fixed	operator/( const Fixed& rhs ) const;
```

#### :point_right: Addition and subtraction operators
The addition and subtraction operators simply compute the sum or difference of two fixed-point values `_rawBits` from the left-hand side (`this`) and the right-hand side (`rhs`).

#### :point_right: Multiplication operator
```cpp
Fixed	Fixed::operator*( const Fixed& rhs ) const
{
	Fixed	result;

	result.setRawBits((this->_rawBits * rhs._rawBits) >> Fixed::_fractionalBits);
	return (result);
}
```
Multiplies the two raw integer values (`this->_rawBits` and `rhs._rawBits`), then adjust for Fractional Bits in shifting the result right by the number of fractional bits (`Fixed::_fractionalBits`).  
```
== Example ==
a: 1.5 in fixed-point (represented as 1.5 * 2^8(= 256) = 384 in _rawBits)
b: 2.0 in fixed-point (represented as 2.0 * 2^8 = 512 in _rawBits)

Perform multiplication:
a * b = 384 * 512 = 196608

Adjust for fractional bits:
196608 >> 8 (196608 / 2^8) = 768

Convert 768 to float:
768 >> 8 (768 / 2^8) = 3.0
```

#### :point_right: Division operator
```cpp
Fixed	Fixed::operator/( const Fixed& rhs ) const
{
	Fixed	result;

	result.setRawBits((this->_rawBits << Fixed::_fractionalBits) / rhs._rawBits);
	return (result);
}
```
Adjust the left-hand side `this->_rawBits` in shifting left by the number of fractional bits (`Fixed::_fractionalBits`), then divide the left-hand side `this->_rawBits` by the right-hand side `rhs._rawBits`. 
```
== Example ==
a: 1.5 in fixed-point (represented as 1.5 * 2^8 = 384 in _rawBits)
b: 2.0 in fixed-point (represented as 2.0 * 2^8 = 512 in _rawBits)

Adjust for fractional bits:
384 << 8 (384 * 2^8) = 98304

Perform division:
98304 / 512 = 192

Convert 192 to float:
192 >> 8 (192 / 2^8) = 0.75
```

### :small_orange_diamond: Increment/decrement (pre-increment and post-increment, pre-decrement and post-decrement) operators
```cpp
Fixed&	operator++( void );
Fixed	operator++( int );
Fixed&	operator--( void );
Fixed	operator--( int );
```
> [!TIP]
> :abacus: Pre-increment, pre-decrement `++a / --a`  
> Return the object after incrementing/decrementing the value.
> This is more efficient than post-increment and post-decrement because it doesn`t create a copy of object.
>
> :abacus: Post-increment, post-decrement `a++ / a--`  
> Return the object before incrementing/decrementing the value
> Slight overhead because it creates a temporay copy of the object.

#### :point_right: Pre-increment / pre-decrement operators
Pre-increment and pre-decrement operators increase/decrease `_rawBits` by 1 so that the operators will increase/decrease the fixed-point value by the smallest representable ε, ensuring that 1 + ε > 1.
Then it returns a reference to the object.

```cpp
Fixed&	Fixed::operator++( void )
{
	// Increase _rawBits value of the object by 1
	++this->_rawBits;

	// Return a reference to the object
	return (*this);
}

Fixed&	Fixed::operator--( void )
{
	--this->_rawBits;
	return (*this);
}
```

#### :point_right: Post-increment / post-decrement operators
Post-increment and post-decrement operators increase/decrease `_rawBits` by 1, returning the value before the operation (1 + ε > 1). They return a copy of the object (`tmp`).

```cpp
Fixed	Fixed::operator++( int )
{
	// Create a copy of the object
	Fixed	tmp(*this);

	// Increase _rawBits value of the object by 1
	this->_rawBits++;

	// Return the copy
	return (tmp);
}

Fixed	Fixed::operator--( int )
{
	Fixed	tmp(*this);

	this->_rawBits--;
	return (tmp);
}
```

### :small_orange_diamond: Static member function (min/max)
```c
static Fixed&		min( Fixed& lhs, Fixed& rhs );
static const Fixed&	min( const Fixed& lhs, const Fixed& rhs );
static Fixed&		max( Fixed& lhs, Fixed& rhs );
static const Fixed&	max( const Fixed& lhs, const Fixed& rhs );
```
Implement Fixed-Point `min` and `max` Function both in non-const reference version and const reference version.   

#### :small_orange_diamond: Non-const reference version  
This version takes the non-const references to 2 Fixed objects as parameters and returns a non-const reference to the smaller/grater of the two Fixed objects.  
It allows modification of the returned Fixed object since it returns a non-const reference. It can be used when you need to work with and potentially modify the smaller/grater Fixed object directly.  

#### :small_orange_diamond: Const reference version
This version takes the const reference to 2 Fixed objects and returns a const reference to the smaller/grater of the two Fixed objects.
It prevents modification of the returned Fixed object since it returns a const reference.  

## ex03: BSP

Implement a function which indicates whether a point is inside of a triangle or not.

<img width="80%" alt="bsp01" src="https://github.com/ysengoku/42-cpp/assets/130462445/ce3270c9-f8bb-4dbf-bcd1-ea5d30b6622c">

### Area Method Algorithm  
I used the area method to determine if a point P lies inside a triangle formed by three points A, B, and C.  
The algorithm compares the area of triangle ABC with the sum of the areas of triangles PAB, PBC, and PCA. 
If the sum of the areas of these three triangles equals the area of triangle ABC, then point P is inside the triangle.

#### Steps
1. Define the vertices of the triangle and the point to be tested:   
  - Triangle vertices: A(x1,y1), B(x2,y2), and C(x3,y3).   
  - Point to test: P(x,y).   

2. Calculate the area of a triangle:
I used Shoelace formula to calculate the area of a triangle.   
For the triangle ABC, the formula is as following.   
`area = | 1/2 ((x2 - x1) * (y3 - y1)) - ((y2 - y1) * (x3 - x1))|`

<img width="80%" alt="bsp02" src="https://github.com/ysengoku/42-cpp/assets/130462445/a12b7b98-c67e-4cd4-b05b-a015e87a1708">

  
3. Comapre the area of the triangle ABC and the sum of 3 triangles PAB, PBC, and PCA.   
Because the subject says _"Thus, if the point is a vertex or on edge, it will return False."_, We need to check it before return the result.
- If the point is a vertex, P(x,y) equals A(x1,y1), B(x2,y2), or C(x3,y3).
- If the point is in edge, the area of one of the 3 triangles is zero.
