#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ListNode {
    char player_id[100]; // 데이터 필드 
    struct ListNode* link; // 링크 필드
} ListNode;

ListNode* insert_last(ListNode* head, char* data)
{
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    
    if(node == NULL) {
        printf("메모리 공간 오류!\n");
        exit(1);
    }
    
    strcpy(node->player_id, data);
    
    if(head == NULL) // 빈 리스트인 경우
    {
        head = node;
        node->link = node; // 자신을 가리킨다.
    }
    else
    {
        node->link = head->link;
        head->link = node;
        head = node;
    }

    
    return head;
}

void free_list(ListNode* head)
{
    if(head == NULL)
        return; 
    
    ListNode* p = head; // 마지막 노드를 가리킨다.
    ListNode* temp;
    
    do {
        temp = p;
        p = p->link;
        free(temp);
    } while(p!=head); // 마지막 노드 전 까지 삭제
}

int main(void)
{
    ListNode* head = NULL;
    ListNode* p;
    
    int playerNum;
    printf("===== 보드 게임의 턴 순서 출력 프로그램입니다. 플레이어 수를 입력하세요 =====\n");
    scanf("%d", &playerNum);
    
    for(int i = 0; i < playerNum; i++)
    {
        printf("%d번 플레이어의 ID를 입력하세요:", i + 1);
        char player_id[100];
        scanf("%s", player_id);
        
        head = insert_last(head, player_id);
    }
    
    int input;
    int turn = 1;
    p = head->link;
    while(1)
    {
        printf("===== 턴을 진행하려면 숫자 1을 입력하세요. 게임 종료를 위해 아무 값이나 입력하세요. =====\n");
        scanf("%d", &input);
        
        if(input != 1)
            break;
            
        printf("%d번 턴의 플레이어: %s\n", turn, p->player_id);
        p = p->link;
        turn++;
    }
    free_list(head);
    
    printf("===== 프로그램이 종료되었습니다. =====");
    
    return 0;
}