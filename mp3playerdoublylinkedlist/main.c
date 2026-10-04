#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct DListNode {
    struct DListNode* llink;
    char song_name[100];
    struct DListNode* rlink;
} DListNode;

void init(DListNode* phead)
{
    phead->rlink = phead;
    phead->llink = phead;
}

void print_list(DListNode* head)
{
    DListNode* p = head->rlink;
    
    for(;p!=head; p = p->rlink) {
        printf("<- |%s| ->", p->song_name);
    }
    
    printf("\n");
}

void dinsert(DListNode* before, char* song_name)
{
    DListNode* new_node = (DListNode*)malloc(sizeof(DListNode));
    strcpy(new_node->song_name, song_name);
    
    new_node->rlink = before->rlink;
    new_node->llink = before;
    before->rlink->llink = new_node;
    before->rlink = new_node;
}

void ddelete(DListNode* head, DListNode* removed)
{
    if(removed == head)
        return;
    
    removed->rlink->llink = removed->llink;
    removed->llink->rlink = removed->rlink;
    free(removed);
}

DListNode* add_song(DListNode* head, DListNode* current)
{
    DListNode* p = head->llink; // 마지막 곡을 가리키게
    
    char song_name[100];
    printf("========== 곡 추가하기 ==========\n");
    printf("추가 하고 싶은 곡의 이름을 입력하세요:");
    scanf("%s", song_name);
    
    if(head == head->rlink) { // 비어있다면
        dinsert(head, song_name);
        current = current->rlink;
    }
    else {
        dinsert(head, song_name);
    }
    
    return current;
}

DListNode* remove_song(DListNode* head, DListNode* current)
{
    printf("========== 곡 삭제하기 ==========\n");
    printf("마지막 곡이 삭제되었습니다.");
    
    if(current == head->llink) {
        current = head->llink->llink; // 만약 현재 가리키는 곡이 삭제 대상이라면 왼쪽으로 이동
    }
    
    ddelete(head, head->llink);
    
    return current;
}

void mp3_menu(DListNode* head)
{
    char input;
    DListNode* current_song = head->rlink; // 현재 곡 노드를 가리키는 포인터
    while(1)
    {
        printf("========== PLAYLIST: ");
        print_list(head);
        printf("\n========== NOW PLAYING: %s==========\n", current_song->song_name);
        
        printf("========== MP3 플레이어 ==========\n");
        printf("명령어를 입력하세요-> a: 곡 추가 / s: 곡 삭제 / <: 왼쪽 곡 이동 / >: 오른쪽 곡 이동 / q: 프로그램 나가기\n");
        scanf(" %c", &input);

        switch(input)
        {
            case 'a':
                current_song = add_song(head, current_song);
                break;
            case 's':
                current_song = remove_song(head, current_song);
                break;
            case '<':
                current_song = current_song->llink;
                if(current_song == head)
                    current_song = current_song->llink;
                
                break;
            case '>':
                current_song = current_song->rlink;                
                if(current_song == head)
                    current_song = current_song->rlink;
                break;
            case 'q':
                break;
            default:
                printf("!: 잘못된 입력입니다.\n");
                break;
        }
        
        if(input == 'q')
            break;
    }
}

int main(void)
{
    DListNode* head = (DListNode*)malloc(sizeof(DListNode));
    init(head);
    mp3_menu(head);
}