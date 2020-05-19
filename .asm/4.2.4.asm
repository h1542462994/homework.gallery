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
    mov ax, 6466h ; ax = d,f
    mov word ptr [prline+5], ax
    
           
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
