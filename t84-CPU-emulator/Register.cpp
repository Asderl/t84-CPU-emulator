#include "Register.h"

Register::Register(uint8_t* memory, const char* name)
{
	this->memory = memory;
	this->name = name;
}

void Register::dump(DUMP_MODE base)
{
	std::cout << this->name << " Register: ";
	switch (base)
	{
	case DUMP_MODE::BIN:
		std::cout << std::bitset<8>(this->value);
		break;
	case DUMP_MODE::DEC:
		std::cout << this->value;
		break;
	case DUMP_MODE::HEX:
		std::cout << std::hex << this->value;
		break;
	}
}

void Register::set(uint8_t value)
{
	this->value = value;
}

void Register::inc()
{
	this->value++;
}

void Register::dec()
{
	this->value--;
}

void Register::reset()
{
	this->value = 0;
}

void Register::load(int addr)
{
	this->value = this->memory[addr];
}

void Register::store(int addr)
{
	this->memory[addr] = this->value;
}

void Register::add(uint8_t val)
{
	this->value += val;
}

void Register::sub(uint8_t val)
{
	this->value -= val;
}

void Register::shl()
{
	this->value <<= 1;
}

void Register::shr()
{
	this->value >>= 1;
}
