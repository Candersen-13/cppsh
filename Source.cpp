//cppsh is a C++ Shell for Windows/Linux
//Author: Chase Andersen
//Last update: 05/12/2024
//Version: v0.0.1

#include <iostream>
#include <stdlib.h>


char* cppsh_read_line() {
	int cppsh_buf_size = 1024;
	int bufsize = cppsh_buf_size;
	int position = 0;
	char* buffer = (char*) malloc(sizeof(char) * bufsize);
	int c;

	if (!buffer) {
		std::cerr << "cppsh: Allocation Error";
		exit(EXIT_FAILURE);
	}

	while (1) {
		c = getchar();

		//If we hit EOF, replace it will a NULL character and return
		if (c == EOF || c == '\n') {
			buffer[position] = '\0';
			return buffer;
		}
		else {
			buffer[position] = c;
		}
		position++;
	}

	//If we exceed the limit of the buffer realocate
	if (position >= bufsize) {
		bufsize += cppsh_buf_size;
		buffer = (char*) realloc(buffer, bufsize);

		if (!buffer) {
			std::cerr << "cppsh: Allocation Error";
			exit(EXIT_FAILURE);
		}
	}
}

char* cppsh_split_line(char* line) {

}

int cppsh_execute(char* args) {

}

//Loop start
/*Basic features:
* Read input from user
* Parse the input into the command and arguments
* Execute the command
*/
void cppsh_loop() {
	char* line;
	char* args;
	int status = 0;

	do {
		std::cout << "> ";
		line = cppsh_read_line();
		args = cppsh_split_line(line);
		status = cppsh_execute(args);

		free(line);
		free(args);
	} while (status);

}

int main() {
	//Load config files if any. Such as display setting for users

	//Run command loop to start
	cppsh_loop();

	//Clean up and exit
	return EXIT_SUCCESS;
}