

CC            = gcc
FLAGS         = -m64 -pipe -O3 -Wall -W -D_REENTRANT
LINK          = gcc
LFLAGS        = -m64 -Wl,-O3
LIBS          = -lhidapi-libusb
DEL_FILE      = rm -f

SRCPATH       = ./src/
SOURCES       = $(SRCPATH)light2.c 
OBJECTS       = light2.o
TARGET        = light2
INSTALLPREFIX = /usr/local/bin


all: Makefile $(TARGET)

$(TARGET): 	$(OBJECTS)
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(LIBS)

clean:
	-$(DEL_FILE) $(OBJECTS)

delete: clean
	-$(DEL_FILE) $(TARGET)

install: all
	@cp -v $(TARGET) $(INSTALLPREFIX)/$(TARGET)
	@chmod 755 $(INSTALLPREFIX)/$(TARGET)


main.o: $(SRCPATH)light2.c
	$(CC) -c $(FLAGS) -o light2.o $(SRCPATH)light2.c

