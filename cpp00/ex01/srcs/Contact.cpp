
#include "Contact.hpp"

/*===== Constructor & Destructor =============================================*/

Contact::Contact( void )
{
//	std::cout << "Constructor called" << std::endl;
	this->_firstname = "";
	this->_lastname = "";
	this->_nickname = "";
	this->_phone = "";
	this->_secret = "";
//	this->empty = true;
	return;
}

Contact::~Contact( void )
{	
//	std::cout << "Destructor called" << std::endl;
	return;
}

/*===== Public Functions =====================================================*/

void	Contact::setFirstName( void )
{
	bool	success = false;

	while(!success)
	{
		this->_firstname = this->_getInput("Enter first name");
		if (this->_firstname.empty())
			std::cout << "Invalid input" << std::endl;
		else
			success = true;
	}
}

void	Contact::setLastName( void )
{
	bool	success = false;

	while(!success)
	{
		this->_lastname = this->_getInput("Enter last name");
		if (this->_lastname.empty())
			std::cout << "Invalid input" << std::endl;
		else
			success = true;
	}
}

void	Contact::setNickname( void )
{
	bool	success = false;

	while(!success)
	{
		this->_nickname = this->_getInput("Enter nickname");
		if (this->_nickname.empty())
			std::cout << "Invalid input" << std::endl;
		else
			success = true;
	}
}

void	Contact::setPhone( void )
{
	bool	success = false;

	while(!success)
	{
		this->_phone = this->_getInput("Enter phone number");
		if (this->_phone.empty() || this->_isNum(this->_phone) == false)
			std::cout << "Invalid input" << std::endl;
		else
			success = true;
	}
}

void	Contact::setDarkestSecret( void )
{
	bool	success = false;

	while(!success)
	{
		this->_secret = this->_getInput("Enter darkest secret");
		if (this->_nickname.empty())
			std::cout << "Invalid input" << std::endl;
		else
			success = true;
	}
}

std::string	Contact::getFirstName( void )
{
	return (this->_firstname);
}

std::string	Contact::getLastName( void )
{
	return (this->_lastname);
}

std::string Contact::getNickname( void )
{
	return (this->_nickname);
}

std::string Contact::getPhone( void )
{
	return (this->_phone);
}

std::string Contact::getSecret( void )
{
	return (this->_secret);
}

/*===== Private Functions ====================================================*/

std::string	Contact::_getInput( std::string prompt )
{
	std::string	input;

	std::cout << prompt << ": ";
	std::cin >> input;
	return (input);
}

bool	Contact::_isNum( std::string input )
{
	for (size_t i = 0; i < input.length(); i++)
	{
		if (!isdigit(input[i]))
			return (false);
	}
	return (true);
}
