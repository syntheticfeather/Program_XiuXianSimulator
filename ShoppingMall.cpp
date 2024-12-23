#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "MainScreen.h"
#include "Shop.h"




Node* createNode(int Type) {
    // ��̬�����ڴ��һ���µĽڵ�
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->Type = 4;
    return newNode; // �����´����Ľڵ�ָ��
}
//// ����ڵ㵽����ͷ��
//void insertAtHead(Node** head, Node* newNode) {
//    if (newNode == NULL) return; // ����½ڵ�Ϊ�գ���ֱ�ӷ��ز����κβ���
//
//    // ���½ڵ���뵽����ͷ��
//    newNode->next = *head; // �½ڵ��nextָ��ǰһ��ͷ�ڵ�
//    *head = newNode; // ����ͷָ��ָ���½ڵ�
//}

//bool insert_item(Node* L, Node Node, int choice) 
//{    
//    Node* NewNode = (Node*)malloc(sizeof(Node));
//    Node* new_node = (Node*)malloc(sizeof(Node));
//    if (new_node == NULL) 
//    {
//        fprintf(stderr, "�ڴ����ʧ�ܣ�\n");
//        return false; // �ڴ����ʧ�ܣ�����ʧ��
//    }
//
//
//    new_node->next = NULL; // �½ڵ����һ�ڵ��ʼ��ΪNULL
//
//    new_node->next = L->next; // �½ڵ��nextָ��ǰ����ĵ�һ���ڵ�
//    L->next = new_node; // ����ͷ�ڵ��ָ��ָ���½ڵ�
//
//    return true; // ����ɹ�
//}
void insertAtHead(Node** L, Node* item)
{
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        return; // �ڴ����ʧ�ܣ�����ʧ��
    }    
    new_node->item = item->item;
    new_node->Type = item->Type;
    new_node->next = NULL;
    if ((*L)->next == NULL) {
        (*L)->next = new_node; // �������Ϊ��
    }
    else {
        Node* current = *L;
        while (current->next != NULL) {
            current = current->next; // �ƶ�����һ���ڵ�
        }
        current->next = new_node; // ���½ڵ���뵽����ĩβ
    }
}

//// ------------------------------------------------------------------------------------------------------------------------------------------------ -
//// ֧�����������Թ�����Ʒ������ҵ�Ǯ���пۿ�
//void buyItem(Player_* player,int Type) {
//
//    // �������Ƿ����㹻�Ľ�����������Ʒ
//    if (player->Coin < newItem->item.elixir.Coin) {
//        printf("Insufficient funds to buy %s.\n", newItem->item.elixir.name);        
//    }
//    // ����ҵĽ���п۳���Ӧ�Ľ��
//    player->Coin -= newItem->item.elixir.Coin;
//
//    // �滻ͬ���͵�����װ��������У�
//    int idx = newItem->type;
//    if (player->equipment[idx]) {
//        // �ͷž�װ��ռ�õ��ڴ�
//        free(player->equipment[idx]);
//    }
//    player->equipment[idx] = newItem; // ����װ��ָ������Ӧλ��
//
//    // ����װ����ӵ���ұ��������ͷ��
//    insertAtHead(&player->inventory, newItem);
//
//    // ��ӡ����ɹ�����Ϣ
//    printf("Bought %s for %d. Remaining Coin: %d\n", newItem->item.elixir.name, newItem->item.elixir.Coin, player->Coin);    
//}
////-------------------------------------------------------------------------------------------------------------------------------------------------
//
//
//
//// ʹ��ҩ�������������
//int UseELIXIR(Node* current, Player_* player) { // ������������������ָ��ǰ�ڵ㣨��Ҫʹ�õ�ҩˮ����ָ���ָ����ҽṹ���ָ��
//    if (current == NULL || current->type != TYPE_ELIXIR)
//    {
//        return;
//    }
//    else
//    {
//        ELIXIR* elixir = &current->item.elixir; // ��ȡ��ǰ�ڵ��д洢��ʵ��ҩˮ����
//        // ��ӡһ����Ϣ��ʾҩˮʹ�ú��Ч��
//        printf("Used Elixir: ATK +%d, DF +%d, HP +%d\n", elixir->ATK, elixir->DF, elixir->HP);
//
//        // ������δ��������Ƴ��Ѿ�ʹ�õ�ҩˮ�ڵ�
//        Node* prev = NULL; // ����һ��ָ��ǰһ���ڵ��ָ�룬��ʼֵ��ΪNULL
//        Node* temp = player->inventory; // ����ұ�������ͷ����ʼ����Ѱ��Ŀ��ڵ�
//        while (temp && temp != current) { // ��δ��������ĩβ����δ�ҵ�Ŀ��ڵ�ʱ����ѭ��
//            prev = temp; // ����ǰһ���ڵ�ָ��
//            temp = temp->next; // �ƶ�����һ���ڵ�
//        }
//        if (temp == current) { // ����ҵ���ƥ��Ľڵ�
//            if (prev) { // ���Ŀ��ڵ㲻������ĵ�һ��Ԫ��
//                prev->next = current->next; // ��ǰһ���ڵ��nextָ��ָ��Ŀ��ڵ�֮��Ľڵ�
//            }
//            else { // �������Ŀ��ڵ�������ĵ�һ��Ԫ��
//                player->inventory = current->next; // ������ұ�������ͷ��ָ��
//            }
//            free(current); // �ͷŲ�����Ҫ��Ŀ��ڵ���ռ�õ��ڴ�
//        }
//    }
//
//    
//}
//
//
//
//
//// ��ʼ�����
//void initPlayer(Player_* player, const char* playerName, int ATK, int DF, int HP) { // �����˲�������
//    // ��ȫ�ظ���������ֵ��ṹ���ڴ�
//    strncpy(player->name, playerName, sizeof(player->name) - 1);
//    player->name[sizeof(player->name) - 1] = '\0'; // ȷ���ַ�����null��β
//
//    // ��ʼ����ҵĻ�������
//    player->Coin = 4; // ��ʼ�������
//    player->inventory = NULL; // ��ʼ����Ϊ��
//    for (int i = 0; i < 4; ++i) {
//        player->equipment[i] = NULL; // ��ʼ��ÿ��װ����λΪ��
//    }
//    player->ATK = ATK; // ��ʼ��������
//    player->DF = DF; // ��ʼ��������
//    player->HP = HP; // ��ʼ������ֵ
//}
//
//// ��ӡ��������
//void printInventory(const Node* head) {
//    const Node* current = head;
//    while (current != NULL) {
//        // ���ݽڵ����ʹ�ӡ��ͬ��ʽ����Ϣ
//        switch (current->type) {
//        case TYPE_WEAPON:
//            printf("Weapon: %s, ATK: %d, Coin: %d\n", current->item.weapon.name, current->item.weapon.ATK, current->item.weapon.Coin);
//            break;
//        case TYPE_ARMOR:
//            printf("Armor: %s, HP: %d, DF: %d, Coin: %d\n", current->item.armor.name, current->item.armor.HP, current->item.armor.DF, current->item.armor.Coin);
//            break;
//        case TYPE_DECORATION:
//            printf("Decoration: %s, ATK: %d, HP: %d, DF: %d, Coin: %d\n", current->item.accessory.name, current->item.accessory.ATK, current->item.accessory.HP, current->item.accessory.DF, current->item.accessory.Coin);
//            break;
//        case TYPE_ELIXIR:
//            printf("Elixir: %s, ATK +%d, DF +%d, HP +%d, Coin: %d\n", current->item.elixir.name, current->item.elixir.ATK, current->item.elixir.DF, current->item.elixir.HP, current->item.elixir.Coin);
//            break;
//        }
//        current = current->next; // �ƶ�����һ���ڵ�
//    }
//}
//// ���������Դ
//void cleanupPlayer(Player_* player) { // �����˲�������
//    // �ͷ�����װ����λ�е��ڴ�
//    for (int i = 0; i < 4; ++i) {
//        if (player->equipment[i]) {
//            free(player->equipment[i]);
//        }
//    }
//
//    // �ͷű��������е����нڵ�
//    Node* current = player->inventory;
//    while (current != NULL) {
//        Node* temp = current;
//        current = current->next;
//        free(temp);
//    }
//    player->inventory = NULL; // ��󽫱���ָ����ΪNULL
//}
//
void Load_Nodes(Node** L)
{
    FILE* fp;    
    Node* p, * r, * TempNode;
    *L = (Node*)malloc(sizeof(Node));
    r = *L;
    if ((fp = fopen("Bag.txt", "r")) == NULL)
    {
        return;
    }
    else 
    {
        while (!feof(fp)) {
            TempNode = (Node*)malloc(sizeof(Node));
            if (TempNode == NULL)
            {
                return;
            }
            fscanf(fp, "%d ", &TempNode->Type);
            switch (TempNode->Type) {
            case TYPE_WEAPON:
                fscanf(fp,"%f %d\n",&TempNode->item.weapon.ATK, &TempNode->item.weapon.Coin);
                break;
            case TYPE_ARMOR:
                fscanf(fp,"%f %f %d\n", &TempNode->item.armor.HP, &TempNode->item.armor.DF, &TempNode->item.armor.Coin);
                break;
             case TYPE_DECORATION:
                fscanf(fp,"%f %f %f %d\n", &TempNode->item.decoration.ATK, &TempNode->item.decoration.HP, &TempNode->item.decoration.DF, &TempNode->item.decoration.Coin);
                break;
            case TYPE_ELIXIR:
                fscanf(fp,"%f %d\n", &TempNode->item.elixir.rate, &TempNode->item.elixir.Coin);
                break;
            }            
            p = (Node*)malloc(sizeof(Node));
            p = TempNode;
            r->next = p;
            r = p;            
        }
    }
    fclose(fp);
    r->next = NULL;    
}

void Save_NodeList(Node* HeadNode) {
    FILE* file = fopen("Bag.txt", "w");
    if (file == NULL)
    {
        return;
    }
    Node* Cur = HeadNode;
    while (Cur != NULL)
    {
        switch (Cur->Type) 
        {
        case TYPE_WEAPON:
            fprintf(file, "0 %f %d\n", Cur->item.weapon.ATK, Cur->item.weapon.Coin);
            break;
        case TYPE_ARMOR:
            fprintf(file, "1 %f %f %d\n", Cur->item.armor.HP, Cur->item.armor.DF, Cur->item.armor.Coin);
            break;
        case TYPE_DECORATION:
            fprintf(file, "2 %f %f %f %d\n", Cur->item.decoration.ATK, Cur->item.decoration.HP, Cur->item.decoration.DF, Cur->item.decoration.Coin);
            break;
        case TYPE_ELIXIR:
            fprintf(file, "3 %f %d\n", Cur->item.elixir.rate, Cur->item.elixir.Coin);
            break;
        }
        Cur = Cur->next;
    }
    fclose(file);
}