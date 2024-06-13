#include "CPU.h"

int main() {
	CPU cpu(4096, 2048);
	cpu.run();
	for (int i = 0; i < 4; i++) {
		(cpu.registers+i)->dump(DUMP_MODE::BIN);
		std::cout << "\t";
	}
	return 0;
}