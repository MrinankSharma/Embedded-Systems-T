#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void error1(void) {
  puts("Q1: Find the error in this code segment. It should print the range 0-9 twice.\n");

  // allocate memory for arrays i, j
  int *i = malloc(sizeof(int));
  int *j = malloc(sizeof(int));

  int **p;
  p = &i;
  for (**p = 0; **p < 10; ++**p) {
    printf("%d ", **p);
  }

  free(*p);
  p = &j;
  for (**p = 0; **p < 10; ++**p) {
    printf("%d ", **p);
  }
  free(*p);
  puts("\n");
}

void output(char *str) {
  // char new_str[20]; 
  // could copy str by value instead here. 
  if (str) {
    str[0] = 'J';
    puts(str);
  }
}

void error2(void) {
  puts("Q2: Find the error in this code segment. It should print \"Jello World\" once and \"Joodbye!\" twice.\n");

  char data[] = "Hello World!";
  output(data);
  char const_data[] = "Goodbye!"; 
  output(const_data);
  // output(const_data);
  // this goodbye comes up as a char constant, so it doesn't work.
  // output(&(L"Goodbye!"));
  // output("Goodbye");
}

void error3(void) {
  char *data = 0;
  int sizes[] = { 1, 32, 512, 1024, 1048576 };
  data = malloc(sizes[0]);
  memset(data, rand(), sizes[0]);
  int i;
  for (i = 1; i < sizeof(sizes) / sizeof(sizes[0]); ++i) {
    printf("%i", i);
    free(data);
    // realloc(data, sizes[i]);
    data = malloc(sizes[i]);
    memset(data, rand(), sizes[i]);
  }
}

void run_illegal_memory_exercise(void) {
  puts("Illegal memory exercises");
  puts("------------------------------\n");
  error1();
  error2();
  error3();
  puts("\n");
}
