#include <stdio.h>

// TODO: Write fibonacci code as illustrated on exercise sheet.
int *reserve_memory(){
  return (int *) malloc(100 * sizeof(int));
}

void initialise_memory(int *data){
  int i;
  for (i = 0; i<100; i++){
    data[i] = 0;
  }
}

void manipulate_data(int *data){
  data[0] = 1;
  data[1] = 1;
  int i;
  for (i=2; i<100; ++i){
    data[i] = data[i-2] + data[i-1];
  }
}

void release_memory(int *data){
  free(data);
}


void run_malloc_free_exercise(void) {
  puts("Malloc/free exercises");
  puts("------------------------------\n");
  int *data = reserve_memory();
  manipulate_data(data);
  for (int i=0; i<100; i++){
    printf("%d", *(data+i));
  }
  // TODO: Print all generated Fibonacci values
  puts("\n\n");
  release_memory(data);
}

