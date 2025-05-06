#pragma once
#include <string>

#define RESET "\033[0m"
#define BOLD "\033[1m"
#define BLACK "\033[30m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"
#define WHITESPACE_CHARS " \t\n\r\f\v"

namespace utils
{
    void	toUpperCase(std::string& str);
    void	getValidInput(const std::string &prompt, std::string &input, std::string exceptions);
    void	getValidIntegerInput(const std::string &prompt, std::string &input, std::string additional_valid_chars);
    void	getValidAlphaInput(const std::string &prompt, std::string &input, std::string additional_valid_chars);
    bool	is_str_number(const std::string &str, std::string allowed_chars);
    bool	is_str_alpha(const std::string &str, std::string allowed_chars);
    bool	anyCharInString(const std::string& str, const std::string& chars);
    bool	charInString(char c, const std::string& str);
    void	alert_msg(const std::string& str, const std::string& color = RED);
}