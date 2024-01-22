#include "RandomFuzzer.h"

using namespace std;

char* fuzzer(int max_length = 100, int char_start = 32, int char_range = 32) {
	srand(static_cast<unsigned int>(time(NULL)));
	int string_length = rand() % max_length + 1;
	char out[string_length];
	for (int i = 0; i < string_length; i++) {
		int rand_int = rand() % 32 + 1;
		char rand_chr = rand_int;
		strncat(out, &rand_chr, 1);
	}
	return out;
}
