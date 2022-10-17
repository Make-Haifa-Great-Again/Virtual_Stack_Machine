CXX = g++
CC = $(CXX)

CPPFLAGS = -I $(INC_DIR) -I $(INL_DIR)
CPPFLAGS += -MMD -MP
# CPPFLAGS += -DDEBUG
# c language
CFLAGS = -g3

# c++ language
CXXFLAGS = -std=c++17
CXXFLAGS+= -Wall -pedantic
CXXFLAGS+= -Wextra
CXXFLAGS+= -Werror
CXXFLAGS+= -g3

LDFLAGS =
LDLIBS =

SRC_DIR= ../../src/
INC_DIR= ../../inc/
INL_DIR= ../../inc/inl/

TARGET = utest
# ! Fill only this:
OBJS = utest.o $(SRC_DIR)svm_stack_vm.o $(SRC_DIR)svm_kitchen.o

all: $(TARGET)

$(TARGET): $(OBJS)

check: all
	./$(TARGET)

vala: all
	valgrind --leak-check=yes --track-origins=yes -s ./$(TARGET)

DEPENDS= $(OBJS:%.o=%.d)

clean:
	@$(RM) $(TARGET) $(OBJS) $(DEPENDS)

.PHONY: all check clean DEPENDS

-include $(DEPENDS)