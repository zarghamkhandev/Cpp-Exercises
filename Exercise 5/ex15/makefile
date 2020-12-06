ITEMS = helloT pi
SERIAL_ITEMS = $(addsuffix -serial, $(ITEMS))
PARALLEL_ITEMS = $(addsuffix -parallel, $(ITEMS))
TARGETS = $(SERIAL_ITEMS) $(PARALLEL_ITEMS)
CC = g++ -std=c++17
CCPAR = $(CC) -fopenmp

all: $(TARGETS)

%-serial: %.cc
	$(CC) $< -o $@

%-parallel: %.cc
	$(CCPAR) $< -o $@ 

clean:
	rm *-serial *-parallel