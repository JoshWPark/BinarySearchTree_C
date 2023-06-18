//이진탐색트리
#include<stdio.h>
#include<stdlib.h>

typedef struct treenode {
   struct treenode* left;
   int data;
   struct treenode* right;
}treenode;

treenode* new_node(int value) {
   treenode* p = (treenode*)malloc(sizeof(treenode));
   p->data = value;
   p->left = p->right = NULL;
   return p;
}
treenode* insert_node(treenode*root, int data) {
   if (root == NULL)
      return new_node(data);
   if (data < root->data)
      root->left = insert_node(root->left, data);
   else if (data > root->data) {
      root->right = insert_node(root->right, data);
   }
   return root;

}
treenode* min_value_node(treenode* root) {
   treenode* current = root;
   while (current->left != NULL)
      current = current->left;
   return current;
}
treenode* delete_node(treenode*root,int data) {
   if (root == NULL)
      return root;
   if (data < root->data)
      root->left = delete_node(root->left, data);
   else if (data > root->data)
      root->right = delete_node(root->right, data);
   else {
      if (root->left == NULL) {
         treenode* p = root->right;
         free(root);
         return p;
      }
      else if (root->right == NULL) {
         treenode* p = root->left;
         free(root);
         return p;
      }
      treenode* p = min_value_node(root->right);
      root->data = p->data;
      root->right = delete_node(root->right, p->data);
   }
   return root;
}
treenode* search_node(treenode*root, int data) {
   if (root == NULL)
      return NULL;
   if (data == root->data)
      return root;
   else if (data < root->data)
      return search_node(root->left, data);
   else
      return search_node(root->right, data);
}

void inorder(treenode*root) {
   if (root != NULL) {
      inorder(root->left);
      printf("[%d] ", root->data);
      inorder(root->right);
   }
}


int countallnodes(treenode* root) {
    if (root == NULL) {
        return 0;
    }
    else {
        int count = 1; // Count the current root node
        count += countallnodes(root->left); // Recursively count nodes in the left subtree
        count += countallnodes(root->right); // Recursively count nodes in the right subtree
        return count;
    }
}

int countsinglenodes(treenode* root) {
    if (root == NULL) {
        return 0;
    }

    if (root->left == NULL && root->right == NULL)
        return 1;

    int count = 0;
    count += countsinglenodes(root->left);
    count += countsinglenodes(root->right);
    
    return count;
}


int counttreeheight(treenode* root) {
    if (root == NULL) {
        return 0;
    }
    
    if (root->left == NULL && root->right == NULL)
        return 1;

    int leftheight = 1;
    int rightheight = 1;
    leftheight += counttreeheight(root->left);
    rightheight += counttreeheight(root->right);
    
    if(leftheight > rightheight)
        return leftheight;
    else if (leftheight < rightheight)
        return rightheight;
    else
        return leftheight;
}

treenode* insert(treenode* root){
    system("cls");
    int node = 0;
    while(1){
        printf("\n(0 입력 시 노드 삽입 종료) 이진트리에 넣고 싶은 숫자를 입력하시오: ");
        scanf_s("%d", &node);

        if(node==0)
            break;
        
        root = insert_node(root, node);
    }
    return root;
}

treenode* delete(treenode* root){
    system("cls");
    int node = 0;
    while(1){
        printf("\n(0 입력 시 노드 삭제 종료) 이진트리에서 삭제하고 싶은 숫자를 입력하시오: ");
        scanf_s("%d", &node);

        if(node==0)
            break;
        
        root = delete_node(root, node);
    }
    return root;
}

treenode* search(treenode* root){
    system("cls");
    int node = 0;
    while(1){
        printf("\n(0 입력 시 노드 검색 종료) 이진트리에서 검색하고 싶은 숫자를 입력하시오: ");
        scanf_s("%d", &node);

        if(node==0)
            break;
        
        if (search_node(root, node) != NULL)
            printf("노드 탐색 성공\n");
        else
            printf("노드 탐색 실패\n");

    }
    return root;
}

void startmenu()
{
    //사용자의 입력 값
    int a;
    //BinaryTree
    treenode* root = NULL;
    //while 반복문을 사용해 사용자가 정해진 메뉴에서만 고를 수 있게 한다. 
    while (1)
    {
        // 화면 지우기
        system("cls");
        printf("--이진탐색트리의 연산 선택--\n");
        printf("1. 노드 삽입 \n");
        printf("2. 노드 삭제 \n");
        printf("3. 노드 검색 \n");
        printf("4. 중위 순회 \n");
        printf("5. 트리의 총 노드 수 \n");
        printf("6. 트리의 단말노드의 수 \n");
        printf("7. 트리의 높이 \n");
        printf("8. 프로그램 종료\n\n");
        printf("번호를 입력하시오: ");
        scanf_s("%d", &a);

        switch (a)
        {
            case 1:
                root = insert(root);
                break;
            case 2:
                root = delete(root);
                break;
            case 3:
                search(root);
                break;
            case 4:
                inorder(root);
                break;
            case 5:
                printf("노드의 총 개수 : %d \n\n", countallnodes(root) );
                break;
            case 6:
                printf("단일노드의 총 개수 : %d \n\n", countsinglenodes(root) );
                break;
            case 7:
                printf("트리의 높이 : %d \n\n", counttreeheight(root) );
                break;
            case 8:
                exit(0);
            default:
                printf("1~8 중에 골라주세요. \n");
                break;
        }
    }
}

int main() {
    startmenu();
}