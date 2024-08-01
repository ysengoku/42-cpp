# CPP Module06 (On working)

## ex00
### Check input value type (char, int, float or double)
#### Check if the input valur is int
We can use `long strtol( const char* str, char** str_end, int base );` from `cstdlib`

```c++
int	main(int argc, char **argv)
{
	errno = 0;
	char*	end;
	long	num;

	if (argc == 2)
	{
		num = std::strtol(argv[1], &end, 10);
		if (*end != '\0')
			std::cout << "Invalid argument" << std::endl;
		else if (errno == ERANGE || num > INT_MAX || num < INT_MIN)
			std::cout << "Overflow" << std::endl;
		else
			std::cout << "Converted value: " << num << std::endl;
	}
	else
		std::cout << "Usage: ./convert <value to convert>" << std::endl;
    return 0;
}
```
```
➜  ex00 git:(main) ✗ ./convert 123
Converted value: 123
➜  ex00 git:(main) ✗ ./convert -123  
Converted value: -123
➜  ex00 git:(main) ✗ ./convert +123
Converted value: 123
➜  ex00 git:(main) ✗ ./convert -2147483648
Converted value: -2147483648
➜  ex00 git:(main) ✗ ./convert -2147483649
Overflow
➜  ex00 git:(main) ✗ ./convert 2147483648
Overflow
➜  ex00 git:(main) ✗ ./convert 2147483647
Converted value: 2147483647
➜  ex00 git:(main) ✗ ./convert 0         
Converted value: 0
➜  ex00 git:(main) ✗ ./convert aaa
Invalid argument
➜  ex00 git:(main) ✗ ./convert 123abc
Invalid argument
➜  ex00 git:(main) ✗ ./convert a123
Invalid argument

```

#### Check if the input valur is double
We can use `double strtod(const char* str, char** str_end)` from `cstdlib`

```c++
# define NAN_DOUBLE std::numeric_limits<double>::quiet_NaN()
# define INF_DOUBLE std::numeric_limits<double>::infinity()

// double max_double = std::numeric_limits<double>::max();
// double min_double = std::numeric_limits<double>::min();
// Maximum double value: 1.79769e+308
// Minimum positive double value: 2.22507e-308

int	main(int argc, char** argv)
{
	if (argc == 2)
	{
		double num;
		std::string input = static_cast<std::string>(argv[1]);
		if (input == "nan")
			num = NAN_DOUBLE;
		else if (input == "+inf")
			num = INF_DOUBLE;
		else if (input == "-inf")
			num = -INF_DOUBLE;
		else if (input.find('.') == std::string::npos)
		{
			std::cout << "It's not double." << std::endl;
			return 1;
		}
		else
		{
    		errno = 0;
    		char *end;

    		num = std::strtod(input.c_str(), &end);
    		if (*end != '\0')
    		{
    			std::cout << "It's not double." << std::endl;
        		return 1;
    		}
    		if (errno == ERANGE)
    		{
        		std::cout << "Overflow" << std::endl;
        		return 1;
    		}    
		}
		std::cout << "It's double." << std::endl;
		std::size_t precision = input.length() - input.find('.') - 1;
		std::cout << "Convertd value: " << std::fixed << std::setprecision(precision) << num << std::endl;
		return 0;
	}
	std::cout << "Usage: ./convert <value to convert>" << std::endl;
	return 1;
}
```
   
Output examples   
```
➜  ex01 git:(main) ✗ ./a.out 0.0
It's double.
Convertd value: 0.0
➜  ex01 git:(main) ✗ ./a.out 42.0
It's double.
Convertd value: 42.0
➜  ex01 git:(main) ✗ ./a.out -42.0
It's double.
Convertd value: -42.0
➜  ex01 git:(main) ✗ ./a.out 42.0f
It's not double.
➜  ex01 git:(main) ✗ ./a.out a    
It's not double.
➜  ex01 git:(main) ✗ ./a.out 1.79769e+308        
It's double.
Convertd value: 179769000000000006323030492138942643493033036433685336215410983289126434148906289940615299632196609445533816320312774433484859900046491141051651091672734470972759941382582304802812882753059262973637182942535982636884444611376868582636745405553206881859340916340092953230149901406738427651121855107737424232448.0000000000
➜  ex01 git:(main) ✗ ./a.out 2.79769e+308
Overflow
```

#### Check if the input valur is float
As `std::strtof` is not supported in C++98, we can use `double strtod(const char* str, char** str_end)` with some additionnel condition.

```c++
#define NANF std::numeric_limits<float>::quiet_NaN()
#define INFF std::numeric_limits<float>::infinity()
#define FLOAT_MAX std::numeric_limits<float>::max()
#define FLOAT_LOWEST std::numeric_limits<float>::lowest()

int	main(int argc, char** argv)
{
	if (argc == 2)
	{
		float	num;
		std::string input = static_cast<std::string>(argv[1]);
	
		if (input == "nanf")
			num = std::numeric_limits<float>::quiet_NaN();
		else if (input == "+inff")
			num = std::numeric_limits<float>::infinity();
		else if (input == "-inff")
			num = -std::numeric_limits<float>::infinity();
		else if (input.find('.') == std::string::npos)
		{
			std::cout << "It's not float"<< std::endl;
			return 1;
		}
		else
		{
			errno = 0;
			char	*end;
			double	tmp = std::strtod(input.c_str(), &end);
			if (*end != 'f' || *(end + 1) != '\0')
			{
				std::cout << "Not a float" << std::endl;
				return 1;
			}
			const float	max_float = std::numeric_limits<float>::max();
			// max_float == 3.40282e+38

			num = static_cast<float>(tmp);
			if (errno == ERANGE || num > max_float || num < -max_float)
			{
				std::cout << "Overflow" << std::endl;
				return 1;
			}
		}
		std::cout << "It's float"<< std::endl;
		std::size_t precision = input.length() - input.find('.') - 1;
		std::cout << "Convertd value: " << std::fixed << std::setprecision(precision) << num << std::endl;
		return 0;
	}
	std::cout << "Usage: ./convert <value to convert>" << std::endl;
	return 1;
}
```
```
➜  ex01 git:(main) ✗ ./a.out 0.0f                      
It's float
Convertd value: 0.00
➜  ex01 git:(main) ✗ ./a.out 42.0f
It's float
Convertd value: 42.00
➜  ex01 git:(main) ✗ ./a.out -42.0f
It's float
Convertd value: -42.00
➜  ex01 git:(main) ✗ ./a.out 42    
It's not float
➜  ex01 git:(main) ✗ ./a.out a 
It's not float
➜  ex01 git:(main) ✗ ./a.out 42fa
It's not float
➜  ex01 git:(main) ✗ ./a.out 42af
It's not float
```

#### Infinity and NaN(Not a Number)

`+inff` : `std::numeric_limits<float>::infinity()`
`-inff` : `-std::numeric_limits<float>::infinity()`
`nanf` : `std::numeric_limits<float>::quiet_NaN()`
`+inf` : `std::numeric_limits<double>::infinity()`
`-inf` : `-std::numeric_limits<double>::infinity()`
`nan` : `std::numeric_limits<double>::quiet_NaN()`

> [!NOTE]
> If `value != value` is true, the value is NaN

