; multi-segment executable file template.

data segment
    ; add your data here!
    pkey db "press any key...$"
    numbers db -4,6,7,-8,12,14,17,-9,-8,20,18,-3,-5,7,27,32,84,-7,-2,6
    number_len equ $-numbers
    
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
    
    mov si, 0
    mov di, number_len - 1 ; �ֱ�ָ���һ�������һ��Ԫ��
judge_1:
    cmp si, di
    ja print_p_count ; si > di ��ֱ���������
    cmp numbers[si], 0
    jng judge_2 ; numbers[si] <= 0 �������һ���ж�
    inc si
    jmp judge_1
judge_2:
    cmp si, di
    ja print_p_count ; si > di ��ֱ���������
    cmp numbers[di], 0
    jg do_swap ; numbers[di] > 0 ����뽻��
    dec di
    jmp judge_2
do_swap:
    mov al, numbers[si] ; al(1) <- numbers[si]
    push ax
    mov al, numbers[di] ; al(2) <- numbers[di]
    mov numbers[si], al ; numbers[si] <- al(2)
    pop ax
    mov numbers[di], al ; numbers[di] <- al(1)
    inc si
    dec di
    jmp judge_1
               
print_p_count:
    mov ax, si
    call print_number ; ��������ĸ���
    push ax
    mov dl, 20h
    mov ah, 2
    int 21h ; ���һ���ո�
    pop ax
    xor ax, 0ffffh
    inc ax
    add ax, number_len
    call print_number ; ��������ĸ���
    
    mov dl, 0dh
    mov ah, 2
    int 21h
    mov dl, 0ah
    mov ah, 2
    int 21h
    
    mov cx, number_len
    lea si, numbers
    
loop_print:
    lodsb
    cbw ; ���ֽ���չ����
    call print_number_flag ; �����ǰ������
    mov dl, 20h
    mov ah, 2
    int 21h
    loop loop_print 
            
    lea dx, pkey
    mov ah, 9
    int 21h        ; output string at ds:dx
    
    ; wait for any key....    
    mov ah, 1
    int 21h
    
    mov ax, 4c00h ; exit to operating system.
    int 21h

; ��ģ�飬�з�������10������ʾ������(AX,����)�����(Console)��
print_number_flag:  
    push ax
    push dx ; �ݴ�dx
    cmp ax, 0
    jge call_print_number 
    
    push ax ; �ݴ�ax
    mov dl, 2dh
    mov ah, 2
    int 21h ; ���һ��'-'(0x2d)�ַ�
    ; ת��Ϊ��Ӧ������
    pop ax ; �ָ�ax
    xor ax, 0ffffh ; ����λȡ��
    inc ax ; +1 
call_print_number:
    call print_number
    pop dx
    pop ax
    ret    
    
; ��ģ�飬�޷�������10������ʾ������(AX,����)�����(Console)��
print_number:
    ; ��������
    push ax
    push bx
    push cx
    push dx
    
    mov cx, 0
    mov bx, 10
    
loop_div_number:
    cmp ax, 0
    jz branch_show_number ; ���ax!=0����ִ��ȡ��
    
    mov dx, 0 ; ��չ�޷�����
    div bx ; ��10
    inc cx
    push dx ; ���м������ѹ���ջ
    jmp loop_div_number ; ������ѭ��������ʹ��jmp
        
branch_show_number:
    cmp cx, 0
    jz print_number_0
    
loop_print_number:
    pop dx
    add dl, 30h
    mov ah, 2
    int 21h ; �����ջ��ջ��������    
    loop loop_print_number
    jmp print_number_out
print_number_0:
    mov dl, 30H
    mov ah, 2
    int 21h ; ����ַ�'0'
        
print_number_out:
    ; �ָ�����
    pop dx
    pop cx
    pop bx
    pop ax
    ret    
ends

end start ; set entry point and stop the assembler.
