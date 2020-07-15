; multi-segment executable file template.

data segment
    ; add your data here!
    pkey db "press any key...$"
    buf db "HeLloWorLd"
    buf_len equ $-buf
    numbers db "0123456789"
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
    mov cx, buf_len
    lea si, buf
    lea di, buf
    mov ah, 0

; ����ѭ����    
cal_character:
    lodsb ; ��ȡһ���ַ�
    cmp al,61h 
    jb sto_buf ; ��61H(a)�Ƚϣ���<61H(a)��������sto_buf����
    cmp al,7ah
    ja sto_buf ; ��7AH(z)�Ƚϣ���>7AH(z)��������sto_buf����
    ; ִ��Сдת��д���룬������
    sub al,20h
    inc ah
sto_buf:
    stosb ; д��һ���ַ�
    loop cal_character
    
    ; ���ah
    ; ���ֵΪ10����ah=10ʱ���10��ah<10ʱ�����"30H+al"(ת��Ϊ�ַ���)
    cmp ah, 10
    jb print_branch
    mov dl, 31h ;����ַ�1
    mov ah, 2
    int 21h
    mov dl, 30h
    int 21h
    jmp out_print      
print_branch:
    add ah, 30h
    mov dl, ah
    mov ah, 2
    int 21h          
out_print:
            
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
