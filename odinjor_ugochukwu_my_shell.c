// Program: Command Launcher
// Author's Name: Ugochukwu Odinjor
// Purpuse: Stimulate very basic shell like commands

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_INPUT 1024

int main() {
	char input[MAX_INPUT];

	while(1) {
		printf("my_shell :> ");
		fflush(stdout);
	
		// Read input
		if (fgets(input, sizeof(input), stdin) == NULL) {
			printf("\nExiting shell.\n");
			break;
		}
		
		// REmove newline
		input[strcspn(input, "\n")] = '\0';
		
		// Checks for tthe exit command before forking
		if (strcmp(input, "exit") == 0){
			printf("Goodbye!\n");
			break;
		} 
		
		// Skip empty input
		if (strlen(input) == 0) continue;
		
		// Build full path to command
		char command_path[256] = "/bin/";
		strncat(command_path, input, sizeof(command_path) - strlen(command_path) - 1);
		
		// Create a child process
		pid_t pid = fork();
		if (pid < 0) {
			perror("Fork failed");
			continue;
		}
		
		if (pid == 0) {
			// In child process
			execl(command_path, input, (char *)NULL);
			
			// If execl fails
			perror("Execl failed");
			exit(EXIT_FAILURE);
		} else {
			// In parent process
			int status;
			if (wait(&status) == -1) {
				perror("Wait failed");
			}
		}
	}
	return 0;
}
