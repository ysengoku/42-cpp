# CPP Module06 (On working)

## ex00
### std::strtol (cstdlib)
`long	strtol( const char* str, char** str_end, int base );`

```c++
int	main(int argc, char** argv)
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

### std::strtod

```c++
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
    	errno = 0;
    	char *end;

    	double num = std::strtod(argv[1].c_str(), &end);
    	if (errno == ERANGE)
    	{
        	std::cout << "Overflow" << std::endl;
        	return 1;
    	}    
    	if (*end != '\0')
    	{
    		std::cout << "Invalid input" << std::endl;
        	return 1;
    	}    
    	std::size_t precision = argv[1].length() - argv[1].find('.') - 1;
    	if (argv[1].length() == precision)
        	precision = 1;
   		std::cout << std::fixed << std::setprecision(precision) << num << std::endl;
	}
	else
		std::cout << "Usage: ./convert <value to convert>" << std::endl;
	return 0;
}
```