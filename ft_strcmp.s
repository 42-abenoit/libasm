global	ft_strcmp

section	.text
ft_strcmp:	xor	rax, rax
			jmp	check_1

loop:		mov	cl, byte[rsi + rax]
			cmp	byte[rdi + rax], cl
			jne	ret_no
			inc	rax
			jmp	check_1

check_1:	cmp	byte[rdi + rax], 0
			je	check_2
			jmp	loop

check_2:	cmp	byte[rsi + rax], 0
			je	ret_ye
			jmp	loop

ret_ye:		xor	rax, rax
			ret

ret_no:		mov	rax, -1
			ret
