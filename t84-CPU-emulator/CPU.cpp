#include "CPU.h"

void CPU::fetch_instruction()
{
	this->registers[4].load(this->PC);
	this->PC++;
}

bool CPU::execute_instruction()
{
	switch (this->registers[4].value)
	{
	case 0x0: break;

#pragma region 0x4... opcodes
	case 0x41: //mov A, B
		this->registers[0].set(this->registers[1].value);
		break;
	case 0x42: //mov A, C
		this->registers[0].set(this->registers[2].value);
		break;
	case 0x43: //mov A, D
		this->registers[0].set(this->registers[3].value);
		break;
	case 0x44: //add A, B
		this->registers[0].add(this->registers[1].value);
		break;
	case 0x45: //add A, C
		this->registers[0].add(this->registers[2].value);
		break;
	case 0x46: //add A, D
		this->registers[0].add(this->registers[3].value);
		break;
	case 0x47: //sub A, B
		this->registers[0].sub(this->registers[1].value);
		break;
	case 0x48: //sub A, C
		this->registers[0].sub(this->registers[2].value);
		break;
	case 0x49: //sub A, D
		this->registers[0].sub(this->registers[3].value);
		break;
#pragma endregion

#pragma region 0x5... opcodes
	case 0x50: //mov B, A
		this->registers[1].set(this->registers[0].value);
		break;
	case 0x52: //mov B, C
		this->registers[1].set(this->registers[2].value);
		break;
	case 0x53: //mov B, D
		this->registers[1].set(this->registers[3].value);
		break;
#pragma endregion

#pragma region 0x6... opcodes
	case 0x60: //mov C, A
		this->registers[2].set(this->registers[0].value);
		break;
	case 0x61: //mov C, B
		this->registers[2].set(this->registers[1].value);
		break;
	case 0x63: //mov C, D
		this->registers[2].set(this->registers[3].value);
		break;
#pragma endregion

#pragma region 0x7... opcodes
	case 0x70: //mov D, A
		this->registers[3].set(this->registers[0].value);
		break;
	case 0x71: //mov D, B
		this->registers[3].set(this->registers[1].value);
		break;
	case 0x72: //mov D, C
		this->registers[3].set(this->registers[2].value);
		break;
#pragma endregion
	
	}
	return true;
}

CPU::CPU(int mem_size, int stack_offset)
{
	this->memory_block = new Memory(mem_size, stack_offset);
	this->PC = 0;
	this->SP = this->memory_block->offset;
	this->registers = new Register[5] {Register(this->memory_block->memory, "A"), Register(this->memory_block->memory, "B"), 
		Register(this->memory_block->memory, "C"), Register(this->memory_block->memory, "D"), Register(this->memory_block->memory, "IR")};
	this->flags = Flags();
	this->is_running = false;
}

void CPU::run()
{
	while (this->is_running)
	{
		
	}
}
