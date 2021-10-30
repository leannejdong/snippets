
a.out:     file format elf32-i386


Disassembly of section .init:

00001000 <_init>:
    1000:	f3 0f 1e fb          	endbr32 
    1004:	53                   	push   %ebx
    1005:	83 ec 08             	sub    $0x8,%esp
    1008:	e8 a3 00 00 00       	call   10b0 <__x86.get_pc_thunk.bx>
    100d:	81 c3 cf 2f 00 00    	add    $0x2fcf,%ebx
    1013:	8b 83 18 00 00 00    	mov    0x18(%ebx),%eax
    1019:	85 c0                	test   %eax,%eax
    101b:	74 02                	je     101f <_init+0x1f>
    101d:	ff d0                	call   *%eax
    101f:	83 c4 08             	add    $0x8,%esp
    1022:	5b                   	pop    %ebx
    1023:	c3                   	ret    

Disassembly of section .plt:

00001030 <.plt>:
    1030:	ff b3 04 00 00 00    	pushl  0x4(%ebx)
    1036:	ff a3 08 00 00 00    	jmp    *0x8(%ebx)
    103c:	0f 1f 40 00          	nopl   0x0(%eax)
    1040:	f3 0f 1e fb          	endbr32 
    1044:	68 00 00 00 00       	push   $0x0
    1049:	e9 e2 ff ff ff       	jmp    1030 <.plt>
    104e:	66 90                	xchg   %ax,%ax

Disassembly of section .plt.got:

00001050 <__cxa_finalize@plt>:
    1050:	f3 0f 1e fb          	endbr32 
    1054:	ff a3 14 00 00 00    	jmp    *0x14(%ebx)
    105a:	66 0f 1f 44 00 00    	nopw   0x0(%eax,%eax,1)

Disassembly of section .plt.sec:

00001060 <__libc_start_main@plt>:
    1060:	f3 0f 1e fb          	endbr32 
    1064:	ff a3 0c 00 00 00    	jmp    *0xc(%ebx)
    106a:	66 0f 1f 44 00 00    	nopw   0x0(%eax,%eax,1)

Disassembly of section .text:

00001070 <_start>:
    1070:	f3 0f 1e fb          	endbr32 
    1074:	31 ed                	xor    %ebp,%ebp
    1076:	5e                   	pop    %esi
    1077:	89 e1                	mov    %esp,%ecx
    1079:	83 e4 f0             	and    $0xfffffff0,%esp
    107c:	50                   	push   %eax
    107d:	54                   	push   %esp
    107e:	52                   	push   %edx
    107f:	e8 22 00 00 00       	call   10a6 <_start+0x36>
    1084:	81 c3 58 2f 00 00    	add    $0x2f58,%ebx
    108a:	8d 83 74 d2 ff ff    	lea    -0x2d8c(%ebx),%eax
    1090:	50                   	push   %eax
    1091:	8d 83 04 d2 ff ff    	lea    -0x2dfc(%ebx),%eax
    1097:	50                   	push   %eax
    1098:	51                   	push   %ecx
    1099:	56                   	push   %esi
    109a:	ff b3 1c 00 00 00    	pushl  0x1c(%ebx)
    10a0:	e8 bb ff ff ff       	call   1060 <__libc_start_main@plt>
    10a5:	f4                   	hlt    
    10a6:	8b 1c 24             	mov    (%esp),%ebx
    10a9:	c3                   	ret    
    10aa:	66 90                	xchg   %ax,%ax
    10ac:	66 90                	xchg   %ax,%ax
    10ae:	66 90                	xchg   %ax,%ax

000010b0 <__x86.get_pc_thunk.bx>:
    10b0:	8b 1c 24             	mov    (%esp),%ebx
    10b3:	c3                   	ret    
    10b4:	66 90                	xchg   %ax,%ax
    10b6:	66 90                	xchg   %ax,%ax
    10b8:	66 90                	xchg   %ax,%ax
    10ba:	66 90                	xchg   %ax,%ax
    10bc:	66 90                	xchg   %ax,%ax
    10be:	66 90                	xchg   %ax,%ax

000010c0 <deregister_tm_clones>:
    10c0:	e8 e4 00 00 00       	call   11a9 <__x86.get_pc_thunk.dx>
    10c5:	81 c2 17 2f 00 00    	add    $0x2f17,%edx
    10cb:	8d 8a 2c 00 00 00    	lea    0x2c(%edx),%ecx
    10d1:	8d 82 2c 00 00 00    	lea    0x2c(%edx),%eax
    10d7:	39 c8                	cmp    %ecx,%eax
    10d9:	74 1d                	je     10f8 <deregister_tm_clones+0x38>
    10db:	8b 82 10 00 00 00    	mov    0x10(%edx),%eax
    10e1:	85 c0                	test   %eax,%eax
    10e3:	74 13                	je     10f8 <deregister_tm_clones+0x38>
    10e5:	55                   	push   %ebp
    10e6:	89 e5                	mov    %esp,%ebp
    10e8:	83 ec 14             	sub    $0x14,%esp
    10eb:	51                   	push   %ecx
    10ec:	ff d0                	call   *%eax
    10ee:	83 c4 10             	add    $0x10,%esp
    10f1:	c9                   	leave  
    10f2:	c3                   	ret    
    10f3:	8d 74 26 00          	lea    0x0(%esi,%eiz,1),%esi
    10f7:	90                   	nop
    10f8:	c3                   	ret    
    10f9:	8d b4 26 00 00 00 00 	lea    0x0(%esi,%eiz,1),%esi

00001100 <register_tm_clones>:
    1100:	e8 a4 00 00 00       	call   11a9 <__x86.get_pc_thunk.dx>
    1105:	81 c2 d7 2e 00 00    	add    $0x2ed7,%edx
    110b:	55                   	push   %ebp
    110c:	89 e5                	mov    %esp,%ebp
    110e:	53                   	push   %ebx
    110f:	8d 8a 2c 00 00 00    	lea    0x2c(%edx),%ecx
    1115:	8d 82 2c 00 00 00    	lea    0x2c(%edx),%eax
    111b:	83 ec 04             	sub    $0x4,%esp
    111e:	29 c8                	sub    %ecx,%eax
    1120:	89 c3                	mov    %eax,%ebx
    1122:	c1 e8 1f             	shr    $0x1f,%eax
    1125:	c1 fb 02             	sar    $0x2,%ebx
    1128:	01 d8                	add    %ebx,%eax
    112a:	d1 f8                	sar    %eax
    112c:	74 14                	je     1142 <register_tm_clones+0x42>
    112e:	8b 92 20 00 00 00    	mov    0x20(%edx),%edx
    1134:	85 d2                	test   %edx,%edx
    1136:	74 0a                	je     1142 <register_tm_clones+0x42>
    1138:	83 ec 08             	sub    $0x8,%esp
    113b:	50                   	push   %eax
    113c:	51                   	push   %ecx
    113d:	ff d2                	call   *%edx
    113f:	83 c4 10             	add    $0x10,%esp
    1142:	8b 5d fc             	mov    -0x4(%ebp),%ebx
    1145:	c9                   	leave  
    1146:	c3                   	ret    
    1147:	8d b4 26 00 00 00 00 	lea    0x0(%esi,%eiz,1),%esi
    114e:	66 90                	xchg   %ax,%ax

00001150 <__do_global_dtors_aux>:
    1150:	f3 0f 1e fb          	endbr32 
    1154:	55                   	push   %ebp
    1155:	89 e5                	mov    %esp,%ebp
    1157:	53                   	push   %ebx
    1158:	e8 53 ff ff ff       	call   10b0 <__x86.get_pc_thunk.bx>
    115d:	81 c3 7f 2e 00 00    	add    $0x2e7f,%ebx
    1163:	83 ec 04             	sub    $0x4,%esp
    1166:	80 bb 2c 00 00 00 00 	cmpb   $0x0,0x2c(%ebx)
    116d:	75 27                	jne    1196 <__do_global_dtors_aux+0x46>
    116f:	8b 83 14 00 00 00    	mov    0x14(%ebx),%eax
    1175:	85 c0                	test   %eax,%eax
    1177:	74 11                	je     118a <__do_global_dtors_aux+0x3a>
    1179:	83 ec 0c             	sub    $0xc,%esp
    117c:	ff b3 28 00 00 00    	pushl  0x28(%ebx)
    1182:	e8 c9 fe ff ff       	call   1050 <__cxa_finalize@plt>
    1187:	83 c4 10             	add    $0x10,%esp
    118a:	e8 31 ff ff ff       	call   10c0 <deregister_tm_clones>
    118f:	c6 83 2c 00 00 00 01 	movb   $0x1,0x2c(%ebx)
    1196:	8b 5d fc             	mov    -0x4(%ebp),%ebx
    1199:	c9                   	leave  
    119a:	c3                   	ret    
    119b:	8d 74 26 00          	lea    0x0(%esi,%eiz,1),%esi
    119f:	90                   	nop

000011a0 <frame_dummy>:
    11a0:	f3 0f 1e fb          	endbr32 
    11a4:	e9 57 ff ff ff       	jmp    1100 <register_tm_clones>

000011a9 <__x86.get_pc_thunk.dx>:
    11a9:	8b 14 24             	mov    (%esp),%edx
    11ac:	c3                   	ret    

000011ad <add>:
    11ad:	f3 0f 1e fb          	endbr32 
    11b1:	55                   	push   %ebp
    11b2:	89 e5                	mov    %esp,%ebp
    11b4:	8b 55 08             	mov    0x8(%ebp),%edx
    11b7:	8b 45 0c             	mov    0xc(%ebp),%eax
    11ba:	01 d0                	add    %edx,%eax
    11bc:	5d                   	pop    %ebp
    11bd:	c3                   	ret    

000011be <main>:
    11be:	f3 0f 1e fb          	endbr32 
    11c2:	55                   	push   %ebp
    11c3:	89 e5                	mov    %esp,%ebp
    11c5:	6a 03                	push   $0x3
    11c7:	6a 02                	push   $0x2
    11c9:	e8 df ff ff ff       	call   11ad <add>
    11ce:	83 c4 08             	add    $0x8,%esp
    11d1:	b8 00 00 00 00       	mov    $0x0,%eax
    11d6:	c9                   	leave  
    11d7:	c3                   	ret    
    11d8:	66 90                	xchg   %ax,%ax
    11da:	66 90                	xchg   %ax,%ax
    11dc:	66 90                	xchg   %ax,%ax
    11de:	66 90                	xchg   %ax,%ax

000011e0 <__libc_csu_init>:
    11e0:	f3 0f 1e fb          	endbr32 
    11e4:	55                   	push   %ebp
    11e5:	e8 6b 00 00 00       	call   1255 <__x86.get_pc_thunk.bp>
    11ea:	81 c5 f2 2d 00 00    	add    $0x2df2,%ebp
    11f0:	57                   	push   %edi
    11f1:	56                   	push   %esi
    11f2:	53                   	push   %ebx
    11f3:	83 ec 0c             	sub    $0xc,%esp
    11f6:	89 eb                	mov    %ebp,%ebx
    11f8:	8b 7c 24 28          	mov    0x28(%esp),%edi
    11fc:	e8 ff fd ff ff       	call   1000 <_init>
    1201:	8d 9d 04 ff ff ff    	lea    -0xfc(%ebp),%ebx
    1207:	8d 85 00 ff ff ff    	lea    -0x100(%ebp),%eax
    120d:	29 c3                	sub    %eax,%ebx
    120f:	c1 fb 02             	sar    $0x2,%ebx
    1212:	74 29                	je     123d <__libc_csu_init+0x5d>
    1214:	31 f6                	xor    %esi,%esi
    1216:	8d b4 26 00 00 00 00 	lea    0x0(%esi,%eiz,1),%esi
    121d:	8d 76 00             	lea    0x0(%esi),%esi
    1220:	83 ec 04             	sub    $0x4,%esp
    1223:	57                   	push   %edi
    1224:	ff 74 24 2c          	pushl  0x2c(%esp)
    1228:	ff 74 24 2c          	pushl  0x2c(%esp)
    122c:	ff 94 b5 00 ff ff ff 	call   *-0x100(%ebp,%esi,4)
    1233:	83 c6 01             	add    $0x1,%esi
    1236:	83 c4 10             	add    $0x10,%esp
    1239:	39 f3                	cmp    %esi,%ebx
    123b:	75 e3                	jne    1220 <__libc_csu_init+0x40>
    123d:	83 c4 0c             	add    $0xc,%esp
    1240:	5b                   	pop    %ebx
    1241:	5e                   	pop    %esi
    1242:	5f                   	pop    %edi
    1243:	5d                   	pop    %ebp
    1244:	c3                   	ret    
    1245:	8d b4 26 00 00 00 00 	lea    0x0(%esi,%eiz,1),%esi
    124c:	8d 74 26 00          	lea    0x0(%esi,%eiz,1),%esi

00001250 <__libc_csu_fini>:
    1250:	f3 0f 1e fb          	endbr32 
    1254:	c3                   	ret    

00001255 <__x86.get_pc_thunk.bp>:
    1255:	8b 2c 24             	mov    (%esp),%ebp
    1258:	c3                   	ret    

Disassembly of section .fini:

0000125c <_fini>:
    125c:	f3 0f 1e fb          	endbr32 
    1260:	53                   	push   %ebx
    1261:	83 ec 08             	sub    $0x8,%esp
    1264:	e8 47 fe ff ff       	call   10b0 <__x86.get_pc_thunk.bx>
    1269:	81 c3 73 2d 00 00    	add    $0x2d73,%ebx
    126f:	83 c4 08             	add    $0x8,%esp
    1272:	5b                   	pop    %ebx
    1273:	c3                   	ret    
