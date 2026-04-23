#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Form
{
	private:
		const std::string _name;
		bool _isSigned;
		const int _gradeToSign;
		const int _gradeToExecute;
	public:
		Form();
		Form(const std::string& name, bool isSigned, const int gradeToSign, const int gradeToExecute);
		Form(const Form& other);
		Form& operator=(const Form& other);
		~Form();
		class GradeTooHighException : public std::exception
		{
			const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			const char* what() const throw();
		};
		const std::string getName();
		bool getSigned();
		const int getGradeToSign();
		const int getGradeToExecute();

		void beSigned(Bureaucrat &b);
};

std::ostream& operator<<(std::ostream& os, const Form& a);

#endif
