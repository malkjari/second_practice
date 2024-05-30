CC = gcc
CFLAGS = -Wall -fPIC -Iinclude
LDFLAGS = -shared
TARGET = libmysyslog.so
SRC = src/mysyslog.c

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET) $(LDFLAGS)

clean:
	rm -f $(TARGET) *.o

deb:
	# Команды для сборки deb-пакета
	fakeroot dpkg-deb --build .

.PHONY: all clean deb
