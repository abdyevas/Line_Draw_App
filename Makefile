CC	= gcc
CFLAGS = -Wall
LDFLAGS = -lglut -lGL -lm
OBJFILES = LineDraw.o Vector.o
TARGET = exe 

all: $(TARGET)

$(TARGET) : $(OBJFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES) $(LDFLAGS)

clean:
	rm -f $(OBJFILES) $(TARGET) *~