/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchaman <abchaman@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 14:12:19 by abchaman          #+#    #+#             */
/*   Updated: 2026/07/02 23:58:56 by abchaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("Default"), _issigned(false), _gradeToSign(150), _gradeToExecute(150) {}

Form::Form(const std::string name, const int gradeToSign, const int gradeToExecute)
	: _name(name),_issigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
	{
		throw Form::GradeTooHighException();
	}
	if (gradeToSign > 150 || gradeToExecute > 150)
	{
		throw Form::GradeTooLowException();
	}
}

Form::Form(const Form& other) : _name(other._name), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{

	this->_issigned = other._issigned;
}

Form& Form::operator=(const Form& other)
{
	if (this != &other)
	{
		this->_issigned = other._issigned;
	}
	return *this;
}
Form::~Form(){};

std::string Form::get_name() const
{
	return _name;
}

bool Form::get_issigned() const
{
	return _issigned;
}
int Form::get_gradetosign() const
{
	return _gradeToSign;
}

int Form::get_gradetoexecute() const
{
	return _gradeToExecute;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "Form grade requirement is too high!";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Bureaucrat's grade is too low to sign this form!";
}

void Form::beSigned(Bureaucrat& b)
{
	if (b.getGrade() > _gradeToSign)
	{
		throw Form::GradeTooLowException();
	}
	_issigned = true;
}

std::ostream& operator<<(std::ostream& os, const Form& form)
{
	os << "Form: " << form.get_name()
		<< ", Status: " << (form.get_issigned() ? "Signed" : "Not signed")
		<< ", Sign Grade required: " << form.get_gradetosign()
		<< ", Execute Grade required: " << form.get_gradetoexecute() << ".";
	return os;
}
