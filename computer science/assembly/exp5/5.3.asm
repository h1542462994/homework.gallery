; multi-segment executable file template.

data segment
    ; add your data here!
    pkey db "press any key...$"
    numbers dw -1324,-2875,-1230
    numbers_len db ($-numbers)/2
    number_width dw 2
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
    
    mov ch, 0
    mov cl, numbers_len ; cxΪ���ֵĸ���
    lea si, numbers ; siִ�е�һ��Ԫ��
    lodsw 
    dec cx ; �ƶ���һ��Ԫ�ص�ax
    jcxz print_ax ; ���ֻ��һ�����������
loop_cmp_number:
    cmp ax, [si]
    jnl branch_cmp_number_out
    mov ax, [si] ; ��ax > [si] ���бȽ�
branch_cmp_number_out:
    add si, number_width  ; si ָ����һ��Ԫ��
    loop loop_cmp_number
    
print_ax:
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
    ret    
    
; ��ģ�飬�޷�������10������ʾ������(AX,����)�����(Console)��
print_number:
    ; ��������
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
    ret    
ends

end start ; set entry point and stop the assembler.
