#include "3-calc.h"
/**
*
*/
int (*get_op_func(char *s))(int, int)
{
  op_t ops[] = {
      {"+", op_add},
      {"-", op_sub},
      {"*", op_mul},
      {"/", op_div},
      {"%", op_mod},
      {NULL, NULL}
  };
  int i;
  for(i=0; ops[i].op != NULL;i++)
    {
      if(*(ops[i].op) == *s && s[1]=='\0') /*to ensure that operator is a single character*/
        return(ops[i].f);
    }
    printf(" function error \n");
    exit(99);
}
