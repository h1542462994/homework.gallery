; multi-segment executable file template.

data segment
    ; add your data here!
    pkey db "press any key...$"
    grade_store db 9,76,69,84,73,88,99,63,100,80
    s6 db 0
    s7 db 0
    s8 db 0
    s9 db 0
    s10 db 0 
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

    call calculate
    call print_number
            
    lea dx, pkey
    mov ah, 9
    int 21h        ; output string at ds:dx
    
    ; wait for any key....    
    mov ah, 1
    int 21h
    
    mov ax, 4c00h ; exit to operating system.
    int 21h

calculate:
    pushf
    push dx
    push cx
    mov dx, 1
    mov cx, 2
add_calculate:
    mov al, cl
    mov ah, al
    inc ah ; ah = n + 1, al = n
    mul ah ; ax = ah * al
    add dx, ax 
    inc cx
    cmp ax, 200
    jna add_calculate
    mov ax, dx
    pop cx
    pop dx
    popf
    ret
; 子模块，输入(AX)，输出为屏幕。
print_number:
    ; 保存数据
    pushf
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
    popf
    ret    
ends

end start ; set entry point and stop the assembler.
