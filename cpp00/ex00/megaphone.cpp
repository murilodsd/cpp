/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-souz <mde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 10:55:51 by mde-souz          #+#    #+#             */
/*   Updated: 2025/04/29 17:41:26 by mde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>
#include <cstdlib>

void	toUpperCase(std::string &str)
{
	size_t i = 0;

	while (i < str.length())
	{
		str[i] = std::toupper(str[i]);
		i++;
	}
}

int main(int argc, char const *argv[])
{
	int		i;
	std::string	str;

	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		i = 1;
		while (i < argc)
		{
			str = argv[i];
			toUpperCase(str);
			std::cout << str;
			i++;	
		}		
	}
	std::cout << std::endl;	
	return (EXIT_SUCCESS);
}
