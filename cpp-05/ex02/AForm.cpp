/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchaman <abchaman@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 14:12:19 by abchaman          #+#    #+#             */
/*   Updated: 2026/07/10 03:45:53 by abchaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("Default"), _issigned(false), _gradeToSign(150), _gradeToExecute(150) {}

AForm::AForm(const std::string name, const int gradeToSign, const int gradeToExecute)
	: _name(name),_issigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
	{
		throw AForm::GradeTooHighException();
	}
	if (gradeToSign > 150 || gradeToExecute > 150)
	{
		throw AForm::GradeTooLowException();
	}
}

AForm::AForm(const AForm& other) : _name(other._name), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{

	this->_issigned = other._issigned;
}

AForm& AForm::operator=(const AForm& other)
{
	if (this != &other)
	{
		this->_issigned = other._issigned;
	}
	return *this;
}
AForm::~AForm(){};

std::string AForm::get_name() const
{
	return _name;
}

bool AForm::get_issigned() const
{
	return _issigned;
}
int AForm::get_gradetosign() const
{
	return _gradeToSign;
}

int AForm::get_gradetoexecute() const
{
	return _gradeToExecute;
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return "AForm grade requirement is too high!";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "Bureaucrat's grade is too low to sign this Aform!";
}

const char* AForm::NotSignedException::what() const throw()
{
	return "Form cannot be executed because it is not signed!";
}

void AForm::beSigned(Bureaucrat& b)
{
	if (b.getGrade() > _gradeToSign)
	{
		throw AForm::GradeTooLowException();
	}
	_issigned = true;
}

std::ostream& operator<<(std::ostream& os, const AForm& Aform)
{
	os << "AForm: " << Aform.get_name();
	if (Aform.get_issigned())
	{
		os << " Signed";
	}
	else
	{
		os << " Not signed";
	}
	os << ", Sign Grade required: " << Aform.get_gradetosign()
		<< ", Execute Grade required: " << Aform.get_gradetoexecute() << ".";
	return os;
}

void AForm::checkExecution(Bureaucrat const & executor) const
{
	if (!_issigned)
	{
		throw AForm::NotSignedException();
	}
	if (executor.getGrade() > _gradeToExecute)
	{
		throw AForm::GradeTooLowException();
	}
}
