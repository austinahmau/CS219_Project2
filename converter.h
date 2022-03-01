#ifndef CONVERTER_H
#define CONVERTER_H

#include <string>
#include <iostream>

class Converter{
private:
	std::string operand;

public:
	//function definitions
	Converter();
	std::string hexToBinary(std::string operand);
};
#endif
