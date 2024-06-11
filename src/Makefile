# Makefile for compiling a C++ project with hiredis, jsoncpp, and mysqlclient

# Compiler
CXX = g++

# Libraries
LIBS = -ljsoncpp -lmysqlclient -lhiredis

# Target executables
TARGETS = server client

# Source files
SRCS_SERVER = server.cpp
SRCS_CLIENT = client.cpp

# Object files
OBJS_SERVER = $(SRCS_SERVER:.cpp=.o)
OBJS_CLIENT = $(SRCS_CLIENT:.cpp=.o)

# Default target
all: $(TARGET)

# Linking server
server: $(OBJS_SERVER)
	$(CXX) -o server $(OBJS_SERVER) $(LIBS)

# Linking client
client: $(SRCS_CLIENT)
	$(CXX) -o client $(SRCS_CLIENT)


# Compiling
%.o: %.cpp
	$(CXX) -c $< -o $@

# Clean up
clean:
	rm -f $(OBJS_SERVER) $(OBJS_CLIENT) $(TARGETS)

# Phony targets
.PHONY: all clean
