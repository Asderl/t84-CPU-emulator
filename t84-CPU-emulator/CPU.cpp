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
#pragma region "0x... opcodes"
	case 0x0: break;
#pragma endregion

#pragma region "0x4... opcodes"
	case 0x40: //inc A
		this->registers[0].inc();
		break;
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
	case 0x4A: //dec A
		this->registers[0].dec();
		break;
	case 0x4B: //neg A
		this->registers[0].set(-this->registers[0].value);
		break;
	case 0x4C: //shl A
		this->registers[0].shl();
		break;
	case 0x4D: //shr A
		this->registers[0].shr();
		break;
#pragma endregion

#pragma region "0x5... opcodes"
	case 0x50: //inc B
		this->registers[1].inc();
		break;
	case 0x51: //mov B, A
		this->registers[1].set(this->registers[0].value);
		break;
	case 0x52: //mov B, C
		this->registers[1].set(this->registers[2].value);
		break;
	case 0x53: //mov B, D
		this->registers[1].set(this->registers[3].value);
		break;
	case 0x54: //add B, A
		this->registers[1].add(this->registers[0].value);
		break;
	case 0x55: //add B, C
		this->registers[1].add(this->registers[2].value);
		break;
	case 0x56: //add B, D
		this->registers[1].add(this->registers[3].value);
		break;
	case 0x57: //sub B, A
		this->registers[1].sub(this->registers[0].value);
		break;
	case 0x58: //sub B, C
		this->registers[1].sub(this->registers[2].value);
		break;
	case 0x59: //sub B, D
		this->registers[1].sub(this->registers[3].value);
		break;
	case 0x5A: //dec B
		this->registers[1].dec();
		break;
	case 0x5B: //neg B
		this->registers[1].set(-this->registers[1].value);
		break;
	case 0x5C: //shl B
		this->registers[1].shl();
		break;
	case 0x5D: //shr B
		this->registers[1].shr();
		break;
#pragma endregion

#pragma region "0x6... opcodes"
	case 0x60: //inc C
		this->registers[2].inc();
		break;
	case 0x61: //mov C, A
		this->registers[2].set(this->registers[0].value);
		break;
	case 0x62: //mov C, B
		this->registers[2].set(this->registers[1].value);
		break;
	case 0x63: //mov C, D
		this->registers[2].set(this->registers[3].value);
		break;
	case 0x64: //add C, A
		this->registers[2].add(this->registers[0].value);
		break;
	case 0x65: //add C, B
		this->registers[2].add(this->registers[1].value);
		break;
	case 0x66: //add C, D
		this->registers[2].add(this->registers[3].value);
		break;
	case 0x67: //sub C, A
		this->registers[2].sub(this->registers[0].value);
		break;
	case 0x68: //sub C, B
		this->registers[2].sub(this->registers[1].value);
		break;
	case 0x69: //sub C, D
		this->registers[2].sub(this->registers[3].value);
		break;
	case 0x6A: //dec C
		this->registers[2].dec();
		break;
	case 0x6B: //neg C
		this->registers[2].set(-this->registers[2].value);
		break;
	case 0x6C: //shl C
		this->registers[2].shl();
		break;
	case 0x6D: //shr C
		this->registers[2].shr();
		break;
#pragma endregion

#pragma region "0x7... opcodes"
	case 0x70: //inc D
		this->registers[3].inc();
		break;
	case 0x71: //mov D, A
		this->registers[3].set(this->registers[0].value);
		break;
	case 0x72: //mov D, B
		this->registers[3].set(this->registers[1].value);
		break;
	case 0x73: //mov D, C
		this->registers[3].set(this->registers[2].value);
		break;
	case 0x74: //add D, A
		this->registers[3].add(this->registers[0].value);
		break;
	case 0x75: //add D, B
		this->registers[3].add(this->registers[1].value);
		break;
	case 0x76: //add D, C
		this->registers[3].add(this->registers[2].value);
		break;
	case 0x77: //sub D, A
		this->registers[3].sub(this->registers[0].value);
		break;
	case 0x78: //sub D, B
		this->registers[3].sub(this->registers[1].value);
		break;
	case 0x79: //sub D, C
		this->registers[3].sub(this->registers[2].value);
		break;
	case 0x7A: //dec D
		this->registers[3].dec();
		break;
	case 0x7B: //neg D
		this->registers[3].set(-this->registers[3].value);
		break;
	case 0x7C: //shl D
		this->registers[3].shl();
		break;
	case 0x7D: //shr D
		this->registers[3].shr();
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
	this->is_running = true;
	while (this->is_running && this->PC < this->SP)
	{
		this->fetch_instruction();
		if (!this->execute_instruction()) {
			this->is_running = false;
			std::cout << "An error occured while instruction executing!";
			break;
		}
	}
}
