# Makefile

all: pizza tires

houseofpizza: houseofpizza.c mathHelper.c mathHelper.h
	clang -ggdb3 -O0 -std=c11 -Wall -Werror -o houseofpizza houseofpizza.c mathHelper.c -lcs50 -lm
	
houseoftires: houseoftires.c mathHelper.c mathHelper.h
	clang -ggdb3 -O0 -std=c11 -Wall -Werror -o houseoftires houseoftires.c mathHelper.c -lcs50 -lm
	
clean:
	rm -f *.o a.out core pizza tires