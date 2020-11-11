global	ft_read
extern	__errno_location
section	.text

ft_read:	xor	rax, rax
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
