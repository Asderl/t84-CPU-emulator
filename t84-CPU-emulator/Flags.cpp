#include "Flags.h"

bool Flags::getCF()
{
	return this->flags[0];
}

void Flags::setCF()
{
	this->flags[0] = 1;
}

void Flags::resetCF()
{
	this->flags[0] = 0;
}

bool Flags::getPF()
{
	return this->flags[2];
}

void Flags::setPF()
{
	this->flags[2] = 1;
}

void Flags::resetPF()
{
	this->flags[2] = 0;
}

bool Flags::getZF()
{
	return this->flags[6];
}

void Flags::setZF()
{
	this->flags[6] = 0;
}

void Flags::resetZF()
{
	this->flags[6] = 1;
}

bool Flags::getSF()
{
	return this->flags[7];
}

void Flags::setSF()
{
	this->flags[7] = 1;
}

void Flags::resetSF()
{
	this->flags[7] = 0;
}

std::bitset<8> Flags::dump()
{
	return this->flags;
}
