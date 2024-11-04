// main_dynamic.c: 동적 로딩 예제
#include <stdio.h>
#include <dlfcn.h>

int main() {
    int a, b;
    printf("두 정수를 입력하세요: ");
    scanf("%d %d", &a, &b);

    // 동적 라이브러리 열기
    void *handle = dlopen("./liboperations.so", RTLD_LAZY);
    if (!handle) {
        printf("Error: %s\n", dlerror());
        return 1;
    }

    // 함수 포인터로 라이브러리 함수 호출
    int (*add)(int, int) = dlsym(handle, "add");
    int (*subtract)(int, int) = dlsym(handle, "subtract");
    int (*multiply)(int, int) = dlsym(handle, "multiply");
    float (*divide)(int, int) = dlsym(handle, "divide");

    if (!add || !subtract || !multiply || !divide) {
        printf("Error: %s\n", dlerror());
        dlclose(handle);
        return 1;
    }

    // 함수 호출
    printf("덧셈 결과: %d\n", add(a, b));
    printf("뺄셈 결과: %d\n", subtract(a, b));
    printf("곱셈 결과: %d\n", multiply(a, b));
    printf("나눗셈 결과: %.2f\n", divide(a, b));

    // 동적 라이브러리 닫기
    dlclose(handle);
    return 0;
}
