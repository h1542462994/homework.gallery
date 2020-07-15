data segment
    ; add your data here!
    pkey db "press any key...$"
    datax dw 2316h
    datay dw 0237h
    dataz dw ?
    error_msg db "你的输入有误，请重新输入"
ends

stack segment
    dw   128  dup(0)
ends

code segment
start:
; set segment registers:
    mov ax, data
    mov ds, ax
    mov es, ax

loop_input:
    mov ah, 1
    int 21h ; 输入一个字符
    cmp al, 'A'
    jne judge_b
    call func_add ; 执行add操作
    jmp judge_out
judge_b:
    cmp al, 'B'
    jne judge_c
    call func_sub ; 执行sub操作
    jmp judge_out
judge_c:
    cmp al, 'C'
    jne judge_other
    call func_mul ; 执行mul操作
    jmp judge_out
judge_other:
    call func_other ; 执行其他操作
    jmp loop_input
judge_out:    
            
    lea dx, pkey
    mov ah, 9
    int 21h        ; output string at ds:dx
    
    ; wait for any key....    
    mov ah, 1
    int 21h
    
    mov ax, 4c00h ; exit to operating system.
    int 21h
func_add:
    push ax
    mov ax, datax
    add ax, datay
    mov dataz, ax
    pop ax
    ret
func_sub:
    push ax
    mov ax, datax
    sub ax, datay
    cmp ax, 0
    jge re
    xor ax, 0ffffh
    inc ax ; ax取反+1
re: 
    mov dataz, ax
    pop ax
    ret
func_mul:
    push ax
    push dx
    mov ax, datax
    mov dx, datay
    mul dx
    mov dataz, ax
    pop dx
    pop ax
    ret
func_other:
    lea dx, error_msg
    mov ah, 9
    int 21h
    ret
ends

end start