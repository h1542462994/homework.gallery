; multi-segment executable file template.

data segment
    ; add your data here!
    pkey db "press any key...$"
    STATUS db 15h ; 00010101
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

    mov al, STATUS
    and al, 15h
    mov ah, 0
    mov cx, 8
; calculate the count of 1 in al
; and store the result to ah
calculate:
    shl al, 1 ; left move
    adc ah, 0 ; add with carry
    loop calculate
    cmp ah, 3h
    jz ROUTINE_1
    cmp ah, 2h
    jz ROUTINE_2
    cmp ah, 1h
    jz ROUTINE_3
    jmp ROUTINE_4   
    ; jmp exit
ROUTINE_1:
    mov bl, 3
    jmp exit
ROUTINE_2:
    mov bl, 2
    jmp exit
ROUTINE_3:
    mov bl, 1
    jmp exit
ROUTINE_4:
    mov bl, 0
    jmp exit    
exit:       
    ; wait for any key....    
    mov ah, 1
    int 21h
    
    mov ax, 4c00h ; exit to operating system.
    int 21h    
ends

end start ; set entry point and stop the assembler.
