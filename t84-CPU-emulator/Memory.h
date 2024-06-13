#pragma once
#include "util.h"

#ifndef MEMORY_H
#define MEMORY_H

class Memory
{
private:
	int max_value = UINT8_MAX;
	void setitem(int addr, uint8_t item);
	uint8_t* getitem(int addr);

public:
	int size;
	int offset;
	uint8_t* memory;
	Memory(int memsize, int base_offset);
	void write(int offset, uint8_t item);
	uint8_t read(int addr);
	void dump(DUMP_MODE base);
};

#endif