#include <set/set.h>
#include <random>

using namespace set;

int main() {
	Set ki;
	for (int i = 0; i < 100; ++i) {
		ki.insert(rand() % 1000);
	}
	ki.print_set();
	return 1;
}