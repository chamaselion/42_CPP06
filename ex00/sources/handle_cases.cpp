/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_cases.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bszikora <bszikora@student.42helbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 15:23:09 by bszikora          #+#    #+#             */
/*   Updated: 2025/09/30 17:12:17 by bszikora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Tools.hpp"
#include "ScalarConverter.hpp"
//change test;
int special_case(int special) // 2 = +inf, 3 = -inf, 4 = nan
{
	std::string special_cases[5] = {"", "", "+inf", "-inf", "nan"};
	std::string fspecial_cases[5] = {"", "", "+inff", "-inff", "nanf"};

	std::cout << special << std::endl;
	if (special == 2 || special == 3 || special == 4)
	{
		std::cout << "char: " << "impossible" << std::endl;
		std::cout << "int: " << "impossible" << std::endl;
		std::cout << "float: " << fspecial_cases[special] << std::endl;
		std::cout << "double: " << special_cases[special] << std::endl;
		return 1;
	}
	else if (special > 0 || special < 0)
		return (std::cout << "Something went wrong with this special case.\n", 1);
	return (0);
}

void itsa_char(s_values *info)
{		
	info->charchar = info->input.empty() ? '\0' : info->input.length() != 1 ? info->input[1] : info->input[0];
	info->doublenum = static_cast<double>(info->charchar);
	info->floatingnum = static_cast<float>(info->charchar);
	info->integernum = static_cast<int>(info->charchar);
}

void itsa_int(s_values *info)
{
    try {
        info->integernum = std::stoi(info->input);
    } catch (const std::out_of_range& e) {
		info->int_possible = false;
        
    }
	info->doublenum = static_cast<double>(info->integernum);
	info->floatingnum = static_cast<float>(info->integernum);
	info->charchar = static_cast<char>(info->integernum);
}

void itsa_float(s_values *info)
{	
	info->floatingnum = std::stof(info->input);
	info->doublenum = static_cast<double>(info->floatingnum);
	info->integernum = static_cast<int>(info->floatingnum);
	info->charchar = static_cast<char>(info->floatingnum);
}

void itsa_double(s_values *info)
{	
	info->doublenum = std::stod(info->input);
	info->integernum = static_cast<int>(info->doublenum);
	info->floatingnum = static_cast<float>(info->doublenum);
	info->charchar = static_cast<char>(info->doublenum);
}

static bool is_print(char c)
{
    return (c >= 32 && c <= 126);
}

void print_cases(s_values *info)
{
    std::cout << "char: ";
    if (!info->char_possible)
        std::cout << "impossible";
    else if (is_print(info->charchar))
        std::cout << "'" << info->charchar << "'";
    else
        std::cout << "Non displayable";
    std::cout << std::endl;
    
    std::cout << "int: ";
    if (!info->int_possible)
        std::cout << "impossible";
    else
        std::cout << info->integernum;
    std::cout << std::endl;
    
    std::cout << "float: ";
    if (!info->float_possible)
        std::cout << "impossible";
    else if (info->type == TYPE_INT || (info->floatingnum - static_cast<int>(info->floatingnum)) == 0)
        std::cout << info->floatingnum << ".0f";
    else
        std::cout << info->floatingnum << "f";
    std::cout << std::endl;
    
    std::cout << "double: ";
    if (!info->double_possible) {
        std::cout << "impossible";
    } else if (info->type == TYPE_INT || (info->doublenum - static_cast<int>(info->doublenum)) == 0) {
        std::cout << info->doublenum << ".0";
    } else {
        std::cout << info->doublenum;
    }
    std::cout << std::endl;
}

int handle_cases(s_values *info)
{
	switch (info->type)
	{
	case TYPE_CHAR:
		itsa_char(info);
		break;
		
	case TYPE_INT:
		itsa_int(info);
		break;
	
	case TYPE_FLOAT:
		itsa_float(info);
		break;
	
	case TYPE_DOUBLE:
		itsa_double(info);
		break;
	default:
		break;
	}
	print_cases(info);
	return 0;
}

