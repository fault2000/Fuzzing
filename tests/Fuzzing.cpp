// Fuzzing.cpp : 애플리케이션의 진입점을 정의합니다.
//

#include <Fuzzing.h>
#include <RandomFuzzer.h>
#include <CIF.h>
using namespace std;

int main(int argc, char *argv[])
{
	char* input = fuzzer(1000, 'a', 26);
	FILE* inputFile = CIF(input);
	return 0;
}
