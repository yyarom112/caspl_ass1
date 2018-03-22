// Implement a post-fix calculator using a stack.
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#define MAX_ELEMENTS 100
#define ROGUE_VALUE -99999

typedef int stackdata_t;
typedef struct{
  int top;
  stackdata_t SA[MAX_ELEMENTS];
} arrstack_t;

arrstack_t* init_stack();
stackdata_t evaluate_expression(const char const*, size_t);
stackdata_t pop(arrstack_t*);
bool push(arrstack_t*, stackdata_t);
bool empty(arrstack_t*);
bool full(arrstack_t*);
void printstack(arrstack_t*);
int gettoken(const char const*, int);

int main(){
  char buf[20];
  char expression[20];
  char *prompt = "Enter a postfix expression: ";
  stackdata_t d;
  size_t strlength;

  printf("%s", prompt);
  fgets(buf, sizeof buf, stdin);
  sscanf(buf, "%[a-zA-Z0-9 +-*/]s", expression);

  strlength = strlen(expression);
  d = evaluate_expression(expression, strlength);
  printf("Expression value: %d\n", d);

  return 0;
}

arrstack_t*  init_stack(){
  arrstack_t *s = malloc(sizeof *s);
  s->top = -1;
  return s;
}

stackdata_t evaluate_expression(const char const *expression, size_t strlength){
  printf("The expression: %s\n", expression);
  int startpos = 0;
  int endpos = 0;
  char token[10];
  arrstack_t *stack = init_stack();
  stackdata_t n, m;
  while(endpos < strlength){
    endpos = gettoken(expression, startpos);
    strncpy(token, expression + startpos, endpos - startpos);
    //printf("Token: %s\n", token);

    // Push digits, pop for operations.
    if(sscanf(token, "%d", &n)){
      push(stack, n);
    }
    else{
      m = pop(stack);
      n = pop(stack);
      if(strncmp(token, "+", 1) == 0){
        push(stack, n+m);
      }
      else if(strncmp(token, "-", 1) == 0){
        push(stack, n-m);
      }
      else if(strncmp(token, "/", 1) == 0){
        push(stack, n/m);
      }
      else {
        push(stack, n*m);
      }
    }
    startpos = endpos+1;
    memset(token, '\0', sizeof token);
  }
  n = pop(stack);
  return n;
}

int gettoken(const char const *exp_str, int i){
  char c = exp_str[i];
  while (c != ' ' && c != '\0'){
    i++;
    c = exp_str[i];
  }
  return i;
}

stackdata_t pop(arrstack_t *stack){
  stackdata_t d;
  if(empty(stack)){
    d = ROGUE_VALUE;
  }
  else{
    d = stack->SA[stack->top];
    stack->top--;
  }
  return d;
}

bool push(arrstack_t *stack, stackdata_t data){
  if(full(stack)){
    return false;
  }
  else{
    stack->top++;
    stack->SA[stack->top] = data;
    return true;
  }
}

bool empty(arrstack_t *stack){
  return stack->top == -1;
}

bool full(arrstack_t *stack){
  return stack->top == (MAX_ELEMENTS-1);
}

void printstack(arrstack_t *stack){
  stackdata_t d;
  while(!empty(stack)){
    d = pop(stack);
    printf("%d\n", d);
  }
}
