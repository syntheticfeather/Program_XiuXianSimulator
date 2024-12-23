#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "MainScreen.h"
#include "Shop.h"




Node* createNode(int Type) {
    // 动态分配内存给一个新的节点
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->Type = 4;
    return newNode; // 返回新创建的节点指针
}
//// 插入节点到链表头部
//void insertAtHead(Node** head, Node* newNode) {
//    if (newNode == NULL) return; // 如果新节点为空，则直接返回不做任何操作
//
//    // 将新节点插入到链表头部
//    newNode->next = *head; // 新节点的next指向前一个头节点
//    *head = newNode; // 更新头指针指向新节点
//}

//bool insert_item(Node* L, Node Node, int choice) 
//{    
//    Node* NewNode = (Node*)malloc(sizeof(Node));
//    Node* new_node = (Node*)malloc(sizeof(Node));
//    if (new_node == NULL) 
//    {
//        fprintf(stderr, "内存分配失败！\n");
//        return false; // 内存分配失败，插入失败
//    }
//
//
//    new_node->next = NULL; // 新节点的下一节点初始化为NULL
//
//    new_node->next = L->next; // 新节点的next指向当前链表的第一个节点
//    L->next = new_node; // 更新头节点的指针指向新节点
//
//    return true; // 插入成功
//}
void insertAtHead(Node** L, Node* item)
{
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        return; // 内存分配失败，插入失败
    }    
    new_node->item = item->item;
    new_node->Type = item->Type;
    new_node->next = NULL;
    if ((*L)->next == NULL) {
        (*L)->next = new_node; // 如果链表为空
    }
    else {
        Node* current = *L;
        while (current->next != NULL) {
            current = current->next; // 移动到下一个节点
        }
        current->next = new_node; // 将新节点插入到链表末尾
    }
}

//// ------------------------------------------------------------------------------------------------------------------------------------------------ -
//// 支付函数：尝试购买商品并从玩家的钱包中扣款
//void buyItem(Player_* player,int Type) {
//
//    // 检查玩家是否有足够的金币来购买此物品
//    if (player->Coin < newItem->item.elixir.Coin) {
//        printf("Insufficient funds to buy %s.\n", newItem->item.elixir.name);        
//    }
//    // 从玩家的金币中扣除相应的金额
//    player->Coin -= newItem->item.elixir.Coin;
//
//    // 替换同类型的现有装备（如果有）
//    int idx = newItem->type;
//    if (player->equipment[idx]) {
//        // 释放旧装备占用的内存
//        free(player->equipment[idx]);
//    }
//    player->equipment[idx] = newItem; // 将新装备指针存入对应位置
//
//    // 将新装备添加到玩家背包链表的头部
//    insertAtHead(&player->inventory, newItem);
//
//    // 打印购买成功的消息
//    printf("Bought %s for %d. Remaining Coin: %d\n", newItem->item.elixir.name, newItem->item.elixir.Coin, player->Coin);    
//}
////-------------------------------------------------------------------------------------------------------------------------------------------------
//
//
//
//// 使用药剂增加玩家属性
//int UseELIXIR(Node* current, Player_* player) { // 函数接收两个参数：指向当前节点（即要使用的药水）的指针和指向玩家结构体的指针
//    if (current == NULL || current->type != TYPE_ELIXIR)
//    {
//        return;
//    }
//    else
//    {
//        ELIXIR* elixir = &current->item.elixir; // 获取当前节点中存储的实际药水数据
//        // 打印一条消息显示药水使用后的效果
//        printf("Used Elixir: ATK +%d, DF +%d, HP +%d\n", elixir->ATK, elixir->DF, elixir->HP);
//
//        // 下面这段代码用于移除已经使用的药水节点
//        Node* prev = NULL; // 定义一个指向前一个节点的指针，初始值设为NULL
//        Node* temp = player->inventory; // 从玩家背包链表头部开始遍历寻找目标节点
//        while (temp && temp != current) { // 当未到达链表末尾且尚未找到目标节点时继续循环
//            prev = temp; // 更新前一个节点指针
//            temp = temp->next; // 移动到下一个节点
//        }
//        if (temp == current) { // 如果找到了匹配的节点
//            if (prev) { // 如果目标节点不是链表的第一个元素
//                prev->next = current->next; // 将前一个节点的next指针指向目标节点之后的节点
//            }
//            else { // 否则，如果目标节点是链表的第一个元素
//                player->inventory = current->next; // 更新玩家背包链表头部指针
//            }
//            free(current); // 释放不再需要的目标节点所占用的内存
//        }
//    }
//
//    
//}
//
//
//
//
//// 初始化玩家
//void initPlayer(Player_* player, const char* playerName, int ATK, int DF, int HP) { // 更新了参数类型
//    // 安全地复制玩家名字到结构体内存
//    strncpy(player->name, playerName, sizeof(player->name) - 1);
//    player->name[sizeof(player->name) - 1] = '\0'; // 确保字符串以null结尾
//
//    // 初始化玩家的基础属性
//    player->Coin = 4; // 初始金币数量
//    player->inventory = NULL; // 初始背包为空
//    for (int i = 0; i < 4; ++i) {
//        player->equipment[i] = NULL; // 初始化每个装备槽位为空
//    }
//    player->ATK = ATK; // 初始化攻击力
//    player->DF = DF; // 初始化防御力
//    player->HP = HP; // 初始化生命值
//}
//
//// 打印链表内容
//void printInventory(const Node* head) {
//    const Node* current = head;
//    while (current != NULL) {
//        // 根据节点类型打印不同格式的信息
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
//        current = current->next; // 移动到下一个节点
//    }
//}
//// 清理玩家资源
//void cleanupPlayer(Player_* player) { // 更新了参数类型
//    // 释放所有装备槽位中的内存
//    for (int i = 0; i < 4; ++i) {
//        if (player->equipment[i]) {
//            free(player->equipment[i]);
//        }
//    }
//
//    // 释放背包链表中的所有节点
//    Node* current = player->inventory;
//    while (current != NULL) {
//        Node* temp = current;
//        current = current->next;
//        free(temp);
//    }
//    player->inventory = NULL; // 最后将背包指针置为NULL
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