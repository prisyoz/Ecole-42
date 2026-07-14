#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"


static void testInternForm(Intern& intern, Bureaucrat& bur, std::string formName, std::string target)
{
	AForm* form = intern.makeForm(formName, target);
	if (form)
	{
		bur.signForm(*form);
		bur.executeForm(*form);
		delete form;
	}
}

int main(void)
{
	srand(time(0));

	{
		std::cout << "=== Basic Intern Test ===\n";
		Intern	intern;
		Bureaucrat boss("boss", 1);

		testInternForm(intern, boss, "shrubbery creation", "home");
		testInternForm(intern, boss, "robotomy request", "Bender");
		testInternForm(intern, boss, "presidential pardon", "par");
	}

	{
		std::cout << "\n=== Invalid Form Test ===\n";
		Intern intern;
		Bureaucrat boss("boss", 1);

		testInternForm(intern, boss, "tax evasion", "Clamps");
		testInternForm(intern, boss, "", "target");
		testInternForm(intern, boss, "SHRUBBERY CREATION", "home");
	}

	{
		std::cout << "\n=== Intern Assign Test ===\n";
		Intern intern;
		Intern copy(intern);
		Intern assign;
		assign = intern;
		assign = assign;

		Bureaucrat boss("boss", 1);
		testInternForm(copy, boss, "robotomy request", "copy target");
		testInternForm(assign, boss, "presidential pardon", "assign target");
	}

	{
		std::cout << "\n=== Multiple Interns Test ===\n";
		Intern intern1;
		Intern intern2;
		Bureaucrat boss("boss", 1);

		AForm* form1 = intern1.makeForm("shrubbery creation", "garden");
		AForm* form2 = intern2.makeForm("robotomy request", "Roboto");

		if (form1 && form2)
		{
			boss.signForm(*form1);
			boss.signForm(*form2);
			boss.executeForm(*form1);
			boss.executeForm(*form2);
		}
		delete form1;
		delete form2;
	}

	{
		std::cout << "\n=== NULL return Test ===\n";
		Intern intern;
		Bureaucrat boss("boss", 1);

		AForm* bad = intern.makeForm("bad form", "target");
		if (!bad)
			std::cout << "Correctly returned NULL for unknown form" << std::endl;
		delete bad;
	}

	return 0;
}
