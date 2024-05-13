//cppsh is a C++ Shell for Windows/Linux
//Author: Chase Andersen
//Last update: 05/12/2024
//Version: v0.0.2

#include <iostream>

int main() {
	//Load config files if any. Such as display setting for users

	//Run command loop to start
	cppsh_loop();

	//Clean up and exit
	return EXIT_SUCCESS;
}

//Loop start
/*Basic features:
* Read input from user
* Parse the input into the command and arguments
* Execute the command
*/
void cppsh_loop() {
	std::string* line;
	std::string* args;
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

std::string* cppsh_read_line() {

}

std::string* cppsh_split_line(std::string* line) {

}

int cppsh_execute(std::string* args) {

}