/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 21:17:04 by tlegrand          #+#    #+#             */
/*   Updated: 2023/10/01 22:20:56 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("ShrubberyCreation", "nobody", 145, 137) {};

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src) : AForm(src) {};

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& src) 
{
	if (this == &src)
		return (*this);
	return (*this);
};

ShrubberyCreationForm::~ShrubberyCreationForm(void) {};

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreation", target, 145, 137) {};

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const 
{
	this->checkExe(executor.getGrade());
	
	std::fstream	file((this->getTarget() + "_shrubbery").c_str() , std::ios::out);
	file.exceptions(std::ofstream::failbit);
	
	file 
<< "                     .o00o"  << std::endl
<< "                   o000000oo" << std::endl
<< "                  00000000000o" << std::endl
<< "                 00000000000000" << std::endl
<< "              oooooo  00000000  o88o" << std::endl
<< "           ooOOOOOOOoo  ```''  888888" << std::endl
<< "         OOOOOOOOOOOO'.qQQQQq. `8888'" << std::endl
<< "        oOOOOOOOOOO'.QQQQQQQQQQ/.88'" << std::endl
<< "        OOOOOOOOOO'.QQQQQQQQQQ/ /q" << std::endl
<< "         OOOOOOOOO QQQQQQQQQQ/ /QQ" << std::endl
<< "           OOOOOOOOO `QQQQQQ/ /QQ'" << std::endl
<< "             OO:F_P:O `QQQ/  /Q'" << std::endl
<< "                \\. \\ |  // |" << std::endl
<< "                d\\ \\\\|_////" << std::endl
<< "                qP| \\ _' `|Ob" << std::endl
<< "                   \\  / \\  \\Op" << std::endl
<< "                   |  | O| |" << std::endl
<< "           _       /\\. \\_/ /\\" << std::endl
<< "            `---__/|_\\   //|  __" << std::endl
<< "                  `-'  `-'`-'-'" << std::endl;

	file.close();
};
	
