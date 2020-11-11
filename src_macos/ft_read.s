global	_ft_read
extern	___error
section	.text

_ft_read:	mov	rax, 3
			syscall
			cmp	rax, 0
			jle	ret_error
			ret

ret_error:
			neg	rax
			mov	r8, rax
			call	___error
			mov	[rax], r8
			mov	rax, -1
			ret
