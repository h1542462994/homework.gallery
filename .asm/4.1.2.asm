; multi-segment executable file template.

data segment
    ; strings
    pkey db "press any key...$"
    tip1 db "please input string1:$"
    tip2 db "please input string2:$"
    
    enter_key db 0dh, 0ah, "$"
    match db "match$"
    no_match db "no match$"
    ; datas
    max_len equ 120
    string1 max_len dup(?)
    len1 db 0
    len2 db 0
ends
   
extra segment
    string2 max_len dup(?)
ends
   
stack segment
    dw   128  dup(0)
ends

code segment
start:
; set segment registers:
    mov ax, data
    mov ds, ax
    mov ax, extra
    mov es, ax
    
    ; ��ʼ��
    mov cx, 0
    mov si, 0
    mov di, 0

    ; module:����ģ��
    lea dx, tip1
    mov ah, 9
    int 21h
    lea bx, string1 ;��ַ
input1_loop: 
    ; ����һ���ַ�
    mov ah, 1
    int 21h
    
    cmp al, 0dh ;�ж��Ƿ�Ϊenter
    jz input2
    
    cmp al, 08h ;�ж��Ƿ����˸��
    jz back1
    mov ds:[bx][si], al
    inc si
    jmp input1_loop
back1:
    dec si
    jmp input1_loop    

    
input2:
    mov dl, 0ah ;����ѭ��ʱ����һ��LF��
    mov ah, 2
    int 21h ;��������ַ��Ĺ���
    
    lea dx, tip2
    mov ah, 9
    int 21h
    lea bx, string2
input2_loop:
    mov ah, 1
    int 21h
    
    cmp al, 0dh
    jz input_out
    
    cmp al, 08h ;�ж��Ƿ����˸��
    jz back2
    mov es:[bx][di],al
    inc di
    jmp input2_loop
back2:
    dec di
    jmp input2_loop
input_out:
    mov dl, 0ah ;����ѭ��ʱ����һ��LF��
    mov ah, 2
    int 21h ;��������ַ��Ĺ���        
    
    ; �жϳ����Ƿ����
    mov ax, si
    sub ax, di
    cmp ax, 0
    jnz show_noequal
    
    mov cx, si ; siΪ�Ƚϴ���
    lea si, string1
    lea di, string2
cmp_loop:
    cmpsb
    loop cmp_loop

    jz show_equal
    
show_noequal:
    lea dx, no_match
    jmp show_out
show_equal:
    lea dx, match
show_out:
    mov ah, 9
    int 21h
        
    lea dx, enter_key
    mov ah, 9
    int 21h
           
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
