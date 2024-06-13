#include "Memory.h"

void Memory::setitem(int addr, uint8_t item)
{
	this->memory[addr] = item & this->max_value;
}

uint8_t* Memory::getitem(int addr)
{
	return &this->memory[addr];
}

Memory::Memory(int memsize, int base_offset)
{
	this->size = memsize;
	this->memory = new uint8_t[memsize]{ 0 };
	this->offset = base_offset;
}

void Memory::write(int offset, uint8_t item)
{
	this->setitem(offset, item);
	this->offset++;
}

uint8_t Memory::read(int addr)
{
	return *this->getitem(addr);
}

void Memory::dump(DUMP_MODE base)
{
	switch (base)
	{
	case DUMP_MODE::BIN:
		for (int i = 0; i < sizeof(*this->memory) / sizeof(uint8_t); i++) {
			std::cout << std::bitset<8>(this->memory[i]);
		}
		break;
	case DUMP_MODE::DEC:
		for (int i = 0; i < sizeof(*this->memory) / sizeof(uint8_t); i++) {
			std::cout << this->memory[i];
		}
		break;
	case DUMP_MODE::HEX:
		for (int i = 0; i < sizeof(*this->memory) / sizeof(uint8_t); i++) {
			std::cout << std::hex << this->memory[i];
		}
		break;
	}
}
