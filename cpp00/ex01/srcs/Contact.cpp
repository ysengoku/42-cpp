
#include "Contact.hpp"

/*===== Constructor & Destructor =============================================*/

Contact::Contact( void ) : _firstname(""), 	_lastname(""), _nickname(""), _phone(""), _secret("")
{
	return;
}

Contact::~Contact( void )
{	
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
			std::cout << YELLOW << "Invalid input" << RESET << std::endl;
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
			std::cout << "Invalid input. Phone number field only accepts numerical values." << std::endl;
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
	std::cout << MAGENTA << "Your new contact has been successfully saved." << RESET << std::endl << std::endl;
}

std::string	Contact::getFirstName( void ) const
{
	return (this->_firstname);
}

std::string	Contact::getLastName( void ) const
{
	return (this->_lastname);
}

std::string Contact::getNickname( void ) const
{
	return (this->_nickname);
}

std::string Contact::getPhone( void ) const
{
	return (this->_phone);
}

std::string Contact::getSecret( void ) const
{
	return (this->_secret);
}

/*===== Private Functions ====================================================*/

std::string	Contact::_getInput( std::string prompt )
{
	std::string	input;

	while (true)
	{
		std::cout << prompt << ": ";
		std::cin >> input;
		if (!input.empty())
			break ;
	}
	return (input);
}

bool	Contact::_isNum( std::string input ) const
{
	for (size_t i = 0; i < input.length(); i++)
	{
		if (!isdigit(input[i]))
			return (false);
	}
	return (true);
}
