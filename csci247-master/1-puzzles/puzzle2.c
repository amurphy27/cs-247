/* This program reads a line from the console, verifies that it contains a
 * sequence of unsigned integers, and that those integers are the beginning of a
 * specific mathematical sequence.  The program succeeds if the string matches,
 * otherwise, it reports the error and returns failure.
 *
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Matches
 * Returns true if line is a sequence of unsigned that matches the hard-coded
 * mathematical sequence.  
 *
 */

// The variable lineBuilder holds the tokens found from strtok to compare to the secret
bool matches(char* line) {
  char* secret = "1 1 5";
  char* lineBuilder = strtok(line, " ");
  while (strtok(NULL, " ") != NULL)
  {
    lineBuilder = strtok(NULL, " ");
  }
  return ~strcmp(secret, lineBuilder);
}


/* Main
 * Returns success if the input string matches (above).  Otherwise, it returns
 * failure.  
 *
 * There are really two failure modes: gitline falure, input mismatch.  In the
 * former case, perror is used to display the error condition set by getline.
 * In the latter case, the a brief error message is printed.  
 *
 * Note the if-statement that removes the trailing new-line.  The last character
 * from getline does not have to be a new-line, so the if-statement is
 * required.  
 */

int main() {
  bool   isSuccess = false;
  char*  line = NULL;
  size_t size = 0;
  size_t len  = getline(&line, &size, stdin);

  if(-1 == len) {
    perror("getline");
  }
  else {
    
    if(line[len-1] == '\n') {
      line[len-1] = '\0';
    }
       
    isSuccess = matches(line);

    if(!isSuccess) {
      printf("Didn't match\n");
    }

    free(line);
  }

  return isSuccess ? EXIT_SUCCESS : EXIT_FAILURE;
}
