; multi-segment executable file template.

data segment
    ; strings
    pkey db "press any key...$"
    tip1 db "please input string1:$"
    tip2 db "please input string2:$"
    
    enter_key db 0dh, 0ah, "$"
    match db "match$"
    no_match db "no match$"
    ; datas
    max_len equ 120
    string1 max_len dup(?)
    len1 db 0
    len2 db 0
ends
   
extra segment
    string2 max_len dup(?)
ends
   
stack segment
    dw   128  dup(0)
ends

code segment
start:
; set segment registers:
    mov ax, data
    mov ds, ax
    mov ax, extra
    mov es, ax
    
    ; 初始化
    mov cx, 0
    mov si, 0
    mov di, 0

    ; module:输入模块
    lea dx, tip1
    mov ah, 9
    int 21h
    lea bx, string1 ;基址
input1_loop: 
    ; 键入一个字符
    mov ah, 1
    int 21h
    
    cmp al, 0dh ;判断是否为enter
    jz input2
    
    cmp al, 08h ;判断是否是退格键
    jz back1
    mov ds:[bx][si], al
    inc si
    jmp input1_loop
back1:
    dec si
    jmp input1_loop    

    
input2:
    mov dl, 0ah ;跳出循环时补足一个LF。
    mov ah, 2
    int 21h ;调用输出字符的功能
    
    lea dx, tip2
    mov ah, 9
    int 21h
    lea bx, string2
input2_loop:
    mov ah, 1
    int 21h
    
    cmp al, 0dh
    jz input_out
    
    cmp al, 08h ;判断是否是退格键
    jz back2
    mov es:[bx][di],al
    inc di
    jmp input2_loop
back2:
    dec di
    jmp input2_loop
input_out:
    mov dl, 0ah ;跳出循环时补足一个LF。
    mov ah, 2
    int 21h ;调用输出字符的功能        
    
    ; 判断长度是否相等
    mov ax, si
    sub ax, di
    cmp ax, 0
    jnz show_noequal
    
    mov cx, si ; si为比较次数
    lea si, string1
    lea di, string2
cmp_loop:
    cmpsb
    loop cmp_loop

    jz show_equal
    
show_noequal:
    lea dx, no_match
    jmp show_out
show_equal:
    lea dx, match
show_out:
    mov ah, 9
    int 21h
        
    lea dx, enter_key
    mov ah, 9
    int 21h
           
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
