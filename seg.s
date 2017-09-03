global loadgdt

; loadgdt - loads a Global Descriptor Table from memory address
; stack:	[esp + 4] The address of the global descriptor table

loadgdt:
	lgdt [esp + 4]
	ret
