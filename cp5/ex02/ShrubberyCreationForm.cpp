/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 19:05:39 by eslamber          #+#    #+#             */
/*   Updated: 2024/04/30 19:24:56 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

// Constructeur
ShrubberyCreationForm::ShrubberyCreationForm(const std::string target)
	:AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
}

// Surcharge d'opérateur
ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &cpy)
{
	AForm::operator=(cpy);
	return (*this);
}

// Setter
// Getter
const std::string	ShrubberyCreationForm::getTarget() const
{
	return (this->_target);
}

// Fonctions membres
void	ShrubberyCreationForm::verifFileOpenedThrow(std::ofstream &file) const
{
	if (!file.is_open())
		throw ShrubberyCreationForm::FileNotOpenException();
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	verifNotSignedFormThrow();
	verifTooLowExeThrow(executor.getGrade());
	std::ofstream	file((_target + "_shrubbery").c_str());
	verifFileOpenedThrow(file);
	file << "	The Worm\'s Turn" << std::endl << std::endl << std::endl << std::endl;
	file << "              _{\\ _{\\{\\/}/}/}__" << std::endl;
	file << "             {/{/\\}{/{/\\}(\\}{/\\} _" << std::endl;
	file << "            {/{/\\}{/{/\\}(_)\\}{/{/\\} _" << std::endl;
	file << "         {\\{/(\\}\\}{/{/\\}\\}{/){/\\}\\}/\\}" << std::endl;
	file << "        {/{/(_)/}{\\{/)\\}{\\(_){/}/}/}/}" << std::endl;
	file << "       _{\\{/{/{\\{/{/(_)/}/}/}{\\(/}/}/}" << std::endl;
	file << "      {/{/{\\{\\{\\(/}{\\{\\/}/}{\\}(_){\\/}\\}" << std::endl;
	file << "      _{\\{/{\\{/(_)\\}/}{/{/{/\\}\\})\\}{/\\}" << std::endl;
	file << "     {/{/{\\{\\(/}{/{\\{\\{\\/})/}{\\(_)/}/}\\}" << std::endl;
	file << "      {\\{\\/}(_){\\{\\{\\/}/}(_){\\/}{\\/}/})/}" << std::endl;
	file << "       {/{\\{\\/}{/{\\{\\{\\/}/}{\\{\\/}/}\\}(_)" << std::endl;
	file << "      {/{\\{\\/}{/){\\{\\{\\/}/}{\\{\\(/}/}\\}/}" << std::endl;
	file << "       {/{\\{\\/}(_){\\{\\{\\(/}/}{\\(_)/}/}\\}" << std::endl;
	file << "         {/({/{\\{/{\\{\\/}(_){\\/}/}\\}/}(\\}" << std::endl;
	file << "          (_){/{\\/}{\\{\\/}/}{\\{\\)/}/}(_)" << std::endl;
	file << "            {/{/{\\{\\/}{/{\\{\\{\\(_)/}" << std::endl;
	file << "             {/{\\{\\{\\/}/}{\\{\\}/}" << std::endl;
	file << "              {){/ {\\/}{\\/} \\}\\}" << std::endl;
	file << "              (_)  \\.-\'.-/" << std::endl;
	file << "          __...--- |\'-.-\'| --...__" << std::endl;
	file << "   _...--\"   .-\'   |\'-.-\'|  \' -.  \"\"--..__" << std::endl;
	file << " -\"    \' .  . \'    |.\'-._| \'  . .  \'   jro" << std::endl;
	file << " .  \'-  \'    .--\'  | \'-.\'|    .  \'  . \'" << std::endl;
	file << "          \' ..     |\'-_.-|" << std::endl;
	file << "  .  \'  .       _.-|-._ -|-._  .  \'  ." << std::endl;
	file << "              .\'   |\'- .-|   \'." << std::endl;
	file << "  ..-\'   \' .  \'.   `-._.-�   .\'  \'  - ." << std::endl;
	file << "   .-\' \'        \'-._______.-\'     \'  ." << std::endl;
	file << "        .      ~," << std::endl;
	file << "    .       .   |\\   .    \' \'-." << std::endl;
	file << "    ___________/  \\____________" << std::endl;
	file << "   /  Why is it, when you want \\" << std::endl;
	file << "  |  something, it is so damn   |" << std::endl;
	file << "  |    much work to get it?     |" << std::endl;
	file << "   \\___________________________/" << std::endl << std::endl;
	file.close();
}

// Classes abstraites
const char	*ShrubberyCreationForm::FileNotOpenException::what() const throw()
{
	return ("File not opened");
}

// Destructeur
ShrubberyCreationForm::~ShrubberyCreationForm()
{
}
