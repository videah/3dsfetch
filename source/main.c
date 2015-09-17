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
#include "ini.h"

// Config //

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

	ini_t *config = ini_load("config.ini");

	const char *username =		ini_get(config, "config", "username");
	const char *hostname =		ini_get(config, "config", "hostname");
	const char *os =			ini_get(config, "config", "os");
	const char *firmware =		ini_get(config, "config", "firmware");
	const char *packages =		ini_get(config, "config", "packages");
	const char *shell = 		ini_get(config, "config", "shell");
	const char *resolution =	ini_get(config, "config", "resolution");
	const char *cpu =			ini_get(config, "config", "cpu");
	const char *memory =		ini_get(config, "config", "memory");
	const char *gpu =			ini_get(config, "config", "gpu");

	gfxInitDefault();

	consoleInit(GFX_TOP, NULL); // Initialize console on top screen.

	int x = 20;

	printf(asciiart, 0, 0);

	while (aptMainLoop()) {

		hidScanInput(); // Scan for inputs

		u32 kDown = hidKeysDown(); // Get keys that are down

		if (kDown & KEY_START) break; // Break and return to the Homebrew Menu

		printLine(username, hostname, x, 6); // username@hostname

		printLine("OS: ", os, x, 8); // Don't have a better name for this

		printLine("Firmware: ", firmware, x, 10); // Detect it somehow?

		printLine("Packages: ", packages, x, 12); // Maybe get number of homebrew somehow?

		printLine("Shell: ", shell, x, 14); // 3DS can't really have a shell but whatever

		printLine("Resolution: ", resolution, x, 16); // Needs changed for 2DS

		printLine("CPU: ", cpu, x, 18); // This also needs changed for 2DS

		printLine("Memory: ", memory, x, 20); // Maybe get RAM usage somehow?

		printLine("GPU: ", gpu, x, 22);

	}

	gfxExit();

	ini_free(config);
	
	return 0;

}