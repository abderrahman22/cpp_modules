#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>

class Bureaucrat;

class AForm
{
	private:
		const std::string _name;
		bool _issigned;
		const int _gradeToSign;
		const int _gradeToExecute;
	public:
		AForm();
		AForm(const std::string name, const int gradeToSign, const int gradeToExecute);
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);
		virtual ~AForm();
		class NotSignedException : public std::exception
		{
			const char* what() const throw();
		};
		class GradeTooHighException : public std::exception
		{
			const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			const char* what() const throw();
		};
		void  beSigned(Bureaucrat& other);

		std::string get_name() const;
		bool get_issigned() const;
		int get_gradetosign() const;
		int get_gradetoexecute() const;
		void checkExecution(Bureaucrat const & executor) const;

		virtual void execute(Bureaucrat const & executor) const = 0;
};

std::ostream& operator<<(std::ostream& os, const AForm& Aform);

#endif
