#include "Form.hpp"

int main()
{
	try 
	{
		Form f("SimpleForm", 50, 30);
		std::cout << f << std::endl;
		try {
			Bureaucrat good("Alice", 40);
			good.signForm(f);
			std::cout << f << std::endl;
		}
		catch (std::exception& e) {
			std::cout << "Exception caught: " << e.what() << '\n';
		}
		try {
			Bureaucrat bad("Bob", 100);
			Form f2("HardForm", 20, 10);
			bad.signForm(f2);
		}
		catch (std::exception& e) {
			std::cout << "Exception caught: " << e.what() << '\n';
		}
	}
	catch (std::exception& e) {
		std::cout << "Exception caught: " << e.what() << '\n';
	}

	return 0;
}