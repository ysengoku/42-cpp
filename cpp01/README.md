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
`fstream_object.open(filename, mode);`  

There are 4 mode to open a file:
- `std::ios::in`: Used to open a file in read-only mode
- `std::ios::out`: It overwrites the contents. If the old content is smaller than the new one, some content will remain.
- `std::ios::trunc`: Open a file and delete the contents if the file already exist.
- `std::ios::app`: Open a file to write in append mode.
  

```cpp
bool	FileHandler::openInfile( void )
{
	// 
	this->_ifs.open(this->_infileName.c_str(), std::ifstream::in);

	// Error handling.
	if (!this->_ifs.is_open())
	{
    		std::cerr << "Failed to open the file: " << this->_infileName << std::endl;
    		return (false);
	}

	return (true);
}
```
  
We need to close the file with `fstream_object.close();` when we don't need it anymore.   

