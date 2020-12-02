/*
 * MIT License
 *
 * Copyright(c) 2020 Leonardo Henrique Guimaraes <leonardo.guimaraeslhg@gmail.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

 //Theirs
#include <stdio.h>
#include <stdlib.h>

// My lib
#include "utils.h"

/* *
 *  @brief Open input and output files and deliver
 *         then to core_run function
 *
 *  @param Input file
 *
 *  @return A integer meaning exit successful or failure
 */
int main(int argc, char *argv[]){
	FILE *input, *output;

	input = fopen(argv[1], "r");

	if(input == NULL)
		goto error_input_file;

	output = fopen("saida.txt", "w");

	if(output == NULL)
		goto error_output_file;

	core_run(input, output);

	// fclose(input);
	fclose(output);

	return(EXIT_SUCCESS);

error_output_file:
	printf("%s\n", ERROR_OUTPUT_MESSAGE);
	// fclose(input);
	return (EXIT_FAILURE);

error_input_file:
	printf("%s\n", ERROR_INPUT_MESSAGE);
	return (EXIT_FAILURE);
}
