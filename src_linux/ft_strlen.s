global	ft_strlen
section	.text

ft_strlen:	
			mov	rax, rdi
			jmp	loop

loop:
			cmp byte [rax], 0
			jz	ret_val
			inc	rax
			jmp	loop

ret_val:
			sub	rax, rdi
			ret
