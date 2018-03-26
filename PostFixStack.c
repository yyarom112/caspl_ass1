//
// Created by weilern on 22/03/18.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
 * the addition code from the ass instructions
typedef struct bignum {
    long number_of_digits;
    char *digit;
} bignum;
*/
#define MAX_SIZE 1024
#define error_sign -999999
typedef int st_arg;

typedef struct {
    int top;
    st_arg SA[MAX_SIZE];
} pfStack;

//TODO - all the funs that return int -> 0=false , 1=true;
//the funcs declaration
int push(pfStack *, st_arg);

st_arg pop(pfStack *);

int is_empty(pfStack *);

int is_full(pfStack *);

st_arg calculate(const char const *, size_t);

pfStack *init_Stack();

//the funcs implements
int push(pfStack *stack, st_arg input) {
    if (is_full(stack))
        return 0;
    stack->top++;
    stack->SA[stack->top] = input;
    return 1;
}

int is_full(pfStack *pfStack1) {
    if (pfStack1->top == MAX_SIZE - 1)
        return 1;
    return 0;
}

int is_empty(pfStack *pfStack1) {
    if (pfStack1->top == -1)
        return 1;
    return 0;
}



st_arg pop(pfStack *pfStack1) {
    st_arg output;
    if (!is_empty(pfStack1)) {
        output = pfStack1->SA[pfStack1->top];
        pfStack1->top--;
    } else
        output = error_sign;
    return output;
}

st_arg calc(pfStack *pfStack1) {
    st_arg a, b, output;
    char action;
    //while there are more then 1 argument
    while (pfStack1->top > 1) {
        a = pop(pfStack1);
        b = pop(pfStack1);
        action = pop(pfStack1);
        switch (action) {
            case '*':
                push(pfStack1, a * b);
                break;
            case '+':
                push(pfStack1, a + b);
                break;
            case '-':
                push(pfStack1, a - b);
                break;
            case '/':
                push(pfStack1, a / b);
                break;
            default:
                break;
        }
    }
    output = pop(pfStack1);
    return output;

}

pfStack *init_Stack() {
    pfStack *s = malloc(sizeof *s);
    s->top = -1;
    return s;
}

//TODO - to yuval - I made the stack initial in the main, and not in separate
//TODO   func because of the need to get the information from a file
int main(int argc, char **argv) {
    int a,b,is_minus=0,num=0, need_to_insert=0;
    //char inputText[1024];
    char tmp;
    pfStack* st=init_Stack();
    //FILE * text=fopen(argv[i],"r");
    FILE * text=fopen("/home/weilern/CLionProjects/archiAss1/input.txt","r");
            //check  that able to read from the file
            if(text == NULL) {
                perror("Error opening file");
                return(-1);
            }
    tmp= (char) fgetc(text);

    while(tmp!=EOF) {
        switch (tmp) {
            case '1':
                num = num * 10 + 1;
                need_to_insert = 1;
                break;
            case '2':
                num = num * 10 + 2;
                need_to_insert = 1;
                break;
            case '3':
                num = num * 10 + 3;
                need_to_insert = 1;
                break;
            case '4':
                num = num * 10 + 4;
                need_to_insert = 1;
                break;
            case '5':
                num = num * 10 + 5;
                need_to_insert = 1;
                break;
            case '6':
                num = num * 10 + 6;
                need_to_insert = 1;
                break;
            case '7':
                num = num * 10 + 7;
                need_to_insert = 1;
                break;
            case '8':
                num = num * 10 + 8;
                need_to_insert = 1;
                break;
            case '9':
                num = num * 10 + 9;
                need_to_insert = 1;
                break;
            case '0':
                num = num * 10 + 0;
                need_to_insert = 1;
                break;

                //minus case
            case '_':
                is_minus = 1;
                break;

                //space cases
            case ' ':
                if (need_to_insert == 1){
                    if (is_minus == 1)
                        num *= -1;
                    push(st,num);
                }
                num = 0;
                is_minus = 0;
                need_to_insert = 0;
                break;
            case '\t':
                if (need_to_insert == 1){
                    if (is_minus == 1)
                        num *= -1;
                    push(st,num);
                }
                num = 0;
                is_minus = 0;
                need_to_insert = 0;
                break;

                //operator cases
            case '+':
                //case the the + comes right after an int example: 8+
                if (need_to_insert == 1){
                    if (is_minus == 1)
                        num *= -1;
                    push(st,num);
                }
                //do the math
                a=pop(st);
                b=pop(st);
                push(st,a+b);
                //reset for the next iteration
                num = 0;
                is_minus = 0;
                need_to_insert = 0;
                break;
            case '-':
                if (need_to_insert == 1){
                    if (is_minus == 1)
                        num *= -1;
                    push(st,num);
                }
                //do the math
                a=pop(st);
                b=pop(st);
                push(st,a-b);
                //reset for the next iteration
                num = 0;
                is_minus = 0;
                need_to_insert = 0;
                break;
            case '*':
                if (need_to_insert == 1){
                    if (is_minus == 1)
                        num *= -1;
                    push(st,num);
                }
                //do the math
                a=pop(st);
                b=pop(st);
                push(st,a*b);
                //reset for the next iteration
                num = 0;
                is_minus = 0;
                need_to_insert = 0;
                break;
            case '/':
                if (need_to_insert == 1){
                    if (is_minus == 1)
                        num *= -1;
                    push(st,num);
                }
                //do the math
                a=pop(st);
                b=pop(st);
                push(st,a/b);
                //reset for the next iteration
                num = 0;
                is_minus = 0;
                need_to_insert = 0;
                break;
            default:
                num = 0;
                is_minus = 0;
                need_to_insert = 0;
                break;
        }
        tmp = (char) fgetc(text);
    }
    printf("%d\n",pop(st));


    /*FILE *output;
    char inputText[1024];
    int j = 0, i = 0, num = 0;
    int is_minus = 0, need_to_insert = 0;
    pfStack *a = init_Stack();
    output = fopen(argv[i], "r");
    if (output == NULL) {
        perror("Error opening file");
        return (-1);
    }
    char tmp;
    for (; i < argc; i++) {
        tmp = (char) fgetc(output);
        //switch (tmp)
        // digits cases
        if (tmp == '1') {
            num = num * 10 + 1;
            need_to_insert = 1;
        }
        if (tmp == '2') {
            num = num * 10 + 2;
            need_to_insert = 1;
        }
        if (tmp == '3') {
            num = num * 10 + 3;
            need_to_insert = 1;
        }
        if (tmp == '4') {
            num = num * 10 + 4;
            need_to_insert = 1;
        }
        if (tmp == '5') {
            num = num * 10 + 5;
            need_to_insert = 1;
        }
        if (tmp == '6') {
            num = num * 10 + 6;
            need_to_insert = 1;
        }
        if (tmp == '7') {
            num = num * 10 + 7;
            need_to_insert = 1;
        }
        if (tmp == '8') {
            num = num * 10 + 8;
            need_to_insert = 1;
        }
        if (tmp == '9') {
            num = num * 10 + 9;
            need_to_insert = 1;
        }
        if (tmp == '0') {
            num = num * 10 + 0;
            need_to_insert = 1;
        }

        if (tmp == '_') {
            is_minus = 1;
        }

        //spaces
        if (tmp == ' ') {
            if (is_minus == 1)
                num *= -1;
            if (need_to_insert == 1) {
                inputText[j] = num;
                j++;
            }
            num = 0;
            is_minus = 0;
            need_to_insert = 0;
        }
        if (tmp == '\t') {
            if (is_minus == 1)
                num *= -1;
            if (need_to_insert == 1) {
                inputText[j] = num;
                j++;
            }
            num = 0;
            is_minus = 0;
            need_to_insert = 0;
        }

        //operator cases
        if (tmp == '+') {
            if (is_minus == 1)
                num *= -1;
            if (need_to_insert == 1) {
                inputText[j] = num;
                j++;
            }
            inputText[j] = '+';
            j++;
            num = 0;
            is_minus = 0;
            need_to_insert = 0;
        }
        if (tmp == '-') {
            if (is_minus == 1)
                num *= -1;
            if (need_to_insert == 1) {
                inputText[j] = num;
                j++;
            }
            inputText[j] = '-';
            j++;
            num = 0;
            is_minus = 0;
            need_to_insert = 0;
        }
        if (tmp == '*') {
            if (is_minus == 1)
                num *= -1;
            if (need_to_insert == 1) {
                inputText[j] = num;
                j++;
            }
            inputText[j] = '*';
            j++;
            num = 0;
            is_minus = 0;
            need_to_insert = 0;
        }
        if (tmp == '/') {
            if (is_minus == 1)
                num *= -1;
            if (need_to_insert == 1) {
                inputText[j] = num;
                j++;
            }
            inputText[j] = '/';
            j++;
            num = 0;
            is_minus = 0;
            need_to_insert = 0;
        }
*/
/*            case '3':
                num = num * 10 + 3;
                need_to_insert = 1;
                break;
            case '4':
                num = num * 10 + 4;
                need_to_insert = 1;
                break;
            case '5':
                num = num * 10 + 5;
                need_to_insert = 1;
                break;
            case '6':
                num = num * 10 + 6;
                need_to_insert = 1;
                break;
            case '7':
                num = num * 10 + 7;
                need_to_insert = 1;
                break;
            case '8':
                num = num * 10 + 8;
                need_to_insert = 1;
                break;
            case '9':
                num = num * 10 + 9;
                need_to_insert = 1;
                break;
            case '0':
                num = num * 10 + 0;
                need_to_insert = 1;
                break;
                //minus case
            case '_':
                is_minus = 1;
                break;
                //space cases
            case ' ':
                if (is_minus == 1)
                    num *= -1;
                if (need_to_insert == 1) {
                    inputText[j] = num;
                    j++;
                }
                num = 0;
                is_minus = 0;
                need_to_insert=0;
                break;
            case '\t':
                if (is_minus == 1)
                    num *= -1;
                if (need_to_insert == 1) {
                    inputText[j] = num;
                    j++;
                }
                num = 0;
                is_minus = 0;
                need_to_insert=0;
                break;
                //operator cases
            case '+':
                if (is_minus == 1)
                    num *= -1;
                if (need_to_insert == 1) {
                    inputText[j] = num;
                    j++;}
                inputText[j] = '+';
//
// Created by weilern on 22/03/18.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
 * the addition code from the ass instructions
typedef struct bignum {
    long number_of_digits;
    char *digit;
} bignum;
*/
#define MAX_SIZE 1024
#define error_sign -999999
typedef int st_arg;

typedef struct {
    int top;
    st_arg SA[MAX_SIZE];
} pfStack;

//TODO - all the funs that return int -> 0=false , 1=true;
//the funcs declaration
int push(pfStack *, st_arg);

st_arg pop(pfStack *);

int is_empty(pfStack *);

int is_full(pfStack *);

st_arg peek(pfStack *);

st_arg calculate(const char const *, size_t);

pfStack *init_Stack();

void clear_the_stack(pfStack *);

//the funcs implements
int push(pfStack *stack, st_arg input) {
    if (is_full(stack))
        return 0;
    stack->top++;
    stack->SA[stack->top] = input;
    return 1;
}

int is_full(pfStack *pfStack1) {
    if (pfStack1->top == MAX_SIZE - 1)
        return 1;
    return 0;
}

int is_empty(pfStack *pfStack1) {
    if (pfStack1->top <= -1)
        return 1;
    return 0;
}

st_arg  peek(pfStack *pfStack1){
    return pfStack1->SA[pfStack1->top];
}

void clear_the_stack(pfStack *pfStack1){
    while(!is_empty(pfStack1))
        pop(pfStack1);
}

st_arg pop(pfStack *pfStack1) {
    st_arg output;
    if (!is_empty(pfStack1)) {
        output = pfStack1->SA[pfStack1->top];
        pfStack1->top--;
    } else
        output = error_sign;
    return output;
}

st_arg calc(pfStack *pfStack1) {
    st_arg a, b, output;
    char action;
    //while there are more then 1 argument
    while (pfStack1->top > 1) {
        a = pop(pfStack1);
        b = pop(pfStack1);
        action = pop(pfStack1);
        switch (action) {
            case '*':
                push(pfStack1, a * b);
                break;
            case '+':
                push(pfStack1, a + b);
                break;
            case '-':
                push(pfStack1, a - b);
                break;
            case '/':
                push(pfStack1, a / b);
                break;
            default:
                break;
        }
    }
    output = pop(pfStack1);
    return output;

}

pfStack *init_Stack() {
    pfStack *s = malloc(sizeof *s);
    s->top = -1;
    return s;
}



//TODO - to yuval - I made the stack initial in the main, and not in separate
//TODO   func because of the need to get the information from a file
int main(int argc, char **argv) {
    int a,b,is_minus=0,num=0, need_to_insert=0;
    //char inputText[1024];
    char tmp;
    pfStack* st=init_Stack();
    //FILE * text=fopen(argv[i],"r");
    FILE * text=fopen("/home/weilern/CLionProjects/archiAss1/input.txt","r");
            //check  that able to read from the file
            if(text == NULL) {
                perror("Error opening file");
                return(-1);
            }
    tmp= (char) fgetc(text);

    while(tmp!=EOF) {
        switch (tmp) {
            case '1':
                num = num * 10 + 1;
                need_to_insert = 1;
                break;
            case '2':
                num = num * 10 + 2;
                need_to_insert = 1;
                break;
            case '3':
                num = num * 10 + 3;
                need_to_insert = 1;
                break;
            case '4':
                num = num * 10 + 4;
                need_to_insert = 1;
                break;
            case '5':
                num = num * 10 + 5;
                need_to_insert = 1;
                break;
            case '6':
                num = num * 10 + 6;
                need_to_insert = 1;
                break;
            case '7':
                num = num * 10 + 7;
                need_to_insert = 1;
                break;
            case '8':
                num = num * 10 + 8;
                need_to_insert = 1;
                break;
            case '9':
                num = num * 10 + 9;
                need_to_insert = 1;
                break;
            case '0':
                num = num * 10 + 0;
                need_to_insert = 1;
                break;

                //minus case
            case '_':
                is_minus = 1;
                break;

                //space cases
            case ' ':
                if (need_to_insert == 1){
                    if (is_minus == 1)
                        num *= -1;
                    push(st,num);
                }
                num = 0;
                is_minus = 0;
                need_to_insert = 0;
                break;
            case '\t':
                if (need_to_insert == 1){
                    if (is_minus == 1)
                        num *= -1;
                    push(st,num);
                }
                num = 0;
                is_minus = 0;
                need_to_insert = 0;
                break;
            case '\n':
                if (need_to_insert == 1){
                    if (is_minus == 1)
                        num *= -1;
                    push(st,num);
                }
                num = 0;
                is_minus = 0;
                need_to_insert = 0;
                break;

                //operator cases
            case '+':
                //case the the + comes right after an int example: 8+
                if (need_to_insert == 1){
                    if (is_minus == 1)
                        num *= -1;
                    push(st,num);
                }
                //do the math
                a=pop(st);
                b=pop(st);
                push(st,a+b);
                //reset for the next iteration
                num = 0;
                is_minus = 0;
                need_to_insert = 0;
                break;
            case '-':
                if (need_to_insert == 1){
                    if (is_minus == 1)
                        num *= -1;
                    push(st,num);
                }
                //do the math
                a=pop(st);
                b=pop(st);
                push(st,b-a);
                //reset for the next iteration
                num = 0;
                is_minus = 0;
                need_to_insert = 0;
                break;
            case '*':
                if (need_to_insert == 1){
                    if (is_minus == 1)
                        num *= -1;
                    push(st,num);
                }
                //do the math
                a=pop(st);
                b=pop(st);
                push(st,a*b);
                //reset for the next iteration
                num = 0;
                is_minus = 0;
                need_to_insert = 0;
                break;
            case '/':
                if (need_to_insert == 1){
                    if (is_minus == 1)
                        num *= -1;
                    push(st,num);
                }
                //do the math
                a=pop(st);
                b=pop(st);
                push(st,a/b);
                //reset for the next iteration
                num = 0;
                is_minus = 0;
                need_to_insert = 0;
                break;

                //special chars cases
            case 'p':
                if (need_to_insert == 1){
                    if (is_minus == 1)
                        num *= -1;
                    push(st,num);
                }
                printf("%d\n",peek(st));
                //reset for the next iteration
                num = 0;
                is_minus = 0;
                need_to_insert = 0;
                break;
            case 'c':
                if (need_to_insert == 1){
                    if (is_minus == 1)
                        num *= -1;
                    push(st,num);
                }
                clear_the_stack(st);
                //reset for the next iteration
                num = 0;
                is_minus = 0;
                need_to_insert = 0;
                break;
//TODO - what does they meant when written- return underlying shell
            case 'q':
                exit(0);


            default:
                num = 0;
                is_minus = 0;
                need_to_insert = 0;
                break;
        }
        tmp = (char) fgetc(text);
    }
    printf("is the stack is empty->%i\n",is_empty(st));
    printf("%d\n",pop(st));
    printf("is the stack is empty->%i\n",is_empty(st));
    fclose(text);
    return 0;
}




