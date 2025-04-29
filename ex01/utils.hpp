#pragma once
#include <string>

namespace utils
{
    void	toUpperCase(std::string &str);
    void	getValidInput(const std::string &prompt, std::string &input);
    void	getValidNumberInput(const std::string &prompt, std::string &input);
    void	getValidAlphaInput(const std::string &prompt, std::string &input);
    bool	str_is_number(const std::string &str);
    bool	str_is_alpha(const std::string &str);
}