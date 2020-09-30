global	ft_strlen
section	.text

ft_strlen:	xor	rax, rax
			jmp	loop

loop:		cmp byte[rdi + rax], 0
			je	ret_val
			inc	rax
			jmp	loop

ret_val:	ret
