; multi-segment executable file template.

data segment
    ; add your data here!
    pkey db "press any key...$"
    grade_store db 9,76,69,84,73,88,99,63,100,80
    s6 db 0
    s7 db 0
    s8 db 0
    s9 db 0
    s10 db 0 
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

    lea bx, grade_store
    mov cl, [bx]
    mov ch, 0 ; cx = 成绩个数
    mov si, 1 ; [bx][si]当前的成绩
loop_grade:
    mov al, [bx][si]
    mov ah, 0
    inc si
    call grade_level
    lea di, s6
    add di, ax ; di = 存储的位置
    mov dl, [di]
    inc dl
    mov [di], dl
    loop loop_grade
            
    lea dx, pkey
    mov ah, 9
    int 21h        ; output string at ds:dx
    
    ; wait for any key....    
    mov ah, 1
    int 21h
    
    mov ax, 4c00h ; exit to operating system.
    int 21h
; input ax = 当前的成绩; output ax = 成绩的等级,60~69=0，70~79=1，依次类推
grade_level:
    pushf
    push dx
    
    mov dl, 10
    div dl ; al= 6..10
    sub al, 6 ;al = 0..5
    cbw
    
    pop dx
    popf
    ret
ends

end start ; set entry point and stop the assembler.
