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

#define USER_NAME "ruairidh"
#define HOST_NAME "@3ds"

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

	int x = 20;

	while (aptMainLoop()) {

		hidScanInput(); // Scan for inputs

		u32 kDown = hidKeysDown(); // Get keys that are down

		if (kDown & KEY_START) break; // Break and return to the Homebrew Menu

		printPos(asciiart, 0, 0);

		printLine(USER_NAME, HOST_NAME, x, 6); // username@hostname

		printLine("OS: ", "3DS System Software", x, 8); // Don't have a better name for this

		printLine("Kernel:  ", osGetKernelVersion(), x, 10); // Doesn't work in emulator, needs testing

		printLine("Packages: ", "0", x, 12); // Maybe get number of homebrew somehow?

		printLine("Shell: ", "None", x, 14); // 3DS can't really have a shell but whatever

		printLine("Resolution: ", "800x240 | 320x240", x, 16); // Needs changed for 2DS

		printLine("CPU: ", "4x MPCore & 4x VFPv2", x, 18); // This also needs changed for 2DS

		printLine("Memory: ", "128MiB", x, 20); // Maybe get RAM usage somehow?

		printLine("GPU: ", "DMP PICA200 268MHz", x, 22);

	}

	return 0;

}