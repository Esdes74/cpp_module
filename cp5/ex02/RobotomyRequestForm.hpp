/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 19:06:26 by eslamber          #+#    #+#             */
/*   Updated: 2024/04/30 18:41:24 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"
# include <cstdlib>

class RobotomyRequestForm: public AForm
{
	private:
		const std::string	_target;
		RobotomyRequestForm();

	public:
		// Constructeur
		RobotomyRequestForm(const std::string target);

		// Surcharge d'opérateur
		RobotomyRequestForm	&operator=(const RobotomyRequestForm &cpy);

		// Setter
		// Getter
		const std::string		getTarget() const;

		// Fonctions membres
		virtual void			execute(Bureaucrat const &executor) const;

		// Classes d'exception
		// Destructeur
		~RobotomyRequestForm();
};

#endif