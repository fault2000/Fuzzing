#include <Exec.h>
#include <iostream>
#define BUFFER_MAX 128
using namespace std;

string exec(const char* cmd) {
    char buffer[BUFFER_MAX];
    string result;

    auto pipe = popen(cmd, "r");

    if (!pipe) throw runtime_error("popen() failed!");

    while (fgets(buffer, BUFFER_MAX, pipe) != NULL) {
        result += buffer;
    }

    auto rc = pclose(pipe);

    if (rc == EXIT_SUCCESS) { // == 0
        return "";
    }
    else if (rc == EXIT_FAILURE) {  // EXIT_FAILURE is not used by all programs, maybe needs some adaptation.
        return result;
    }
    return result;
}