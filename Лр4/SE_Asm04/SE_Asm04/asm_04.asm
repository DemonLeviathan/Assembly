.586P
.MODEL FLAT, STDCALL
includelib kernel32.lib
ExitProcess PROTO : DWORD
.STACK 4096
.DATA
var1 DB 1
var2 EQU 257
.CODE
main PROC
START:
invoke ExitProcess, 0
main ENDP
end main