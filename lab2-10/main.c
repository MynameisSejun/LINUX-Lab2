#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 학생 정보를 저장할 구조체
typedef struct {
    char name[30];
    int midterm;
    int final;
} Student;

// 이진 트리 노드 구조체
typedef struct Node {
    Student data;
    struct Node *left, *right;
} Node;

// 노드 생성 함수
Node* createNode(Student data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// 이진 탐색 트리에 삽입하는 함수 (이름을 기준으로 정렬)
Node* insert(Node* root, Student data) {
    if (root == NULL) return createNode(data);

    if (strcmp(data.name, root->data.name) < 0)
        root->left = insert(root->left, data);
    else if (strcmp(data.name, root->data.name) > 0)
        root->right = insert(root->right, data);

    return root;
}

// 이름으로 학생 정보를 탐색하는 함수
Node* search(Node* root, char* name) {
    if (root == NULL || strcmp(root->data.name, name) == 0)
        return root;

    if (strcmp(name, root->data.name) < 0)
        return search(root->left, name);

    return search(root->right, name);
}

// 중위 순회로 학생 정보 출력
void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("이름: %s, 중간: %d, 기말: %d\n", root->data.name, root->data.midterm, root->data.final);
        inorder(root->right);
    }
}

// 메인 함수
int main() {
    int n;
    printf("학생 수를 입력하세요: ");
    scanf("%d", &n);

    Node* root = NULL;

    // 학생 수 만큼 입력받아 트리에 삽입
    for (int i = 0; i < n; i++) {
        Student student;
        printf("학생 이름: ");
        scanf("%s", student.name);
        printf("중간 점수: ");
        scanf("%d", &student.midterm);
        printf("기말 점수: ");
        scanf("%d", &student.final);

        root = insert(root, student);
    }

    // 중위 순회로 전체 학생 정보 출력
    printf("\n=== 학생 정보 출력 (이름 순) ===\n");
    inorder(root);

    // 특정 이름으로 학생 탐색
    char searchName[30];
    printf("\n찾을 학생 이름을 입력하세요: ");
    scanf("%s", searchName);

    Node* found = search(root, searchName);
    if (found != NULL)
        printf("이름: %s, 중간: %d, 기말: %d\n", found->data.name, found->data.midterm, found->data.final);
    else
        printf("해당 이름의 학생이 없습니다.\n");

    return 0;
}
