; multi-segment executable file template.

data segment
    ; add your data here!
    pkey db "press any key...$"
    numbers db -4,6,7,-8,12,14,17,-9,-8,20,18,-3,-5,7,27,32,84,-7,-2,6
    number_len equ $-numbers
    
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
    
    mov si, 0
    mov di, number_len - 1 ; 分别指向第一个和最后一个元素
judge_1:
    cmp si, di
    ja print_p_count ; si > di 则直接跳到输出
    cmp numbers[si], 0
    jng judge_2 ; numbers[si] <= 0 则进入下一层判断
    inc si
    jmp judge_1
judge_2:
    cmp si, di
    ja print_p_count ; si > di 则直接跳到输出
    cmp numbers[di], 0
    jg do_swap ; numbers[di] > 0 则进入交换
    dec di
    jmp judge_2
do_swap:
    mov al, numbers[si] ; al(1) <- numbers[si]
    push ax
    mov al, numbers[di] ; al(2) <- numbers[di]
    mov numbers[si], al ; numbers[si] <- al(2)
    pop ax
    mov numbers[di], al ; numbers[di] <- al(1)
    inc si
    dec di
    jmp judge_1
               
print_p_count:
    mov ax, si
    call print_number ; 输出正数的个数
    push ax
    mov dl, 20h
    mov ah, 2
    int 21h ; 输出一个空格
    pop ax
    xor ax, 0ffffh
    inc ax
    add ax, number_len
    call print_number ; 输出负数的个数
    
    mov dl, 0dh
    mov ah, 2
    int 21h
    mov dl, 0ah
    mov ah, 2
    int 21h
    
    mov cx, number_len
    lea si, numbers
    
loop_print:
    lodsb
    cbw ; 将字节扩展至字
    call print_number_flag ; 输出当前的数字
    mov dl, 20h
    mov ah, 2
    int 21h
    loop loop_print 
            
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
    push ax
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
    pop ax
    ret    
    
; 子模块，无符号数以10进制显示，输入(AX,数字)，输出(Console)。
print_number:
    ; 保存数据
    push ax
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
    pop ax
    ret    
ends

end start ; set entry point and stop the assembler.
