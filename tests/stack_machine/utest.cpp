#include "mu_test.h"

#include "svm_wizard.hpp"
#include <string>
#include <sstream>

/* UML - https://imgur.com/a/BXosAFv */

BEGIN_TEST(wizard_from_file_hello)
	using svm::Wizard;
	Wizard assm1{"../../resources/svm/test01.asm"};
	std::string output;
	std::stringstream output_ss{output};
	assm1.Assemble(output_ss);
	getline(output_ss, output, static_cast<char>(EOF));
	TRACE(output);
	ASSERT_EQUAL(output, std::string{"Hello"});
END_TEST

BEGIN_TEST(wizard_from_file_test)
	using svm::Wizard;
	Wizard assm1{"../../resources/svm/test02.asm"};
	std::string output;
	std::stringstream output_ss{output};
	assm1.Assemble(output_ss);
	getline(output_ss, output, static_cast<char>(EOF));
	TRACE(output.c_str());
	ASSERT_EQUAL(output, std::string{""});
END_TEST

BEGIN_SUITE(Stack Machine Tests)
	TEST(wizard_from_file_hello)
	TEST(wizard_from_file_test)
END_SUITE
