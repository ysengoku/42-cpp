# CPP Module06

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
		if (errno == ERANGE)
			std::cout << "Overflow" << std::endl;
		else if (*end != '\0')
			std::cout << "Invalid argument" << std::endl;
		else if (num > INT_MAX || num < INT_MIN)
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
