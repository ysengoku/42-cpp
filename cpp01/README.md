# CPP Module01

## ex03
We should create 2 classes `HumanA` and `HumanB`.  

- `HumanA` takes the `Weapon` in its constructor, so always has a Weapon.
- `HumanB` doesn't take the `Weapon` in its constructor, so may not always have a Weapon.

```cpp
class	HumanA
{
	public:
		HumanA( std::string name, Weapon& weapon );
		~HumanA( void );
		void	attack( void );

	private:
		std::string	_name;
		Weapon&		_weapon; // Reference to Weapon
};
```
```cpp
class	HumanB
{
	public:
		HumanB( std::string name);
		~HumanB( void );
		void	setWeapon( Weapon &weapon ); // Use a reference to Weapon
		void	attack( void );
	
	private:
		std::string	_name;
		Weapon*		_weapon; // Pointer to Weapon
};
```
For `HumanB`, we use a reference in the `setWeapon`:
- Since `HumanB` may not always have a `Weapon`, using a reference allows for the weapon to be set (or changed) at any time after a `HumanB` object has been constructed. This provides the flexibility needed to arm `HumanB` instances post-construction, adhering to the requirement that `HumanB` may not always be armed.

- Using a reference ensures that the `setWeapon` function is provided with a valid `Weapon` object, as references must refer to an existing object (they cannot be null). 

- Storing the weapon as a pointer (`this->_weapon = &weapon;`) inside the `setWeapon` method allows `HumanB` to potentially support a state where it has no weapon (e.g., if the pointer is set to `nullptr`). 

## ex04 File manipulation in C++
Open file  
```cpp
void open(const char* filename, ios_base::openmode mode);
```
There are 6 modes to open a file:
- `std::ios::in`: Open a file in read-only mode
- `std::ios::out`: Open a file for writing. It overwrites the contents. If the old content is smaller than the new one, some content will remain.
- `std::ios::trunc`: Open a file and delete the contents existing before.
- `std::ios::app`: Open a file to write in append mode.
- `std::ios::ate`: The output position starts at the end of the file.
- `std::ios::binary`: Operations are performed in binary mode rather than text.
  

```cpp
bool	FileHandler::openInfile( void )
{
	// Convert the filename from string to const char* with .c_str()
	this->_ifs.open(this->_infileName.c_str(), std::ifstream::in);

	// Error handling
	if (!this->_ifs.is_open())
	{
    	std::cerr << "Failed to open the file: " << this->_infileName << std::endl;
    	return (false);
	}
	return (true);
}
```
```cpp
bool	FileHandler::openOutfile( void )
{
	// Open with truncate mode so that the existing content is deleted.
	this->_ofs.open(this->_outfileName.c_str(), std::ios::trunc);

	// Error handling
	if (!this->_ofs.is_open())
	{
    	std::cerr << "Failed to open the output file: " << this->_outfileName << std::endl;
		this->_ifs.close();
    	return (false);
	}
	return (true);
}
```
  
We need to close the file with `fstream_object.close();` when we don't need it anymore.   

```cpp
void	Replacer::replaceStrings( void )
{
	std::string			content;
	std::stringstream	fileContentStream;
	std::ifstream&		ifs = this->_fileHandler.getInputFile();
	std::ofstream&		ouf = this->_fileHandler.getOutputFile();
	
	// Reads the entire content of the input file (ifs) and streams it into fileContentStream. The rdbuf() function returns a pointer to the underlying buffer object associated with the input file stream.
	fileContentStream << ifs.rdbuf();

	// Converts the content of 'fileContentStream' to a string and stores it in 'content'.
	content = fileContentStream.str();

	// Perform the string replacement operation.
	this->_stringReplacer.replaceString(content);

	// Writes the modified content to the output file using the output file stream(ouf).
	ouf << content;
}
```
```cpp
void StringReplacer::replaceString(std::string& content)
{
    std::string result;

    // This will be used to track whether any replacements were made.
    bool replaced = false;

    // This keeps track of the current position in the content string as the method searches for the target substring.
    size_t position = 0;

    // The position of the found substring is stored in nextPosition. If the substring is not found, nextPosition will be std::string::npos.
    size_t nextPosition = content.find(this->_searchedStr, position);

    while (nextPosition != std::string::npos) // Loop as long as _searchedStr is found
    {
	// Appends the portion of content from position to nextPosition to result. This portion excludes the found substring.
        result += content.substr(position, nextPosition - position);

	// Appends _replacingStr (the replacement string) to result, replacing the found substring.
        result += this->_replacingStr;

	// Indicates that at least one replacement has been made.
        replaced = true;

	// Updates position to move past the last found substring.
        position = nextPosition + this->_searchedStrLength;

	// Searches for the next occurrence of _searchedStr starting from the updated position.
        nextPosition = content.find(this->_searchedStr, position);
    }
    // Appends remaining part of content to result.
    result += content.substr(position);
    if (replaced)
    {
        content = result;
        std::cout << "'" << this->_searchedStr << "' was successfully replaced by '"
                  << this->_replacingStr << "'." << std::endl;
    }
    else
        std::cout << "'" << this->_searchedStr << "' was not found in the file." << std::endl;
}
```
