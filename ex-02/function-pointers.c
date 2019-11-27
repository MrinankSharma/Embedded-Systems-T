#include <stdio.h>

void output1(const char *str) {
  puts(str);
}

int output2(unsigned int value, const char *str) {
  return printf("Value: %d, Str: %s", value, str);
}

// TODO: Replace "typeof(output1) *o1" and "typeof(output2) *o2" with the respective function types.
void execute_output(void (*o1)(const char *str), int (*o2)(unsigned int value, const char *str) ) {
  o1("Hello World!");
  o2(999, "Goodbye!");
}

void run_function_pointers_exercise(void) {
  puts("Function pointers exercises");
  puts("------------------------------\n");
  execute_output(output1, output2);
  puts("\n\n");
}
