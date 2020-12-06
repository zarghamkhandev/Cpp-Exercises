DEP = func.dll
TARGET = main
CC = mcs

.SECONDARY:
%.dll: %.cs
	$(CC) -t:library $<

%.exe: %.cs $(DEP)
	$(CC) -r:$(DEP) $<

$(TARGET): $(TARGET).exe
	mkbundle --cross default $< -o $@

clean:
	rm *.dll *.exe $(TARGET)