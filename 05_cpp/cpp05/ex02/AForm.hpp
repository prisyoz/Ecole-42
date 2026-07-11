/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang <pang@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 16:17:41 by pang              #+#    #+#             */
/*   Updated: 2026/07/01 16:17:41 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>

class Bureaucrat;

class AForm
{
	private:
		const std::string	_name;
		bool				_sign;
		const int			_signgrade;
		const int			_execgrade;

	public:
		AForm();
		AForm(std::string name, int signgrade, int execgrade);
		AForm(const AForm& src);
		AForm& operator=(const AForm& src);
		virtual ~AForm();

		std::string	getName() const;
		std::string	getSigned() const;
		int			getSignGrade() const;
		int			getExecGrade() const;

		void			beSigned(const Bureaucrat& bureaucrat);
		virtual void	execute(Bureaucrat const & executor) const;
		virtual void	action() const = 0;

		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw();
		};

		class FormNotSignedException : public std::exception
		{
			public:
				const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif