extern	___error
global	_ft_write

section	.text
_ft_write:
			mov	rax, 0x04
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
