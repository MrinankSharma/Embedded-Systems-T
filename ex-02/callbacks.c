#include <stdio.h>

// TODO: Define callback type for functions like "first" and "second" below.
typedef void (*callbackt)(void);
// TODO: Create storage for callbacks.
#define CALLBACK_STORAGE_SIZE 10

callbackt callback_storage[CALLBACK_STORAGE_SIZE];

void event_occurred(void) {
  // TODO: Implement callback execution.
  for(int i=0; i < CALLBACK_STORAGE_SIZE; i++){
    if(callback_storage[i]){
      (*(callback_storage[i]))();
    }
  }
}

void add_callback(callbackt callback) {
  // TODO: Add callback to created storage.
  for(int i=0; i< CALLBACK_STORAGE_SIZE; i++){
    if (!callback_storage[i]){
      callback_storage[i] = callback;
      break;
    }
  }
}

void remove_callback(callbackt callback) {
  // TODO: Remove callback from storage.
  for(int i=0; i< CALLBACK_STORAGE_SIZE; i++){
    if(callback_storage[i] == callback){
      callback_storage[i] = NULL;
      break;
    }
  }
}

void first(void) {
  puts("first");
}

void second(void) {
  puts("second");
}

void run_callbacks_exercise(void) {
  puts("Callback exercises");
  puts("------------------------------\n");
  add_callback(first);
  add_callback(second);
  event_occurred();
  remove_callback(second);
  event_occurred();
  puts("\n");
}
