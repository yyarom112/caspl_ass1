//
// Created by weilern on 22/03/18.
//

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
}pfStack;

//the funcs declaration
bool push(pfStack*, st_arg);
st_arg pop(pfStack*);
bool is_empty(pfStack*);
bool is_full(pfStack*);
bool last_arg(pfStack*);
st_arg calculate(const char const*, size_t);
pfStack* init_pfStack ();

//the funcs implements
bool push(pfStack* stack,st_arg input){
    if(is_full(stack))
        return false;
    top++;
    stack[top].SA[stack->top]=input;
    return true;
        }

bool is_full (pfStack* pfStack1){
    return pfStack1->top==MAX_SIZE-1;
}

bool is_empty(pfStack* pfStack1){
    return pfStack1->top==0;
}

bool last_arg (pfStack* pfStack1){
    return pfStack1->top==1;
}

st_arg pop(pfStack* pfStack1){
    st_arg output;
    if(!is_empty(pfStack1)){
        output=pfStack1->SA[pfStack1->top];
        top--;
    }
    else
        output=error_sign;
    return output;
}

st_arg calculate(const char const* argument, size_t ,pfStack* pfStack1){
    st_arg a,b,output;
    char action;
    while(!last_arg(pfstack1)){
        a=pop(pfStack1);
        b=pop(pfStack1);
        action=pop(pfStack1);
        switch (action){
            case '+':
                push(pfStack1, a+b);
                break;
            case '-':
                push(pfStack1,a-b);
                break;
            case '*':
                push(pfStack1, a*b);
                break;
            case '/':
                push(pfStack1, a/b);
                break;
            default:
                break;
        }
    }
    output=pop(pfStack1);
    return output;

}

//TODO - to yuval - I made the stack initial in the main, and not in separate
//TODO   func because the need to get the information from a file
int main(int argc, char **argv) {

}

