/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 15:19:11 by eslamber          #+#    #+#             */
/*   Updated: 2024/04/29 19:16:43 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class AForm
{
	private:
		const std::string	_name;
		bool				_sgn;
		const int			_reqSgn;
		const int			_reqExe;

	public:
		// Constructeur
		AForm();
		AForm(const std::string &name, const int gradeSign, const int gradeExec);
		AForm(const AForm &cpy);

		// Surcharge d'opérateur
		AForm				&operator=(const AForm &cpy);

		// Fonctions membres
		void				verifGradeThrow() const;
		void				verifTooLowSgnThrow(const int grade) const;
		void				beSigned(const Bureaucrat &bu);
		virtual void		execute(Bureaucrat const &executor) const = 0;

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

		// Destructeur
		~AForm();
};

std::ostream	&operator<<(std::ostream &os, AForm &out);

#endif