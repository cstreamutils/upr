PREFIX=/usr/bin
all: prod

prod:
	gcc upr.c -o upr
dev:
	gcc -O0 -g upr.c -o upr
clean:
	rm -rf upr
install: prod
	cp upr ${PREFIX}/upr
