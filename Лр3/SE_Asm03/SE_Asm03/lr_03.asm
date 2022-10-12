.586P
.MODEL FLAT, STDCALL
includelib kernel32.lib

ExitProcess PROTO : DWORD

.STACK 4096
.CONST

.DATA
	myBytes BYTE 10h, 20h, 30h, 40h
	myWords WORD 8Ah, 3Bh, 44h, 5Fh, 99h
	myDoubles DWORD 1, 2, 3, 4, 5, 6
	myPointer DWORD myDoubles
	
	array DWORD 7, 3, 3, 1, 5, 0, 9
	sum DWORD 0

.CODE

main PROC
START:

	mov ESI, OFFSET myWords
	mov AX, [ESI + 4]
	mov BX, [ESI + 2]
	mov ECX, lengthof array

	mov ESI, OFFSET array

	mov EBX, 1

CYCLE:
	mov EAX, [ESI]

	add ESI, type array
	add sum, EAX

	cmp EAX, 0 
	jz IfZero
	turn:

	loop CYCLE

	call ExitProcess

	IfZero:
		mov EBX, 0
		jmp turn

main ENDP
end main