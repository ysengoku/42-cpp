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

## ex04
