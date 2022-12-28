#pragma once
#include <iostream>
#include <string>
#include "List.h"
#include "Stack.h"

class Parser {
	List<std::string> lexems;
	std::string example;
	std::string line;
public:
	Parser();
	Parser(std::string examp);
	Parser(Parser& par);
	bool check();
	void parse();
	int size();
	std::string getline();
	std::string getlex();
	void prnt();
};

Parser::Parser() {
	example = "";
}

Parser::Parser(std::string examp){
	example = examp;
}

Parser::Parser(Parser& par) {
	example = par.example;
	lexems = par.lexems;
}

bool Parser::check() {
	StList<char> brekets;
	for (size_t i = 0; i < example.size(); i++) {
		if (example[i] == '(') {
			brekets.push(example[i]);
		}
		else if (example[i] == ')') {
			if (brekets.isEmpty()) {
				std::cout << "Uncorrect brekets subsequence";
				return false;
			}
			brekets.pop();
		}
	}
	if (!brekets.isEmpty()) {
		std::cout << "Lack of brackets";
		return false;
	}
	return true;
}

void Parser::parse() {
	int stat = 0;
	std::string tmp = "";
	for (size_t i = 0; i < example.size(); i++) {
		if (stat == 0) {
			if (std::isdigit(example[i])) {
				tmp += example[i];
			}
			else { 
				stat = 1;
				if (tmp != "") {
					lexems.push_back(tmp);
				}
				line += "1";
				tmp = "";
				
			}
		}
		if (stat == 1) {
			if (!std::isdigit(example[i])) {
				std::string str(1, example[i]);
				lexems.push_back(str);
				line += "0";
			}
			else {
				stat = 0;
				tmp += example[i];
			}
		}
	}
}

int Parser::size() {
	int temp1 = 0;
	List<std::string> temp2 = lexems;
	while (!temp2.isEmpty()) {
		if (!temp2.isEmpty()) {
			temp1 += 1;
			temp2.pop_back();
		}
	}
	return temp1;
}

std::string Parser::getline() {
	return line;
}

std::string Parser::getlex() {
	std::string temp = "";
	temp += lexems.pop_back();
	return temp;
}

void Parser::prnt() {
	lexems.prnt();
}