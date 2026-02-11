/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bszikora <bszikora@student.42helbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 12:55:03 by bszikora          #+#    #+#             */
/*   Updated: 2026/02/11 11:07:00 by bszikora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Tools.hpp"

static bool	is_lchar(s_values *info)
{
	return (info->input.size() == 3 && info->input.front() == '\'' && info->input.back() == '\''
		&& std::isprint(static_cast<unsigned char>(info->input[1])));
}

static bool	is_schar(s_values *info)
{
	return (info->input.size() == 1 && std::isprint(static_cast<unsigned char>(info->input[0]))
		&& !std::isdigit(static_cast<unsigned char>(info->input[0])));
}

static bool is_int(s_values *info)
{
    size_t i = 0;
    long long v;

    if (info->input.empty())
        return false;
    if (info->input[i] == '+' || info->input[i] == '-') {
        if (++i == info->input.size())
            return false;
    }
    for (; i < info->input.size(); ++i) {
        if (!std::isdigit(static_cast<unsigned char>(info->input[i])))
            return false;
    }
    try {
        v = std::stoll(info->input);
        if (v < INT_MIN || v > INT_MAX) {
            info->int_possible = false;
        }
        return true;
    } catch (const std::out_of_range &) {
        info->int_possible = false;
        return false;
    } catch (...) {
        info->int_possible = false;
        return false;
    }
}

static bool	is_numeric(const std::string &s, bool allowDot, bool &sawDot, bool &sawDigit)
{
	char	c;

	for (size_t i = 0; i < s.size(); ++i)
	{
		c = s[i];
		if (c == '.')
		{
			if (!allowDot || sawDot)
				return (false);
			sawDot = true;
		}
		else if (std::isdigit(static_cast<unsigned char>(c)))
			sawDigit = true;
		else
			return (false);
	}
	return (true);
}

static bool	is_sfloat(s_values *info)
{
    info->special = (info->input == "nanf") ? 4 : (info->input == "-inff") ? 3 : (info->input == "+inff") ? 2 : info->special;
    return (info->input == "nanf" || info->input == "+inff" || info->input == "-inff");
}

static int	is_float(s_values *info)
{
    size_t i = 0;
    bool sawDot = false;
    bool sawDigit = false;

    if (is_sfloat(info))
        return info->special;
    if (info->input.size() < 2 || info->input.back() != 'f')
        return false;
    std::string core = info->input.substr(0, info->input.size() - 1);
    if (core.empty())
        return false;
    if (core[i] == '+' || core[i] == '-') {
        if (++i == core.size())
            return false;
    }
    if (!is_numeric(core.substr(i), true, sawDot, sawDigit))
        return false;

    try {
        std::stof(core);
        return sawDot && sawDigit;
    } catch (const std::out_of_range &) {
        info->float_possible = false;
        return false;
    } catch (...) {
        info->float_possible = false;
        return false;
    }
}

static bool	is_sdouble(s_values *info)
{
    info->special = (info->input == "nan") ? 4 : (info->input == "-inf") ? 3 : (info->input == "+inf") ? 2 : info->special;
    return (info->input == "nan" || info->input == "+inf" || info->input == "-inf");
}

static int	is_double(s_values *info)
{
    size_t i = 0;
    bool sawDot = false;
    bool sawDigit = false;

    if (is_sdouble(info))
        return info->special;
    if (info->input.empty())
        return false;
    if (info->input[i] == '+' || info->input[i] == '-') {
        if (++i == info->input.size())
            return false;
    }
    if (!is_numeric(info->input.substr(i), true, sawDot, sawDigit))
        return false;

    try {
        std::stod(info->input);
        info->double_possible = true;
        return sawDot && sawDigit;
    } catch (const std::out_of_range &) {
        info->double_possible = false;
        return false;
    } catch (...) {
        info->double_possible = false;
        return false;
    }
}

int check_type(s_values *info)
{
    int type = TYPE_INVALID;
    type = (is_lchar(info) || is_schar(info)) ? TYPE_CHAR : (is_int(info)) ? TYPE_INT : (is_float(info)) ? TYPE_FLOAT : (is_double(info)) ? TYPE_DOUBLE : type;
    info->type = type;
    return type;
}

int invalid_case(s_values *info)
{
    if (info->type < 0)
        return (std::cout << "This input is invalid for such conversions\n", 1);
    return 0;
}

int	parse(int argc, char **argv)
{
	(void) argv;
	if (argc > 2 || argc < 2)
		return 1;
	return 0;
}