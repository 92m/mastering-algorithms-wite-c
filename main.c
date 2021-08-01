#include "utils.h"
#include <stdio.h>


int main(int argc, char** argv) {

  int x = 1000;
  int y = 1;
  float fc; 
  float fa; 
  float fr;

  swap2(&x, &y, 100);

  fc = 12.12;

  fa = 0.1;

  fr = fa * y * fc; 

  printf("x = %d;\n", x); 

  printf("y = %d;\n", y); 

  printf("The program is over. \n"); 

  printf("结果 = %f\n",  fr); 

  printf("fact res = %d;\n", fact(3)); 

  return 0;
}
