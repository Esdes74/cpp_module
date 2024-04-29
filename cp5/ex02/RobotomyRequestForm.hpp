/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 19:06:26 by eslamber          #+#    #+#             */
/*   Updated: 2024/04/29 20:01:27 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

class RobotomyRequestForm: public AForm
{
	private:
		const Bureaucrat	&target;

	public:
		// Constructeur
		RobotomyRequestForm();
		RobotomyRequestForm(const Bureaucrat &target);

		// Surcharge d'opérateur
		RobotomyRequestForm	&operator=(const RobotomyRequestForm &cpy);

		// Setter
		// Getter
		const Bureaucrat		&getTarget() const;

		// Fonctions membres
		virtual void			execute(Bureaucrat const &executor) const;

		// Classes abstraites
		class GradeTooLowExeException: public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};

		// Destructeur
		~RobotomyRequestForm();
};

#endif