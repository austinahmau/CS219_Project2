#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "converter.h"

const int NUM_ARGS = 2;

int main(int argc, char *argv[]) {
	std::string operation, operand1, operand2;
	std::vector<std::string> operations, operands1, operands2;

	if(argc < NUM_ARGS) {
		std::cout << "correct usage:" << std::endl;
		std::cout << argv[0] << " filename" << std::endl;
		return 0;
  }

	std::ifstream myFile;
	myFile.open(argv[1]);

	if(myFile) {
		while(myFile >> operation >> operand1 >> operand2){
			operations.push_back(operation);
			operands1.push_back(operand1);
			operands2.push_back(operand2);
		}
		myFile.close();
	} 
	else{
		std::cout << "file does not exist" << std::endl;
	}

	for (int i = 0; i < operations.size(); i++) {
		if(operations.at(i) == "ADD"){
			uint32_t num1 = std::stoul(operands1.at(i), 0, 16);
			uint32_t num2 = std::stoul(operands2.at(i), 0, 16);

			std::cout << operations.at(i) << ": " << operands1.at(i) << " + " << operands2.at(i) << " = 0x"<< std::hex << std::uppercase << num2 + num1 << std::endl;
		}
		else if(operations.at(i) == "SUB"){
			uint32_t num1 = std::stoul(operands1.at(i), 0, 16);
			uint32_t num2 = std::stoul(operands2.at(i), 0, 16);

			std::cout << operations.at(i) << ": " << operands2.at(i) << " - " << operands1.at(i) << " = 0x"<< std::hex << std::uppercase << num2 - num1 << std::endl;      
		}
		else if(operations.at(i) == "NOT"){
			std::string num1 = operands1.at(i);
			Converter convert;
			std::string binary = convert.hexToBinary(num1);
			std::string notBinary = "";

			for(int i = 0; i < binary.length(); i++){
				if(binary[i] == '0'){
					notBinary += "1";
				}
				else{
					notBinary += "0";
				}
			}
			uint32_t notNumber = std::stoul(notBinary, 0, 2);
			std::cout << "NOT: ~" << operands1.at(i) << " = 0x" << notNumber << std::endl;
		}
		else if(operations.at(i) == "AND"){
			uint32_t num1 = std::stoul(operands1.at(i), 0, 16);
			uint32_t num2 = std::stoul(operands2.at(i), 0, 16);

			std::cout << "AND: " << operands1.at(i) << " & " << operands2.at(i) << " = 0x" << (num1 & num2) << std::endl;
		}
		else if(operations.at(i) == "ORR"){
			uint32_t num1 = std::stoul(operands1.at(i), 0, 16);
			uint32_t num2 = std::stoul(operands2.at(i), 0, 16);

			std::cout << "ORR: " << operands1.at(i) << " | " << operands2.at(i) << " = 0x" << (num1 | num2) << std::endl;
		}
		else if(operations.at(i) == "XOR"){
			uint32_t num1 = std::stoul(operands1.at(i), 0, 16);
			uint32_t num2 = std::stoul(operands2.at(i), 0, 16);

			std::cout << "XOR: " << operands1.at(i) << " ^ " << operands2.at(i) << " = 0x" << (num1 ^ num2) << std::endl;
		}
		else if(operations.at(i) == "LSR"){
			uint32_t num1 = std::stoul(operands1.at(i), 0, 16);
			num1 = num1 >> 1;
			
			std::cout << "LSR: " << operands1.at(i) << " logical shift right by 1 bit = 0x" << num1 << std::endl;
		}
		else if(operations.at(i) == "LSL"){
			uint32_t num1 = std::stoul(operands1.at(i), 0, 16);
			num1 = num1 << 1;
			
			std::cout << "LSL: " << operands1.at(i) << " logical shift left by 1 bit = 0x" << num1 << std::endl;
		}
		else if(operations.at(i) == "ASR"){
			Converter convert;
			std::string num1String = operands1.at(i);
			std::string getMSB = convert.hexToBinary(num1String);
			char msb = getMSB[0];

			std::string answerASR = "";

			answerASR += msb;
			for(int i = 0; i < getMSB.length() - 1; i++){
				answerASR += getMSB[i];
			}
			uint32_t finalASR = std::stoul(answerASR, 0, 2);

			std::cout << "ASR: " << operands1.at(i) << " arithmetic shift right by 1 bit = 0x" << finalASR << std::endl;
		}	
  	}
}
