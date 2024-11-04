# Makefile for creating a shared library

# 컴파일러 및 옵션 설정
CC = gcc
CFLAGS = -fPIC
LIBNAME = libcalculator

# 오브젝트 파일 목록
OBJS = add.o subtract.o multiply.o divide.o

# 라이브러리 파일 이름
SHARED_LIB = $(LIBNAME).so.1.0.1
SONAME = $(LIBNAME).so.1
LINK_NAME = $(LIBNAME).so

# 기본 목표: 공유 라이브러리 생성
all: $(SHARED_LIB) $(SONAME) $(LINK_NAME)

# 공유 라이브러리 생성 규칙
$(SHARED_LIB): $(OBJS)
	$(CC) -shared -Wl,-soname,$(SONAME) -o $@ $^

# 오브젝트 파일 생성 규칙
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# 클린 업 규칙
clean:
	rm -f $(SHARED_LIB) $(SONAME) $(LINK_NAME) $(OBJS)
