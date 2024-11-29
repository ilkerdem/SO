#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define CHUNK_SIZE (10 * 1024 * 1024) // 10 MB
#define FILE_NAME "large_io_test.txt"

void main() {
  unsigned long long i = 0;
  FILE *file;
  char *data;

  // Allocate a large chunk of memory
  data = (char *)malloc(CHUNK_SIZE);

  // Fill the buffer with dummy data
  memset(data, 'A', CHUNK_SIZE);

  while (1) {
    // Write to a file
    /*        file = fopen("simple_io_test.txt", "w");
            if (file == NULL) {
                perror("Error opening file");
                return;
            }
      */
    file = fopen(FILE_NAME, "w");
    // Write the data to the file
    if (fwrite(data, 1, CHUNK_SIZE, file) != CHUNK_SIZE) {
      perror("Error writing to file");
      fclose(file);
      free(data);
      return;
    }
    fclose(file);

    printf("File write # %llu\n", i++);
    sleep(0.1);
  }
  free(data);
}
