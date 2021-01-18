%ifdef os_mac

global	_ft_strcpy
section	.text

_ft_strcpy:
			push	rcx
			xor	rax, rax
			jmp	check

loop:		mov	cl, byte[rsi + rax]
			mov	byte[rdi + rax], cl
			inc	rax
			jmp	check

check:		cmp	byte[rsi + rax], 0
			je	ret_zero
			jmp	loop

ret_zero:	mov	byte[rdi + rax], 0
			mov	rax, rdi
			pop	rcx
			ret

%endif

%ifdef os_linux

global	ft_strcpy
section	.text

ft_strcpy:
			push	rcx
			xor	rax, rax
			jmp	check

loop:		mov	cl, byte[rsi + rax]
			mov	byte[rdi + rax], cl
			inc	rax
			jmp	check

check:		cmp	byte[rsi + rax], 0
			je	ret_zero
			jmp	loop

ret_zero:
			mov	byte[rdi + rax], 0
			mov	rax, rdi
			pop		rcx
			ret

%endif
