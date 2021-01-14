%ifdef os_mac
global	_ft_list_sort
extern	_ft_list_size
section	.text

_ft_list_sort:
	push	rbp
	mov		r15,	rdi
	mov		r14,	rsi
	mov		r12,	[r15]
	push	r12
	mov		rdi,	r12
	call	_ft_list_size
	pop		r12
	mov		rdx,	rax
	mov		qword r13,	0
	jmp		compare

compare:
	cmp		r12,	0
	jz		check_end
	mov		r11,	r12
	cmp		qword [r11 + 8],	0
	jz		check_end
	mov		r10,	[r11 + 8]
	mov		rdi,	[r11]
	mov		rsi,	[r10]
	push	r11
	push	r10
	push	rdx
	sub		rsp,	8
	call	r14
	add		rsp,	8
	pop		rdx
	pop		r10
	pop		r11
	cmp		eax,	0
	jge		switch
	mov		r12,	r10
	jmp		compare

switch:
	mov		r8,		[r11]
	mov		r9,		[r10]
	mov		[r10], r8
	mov		[r11], r9
	mov		r12,	r10
	jmp		compare

check_end:
	mov		rax,	r13
	cmp		qword rax,	rdx
	jz		end
	inc		qword r13
	mov		r12,	[r15]
	jmp		compare

end:
	mov		rdi,	r15
	mov		rsi,	r14
	pop		rbp
	ret

%endif


%ifdef os_linux
global	ft_list_sort
extern	ft_list_size
section	.text

ft_list_sort:
	push	rbp
	mov		r15,	rdi
	mov		r14,	rsi
	mov		r13,	[r15]
	lea		r12,	[r13]
	mov		rdi,	r12
	call	_ft_list_size
	mov		rdx,	rax
	mov		qword rbx,	0
	jmp		compare

compare:
	cmp		r12,	0
	jz		check_end
	mov		r11,	r12
	cmp		qword [r11 + 8],	0
	jz		check_end
	mov		r10,	[r11 + 8]
	mov		rdi,	[r11]
	mov		rsi,	[r10]
	call	r14
	cmp		eax,	0
	jge		switch
	mov		r12,	r10
	jmp		compare

switch:
	mov		r8,		[r11]
	mov		r9,		[r10]
	mov		[r10], r8
	mov		[r11], r9
	mov		r12,	r10
	jmp		compare

check_end:
	cmp		qword [rbx],	rdx
	jz		end
	inc		qword [rbx]
	lea		r12,	[r13]
	jmp		compare

end:
	mov		rdi,	r15
	mov		rsi,	r14
	pop		rbp
	ret

%endif
