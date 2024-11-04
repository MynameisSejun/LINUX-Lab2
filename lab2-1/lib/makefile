# Makefile for creating a static library and linking it to the main program

# 정적 라이브러리 이름
LIBNAME = libcalculator.a

# 오브젝트 파일 목록
OBJS = add.o subtract.o multiply.o divide.o main.o

# 기본 목표: 라이브러리와 실행 파일 생성
all: $(LIBNAME) main

# 정적 라이브러리 생성 규칙
$(LIBNAME): $(OBJS)
	ar rcs $(LIBNAME) $(OBJS)

# 오브젝트 파일 생성 규칙
add.o: add.c
	gcc -c add.c

subtract.o: subtract.c
	gcc -c subtract.c

multiply.o: multiply.c
	gcc -c multiply.c

divide.o: divide.c
	gcc -c divide.c

# 메인 실행 파일 생성 규칙 (디버깅 심볼 포함)
main: main.o $(LIBNAME)
	gcc -g -I. -L. main.o -lcalculator -o main

# main.o 파일 생성 규칙
main.o: main.c
	gcc -g -c main.c  # 여기에도 -g 플래그 추가

# 클린 업 규칙
clean:
	rm -f $(LIBNAME) $(OBJS) main
