CC=mcs
DLL=func.dll
FUNC=func.cs
MAINCS=main.cs
MAINEXE=main.exe


all: main clean

.SECONDARY:
%.dll: $(FUNC)
	$(CC) -t:library $<

%.exe: $(MAINCS) $(DLL)
	$(CC) -r:$(DLL) $<

main: $(MAINEXE)
	mkbundle --cross default $< -o $@

clean:
	rm $(DLL) $(MAINEXE) main