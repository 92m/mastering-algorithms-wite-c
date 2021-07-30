#include <stdio.h>
#include "utils.h"



int main(int argc, char** argv) {

  int x = 1000;
  int y = 1;

  swap(&x, &y);

  printf("x = %d;\n", x); 
  printf("y = %d;\n", y); 
  printf("The program is over. \n"); 
  return 0;
}