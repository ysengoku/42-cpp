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
➜  ex00 git:(main) ✗ ./convert 123abc
Invalid argument
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
➜  ex00 git:(main) ✗ ./convert a123
Invalid argument

```

#### Check if the input valur is double
We can use `double strtod(const char* str, char** str_end)` from `cstdlib`

```c++
# define NAN_DOUBLE std::numeric_limits<double>::quiet_NaN()
# define INF_DOUBLE std::numeric_limits<double>::infinity()

int	main(int argc, char** argv)
{
    // double max_double = std::numeric_limits<double>::max();
    // double min_double = std::numeric_limits<double>::min();
    // std::cout << "Maximum double value: " << max_double << std::endl;
    // std::cout << "Minimum positive double value: " << min_double << std::endl;

    // Maximum double value: 1.79769e+308
	// Minimum positive double value: 2.22507e-308

	if (argc == 2)
	{
		if (literal == "nan")
			scalar.doubleValue = NAN_DOUBLE;
		else if (literal == "+inf")
			scalar.doubleValue = INF_DOUBLE;
		else if (literal == "-inf")
			scalar.doubleValue = -INF_DOUBLE;
		else
		{
    		errno = 0;
    		char *end;

    		double num = std::strtod(argv[1].c_str(), &end);
    		if (*end != '\0')
    		{
    			std::cout << "Invalid input" << std::endl;
        		return 1;
    		}
    		if (errno == ERANGE)
    		{
        		std::cout << "Overflow" << std::endl;
        		return 1;
    		}    
		}
    	std::size_t precision = argv[1].length() - argv[1].find('.') - 1;
    	if (argv[1].length() == precision)
        	precision = 1;
   		std::cout << std::fixed << std::setprecision(precision) << num << std::endl;
		return 0;
	}
	std::cout << "Usage: ./convert <value to convert>" << std::endl;
	return 1;
}
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
		if (static_cast<std::string>(argv[1]) == "nanf")
			num = std::numeric_limits<float>::quiet_NaN();
		else if (static_cast<std::string>(argv[1]) == "+inff")
			num = std::numeric_limits<float>::infinity();
		else if (static_cast<std::string>(argv[1]) == "-inff")
			num = -std::numeric_limits<float>::infinity();
		else
		{
			errno = 0;
			char	*end;
			float	num;
			double	tmp = std::strtod(argv[1].c_str(), &end);
			if (*end != 'f' || *(end + 1) != '\0')
			{
				std::cout << "Not a float" << std::endl;
				return 1;
			}
			const float	max_float = std::numeric_limits<float>::max();
    		const float	lowest_float = std::numeric_limits<float>::lowest();
			// max_float: 3.40282e+38
			// lowest_float: -3.40282e+38

			// const float denorm_min_float = std::numeric_limits<float>::denorm_min();
			// denorm_min_float: 1.4013e-45

			num = static_cast<float>(tmp);
			if (errno == ERANGE || num > max_float　|| num < lowest_float)
			{
				std::cout << "Overflow" << std::endl;
				return 1;
			}
		}
		std::cout << "It's float"<< std::endl;
		return 0;
	}
	std::cout << "Usage: ./convert <value to convert>" << std::endl;
	return 1;
}
```

#### Infinity and NaN(Not a Number)

```c++
bool is_infinity(float value) {
    return (value == std::numeric_limits<float>::infinity() || value == -std::numeric_limits<float>::infinity());
}

bool is_nan(float value) {
    return (value != value);  // NaNは自分自身と等しくない
}
```