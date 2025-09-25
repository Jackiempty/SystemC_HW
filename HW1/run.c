#include <stdio.h>
#include <string.h>
int main(int argc, char* argv[]) {
  const char* prog = argv[0];
  const char* slash = strrchr(prog, '/');
  if (slash) {
    prog = slash + 1; 
  }
  printf("%s says ", prog);
  printf("Hello World!\n");
  return (0);
}