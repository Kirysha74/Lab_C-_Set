#include <set/set.h>
#include <random>
#include <chrono>
#include <vector>

using namespace set;

int main() {
	/*
	setlocale(LC_CTYPE, "");
	int sum = 0;
	for (int j = 0; j < 100; ++j) {
		Set a;
		auto start = chrono::steady_clock::now();
		for (int i = 0; i < 1000; ++i) {
			a.insert(lcg());
		}
		auto end = chrono::steady_clock::now();
		sum = sum + chrono::duration_cast<chrono::microseconds>(end - start).count();
	}
	cout << 1.0 * sum / 100 << " микросекунд - среднее время заполнения множества 1000 элементами" << endl;

	sum = 0;
	for (int j = 0; j < 100; ++j) {
		Set a;
		auto start = chrono::steady_clock::now();
		for (int i = 0; i < 10000; ++i) {
			a.insert(lcg());
		}
		auto end = chrono::steady_clock::now();
		sum = sum + chrono::duration_cast<chrono::microseconds>(end - start).count();
	}
	cout << 1.0 * sum / 100 << " микросекунд - среднее время заполнения множества 10000 элементами" << endl;
	sum = 0;
	for (int j = 0; j < 100; ++j) {
		Set a;
		auto start = chrono::steady_clock::now();
		for (int i = 0; i < 100000; ++i) {
			a.insert(lcg());
		}
		auto end = chrono::steady_clock::now();
		sum = sum + chrono::duration_cast<chrono::microseconds>(end - start).count();
	}
	cout << 1.0 * sum / 100 << " микросекунд - среднее время заполнения множества 100000 элементами" << endl;


	Set a;
	for (int i = 0; i < 1000; ++i) {
		a.insert(lcg());
	}

	int sum_contains = 0, sum_erase = 0, sum_insert = 0;
	for (int j = 0; j < 1000; ++j) {
		Set b(a);
		auto start = chrono::steady_clock::now();
		b.contains(lcg());
		auto end = chrono::steady_clock::now();
		sum_contains = sum_contains + chrono::duration_cast<chrono::nanoseconds>(end - start).count();
		start = chrono::steady_clock::now();
		b.erase(lcg());
		end = chrono::steady_clock::now();
		sum_erase = sum_erase + chrono::duration_cast<chrono::nanoseconds>(end - start).count();
		start = chrono::steady_clock::now();
		b.insert(lcg());
		end = chrono::steady_clock::now();
		sum_insert = sum_insert + chrono::duration_cast<chrono::nanoseconds>(end - start).count();
	}
	cout << 1.0 * sum_contains / 1000 << "\t" << 1.0 * sum_erase / 1000 << "\t" << 1.0 * sum_insert / 1000 << "\t" << endl;

	for (int i = 0; i < 9000; ++i) {
		a.insert(lcg());
	}

	sum_contains = 0, sum_erase = 0, sum_insert = 0;
	for (int j = 0; j < 1000; ++j) {
		Set b(a);
		auto start = chrono::steady_clock::now();
		b.contains(lcg());
		auto end = chrono::steady_clock::now();
		sum_contains = sum_contains + chrono::duration_cast<chrono::nanoseconds>(end - start).count();
		start = chrono::steady_clock::now();
		b.erase(lcg());
		end = chrono::steady_clock::now();
		sum_erase = sum_erase + chrono::duration_cast<chrono::nanoseconds>(end - start).count();
		start = chrono::steady_clock::now();
		b.insert(lcg());
		end = chrono::steady_clock::now();
		sum_insert = sum_insert + chrono::duration_cast<chrono::nanoseconds>(end - start).count();
	}
	cout << 1.0 * sum_contains / 1000 << "\t" << 1.0 * sum_erase / 1000 << "\t" << 1.0 * sum_insert / 1000 << "\t" << endl;
	for (int i = 0; i < 90000; ++i) {
		a.insert(lcg());
	}

	sum_contains = 0, sum_erase = 0, sum_insert = 0;
	for (int j = 0; j < 1000; ++j) {
		Set b(a);
		auto start = chrono::steady_clock::now();
		b.contains(lcg());
		auto end = chrono::steady_clock::now();
		sum_contains = sum_contains + chrono::duration_cast<chrono::nanoseconds>(end - start).count();
		start = chrono::steady_clock::now();
		b.erase(lcg());
		end = chrono::steady_clock::now();
		sum_erase = sum_erase + chrono::duration_cast<chrono::nanoseconds>(end - start).count();
		start = chrono::steady_clock::now();
		b.insert(lcg());
		end = chrono::steady_clock::now();
		sum_insert = sum_insert + chrono::duration_cast<chrono::nanoseconds>(end - start).count();
	}
	cout << 1.0 * sum_contains / 1000 << "\t" << 1.0 * sum_erase / 1000 << "\t" << 1.0 * sum_insert / 1000 << "\t" << endl;
	*/

	Set k1, k2;
	for (int i = 0; i < 10; ++i) {
		k1.insert(rand() % 10);
		k2.insert(rand() % 10);
	}
	k1.print_set();
	cout << endl;
	k2.print_set();
	cout << endl;
	uni(k1, k2).print_set();
	cout << endl;
	simmetrical_difference(k1, k2).print_set(); 

	return 0;
}