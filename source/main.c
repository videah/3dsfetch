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

#define HOST_NAME "VideahGams"

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

}

int main() {

	gfxInitDefault();

	consoleInit(GFX_TOP, NULL); // Initialize console on top screen.

	while (aptMainLoop()) {

		printPos(asciiart, 0, 0);

		printf("\x1b[31m");

		printPos(HOST_NAME, 22, 8);

		printf("\x1b[0m");

	}

	return 0;

}