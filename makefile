default:
	gcc -Wall -o prog main.c input.c stringWrap.c mapElem.c mapArrayList.c
debug:
	gcc -Wall -o prog -g main.c input.c stringWrap.c mapElem.c mapArrayList.c
clean:
	rm -f prog
