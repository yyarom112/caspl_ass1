SECTION .TEXT
	GLOBAL Add_s
	GLOBAL Subtract
	GLOBAL Multiply
	GLOBAL Divide





Add:
                    push rbp				;backup RBP
                    move rbp, rsp			;reset RBP to current RSP
                    move rbp, rsp			;reset RBP to current RSP
                    adc rdi, rsi                        ;execute
                    move rax, rdi			;put return value into rax
                    move rsp, rbp			;move RBP to RSP
                    pop rbp				;restore RBP
                    RET	                                ;return from the function

Subtract: ;this function do rdi(first arg)-rsi(second arg)
                    push rbp				;backup RBP
                    move rbp, rsp			;reset RBP to current RSP
                    move rbp, rsp			;reset RBP to current RSP
                    sbb rdi, rsi                        ;execute
                    move rax, rdi			;put return value into rax
                    move rsp, rbp			;move RBP to RSP
                    pop rbp				;restore RBP
                    RET	 
Multiply:
                    push rbp				;backup RBP
                    move rbp, rsp			;reset RBP to current RSP
                    move rbp, rsp			;reset RBP to current RSP
                    imult rdi, rsi                      ;execute--for bignum need to change
                    move rax, rdi			;put return value into rax
                    move rsp, rbp			;move RBP to RSP
                    pop rbp				;restore RBP
                    RET	 
Divide:
                    push rbp				;backup RBP
                    move rbp, rsp			;reset RBP to current RSP
                    move rbp, rsp			;reset RBP to current RSP
                    iDIV rdi, rsi                       ;execute--for bignum need to change
                    move rax, rdi			;put return value into rax
                    move rsp, rbp			;move RBP to RSP
                    pop rbp				;restore RBP
                    RET	 
