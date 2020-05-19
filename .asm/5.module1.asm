; multi-segment executable file template.

data segment
    ; add your data here!
    pkey db "press any key...$"
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
    
    ; ���ڲ���
    mov ax, 1323
    call print_number    
            
    lea dx, pkey
    mov ah, 9
    int 21h        ; output string at ds:dx
    
    ; wait for any key....    
    mov ah, 1
    int 21h
    
    mov ax, 4c00h ; exit to operating system.
    int 21h
    
; ��ģ�飬����(AX)�����Ϊ��Ļ��
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
