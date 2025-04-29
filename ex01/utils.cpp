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

	void	getValidInput(const std::string &prompt, std::string &input, std::string exceptions)
	{
		while (true)
		{
			std::cout << prompt;
			std::getline(std::cin, input);

			input.erase(0, input.find_first_not_of(" \t"));
			input.erase(input.find_last_not_of(" \t") + 1);
			
			if (!input.empty() && !anyCharInString(input, exceptions))
				break;
			if (input.empty())
				utils::alert_msg("Input cannot be empty. Please try again.");
			else
				utils::alert_msg("Input has invalid characters. Please try again.");
		}
	};

	void	getValidNumberInput(const std::string &prompt, std::string &input, std::string others_valids_char)
	{
		while (true)
		{
			std::cout << prompt;
			std::getline(std::cin, input);

			input.erase(0, input.find_first_not_of(" \t"));
			input.erase(input.find_last_not_of(" \t") + 1);
			
			if (!input.empty() && is_str_number(input, others_valids_char))
				break;
			utils::alert_msg("Input must be a number cannot be empty. Please try again.");
		}
	};

	void	getValidAlphaInput(const std::string &prompt, std::string &input, std::string others_valids_char)
	{
		while (true)
		{
			std::cout << prompt;
			std::getline(std::cin, input);

			input.erase(0, input.find_first_not_of(" \t"));
			input.erase(input.find_last_not_of(" \t") + 1);
			
			if (!input.empty() && is_str_alpha(input, others_valids_char))
				break;
			utils::alert_msg("Input must have only letters and cannot be empty. Please try again.");
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
		if (str.empty())
			return false;
		for (size_t i = 0; i < str.length(); i++)
		{
			if (!std::isdigit(str[i]) && !charInString(str[i], exceptions))
				return false;
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

	void	alert_msg(std::string str)
	{
		std::cout << RED << str << std::endl << RESET;
	}
}