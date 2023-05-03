#include "file.h"

File::File(string name) {
	myName = name;
}

string File::read() {
	return contents;
}

void File::write(string text)
{
	contents = text;
}