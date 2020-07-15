; multi-segment executable file template.

data segment
    ; add your data here!
    pkey db "press any key...$"
    datas dw -4,6,7,-8,12,14,17,-9,-8,20,18,-3,-5,7,27,32,84,-7,-2,6
    data_len equ ($-numbers)/2
    
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
    
    ; ��ʼ��
    lea si, datas
    mov cx, data_len
    mov ax, 1
    
loop_select:
    mov dx, [si]
    add si, 2 ; ��ȡһ������dx
    test dx, 1
    jnz out_select ; dx��������������ǰѭ��
    test ax, 1
    jnz out_cmp ; ax��������ֱ�Ӹ�ֵ
    cmp dx, ax
    jnl out_select ; dx >= ax ������ǰѭ��    
out_cmp:    
    mov ax, dx
out_select:
    loop loop_select
    
    call print_number_flag
    
            
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
