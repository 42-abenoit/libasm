global	ft_write

section	.text
ft_write:	mov	rax, 0x01
			syscall
			ret
