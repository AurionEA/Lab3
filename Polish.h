#pragma once
#include <iostream>
#include <string>
#include "List.h"
#include "Parser.h"

class Polish {
	Parser par;
	std::string opers;
	StList <std::string> konsts;
public:
	Polish();
	Polish(Parser pr);
	void polishing();
	void prnt();
};

Polish::Polish() {
	opers = "";
}

Polish::Polish(Parser pr) {
	par = pr;
	if (par.check()) {
		par.parse();
	}
	opers = "";
}

void Polish::polishing() {
	std::string temp1 = "";
	Parser temp2 = par;
	std::string temp3 = par.getline();
	for (int i = 0; i < par.size(); i++) {
		temp1 = temp2.getlex();
		if (temp3[i] == 1) {
			konsts.push(temp1);
		}
		else {
			opers = opers + temp1;
		}
	}
}

void Polish::prnt() {
	par.prnt();
	std::cout << std::endl;
	konsts.prnt();
	std::cout << std::endl;
	std::cout << opers;
}