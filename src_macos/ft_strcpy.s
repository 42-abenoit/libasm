global	_ft_strcpy
section	.text

_ft_strcpy:	xor	rax, rax
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
			ret
