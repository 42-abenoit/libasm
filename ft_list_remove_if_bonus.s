%ifdef os_mac
global	_ft_list_remove_if
extern	_free
section	.text

_ft_list_remove_if:
	sub		rsp,	8
	push	rbp
	push	r15
	push	r14
	push	r13
	push	r12
	push	r11
	push	r10
	push	r9
	mov		r15,	rdi		; begin_list
	mov		r14,	rsi		; data_ref
	mov		r13,	rdx		; cmp
	mov		r12,	rcx		; free_fct
	mov		r11,	[r15]
	jmp		comp_first

comp_first:
	mov		r10,	r11	; tmp = *begin_list
	cmp		r10,	0
	jz		end
	push	r10
	push	r14
	mov		rdi,	[r10]
	mov		rsi,	r14
	call	r13
	pop		r14
	pop		r10
	cmp		eax,	0		; while (cmp(tmp->content, data_ref) == 0
	je		switch_first	; switch *begin_list
;	mov		r10,	[r11]	; tmp = *begin_list
	mov		r11,	[r15]
	mov		r9,	[r11 + 8]	; ptr = tmp->next
	jmp		comp_else

switch_first:
	push	r11
	sub		rsp,	8
	mov		rdi,	[r11]
	call	r12
	add		rsp,	8
	pop		r11
	mov		r9,	[r11 + 8]
	push	r9
	mov		rdi,	r11
	call	free
	pop		r9
	mov		[r15],	r9
	mov		r11, [r15]
	jmp		comp_first

comp_else:
	cmp		r9,	0
	jz		end
	push	r9
	push	r14
	mov		rdi,	[r9]
	mov		rsi,	r14
	call	r13
	pop		r14
	pop		r9
	cmp		eax,	0
	je		switch_else
	jmp		next

switch_else:
	push	r9
	push	r11
	mov		rdi,	[r9]
	call	r12
	pop		r11
	pop		r9
	mov		r10,	[r9 + 8]
	mov		[r11 + 8],	r10
	sub		rsp, 8
	mov		rdi,	r9
	call	_free
	add		rsp, 8
	mov		r9, [r11 + 8]
	jmp		comp_else

next:
	mov		r11, 	r9
	mov		r9,	[r9 + 8]
	jmp		comp_else

end:
	mov		rdi,	r15		; begin_list
	mov		rsi,	r14		; data_ref
	mov		rdx,	r13		; cmp
	mov		rcx,	r12		; free_fct
	pop		r9
	pop		r10
	pop		r11
	pop		r12
	pop		r13
	pop		r14
	pop		r15
	pop		rbp
	add		rsp,	8
	ret


%endif

%ifdef os_linux
global	ft_list_remove_if
extern	free
section	.text

ft_list_remove_if:
	sub		rsp,	8
	push	rbp
	push	r15
	push	r14
	push	r13
	push	r12
	push	r11
	push	r10
	push	r9
	mov		r15,	rdi		; begin_list
	mov		r14,	rsi		; data_ref
	mov		r13,	rdx		; cmp
	mov		r12,	rcx		; free_fct
	mov		r11,	[r15]
	jmp		comp_first

comp_first:
	mov		r10,	r11	; tmp = *begin_list
	cmp		r10,	0
	jz		end
	push	r10
	push	r14
	mov		rdi,	[r10]
	mov		rsi,	r14
	call	r13
	pop		r14
	pop		r10
	cmp		eax,	0		; while (cmp(tmp->content, data_ref) == 0
	je		switch_first	; switch *begin_list
;	mov		r10,	[r11]	; tmp = *begin_list
	mov		r11,	[r15]
	mov		r9,	[r11 + 8]	; ptr = tmp->next
	jmp		comp_else

switch_first:
	push	r11
	sub		rsp,	8
	mov		rdi,	[r11]
	call	r12
	add		rsp,	8
	pop		r11
	mov		r9,	[r11 + 8]
	push	r9
	mov		rdi,	r11
	call	free
	pop		r9
	mov		[r15],	r9
	mov		r11, [r15]
	jmp		comp_first

comp_else:
	cmp		r9,	0
	jz		end
	push	r9
	push	r14
	mov		rdi,	[r9]
	mov		rsi,	r14
	call	r13
	pop		r14
	pop		r9
	cmp		eax,	0
	je		switch_else
	jmp		next

switch_else:
	push	r9
	push	r11
	mov		rdi,	[r9]
	call	r12
	pop		r11
	pop		r9
	mov		r10,	[r9 + 8]
	mov		[r11 + 8],	r10
	sub		rsp, 8
	mov		rdi,	r9
	call	free
	add		rsp, 8
	mov		r9, [r11 + 8]
	jmp		comp_else

next:
	mov		r11, 	r9
	mov		r9,	[r9 + 8]
	jmp		comp_else

end:
	mov		rdi,	r15		; begin_list
	mov		rsi,	r14		; data_ref
	mov		rdx,	r13		; cmp
	mov		rcx,	r12		; free_fct
	pop		r9
	pop		r10
	pop		r11
	pop		r12
	pop		r13
	pop		r14
	pop		r15
	pop		rbp
	add		rsp,	8
	ret

%endif
