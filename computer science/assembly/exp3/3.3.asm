; multi-segment executable file template.

data segment
    ; add your data here!
    pkey db "press any key...$"
    x dw 9274
    y dw 7381
    z dw -5621
    v dw 7321
    temp dw ?, ?
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

    mov ax, x
    imul y
    ; dx,ax := x * y
    add ax, z
    adc dx, 0
    ; dx,ax := x * y + z
    sub ax, 540
    sbb dx, 0
    ; dx,ax := x * y + z - 540
    mov temp, ax
    mov temp + 2, dx
    ; temp := x * y + z - 540
    mov ax, v
    cwd
    ; dx,ax := v
    sub ax, temp
    sbb dx, temp + 2
    ; dx,ax := v - (x * y + z - 540)
    idiv x 
                    
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
