# Paths
HTSLIB_INSTALL_PATH=
RABBITBAM_INSTALL_PATH=
LIBDEFLATE_INSTALL_PATH=

# Compiler and flags
CC=gcc
CXX=g++
CFLAGS=-O3 -g
CXXFLAGS=-O3 -g -std=c++11

# Include directories
INCLUDES = -I$(HTSLIB_INSTALL_PATH)/include \
           -I$(RABBITBAM_INSTALL_PATH) \
           -I$(RABBITBAM_INSTALL_PATH)/htslib \
           -I$(LIBDEFLATE_INSTALL_PATH)/include \
           -I$(LIBDEFLATE_INSTALL_PATH)

# Library directories
LIBS = -L$(HTSLIB_INSTALL_PATH)/lib \
       -L$(RABBITBAM_INSTALL_PATH) \
       -L$(LIBDEFLATE_INSTALL_PATH)/lib \
       -L$(LIBDEFLATE_INSTALL_PATH)/lib64

# Libraries to link
LDFLAGS = $(LIBS) -lhts -lz -lpthread -lrabbitbamtools -lrabbitbamread -lrabbitbamwrite -lstdc++

# Final flags
CFLAGS += $(INCLUDES)
CXXFLAGS += $(INCLUDES)

# Example target
all: bam_sort

bam_sort: bam_sort.o sam_opts.o bedidx.o sam_utils.o bam.o
	$(CXX) $^ $(LDFLAGS) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f *.o bam_sort

