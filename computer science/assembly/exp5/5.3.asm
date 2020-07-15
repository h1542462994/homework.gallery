; multi-segment executable file template.

data segment
    ; add your data here!
    pkey db "press any key...$"
    numbers dw -1324,-2875,-1230
    numbers_len db ($-numbers)/2
    number_width dw 2
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
    
    mov ch, 0
    mov cl, numbers_len ; cx为数字的个数
    lea si, numbers ; si执行第一个元素
    lodsw 
    dec cx ; 移动第一个元素到ax
    jcxz print_ax ; 如果只有一个数，则输出
loop_cmp_number:
    cmp ax, [si]
    jnl branch_cmp_number_out
    mov ax, [si] ; 当ax > [si] 进行比较
branch_cmp_number_out:
    add si, number_width  ; si 指向下一个元素
    loop loop_cmp_number
    
print_ax:
    call print_number_flag  
            
    lea dx, pkey
    mov ah, 9
    int 21h        ; output string at ds:dx
    
    ; wait for any key....    
    mov ah, 1
    int 21h
    
    mov ax, 4c00h ; exit to operating system.
    int 21h

; 子模块，有符号数以10进制显示，输入(AX,数字)，输出(Console)。
print_number_flag:
    push dx ; 暂存dx
    cmp ax, 0
    jge call_print_number 
    
    push ax ; 暂存ax
    mov dl, 2dh
    mov ah, 2
    int 21h ; 输出一个'-'(0x2d)字符
    ; 转化为相应的正数
    pop ax ; 恢复ax
    xor ax, 0ffffh ; 所有位取反
    inc ax ; +1 
call_print_number:
    call print_number
    pop dx
    ret    
    
; 子模块，无符号数以10进制显示，输入(AX,数字)，输出(Console)。
print_number:
    ; 保存数据
    push bx
    push cx
    push dx
    
    mov cx, 0
    mov bx, 10
    
loop_div_number:
    cmp ax, 0
    jz branch_show_number ; 如果ax!=0继续执行取数
    
    mov dx, 0 ; 扩展无符号数
    div bx ; 除10
    inc cx
    push dx ; 将中间的数字压入堆栈
    jmp loop_div_number ; 无条件循环，必须使用jmp
        
branch_show_number:
    cmp cx, 0
    jz print_number_0
    
loop_print_number:
    pop dx
    add dl, 30h
    mov ah, 2
    int 21h ; 输出堆栈中栈顶的数字    
    loop loop_print_number
    jmp print_number_out
print_number_0:
    mov dl, 30H
    mov ah, 2
    int 21h ; 输出字符'0'
        
print_number_out:
    ; 恢复数据
    pop dx
    pop cx
    pop bx
    ret    
ends

end start ; set entry point and stop the assembler.
