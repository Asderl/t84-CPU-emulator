#pragma once
#include "util.h"

#ifndef REGISTER_H
#define REGISTER_H

class Register
{
private:
	uint8_t* memory;
	uint8_t max_value = UINT8_MAX;

public:
	Register(uint8_t* memory, const char* name);
	uint8_t value = 0;
	const char* name;
	void dump(DUMP_MODE base);
	void set(uint8_t value);
	void inc();
	void dec();
	void reset();
	void load(int addr);
	void store(int addr);
	void add(uint8_t val);
	void sub(uint8_t val);
	void shl();
	void shr();
};

#endif