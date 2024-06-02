#pragma once
#include "Memory.h"
#include "Register.h"
#include "Flags.h"

#ifndef CPU_H
#define CPU_H

class CPU
{
private:
	void fetch_instruction();
	bool execute_instruction();
	Flags flags;
	Memory* memory_block;

public:
	CPU(int mem_size, int stack_offset);
	void run();
	Register* registers;
	bool is_running;
	int PC;
	int SP;
};

#endif