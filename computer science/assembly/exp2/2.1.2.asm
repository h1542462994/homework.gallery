; multi-segment executable file template.

data segment
    ; add your data here!
    pkey db "press any key...$"
    a db 13
    b db 11
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

    ; add your code here
    mov al, a
    mov bl, b
    mov ah, al
    add ah, bl
    and ah, 1 ; justify if the a+b is odd.
    jnz branch  ; jmp is a+b is odd.
    ; a+b is odd
    mov ah, al
    and ah, 1 ; ah will store if a is odd.
    add al, ah
    add bl, ah
    mov a, al
    mov b, bl
    jmp exit
branch:
    test bl, 1 ; justify if b is odd
    jz exit  ;jmp if b is even
    ; execute if a is even, b is odd.
    mov a, bl
    mov b, al
exit:       
    ; wait for any key....    
    mov ah, 1
    int 21h
    
    mov ax, 4c00h ; exit to operating system.
    int 21h    
ends

end start ; set entry point and stop the assembler.
