#include <Fuzzing.h>
using namespace std;

FILE* CIF(char* input) {
	FILE* tmpf = tmpfile();
	if (tmpf == NULL) {
		cout << "Unable to create tmp file" << endl;
		return 0;
	}
	cout << input << endl;
	fputs(input, tmpf);
	rewind(tmpf);
	/* checking tempfile's name
	char fname[FILENAME_MAX], link[FILENAME_MAX] = { 0 };
	sprintf(fname, "/proc/self/fd/%d", fileno(tmpf));
	if (readlink(fname, link, sizeof link - 1) > 0)
		printf("File name: %s\n", link);
	*/
	
	//fread(&tmpf, sizeof &tmpf, 1, tmpf);
	
	return tmpf;
}
