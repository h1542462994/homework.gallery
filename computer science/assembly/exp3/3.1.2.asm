; multi-segment executable file template.

data segment
    ; add your data here!
    pkey db "press any key...$"
    datax dw 9148h, 8316h
    datay dw 1237h, 8252h
    sumword dw ?
    sumdword dw ?, ?
    errormsg db "overflow exception...$"
    dwl equ 2
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

    mov ax, datax
    add ax, datay
    mov dx, datax + dwl
    adc dx, datay + dwl
    mov sumdword, ax
    mov sumdword + dwl, dx
    
    ; jump is not overflow
    jnc after
    
    lea dx, errormsg
    mov ah, 9
    int 21h ; call the system method (pring string)
after:                
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
