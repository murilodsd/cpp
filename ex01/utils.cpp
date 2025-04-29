#include "utils.hpp"
#include <cctype>
#include <iostream>

namespace utils {
	
	void	toUpperCase(std::string &str)
	{
		size_t i = 0;

		while (i < str.length())
		{
			str[i] = std::toupper(str[i]);
			i++;
		}
	};

	void	getValidInput(const std::string &prompt, std::string &input)
	{
		while (true)
		{
			std::cout << prompt;
			std::getline(std::cin, input);

			input.erase(0, input.find_first_not_of(" \t"));
			input.erase(input.find_last_not_of(" \t") + 1);
			
			if (!input.empty())
				break;
			std::cout << "Input cannot be empty. Please try again." << std::endl;
		}
	};

	void	getValidNumberInput(const std::string &prompt, std::string &input)
	{
		while (true)
		{
			std::cout << prompt;
			std::getline(std::cin, input);

			input.erase(0, input.find_first_not_of(" \t"));
			input.erase(input.find_last_not_of(" \t") + 1);
			
			if (!input.empty() && str_is_number(input))
				break;
			std::cout << "Input must be a number cannot be empty. Please try again." << std::endl;
		}
	};

	void	getValidAlphaInput(const std::string &prompt, std::string &input)
	{
		while (true)
		{
			std::cout << prompt;
			std::getline(std::cin, input);

			input.erase(0, input.find_first_not_of(" \t"));
			input.erase(input.find_last_not_of(" \t") + 1);
			
			if (!input.empty() && str_is_alpha(input))
				break;
			std::cout << "Input must have only letters and cannot be empty. Please try again." << std::endl;
		}
	};

	bool	str_is_number(const std::string &str)
	{
		if (str.empty())
			return false;
		for (size_t i = 0; i < str.length(); i++)
		{
			if (!std::isdigit(str[i]))
				return false;
		}
		return true;
	}

	bool	str_is_alpha(const std::string &str)
	{
		if (str.empty())
			return false;
		for (size_t i = 0; i < str.length(); i++)
		{
			if (!std::isalpha(str[i]))
				return false;
		}
		return true;
	}
}