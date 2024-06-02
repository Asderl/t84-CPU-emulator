#pragma once
#ifndef FLAG_H
#define FLAG_H

#include "util.h"

class Flags
{
private:
	std::bitset<8> flags = std::bitset<8>(0b00000010);

public:
	bool getCF();
	void setCF();
	void resetCF();
	bool getPF();
	void setPF();
	void resetPF();
	bool getZF();
	void setZF();
	void resetZF();
	bool getSF();
	void setSF();
	void resetSF();
	std::bitset<8> dump();
};

#endif