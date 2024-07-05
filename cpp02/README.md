# CPP Module02 

## ex00: Orthodox Canonical Form
In C++ class design, the Orthodox Canonical Form refers to a set of guidelines and practices related to the implementation of specific member functions in a class.   
4 functions that must be implemented are:   
- A default constructor  
- A copy constructor
- A copy assignment operator overload
- A destructor


### A default constructor
Initializes an object with default values or initializes all member variables appropriately when no arguments are provided.
### A copy constructor
Constructs a new object as a copy of an existing object of the same class
### A copy assignment operator overload
Assigns the contents of one object to another existing object of the same class. It should properly handle self-assignment and release any resources held by the target object before copying.
### A destructor 
Cleans up resources allocated by the object when it is destroyed.

Example:
```c
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

### Constructor that converts integers to fixed-point values
This constructor initializes a Fixed object using an integer n, shifting n left by _fractionalBits to represent it as a fixed-point number.
```c
Fixed::Fixed( const int n )
	: _rawBits(n << Fixed::_fractionalBits)
{
	std::cout << YELLOW << "Int constructor called" << RESET << std::endl;
}
```

#### Left Bit Shifting (<<)
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

### Constructor that converts floats to fixed-point values
This constructor initializes a Fixed object using a floating-point number `n`, converting it into a fixed-point representation stored in _rawBits.  
```c
Fixed::Fixed( const float n )
	: _rawBits(roundf(n * (1 << Fixed::_fractionalBits)))
{
	std::cout << YELLOW << "Float constructor called" << RESET << std::endl;
}
```

#### Round and Scale Operation
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

#### Member function to convert fixed-point values back to int
The fixed-point value is stored in `_rawBits` with the number of fractional bits `_fractionalBits`.  
To retrieve the integer part from `_rawBits`, we right shift it by `_fractionalBits`. This operation removes the fractional part, converting the fixed-point value back to an integer.  
```c
int	Fixed::toInt( void ) const
{
	return (this->_rawBits >> Fixed::_fractionalBits);
}
```

#### Member function to convert fixed-point values back to float
As we cannot do direct bit shifting with floats, we divide `_rawBits` by the scaling factor `1 << Fixed::_fractionalBits` to convert the fixed-point value back to a float  
```c
float	Fixed::toFloat( void ) const
{
	return (static_cast<float>(_rawBits) / (1 << Fixed::_fractionalBits));
}
```

#### Overload of the insertion («) operator 
The insertion operator `<<` is used to send output to streams like `std::cout`. 
By overloading this operator, we make it convenient to output Fixed objects directly, converting them to their floating-point representation before printing.
```c
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
