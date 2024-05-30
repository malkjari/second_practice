CC = gcc
CFLAGS = -Wall -fPIC -I../libmysyslog/include -Iinclude
LDFLAGS = -shared
TARGET = libmysyslog-json.so
SRC = src/json_driver.c

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET) $(LDFLAGS)

clean:
	rm -f $(TARGET) *.o

deb:
	# Команды для сборки deb-пакета
	fakeroot dpkg-deb --build .

.PHONY: all clean deb
