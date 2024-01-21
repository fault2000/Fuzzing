// Fuzzing.cpp : 애플리케이션의 진입점을 정의합니다.
//

#include "Fuzzing.h"
using namespace std;

int main(int argc, char *argv[])
{
	fuzzer(1000, 'a', 26);
}
