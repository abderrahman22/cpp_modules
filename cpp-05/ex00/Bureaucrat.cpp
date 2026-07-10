/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchaman <abchaman@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 17:48:14 by abchaman          #+#    #+#             */
/*   Updated: 2026/07/10 03:52:07 by abchaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

//! Canonical form
Bureaucrat::Bureaucrat() : _name(""), _grade(0)
{}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name), _grade(grade)
{}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name)
{
	_grade = other._grade;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
	{
		this->_grade = other._grade;
	}
	return *this;
}

Bureaucrat::~Bureaucrat(){}

//? Logic here

void Bureaucrat::incrementgrade()
{
	if (_grade - 1 < 1)
	{
		throw GradeTooHighException();
	}
	_grade--;
}
void Bureaucrat::decrementgrade()
{
	if (_grade + 1 > 150)
	{
		throw GradeTooLowException();
	}
	_grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	 return "Grade is too high (min 1)";
}
const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	 return "Grade is too low (min 150)";
}

int Bureaucrat::getGrade()
{
	return _grade;
}

std::string Bureaucrat::getName()
{
	return _name;
}
