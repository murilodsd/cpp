#pragma once
#include <string>

namespace utils
{
    void	toUpperCase(std::string &str);
    void	getValidInput(const std::string &prompt, std::string &input);
    bool	is_number(const std::string &str);
}