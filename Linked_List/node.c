#include<stdio.h>
#include<stdlib.h>

typedef struct node{
  int data;
  struct node *link;
}Node;

Node *create_node(int value){
  
  Node *temp = NULL;
  temp = (Node *)malloc(sizeof(Node));
  if (temp == NULL){
    printf("Memory allocation failed!!\n");
    exit(1);
  }
  
  temp->data = value;
  temp->link = NULL;
  
  return temp;
}
  
Node *insert_first(Node *head, int value){
  
  Node *temp = NULL;
  
  temp = create_node(value);
  if (temp != NULL){
    // Make temp node as the first node
    // The next node of the temp is the previously first node
    temp->link = head;
    
    // Make head pointer point to temp node
    head = temp;
  }
  return head; 
}

// value 값을 노드로 만든 후, pre 포인터가 가리키는 노드 다음에 삽입
Node *insert(Node *head, Node *pre, int value){
    Node *p = NULL;

    p = (Node *)create_node(value);

    // 새로 추가되는 노드의 링크 필드 값을 pre의 다음 노드로 설정
    p->link = pre->link;
    // pre의 다음 노드는 새로 추가되는 노드로 설정
    pre->link = p;

    return head;
}


// Delete a node after the node pointed by pre
// 노드 개수가 1인 경우 또는
// 노드 개수가 2 이상이고, 두번째 이후 노드를 삭제할 때 사용
Node *delete(Node *head, Node *pre){
    Node * temp = NULL;

    // 노드 개수가 1인 경우 (head == pre && head->link == NULL)
    if (head->link == NULL){
        temp = pre;
        head = NULL;
    }

    temp = pre->link;
    pre->link = temp->link;
    free(temp);

    return head;
}

Node *delete_first(Node *head){
  
  // Make temp as the first node
  Node *temp = head;
  
  if (temp != NULL)
  
    // If temp is the only node (i.e, first & last at the same time),
    // then, temp->link is NULL
    // Otherwise, temp is not the only node in the list,
    // then, temp->link points to the second node
    // Make head pointer point to either NULL or the address of the 2nd node
    head = temp->link;

  free(temp);
  
  return head;
}
  
void print_list(Node *head){
    Node *p = head;
    if (head == NULL){
        printf("List is empty!!\n");
        exit(1);
    }

    while(p != NULL){
        printf("%d ", p->data);
        p = p->link;
    }
    printf("\n");

    return;
}


int main() {

  Node *head = NULL;
  
  head = insert_first(head, 10);
  head = insert_first(head, 20);
  head = insert_first(head, 30);
  head = insert(head, head, 25);
  print_list(head);
  
  head = delete_first(head);  
  print_list(head);
  head = delete(head, head->link);
  //head = delete_first(head);  
  print_list(head);
  head = delete_first(head); 
  print_list(head);
  head = delete_first(head);
  print_list(head);
  return 0;
}