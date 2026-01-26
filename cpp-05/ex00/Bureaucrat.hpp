#ifndef  BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat
{
	private:
		const std::string name;
	public:
		Bureaucrat();
		~Bureaucrat();
		void GradeTooLowException();
		void GradeTooHighException();
		std::string getName();
		int getGrade();
};

#endif
