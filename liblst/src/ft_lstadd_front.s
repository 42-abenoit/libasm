	.text
	.file	"ft_lstadd_front.c"
	.globl	ft_lstadd_front         # -- Begin function ft_lstadd_front
	.p2align	4, 0x90
	.type	ft_lstadd_front,@function
ft_lstadd_front:                        # @ft_lstadd_front
	.cfi_startproc
# %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	cmpq	$0, -16(%rbp)
	je	.LBB0_2
# %bb.1:
	cmpq	$0, -8(%rbp)
	jne	.LBB0_3
.LBB0_2:
	jmp	.LBB0_4
.LBB0_3:
	movq	-8(%rbp), %rax
	movq	(%rax), %rax
	movq	-16(%rbp), %rcx
	movq	%rax, 8(%rcx)
	movq	-16(%rbp), %rax
	movq	-8(%rbp), %rcx
	movq	%rax, (%rcx)
.LBB0_4:
	popq	%rbp
	.cfi_def_cfa %rsp, 8
	retq
.Lfunc_end0:
	.size	ft_lstadd_front, .Lfunc_end0-ft_lstadd_front
	.cfi_endproc
                                        # -- End function

	.ident	"clang version 9.0.0-2~ubuntu18.04.2 (tags/RELEASE_900/final)"
	.section	".note.GNU-stack","",@progbits
	.addrsig
