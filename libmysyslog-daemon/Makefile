CC = gcc
CFLAGS = -Wall -I../libmysyslog/include
TARGET = mysyslog-daemon
SRC = src/daemon.c

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET) *.o

deb:
	# Команды для сборки deb-пакета
	fakeroot dpkg-deb --build .

.PHONY: all clean deb
