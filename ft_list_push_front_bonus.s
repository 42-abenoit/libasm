
%ifdef	os_mac

global	_ft_list_push_front
extern	_ft_lstnew
section	.text

_ft_list_push_front:
	push	rbp
	push	r15
	push	r14
	push	r13
	push	r12
	mov		r15, rdi
	mov		r14, rsi
	cmp		r15, 0
	jz		end
	cmp		r14, 0
	jz		end
	mov		rdi, r14
	call	_ft_lstnew
	cmp		rax, 0
	jz		end
	mov		r13, [r15]
	mov		[rax + 8], r13
	mov		[r15], rax
	end

end:
	mov		rdi, r15
	mov		rsi, r14
	pop		r12
	pop		r13
	pop		r14
	pop		r15
	pop		rbp
	ret

%endif
%ifdef os_linux

global	ft_list_push_front
extern	ft_lstnew
section	.text

ft_list_push_front:
	push	rbp
	push	r15
	push	r14
	push	r13
	push	r12
	mov		r15, rdi
	mov		r14, rsi
	cmp		r15, 0
	jz		end
	cmp		r14, 0
	jz		end
	mov		rdi, r14
	call	ft_lstnew
	cmp		rax, 0
	jz		end
	mov		r13, [r15]
	mov		[rax + 8], r13
	mov		[r15], rax
	end

end:
	mov		rdi, r15
	mov		rsi, r14
	pop		r12
	pop		r13
	pop		r14
	pop		r15
	pop		rbp
	ret

%endif

