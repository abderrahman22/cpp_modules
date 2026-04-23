/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchaman <abchaman@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 17:48:14 by abchaman          #+#    #+#             */
/*   Updated: 2026/04/23 12:49:20 by abchaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(0) {}

Bureaucrat::Bureaucrat(const std::string& name, int grade):_name(name), _grade(grade)
{
	if (grade > 150)
		throw GradeTooLowException();
	if (grade < 1)
		throw GradeTooHighException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name)
{
	_grade = other._grade;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
	{
		_grade = other._grade;
	}
	return *this;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Destructor called" << std::endl;
}

int Bureaucrat::getGrade() const { return _grade; }
std::string Bureaucrat::getName() const { return _name; }


void Bureaucrat::incrementGrade()
{
	if (_grade - 1 < 1)
	{
		throw GradeTooHighException();
	}
	_grade--;
}
void Bureaucrat::decrementGrade()
{
	if (_grade + 1 > 150)
	{
		throw GradeTooLowException();
	}
	_grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high, minimum is 1";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low ,maximum is 150";
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& a)
{
	os << a.getName() << ", bureaucrat grade " << a.getGrade();
	return os;
}
