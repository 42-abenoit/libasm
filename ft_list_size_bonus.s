%ifdef os_mac
global	_ft_list_size
section	.text

_ft_list_size:
	push	rdi
	xor		rax, rax
	jmp		loop

loop:
	cmp		rdi, 0
	je		success
	inc		rax
	mov		rdi, [rdi + 8]
	jmp		loop

success:
	pop	rdi
	ret
%endif

%ifdef os_linux
global	ft_list_size
section	.text

ft_list_size:
	push	rdi
	xor		rax, rax
	jmp		loop

loop:
	cmp		rdi, 0
	je		success
	inc		rax
	mov		rdi, [rdi + 8]
	jmp		loop

success:
	pop	rdi
	ret

%endif
