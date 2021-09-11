/* stack.c */\
#include <stdlib.h>

#include "list.h"
#include "stack.h"

/* stack_push */
int  stack_push(Stack *stack, const void *data) {
  /* Push the data onto this stack. */
  return list_ins_next(stack, NULL, data);
}

/* stack_pop */
int stack_pop (Stack *stack, void **data) {
  return list_rem_next(stack, NULL, data);
}