; multi-segment executable file template.

data segment
    ; add your data here!
    pkey db "press any key...$"
    cnt1 dw 8,7,6,-2,5,0,0,3,9
    cnt2 dw 9,1,-5,-7,8,11,9,9,1,0
    cnt3 dw 4,3,0,0,-9
    pcount db 0
    mcount db 0
    zcount db 0
    array dw 3,cnt1,cnt2,cnt3
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

    mov cx, array
    mov si, 2
    lea di, pcount
loop_array:    
    mov bx, array[si]
    add si, 2
    call scan_array
    loop loop_array
    
            
    lea dx, pkey
    mov ah, 9
    int 21h        ; output string at ds:dx
    
    ; wait for any key....    
    mov ah, 1
    int 21h
    
    mov ax, 4c00h ; exit to operating system.
    int 21h

; 输入bx = 数组的首地址，di = 输出区的首地址[p,m,z]
scan_array:
pushf
push dx
push cx
push ax
push si
    mov cx, [bx]
    mov si, 2
loop_scan:
    mov ax, [bx][si]
    push bx ; bx暂存
    push di ; di暂存
    mov bx, di
    cmp ax, 0
    jng scan_branch_ng
    ; > 0
    mov di, 0
    jmp scan_branch_out
scan_branch_ng:    
    jl scan_branch_l
    ; = 0
    mov di, 2
    jmp scan_branch_out                   
scan_branch_l:
    ; < 0
    mov di, 1
scan_branch_out:
    ; [bx][di]对应的输出区
    mov dx, [bx][di]
    inc dx
    mov [bx][di], dx
    pop di
    pop bx
    add si, 2
    loop loop_scan
pop si
pop ax
pop cx
pop dx
popf
ret    
ends

end start ; set entry point and stop the assembler.
