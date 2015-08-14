// This code is licensed under the MIT Open Source License.

// Copyright (c) 2015 Ruairidh Carmichael - ruairidhcarmichael@live.co.uk

// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <3ds.h>
#include "util.h"

// Config //

#define HOST_NAME "VideahGams"

#define TEXT_COLOR COLOR_RED

///////////

char const *asciiart = 
"\n\n\n\n\n\n"
"       ######\n"
"     ####  ####\n"
"    #####  #####\n"
"   ## ##    ## ##\n"
"   ##          ##\n"
"  ####        ####\n"
"  ####  ####  ####\n"
"  #### ###### ####\n"
"  #### ###### ####\n"
"  ###  ######  ###\n"
"  #     ####     #\n"
"  #  ##########  #\n"
"  ####  #  #  ####\n"
"   ##   #  #   ## \n"
"    #          #\n"
"    ##        ##\n"
"     ##########\n";

void printPos(char* string, int x, int y) {

	printf("%c[%d;%df",0x1B,y,x);

	printf(string);

	return 0;

}

void printLine(char* string1, char* string2, int x, int y) {

	printf(TEXT_COLOR); printPos(string1, x, y); printf(COLOR_CLEAR); printf(string2);

	return 0;

}

int main() {

	gfxInitDefault();

	consoleInit(GFX_TOP, NULL); // Initialize console on top screen.

	int x = 21;

	while (aptMainLoop()) {

		printPos(asciiart, 0, 0);

		printLine(HOST_NAME, "@3ds", x, 8);

		printLine("Placeholder: ", "", x, 10);

		printLine("GPU: ", "DMP PICA200 268MHz", 22, 11);
		printLine("RAM: ", "0MiB / 128MiB", 22, 12);
		printLine("Placeholder: ", "", x, 13);
		printLine("Placeholder: ", "", x, 14);
		printLine("Placeholder: ", "", x, 15);
		printLine("Placeholder: ", "", x, 16);
		printLine("Placeholder: ", "", x, 17);

		printf(COLOR_CLEAR);

	}

	return 0;

}