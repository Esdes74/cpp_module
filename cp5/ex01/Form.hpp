/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 15:19:11 by eslamber          #+#    #+#             */
/*   Updated: 2024/04/30 15:21:17 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Form
{
	private:
		const std::string	_name;
		bool				_sgn;
		const int			_reqSgn;
		const int			_reqExe;

	public:
		// Constructeur
		Form();
		Form(const std::string &name, const int gradeSign, const int gradeExec);
		Form(const Form &cpy);

		// Surcharge d'opérateur
		Form				&operator=(const Form &cpy);

		// Fonctions membres
		void				verifGradeThrow() const;
		void				verifTooLowSgnThrow(const int grade) const;
		void				verifSignedFormThrow() const;
		void				beSigned(const Bureaucrat &bu);

		// Getters
		const std::string	&getName() const;
		const bool			&getSgn() const;
		const int			&getReqSgn() const;
		const int			&getReqExe() const;

		// Classes d'exception
		class GradeTooHighException: public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};

		class GradeTooLowException: public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};

		class GradeTooLowSgnException: public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};

		class AlreadySignedFormException: public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};

		// Destructeur
		~Form();
};

std::ostream	&operator<<(std::ostream &os, Form &out);

#endif