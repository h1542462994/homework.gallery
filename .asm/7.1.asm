data segment
    pkey db "press any key...$"
    score db 10,87,92,47,88,69,72,58,92,100,84 ; 成绩的数据
    notpassed db 11 dup(0)
    passed db 11 dup(0)
    good db 11 dup(0)
    better db 11 dup(0)
    best db 11 dup(0)
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
    mov cl, score
    mov ch, 0 ; cx=学生的个数
    lea bx, score ; bx=score的首地址
    mov si, 1 ;第一个元素的地址 ; si=当前的成绩的变址
loop_grade:
    mov al,[bx][si] ; al=当前的成绩
    push bx
    call judge_grade
    call push_grade
    pop bx
    inc si ; 跳到下一个成绩
    loop loop_grade
            
    lea dx, pkey
    mov ah, 9
    int 21h        ; output string at ds:dx
    
    ; wait for any key....    
    mov ah, 1
    int 21h
    
    mov ax, 4c00h ; exit to operating system.
    int 21h
; 判断，输入al(成绩),输出bx(对应的存储段的基地址)
judge_grade:
    pushf
    cmp al, 80
    jb judge_cmp_70
    ; 80~100
    cmp al, 90
    jb judge_cmp_1
    ; 90~100
    lea bx, best
    jmp judge_out
judge_cmp_1:
    ; 80~89
    lea bx, better
    jmp judge_out
judge_cmp_70:    
    ; 0~79
    cmp al, 70
    jb judge_cmp_60
    ; 70~79
    lea bx, good
    jmp judge_out 
judge_cmp_60:
    ; 0~69
    cmp al, 60
    jb judge_cmp_2
    lea bx, passed
    jmp judge_out
judge_cmp_2:
    ; 0~59
    lea bx, notpassed
judge_out:    
    popf
    ret
; 存储成绩，输入al(成绩),bx(对应的存储段的基地址)
push_grade:
    push si
    push cx
    mov cl, [bx]
    mov ch, 0 ; cl=存储区内存储的个数
    mov si, cx
    inc si ; si=指向待存储的位置
    mov [bx][si], al ; 存入数据
    inc cl
    mov [bx],cl ; cl+1后写入存储区内存储的个数
    pop cx
    pop si
    ret        
ends

end start ; set entry point and stop the assembler.
