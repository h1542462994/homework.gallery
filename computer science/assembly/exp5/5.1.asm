; multi-segment executable file template.

data segment
    ; add your data here!
    pkey db "press any key...$"
    buf db "HeLloWorLd"
    buf_len equ $-buf
    numbers db "0123456789"
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

    ; 初始化
    mov cx, buf_len
    lea si, buf
    lea di, buf
    mov ah, 0

; 计数循环体    
cal_character:
    lodsb ; 读取一个字符
    cmp al,61h 
    jb sto_buf ; 与61H(a)比较，若<61H(a)，则跳到sto_buf处。
    cmp al,7ah
    ja sto_buf ; 与7AH(z)比较，若>7AH(z)，则跳到sto_buf处。
    ; 执行小写转大写代码，并计数
    sub al,20h
    inc ah
sto_buf:
    stosb ; 写入一个字符
    loop cal_character
    
    ; 输出ah
    ; 最大值为10，当ah=10时输出10，ah<10时，输出"30H+al"(转化为字符串)
    cmp ah, 10
    jb print_branch
    mov dl, 31h ;输出字符1
    mov ah, 2
    int 21h
    mov dl, 30h
    int 21h
    jmp out_print      
print_branch:
    add ah, 30h
    mov dl, ah
    mov ah, 2
    int 21h          
out_print:
            
    lea dx, pkey
    mov ah, 9
    int 21h        ; output string at ds:dx
    
    ; wait for any key....    
    mov ah, 1
    int 21h
    
    mov ax, 4c00h ; exit to operating system.
    int 21h    
ends

end start ; set entry point and stop the assembler.
