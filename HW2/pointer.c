#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <bytes>\n", argv[0]);
    return 1;
  }

  int size = atoi(argv[1]);  // turn argv[1] (char*) to int
  if (size <= 0) {
    fprintf(stderr, "Size must be positive\n");
    return 1;
  }

  // 1. allocate mempory
  void* ptr = malloc(size);
  if (!ptr) {
    perror("malloc failed");
    return 1;
  }

  // 2. fill the memory with char*
  char* cptr = (char*)ptr;
  char pattern[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ123456789";
  int plen = sizeof(pattern) - 1;  // exclude '\0'
  for (int i = 0; i < size; i++) {
    cptr[i] = pattern[i % plen];
  }

  // make sure there's a '\0' at the end of the string,
  // preventing printf from crashing
  if (size > 0) {
    cptr[size - 1] = '\0';
  }

  printf("Generated string:\n%s\n", cptr);

  // 3. print *pair with int
  int* iptr = (int*)ptr;
  int count = size / sizeof(int);  // read the number of int

  printf("\nInteger pairs:\n");
  int i = 0;
  while (i < count) {
    printf("%d : %d\n", iptr[i], iptr[i] - 1);
    i++;
  }

  free(ptr);
  return 0;
}