/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang <pang@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 16:18:20 by pang              #+#    #+#             */
/*   Updated: 2026/07/01 16:18:20 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("unknown"), _sign(false), _signgrade(150), _execgrade(150) {}

AForm::AForm(std::string name, int signgrade, int execgrade) : _name(name), _sign(false), _signgrade(signgrade), _execgrade(execgrade)
{
	if (_signgrade < 1 || _execgrade < 1)
		throw AForm::GradeTooHighException();
	else if (_signgrade > 150 || _execgrade > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm& src) : _name(src._name), _sign(src._sign), _signgrade(src._signgrade), _execgrade(src._execgrade)
{
	if (_signgrade < 1 || _execgrade < 1)
		throw AForm::GradeTooHighException();
	else if (_signgrade > 150 || _execgrade > 150)
		throw AForm::GradeTooLowException();
}

AForm& AForm::operator=(const AForm& src)
{
	(void)src;
	return (*this);
}

AForm::~AForm() {}

std::string	AForm::getName() const
{
	return _name;
}
std::string	AForm::getSigned() const
{
	if (_sign)
		return ("Signed");
	return ("Not Signed");
}

int AForm::getSignGrade() const
{
	return _signgrade;
}

int	AForm::getExecGrade() const
{
	return _execgrade;
}

std::ostream& operator<<(std::ostream& os, const AForm& form)
{
	os << form.getName() << ", " << form.getSigned() << ", sign grade: " << form.getSignGrade() << ", exec grade: " << form.getExecGrade() << ".";
	return os;
}

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > _signgrade)
		throw AForm::GradeTooLowException();
	if (!_sign)
		_sign = true;
}

// check form is signed and grade of bureaucrat attempting to execute is high enough
void	AForm::execute(Bureaucrat const & executor) const
{
	if (!_sign)
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > _execgrade)
		throw AForm::GradeTooLowException();
	action();
}


// GradeTooHighException
const char* AForm::GradeTooHighException::what() const throw()
{
	return ("Grade Too High");
}

// GradeTooLowException
const char* AForm::GradeTooLowException::what() const throw()
{
	return ("Grade Too Low");
}

// FormNotSignedException
const char* AForm::FormNotSignedException::what() const throw()
{
	return ("Form Not Signed");
}