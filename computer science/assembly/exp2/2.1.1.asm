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
    test al, 1 ; justify whether the al is odd
    jz branch ; jump to branch is al is even.
    test bl, 1 ; justify whether the bl is odd.
    jz exit ; jump to exit is al & bl is eve.
    ; the code will be excuted if al & bl is odd.
    inc al
    inc bl
    mov a, al
    mov b, bl
    jmp exit ; to the exit
branch:
    test bl, 1
    jz exit ; jump to exit is al & bl is even.
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
