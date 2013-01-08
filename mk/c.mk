CC=		gcc

CFLAGS=		$(FLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $^
