/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 14:05:05 by eslamber          #+#    #+#             */
/*   Updated: 2024/04/26 15:42:11 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <stdexcept>
# include <string>

class Bureaucrat
{
	private:
		std::string	name;
		int			grade;
	
	public:
		// Constructeurs
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &cpy);

		// Surcharge d'opérateur
		Bureaucrat			&operator=(const Bureaucrat &cpy);

		// Getters
		const std::string	&getName() const;
		const int			&getGrade() const;

		// Fonctions membres
		void				incrementGrade();
		void				decrementGrade();

		// Classes d'exceptions
		class GradeTooHighException: public std::exception
		{
			public:
				virtual const char	*what() const noexcept override;
		}
		
		class GradeTooLowException: public std::exception
		{
			public:
				virtual const char	*what() const noexcept override;
		}

		// Destructeur
		~Bureaucrat();
}

std::ostream	&operator<<(std::ostream os, const Bureaucrat &out);

#endif