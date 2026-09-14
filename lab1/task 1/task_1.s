	.file	"task_1.c"
	.text
	.section	.rodata
.LC0:
	.string	"Enter A and B: "
.LC1:
	.string	"%d %d"
.LC2:
	.string	"Wrong input"
	.align 8
.LC3:
	.string	"Sum of positive multiples of four in [%d, %d] = %d\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	$0, -16(%rbp)
	leaq	.LC0(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	-24(%rbp), %rdx
	leaq	-28(%rbp), %rax
	leaq	.LC1(%rip), %rcx
	movq	%rax, %rsi
	movq	%rcx, %rdi
	movl	$0, %eax
	call	__isoc23_scanf@PLT
	cmpl	$2, %eax
	je	.L2
	leaq	.LC2(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	movl	$1, %eax
	jmp	.L8
.L2:
	movl	-28(%rbp), %edx
	movl	-24(%rbp), %eax
	cmpl	%eax, %edx
	jle	.L4
	movl	-28(%rbp), %eax
	movl	%eax, -12(%rbp)
	movl	-24(%rbp), %eax
	movl	%eax, -28(%rbp)
	movl	-12(%rbp), %eax
	movl	%eax, -24(%rbp)
.L4:
	movl	-28(%rbp), %eax
	movl	%eax, -20(%rbp)
	jmp	.L5
.L7:
	cmpl	$0, -20(%rbp)
	jle	.L6
	movl	-20(%rbp), %eax
	andl	$3, %eax
	testl	%eax, %eax
	jne	.L6
	movl	-20(%rbp), %eax
	addl	%eax, -16(%rbp)
.L6:
	addl	$1, -20(%rbp)
.L5:
	movl	-24(%rbp), %eax
	cmpl	%eax, -20(%rbp)
	jle	.L7
	movl	-24(%rbp), %edx
	movl	-28(%rbp), %eax
	movl	-16(%rbp), %ecx
	leaq	.LC3(%rip), %rdi
	movl	%eax, %esi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, %eax
.L8:
	movq	-8(%rbp), %rdx
	subq	%fs:40, %rdx
	je	.L9
	call	__stack_chk_fail@PLT
.L9:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (GNU) 16.2.1 20260810"
	.section	.note.GNU-stack,"",@progbits
