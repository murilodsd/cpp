#include "utils.hpp"
#include <cctype>
#include <iostream>
#include <functional>
#include <cstdlib>

namespace utils {
	
	void	alert_msg(const std::string& str, const std::string& color)
	{
		std::cout << color << str << std::endl << RESET;
	}

	void	str_trim(std::string& str)
	{
		str.erase(0, str.find_first_not_of(WHITESPACE_CHARS));
		str.erase(str.find_last_not_of(WHITESPACE_CHARS) + 1);
	}

	void	handle_eof(void)
	{
		if (std::cin.eof())
			{
				std::cout << "Input interrupted. Exiting..." << std::endl;
				std::exit(EXIT_FAILURE);
			}
	}

	void	toUpperCase(std::string &str)
	{
		size_t i = 0;

		while (i < str.length())
		{
			str[i] = std::toupper(str[i]);
			i++;
		}
	};

	void	getValidInput(const std::string &prompt, std::string &input, std::string exceptions)
	{
		while (true)
		{
			std::cout << prompt;
			std::getline(std::cin, input);

			handle_eof();

			str_trim(input);
			
			if (!input.empty() && !anyCharInString(input, exceptions))
				break;
			else if (input.empty())
				alert_msg("Input cannot be empty. Please try again.");
			else
				alert_msg("Input has invalid characters. Please try again.");
		}
	};
	
	void	getValidIntegerInput(const std::string &prompt, std::string &input, std::string others_valids_char)
	{
		while (true)
		{
			std::cout << prompt;
			std::getline(std::cin, input);
			
			handle_eof();

			str_trim(input);
			
			if (!input.empty() && is_str_number(input, others_valids_char))
				break;
			if (input.empty())
				alert_msg("Input cannot be empty. Please try again.");
			else if(others_valids_char.empty())
				alert_msg("Input must be an integer. Please try again.");
			else
				alert_msg("Invalid characters. Please try again.");
		}
	};

	void	getValidAlphaInput(const std::string &prompt, std::string &input, std::string others_valids_char)
	{
		while (true)
		{
			std::cout << prompt;
			std::getline(std::cin, input);

			handle_eof();

			str_trim(input);
			
			if (!input.empty() && is_str_alpha(input, others_valids_char))
				break;
			if (input.empty())
				alert_msg("Input cannot be empty. Please try again.");
			else if(others_valids_char.empty())
				alert_msg("Input must contain only letters. Please try again.");
			else
			alert_msg("Invalid characters. Please try again.");
		}
	};

	bool	anyCharInString(const std::string& str, const std::string& chars)
	{
		if (str.empty() || chars.empty()) 
			return false;
		return (str.find_first_of(chars) != std::string::npos);
	}

	bool	charInString(char c, const std::string& str)
	{
		if (str.empty()) 
			return false;
		return (str.find(c) != std::string::npos);
	};

	//If you just need to check if its a number, pass "" as a second argument
	bool	is_str_number(const std::string &str, std::string exceptions)
	{
		size_t i;
	
		if (str.empty())
			return false;
		i = 0;
		if (str[0] == '+' || str[0] == '-')
			i++;
		while (i < str.length())
		{
			if (!std::isdigit(str[i]) && !charInString(str[i], exceptions))
				return false;
			i++;
		}
		return true;
	}

	//If you just need to check if its a aplha, pass "" as a second argument
	bool	is_str_alpha(const std::string &str, std::string exceptions)
	{
		if (str.empty())
			return false;
		for (size_t i = 0; i < str.length(); i++)
		{
			if (!std::isalpha(str[i]) && !charInString(str[i], exceptions))
				return false;
		}
		return true;
	}	
}