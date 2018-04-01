SECTION .TEXT
	GLOBAL Add_s
	GLOBAL Subtract
	GLOBAL Multiply
	GLOBAL Divide



Add_s:
                    push rbp				;backup RBP
                    mov rbp, rsp			;reset RBP to current RSP
                    adc rdi, rsi                        ;execute
                    mov rax, rdi			;put return value into rax
                    mov rsp, rbp			;move RBP to RSP
                    pop rbp				;restore RBP
                    RET	                                ;return from the function

Subtract: ;this function do rdi(first arg)-rsi(second arg)
                    push rbp				;backup RBP
                    mov rbp, rsp			;reset RBP to current RSP
                    sbb rdi, rsi                        ;execute
                    mov rax, rdi			;put return value into rax
                    mov rsp, rbp			;move RBP to RSP
                    pop rbp				;restore RBP
                    RET	 
Multiply:
                    push rbp				;backup RBP
                    mov rbp, rsp			;reset RBP to current RSP
                    imul rdi, rsi                      ;execute--for bignum need to change
                    mov rax, rdi			;put return value into rax
                    mov rsp, rbp			;move RBP to RSP
                    pop rbp				;restore RBP
                    RET	 
Divide:
                    push rbp				;backup RBP
                    mov rbp, rsp			;reset RBP to current RSP
			xor rdx, rdx
			mov rax, rsi
			mov rcx, rdi
			idiv qword rcx
                    ;div rdi, rsi                       ;execute--for bignum need to change
                    ;mov rax, rdi			;put return value into rax
                    mov rsp, rbp			;move RBP to RSP
                    pop rbp				;restore RBP
                    RET	 
