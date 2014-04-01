#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM_OPS 100

#define ADD '+'
#define SUB '-'
#define MUL '*'
#define DIV '/'
#define RES '='
#define KRED  "\x1B[31m" /* error color */
/* operation */

struct {
  char operator;
  int operand;
} operations[MAX_NUM_OPS];

int count = 0;

int main(int argc, const char *argv[])
{
  FILE *fin = stdin, *fout = stdout;

  int i, result = 0;

  if (argc >= 2)
    fin = fopen(argv[1], "r");

  if (fin == NULL) {
    perror("fopen");
    return 1;
  }

  if (argc == 3) {
    fout = fopen(argv[2], "w");
  }

  if (fout == NULL) {
    perror("fopen");

    return 1;
  }

  for (;;) {
    fscanf(fin, "%c", &(operations[count].operator));
    switch (operations[count].operator) {
      case ADD:
        fscanf(fin, "%d\n", &(operations[count].operand));
        break;
      case SUB:
        fscanf(fin, "%d\n", &(operations[count].operand));
        break;
      case MUL:
        fscanf(fin, "%d\n", &(operations[count].operand));
        break;
      case DIV:
        fscanf(fin, "%d\n", &(operations[count].operand));
        break;
      case RES:
        break;
      default:
        fprintf(stderr, "%sSyntax error: Unknown operator %c\n", KRED, operations[count].operator);
        return 2;
    }
    count++;

    if ( (count >= MAX_NUM_OPS) || (operations[count-1].operator == RES) ) break;
  }
  if (operations[count-1].operator != RES) {
    fprintf(stderr, "%sSyntax errors: Missing '=' statement\n", KRED);
    return 2;
  }

  for (i = 0; i < count; i++) {
    switch (operations[i].operator) {
      case ADD:
        result += operations[i].operand;
        break;
      case SUB:
        result -= operations[i].operand;
        break;
      case MUL:
        result *= operations[i].operand;
        break;
      case DIV:
        result /= operations[i].operand;
        break;
      case RES:
        printf("Calculated result is %d\n", result);
        break;
    }
  }
  return 0;
}

