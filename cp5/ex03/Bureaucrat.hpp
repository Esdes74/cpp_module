/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 14:05:05 by eslamber          #+#    #+#             */
/*   Updated: 2024/04/30 16:17:42 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <stdexcept>
# include <string>
# include <iostream>

class AForm;

class Bureaucrat
{
	private:
		std::string	_name;
		int			_grade;

	
	public:
		// Constructeurs
		Bureaucrat();
		Bureaucrat(const std::string &name, int grade);
		Bureaucrat(const Bureaucrat &cpy);

		// Surcharge d'opérateur
		Bureaucrat			&operator=(const Bureaucrat &cpy);

		// Getters
		const std::string	&getName() const;
		const int			&getGrade() const;

		// Fonctions membres
		void				verifGradeThrow() const;
		void				incrementGrade();
		void				decrementGrade();
		void				signForm(AForm &form) const;
		void				executeForm(AForm const &form) const;

		// Classes d'exceptions
		class BureaucratException: public std::exception
		{
			public:
				virtual const char	*what() const throw() = 0;
		};

		class GradeTooHighException: public BureaucratException
		{
			public:
				virtual const char	*what() const throw();
		};
		
		class GradeTooLowException: public BureaucratException
		{
			public:
				virtual const char	*what() const throw();
		};

		// Destructeur
		~Bureaucrat();
};

std::ostream	&operator<<(std::ostream &os, const Bureaucrat &out);

#endif