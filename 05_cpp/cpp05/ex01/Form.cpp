/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang <pang@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 16:17:25 by pang              #+#    #+#             */
/*   Updated: 2026/07/01 16:17:25 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("unknown"), _sign(false), _signgrade(150), _execgrade(150) {}

Form::Form(std::string name, int signgrade, int execgrade) : _name(name), _sign(false), _signgrade(signgrade), _execgrade(execgrade)
{
	if (_signgrade < 1 || _execgrade < 1)
		throw Form::GradeTooHighException();
	else if (_signgrade > 150 || _execgrade > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form& src) : _name(src._name), _sign(src._sign), _signgrade(src._signgrade), _execgrade(src._execgrade)
{
	if (_signgrade < 1 || _execgrade < 1)
		throw Form::GradeTooHighException();
	else if (_signgrade > 150 || _execgrade > 150)
		throw Form::GradeTooLowException();
}

Form& Form::operator=(const Form& src)
{
	(void)src;
	return (*this);
}

Form::~Form() {}

std::string	Form::getName() const
{
	return _name;
}
std::string	Form::getSigned() const
{
	if (_sign)
		return ("Signed");
	return ("Not Signed");
}

int Form::getSignGrade() const
{
	return _signgrade;
}

int	Form::getExecGrade() const
{
	return _execgrade;
}

std::ostream& operator<<(std::ostream& os, const Form& form)
{
	os << form.getName() << ", " << form.getSigned() << ", sign grade: " << form.getSignGrade() << ", exec grade: " << form.getExecGrade() << ".";
	return os;
}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > _signgrade)
		throw Form::GradeTooLowException();
	if (!_sign)
		_sign = true;
}

// GradeTooHighException
const char* Form::GradeTooHighException::what() const throw()
{
	return ("Grade Too High");
}

// GradeTooLowException
const char* Form::GradeTooLowException::what() const throw()
{
	return ("Grade Too Low");
}