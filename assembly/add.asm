
add:     file format elf32-littlearm


Disassembly of section .init:

00010294 <_init>:
   10294:	e92d4008 	push	{r3, lr}
   10298:	eb00001d 	bl	10314 <call_weak_fn>
   1029c:	e8bd8008 	pop	{r3, pc}

Disassembly of section .plt:

000102a0 <.plt>:
   102a0:	e52de004 	push	{lr}		; (str lr, [sp, #-4]!)
   102a4:	e59fe004 	ldr	lr, [pc, #4]	; 102b0 <.plt+0x10>
   102a8:	e08fe00e 	add	lr, pc, lr
   102ac:	e5bef008 	ldr	pc, [lr, #8]!
   102b0:	00010d50 	.word	0x00010d50

000102b4 <__libc_start_main@plt>:
   102b4:	e28fc600 	add	ip, pc, #0, 12
   102b8:	e28cca10 	add	ip, ip, #16, 20	; 0x10000
   102bc:	e5bcfd50 	ldr	pc, [ip, #3408]!	; 0xd50

000102c0 <__gmon_start__@plt>:
   102c0:	e28fc600 	add	ip, pc, #0, 12
   102c4:	e28cca10 	add	ip, ip, #16, 20	; 0x10000
   102c8:	e5bcfd48 	ldr	pc, [ip, #3400]!	; 0xd48

000102cc <abort@plt>:
   102cc:	e28fc600 	add	ip, pc, #0, 12
   102d0:	e28cca10 	add	ip, ip, #16, 20	; 0x10000
   102d4:	e5bcfd40 	ldr	pc, [ip, #3392]!	; 0xd40

Disassembly of section .text:

000102d8 <_start>:
   102d8:	e3a0b000 	mov	fp, #0
   102dc:	e3a0e000 	mov	lr, #0
   102e0:	e49d1004 	pop	{r1}		; (ldr r1, [sp], #4)
   102e4:	e1a0200d 	mov	r2, sp
   102e8:	e52d2004 	push	{r2}		; (str r2, [sp, #-4]!)
   102ec:	e52d0004 	push	{r0}		; (str r0, [sp, #-4]!)
   102f0:	e59fc010 	ldr	ip, [pc, #16]	; 10308 <_start+0x30>
   102f4:	e52dc004 	push	{ip}		; (str ip, [sp, #-4]!)
   102f8:	e59f000c 	ldr	r0, [pc, #12]	; 1030c <_start+0x34>
   102fc:	e59f300c 	ldr	r3, [pc, #12]	; 10310 <_start+0x38>
   10300:	ebffffeb 	bl	102b4 <__libc_start_main@plt>
   10304:	ebfffff0 	bl	102cc <abort@plt>
   10308:	00010478 	.word	0x00010478
   1030c:	000103f8 	.word	0x000103f8
   10310:	00010418 	.word	0x00010418

00010314 <call_weak_fn>:
   10314:	e59f3014 	ldr	r3, [pc, #20]	; 10330 <call_weak_fn+0x1c>
   10318:	e59f2014 	ldr	r2, [pc, #20]	; 10334 <call_weak_fn+0x20>
   1031c:	e08f3003 	add	r3, pc, r3
   10320:	e7932002 	ldr	r2, [r3, r2]
   10324:	e3520000 	cmp	r2, #0
   10328:	012fff1e 	bxeq	lr
   1032c:	eaffffe3 	b	102c0 <__gmon_start__@plt>
   10330:	00010cdc 	.word	0x00010cdc
   10334:	00000018 	.word	0x00000018

00010338 <deregister_tm_clones>:
   10338:	e59f0018 	ldr	r0, [pc, #24]	; 10358 <deregister_tm_clones+0x20>
   1033c:	e59f3018 	ldr	r3, [pc, #24]	; 1035c <deregister_tm_clones+0x24>
   10340:	e1530000 	cmp	r3, r0
   10344:	012fff1e 	bxeq	lr
   10348:	e59f3010 	ldr	r3, [pc, #16]	; 10360 <deregister_tm_clones+0x28>
   1034c:	e3530000 	cmp	r3, #0
   10350:	012fff1e 	bxeq	lr
   10354:	e12fff13 	bx	r3
   10358:	00021024 	.word	0x00021024
   1035c:	00021024 	.word	0x00021024
   10360:	00000000 	.word	0x00000000

00010364 <register_tm_clones>:
   10364:	e59f0024 	ldr	r0, [pc, #36]	; 10390 <register_tm_clones+0x2c>
   10368:	e59f1024 	ldr	r1, [pc, #36]	; 10394 <register_tm_clones+0x30>
   1036c:	e0413000 	sub	r3, r1, r0
   10370:	e1a01fa3 	lsr	r1, r3, #31
   10374:	e0811143 	add	r1, r1, r3, asr #2
   10378:	e1b010c1 	asrs	r1, r1, #1
   1037c:	012fff1e 	bxeq	lr
   10380:	e59f3010 	ldr	r3, [pc, #16]	; 10398 <register_tm_clones+0x34>
   10384:	e3530000 	cmp	r3, #0
   10388:	012fff1e 	bxeq	lr
   1038c:	e12fff13 	bx	r3
   10390:	00021024 	.word	0x00021024
   10394:	00021024 	.word	0x00021024
   10398:	00000000 	.word	0x00000000

0001039c <__do_global_dtors_aux>:
   1039c:	e92d4010 	push	{r4, lr}
   103a0:	e59f4018 	ldr	r4, [pc, #24]	; 103c0 <__do_global_dtors_aux+0x24>
   103a4:	e5d43000 	ldrb	r3, [r4]
   103a8:	e3530000 	cmp	r3, #0
   103ac:	18bd8010 	popne	{r4, pc}
   103b0:	ebffffe0 	bl	10338 <deregister_tm_clones>
   103b4:	e3a03001 	mov	r3, #1
   103b8:	e5c43000 	strb	r3, [r4]
   103bc:	e8bd8010 	pop	{r4, pc}
   103c0:	00021024 	.word	0x00021024

000103c4 <frame_dummy>:
   103c4:	eaffffe6 	b	10364 <register_tm_clones>

000103c8 <add>:
   103c8:	e52db004 	push	{fp}		; (str fp, [sp, #-4]!)
   103cc:	e28db000 	add	fp, sp, #0
   103d0:	e24dd00c 	sub	sp, sp, #12
   103d4:	e50b0008 	str	r0, [fp, #-8]
   103d8:	e50b100c 	str	r1, [fp, #-12]
   103dc:	e51b2008 	ldr	r2, [fp, #-8]
   103e0:	e51b300c 	ldr	r3, [fp, #-12]
   103e4:	e0823003 	add	r3, r2, r3
   103e8:	e1a00003 	mov	r0, r3
   103ec:	e28bd000 	add	sp, fp, #0
   103f0:	e49db004 	pop	{fp}		; (ldr fp, [sp], #4)
   103f4:	e12fff1e 	bx	lr

000103f8 <main>:
   103f8:	e92d4800 	push	{fp, lr}
   103fc:	e28db004 	add	fp, sp, #4
   10400:	e3a01003 	mov	r1, #3
   10404:	e3a00002 	mov	r0, #2
   10408:	ebffffee 	bl	103c8 <add>
   1040c:	e3a03000 	mov	r3, #0
   10410:	e1a00003 	mov	r0, r3
   10414:	e8bd8800 	pop	{fp, pc}

00010418 <__libc_csu_init>:
   10418:	e92d47f0 	push	{r4, r5, r6, r7, r8, r9, sl, lr}
   1041c:	e59f604c 	ldr	r6, [pc, #76]	; 10470 <__libc_csu_init+0x58>
   10420:	e59f504c 	ldr	r5, [pc, #76]	; 10474 <__libc_csu_init+0x5c>
   10424:	e08f6006 	add	r6, pc, r6
   10428:	e08f5005 	add	r5, pc, r5
   1042c:	e0466005 	sub	r6, r6, r5
   10430:	e1a07000 	mov	r7, r0
   10434:	e1a08001 	mov	r8, r1
   10438:	e1a09002 	mov	r9, r2
   1043c:	ebffff94 	bl	10294 <_init>
   10440:	e1b06146 	asrs	r6, r6, #2
   10444:	08bd87f0 	popeq	{r4, r5, r6, r7, r8, r9, sl, pc}
   10448:	e3a04000 	mov	r4, #0
   1044c:	e1a02009 	mov	r2, r9
   10450:	e1a01008 	mov	r1, r8
   10454:	e1a00007 	mov	r0, r7
   10458:	e4953004 	ldr	r3, [r5], #4
   1045c:	e2844001 	add	r4, r4, #1
   10460:	e12fff33 	blx	r3
   10464:	e1560004 	cmp	r6, r4
   10468:	1afffff7 	bne	1044c <__libc_csu_init+0x34>
   1046c:	e8bd87f0 	pop	{r4, r5, r6, r7, r8, r9, sl, pc}
   10470:	00010ae8 	.word	0x00010ae8
   10474:	00010ae0 	.word	0x00010ae0

00010478 <__libc_csu_fini>:
   10478:	e12fff1e 	bx	lr

Disassembly of section .fini:

0001047c <_fini>:
   1047c:	e92d4008 	push	{r3, lr}
   10480:	e8bd8008 	pop	{r3, pc}
