#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 統計結果結構
typedef struct {
  long lines;
  long chars;  // [A-Za-z0-9]
  long uppercase;
  long words;
} Stats;

// 統計檔案
void analyze_file(FILE* fp, Stats* st) {
  int c, prev = ' ';
  st->lines = st->chars = st->uppercase = st->words = 0;

  while ((c = fgetc(fp)) != EOF) {
    // line number
    if (c == '\n') {
      st->lines++;
    }

    // char count: [A-Za-z0-9]
    if (isalnum(c)) {
      st->chars++;
    }

    // is capital
    if (isupper(c)) {
      st->uppercase++;
    }

    // words reconition
    if ((c == ' ' || c == '\n') && (prev != ' ' && prev != '\n')) {
      st->words++;
    }

    prev = c;
  }

  // count lines
  st->lines++;

  // check whether the last string is a word
  if (prev != ' ' && prev != '\n') {
    st->words++;
  }
}

// turn file content to capital and output to "UPPER"
void convert_to_upper(FILE* in, const char* outfile) {
  FILE* out = fopen(outfile, "w");
  if (!out) {
    perror("open UPPER file");
    exit(1);
  }

  int c;
  while ((c = fgetc(in)) != EOF) {
    fputc(toupper(c), out);
  }

  fclose(out);
}

int main(int argc, char* argv[]) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
    return 1;
  }

  FILE* fp = fopen(argv[1], "r");
  if (!fp) {
    perror("open file");
    return 1;
  }

  Stats st;
  analyze_file(fp, &st);

  printf("Lines: %ld\n", st.lines);
  printf("Alphanumeric chars: %ld\n", st.chars);
  printf("Uppercase letters: %ld\n", st.uppercase);
  printf("Words: %ld\n", st.words);

  // rewind first and then transform after
  rewind(fp);
  convert_to_upper(fp, "UPPER.txt");

  fclose(fp);
  return 0;
}
