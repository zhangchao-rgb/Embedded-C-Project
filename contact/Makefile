OBJS = test.o contact.o
CFLAGS += -c -Wall -g
TEST:$(OBJS)
	$(CC) $^ -o $@
%.o:%.c
	$(CC) $^ $(CFLAGS) -o $@
.PHONY:clean
clean:
	rm -f *.o TEST
