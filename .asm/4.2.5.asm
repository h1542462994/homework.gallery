; multi-segment executable file template.

data segment
    ; strings
    pkey db "press any key...$"
    coname db "SPACE EXPLORERS INCO"
    prline db 20 dup(' ')
    len equ $-prline
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
    
    ; the core code
    lea di, coname  ; di 指向 coname
    mov cx, len ; 循环次数（最大）
    mov al, ' ' ; 或者为20h
loop_cmp:
    scasb ; 将al与[di]比较，zf保存比较结果，然后di自增
    jz equal ; 如果包含空格，直接跳到equal段
    loop loop_cmp
    jmp out_cmp
equal: 
    ; 相等的逻辑
    lea bx, coname
out_cmp:
           
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
