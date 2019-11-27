#include "../mini-assert/mini-assert.h"
#include <math.h>


/**
 * Q4: Common type issues
 */
void run_types_exercise(void) {
  puts("Types exercises");
  puts("------------------------------\n");
  unsigned int uint = 248;
  signed int sint = -1;
  if (sint > uint) {
    puts("T1: Why is this line printed? Why is -1 > 248?\n");
    puts("Comparing things of two different data types, and they arent");
    puts("compatible, since they have different ranges. They do some weird");
    puts("conversion");
  }

  int vint = -1;
  printf("T2: What would this output be if we used %%u instead of %%d: %d %u? Explain why.\n\n", vint, vint);
  puts("It converts -1 to an unsigned int, so a big number. ");
  puts("C has this ... type for functions.");


  double d;
  for (d = 10.0; d != 0.0; d -= 0.1) {
    if (d < -1.0) {
      puts("T3: This loop should have terminated at 0.0. Why is this line still printed?\n");
      puts("Because of finite precision.");
      break;
    }
  }

  int initial = 0xFF;
  char down_cast = (char) initial;
  int up_cast = (int) down_cast;
  unsigned int unsin = (unsigned int) down_cast;
  printf("T4: Why is initial != up_cast (%d != %d)? What's the difference between a signed integer downcast vs. upcast?\n", initial, up_cast);
  printf("%u", unsin);

  initial = 0x7F;
  down_cast = (char) initial;
  up_cast = (int) down_cast;
  printf("T4: initial == up_cast (%d != %d)? What is the difference to the previous situation?\n\n\n", initial, up_cast);
}

/**
 * Q5: Cube calculator
 */
void run_get_cube(){
  // Look up scanf to find out how to get user input.
  // TODO: Implement
  float input;
  scanf("%f", &input);
  float cubed = input*input*input;
  printf("%f", cubed);
}

/**
 * Q6: Bitwise operations
 */
int flip_lsb(int value){
  // I will do the first one so you may get an idea.

  // We need to flip the least significant bit. We will use the XOR!
  return value ^ 0x00000001; 
}

int flip_msb(int value) {
  // TODO: Implement
  return value ^ 0x80000000;
}

int clear_lsb(int value) {
  // TODO: Implement
  return value & 0xFFFFFFFE;
}

// Set the value of the most significant bit to the least significant bit.
int set_lsb_to_msb(int value) {
  // TODO: Implement
  return (value & 0xFFFFFFFE)  | (((value & 0x80000000) >> 31) & 0x00000001);
}

int switch_portions(int value) {
  // TODO: Transform 0xABCD1234 to 0x1234ABCD
  return (((value & 0xFFFF0000)>>16) & 0x0000FFFF) | (((value & 0x0000FFFF) <<16 )& 0xFFFF0000);
}

int count_number_of_set_bits(int value) {
  // TODO: Count the number of bits set in the provided value.
  unsigned int signed_val = (unsigned int) value;
  int counter = 0;
  while(signed_val){
      if ((signed_val & 1) == 1){
        counter++;
      }
      signed_val >>=1;
  }
  return counter;
}


/**
 * Q7: Coordinates exercise
 */
double distance_between_coordinates(int x1, int y1, int x2, int y2) {
  // TODO: Implement: Calculate the distance between the two points
  //
  //     (x2,y2)
  //       /
  //      /
  //     /
  //    /
  // (x1,y1)
  //
  return sqrt(((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2)));
}

/**
 * Q8: Time conversion
 */
void run_time_converter(void) {
  // TODO: Implement. Hint: Look up modulus operator!
  int minutes = 100;
  while(minutes != -1){
    puts("how many minutes dude?");
    scanf("%u", &minutes);
    int hours = minutes / 60;
    minutes = minutes % 60;
    printf("%d hours %d minutes\n\n", hours, minutes);
  }
}

/**
 * Q9: Echo program
 */
void run_echo_exercise(void) {
  // TODO: Write a program which echoes every line of code entered, until an "exit" line is received.
  int not_exit = 1;
  while(not_exit){
    char string[50];
    scanf("%s", string);
    sprintf("%s", string);
  }
}


/**
 * Q10: Recursive program
 */
void run_recursive_print(void) {
  // TODO: Write a program which echoes every line of code entered, until an "exit" line is received.
}

void run_coordinates_exercise(void) {
  puts("Coordinates exercise tests");
  puts("------------------------------\n");
  assert_equal_delta(distance_between_coordinates(0, 0, 0, 0), 0.0);
  assert_equal_delta(distance_between_coordinates(0, 10, 20, 20), 22.36);
  assert_equal_delta(distance_between_coordinates(-10, -10, 20, 20), 42.42);
  assert_equal_delta(distance_between_coordinates(20, 20, -10, -10), 42.42);
  assert_equal_delta(distance_between_coordinates(50, 0, 80, 0), 30.0);
  puts("\n");
}

void run_bitwise_exercises(void) {
  puts("Bitwise exercise tests");
  puts("------------------------------\n");
  assert_equal_hex(flip_lsb(0x00000001), 0x00000000);
  assert_equal_hex(flip_lsb(0x00000000), 0x00000001);
  assert_equal_hex(flip_msb(0x80000000), 0x00000000);
  assert_equal_hex(flip_msb(0x00000000), 0x80000000);
  assert_equal_hex(flip_msb(0x01234567), 0x81234567);
  assert_equal_hex(flip_msb(0x81234567), 0x01234567);
  assert_equal_hex(clear_lsb(0x00000001), 0x00000000);
  assert_equal_hex(clear_lsb(0x81234567), 0x81234566);

  assert_equal_hex(set_lsb_to_msb(0x80000000), 0x80000001);
  assert_equal_hex(set_lsb_to_msb(0x00000001), 0x00000000);
  assert_equal_hex(set_lsb_to_msb(0x01234561), 0x01234560);
  assert_equal_hex(switch_portions(0xABCD1234), 0x1234ABCD);
  assert_equal_hex(switch_portions(0x00000000), 0x00000000);
  assert_equal_hex(switch_portions(0x00010000), 0x00000001);
  assert_equal_hex(count_number_of_set_bits(0xABCD0123), 14);
  assert_equal_hex(count_number_of_set_bits(0x00000000), 0);
  assert_equal_hex(count_number_of_set_bits(0x00000003), 2);
}

int main(void) {
  run_types_exercise();
  run_get_cube();
  run_bitwise_exercises();
  run_coordinates_exercise();
  run_time_converter();
  run_echo_exercise();
  run_recursive_print();

  return 0;
}
