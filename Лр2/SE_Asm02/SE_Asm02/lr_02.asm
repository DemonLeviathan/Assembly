.586P
.MODEL FLAT, STDCALL
includelib kernel32.lib
ExitProcess		PROTO : DWORD
MessageBoxA PROTO : DWORD, : DWORD, : DWORD, : DWORD

.STACK 4096
.CONST

.DATA

	var1 DD 5
	var2 DD 3
	str0 DB "Programm", 0
	str1 DB "Result = < >", 0

.CODE

main PROC
START:

	mov eax, var1
	add eax, var2	
	add eax, 30h

	mov str1+10, al
	
	INVOKE MessageBoxA, 0, offset str1, offset str0, 0

	push 0
	call ExitProcess
main ENDP
end main