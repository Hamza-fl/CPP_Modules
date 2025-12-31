/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfalati <hfalati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 15:35:56 by hfalati           #+#    #+#             */
/*   Updated: 2025/12/30 17:02:06 by hfalati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
class Bureaucrat;

class Form {
	
	private :
		const std::string	name;
		bool				isSigned;
		const int			gradeToSign;
		const int			gradeToExecute;

	public :
		Form();
		Form(const std::string& name, int gradeToSign, int gradeToExecute);
		Form(const Form& other);
		Form& operator=(const Form& other);
		~Form();

		const std::string&	getName() const;
		bool get_Sign() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;

		void beSigned(Bureaucrat const& b);

		class GradeTooHighException : public std::exception {
			public :
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public :
				virtual const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const Form& f);

#endif