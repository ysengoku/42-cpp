
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
	while(true)
	{
		this->_firstname = this->_getInput("Enter first name");
		if (this->_firstname.empty() || !this->_isValidChar(this->_firstname))
			std::cout << YELLOW << "Invalid input. Enter only alphabetic characters, numbers, spaces or hyphens('-')." \
			<< RESET << std::endl;
		else
			return ;
	}
}

void	Contact::setLastName( void )
{
	while(true)
	{
		this->_lastname = this->_getInput("Enter last name");
		if (this->_lastname.empty() || !this->_isValidChar(this->_lastname))
			std::cout << YELLOW << "Invalid input. Enter only alphabetic characters, numbers, spaces or hyphens('-')." \
			<< RESET << std::endl;
		else
			return ;
	}
}

void	Contact::setNickname( void )
{
	while(true)
	{
		this->_nickname = this->_getInput("Enter nickname");
		if (this->_nickname.empty() || !this->_isValidChar(this->_nickname))
			std::cout << YELLOW << "Invalid input. Enter only alphabetic characters, numbers, spaces or hyphens('-')." \
			<< RESET << std::endl;
		else
			return ;
	}
}

void	Contact::setPhone( void )
{
	while(true)
	{
		this->_phone = this->_getInput("Enter phone number");
		if (this->_phone.empty() || this->_isNum(this->_phone) == false)
			std::cout << YELLOW << "Invalid input. Phone number field only accepts numerical values." << RESET << std::endl;
		else
			return ;
	}
}

void	Contact::setDarkestSecret( void )
{
	while(true)
	{
		this->_secret = this->_getInput("Enter darkest secret");
		if (this->_nickname.empty() || !this->_isValidChar(this->_secret))
			std::cout << YELLOW << "Invalid input. Enter only alphabetic characters, numbers, spaces or hyphens('-')." \
			<< RESET << std::endl;
		else
			break ;
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
		std::getline(std::cin, input);
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

bool	Contact::_isValidChar(std::string input ) const
{
	for (size_t i = 0; i < input.length(); i++)
	{
		if (!(isalnum(input[i]) || input[i] == '-' || std::isspace(input[i])))
			return (false);
	}
	return (true);
}
