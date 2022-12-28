#include <iostream>
#include "List.h"
#include "Parser.h"
#include "Polish.h"

int main() {
	//List<int> list1;
	//list1.push_back(3);
	//list1.push_frnt(2);
	//list1.prnt();
	//std::cout << std::endl;

	Parser pars1("-2+135*(345-456)");
	//if (pars1.check()) {
	//	pars1.parse();
	//	pars1.prnt();
	//}
	//std::cout << std::endl << std::endl;

	Polish pol1(pars1);

	pars1.parse();
	std::cout << pars1.size() << std::endl;
	pol1.polishing();
	pol1.prnt();
	
	return 0;
}