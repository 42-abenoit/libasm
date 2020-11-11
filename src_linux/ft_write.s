extern	__errno_location
global	ft_write

section	.text
ft_write:
			mov	rax, 0x01
			syscall
			cmp	rax, 0
			jle	_error
			ret

_error:
			neg	rax
			mov	r8, rax
			call	__errno_location wrt ..plt
			mov	[rax], r8
			mov	rax, -1
			ret
