#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>

class Bureaucrat;

class Form
{
	private:
		const std::string _name;
		bool _issigned;
		const int _gradeToSign;
		const int _gradeToExecute;
	public:
		Form();
		Form(const std::string name, const int gradeToSign, const int gradeToExecute);
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
		void  beSigned(Bureaucrat& other);

		std::string get_name() const;
		bool get_issigned() const;
		int get_gradetosign() const;
		int get_gradetoexecute() const;
};

std::ostream& operator<<(std::ostream&, const Form& form);

#endif
