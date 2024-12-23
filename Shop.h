#pragma once
#ifndef SHOP_H
#define SHOP_H

// 定义物品类型枚举
typedef enum {
    TYPE_WEAPON,
    TYPE_ARMOR,
    TYPE_DECORATION,
    TYPE_ELIXIR,
} ItemType;

struct Weapon//武器结构体 
{
    float ATK;
    int Coin;
};
struct Armor//防具结构体
{
    float HP;
    float DF;
    int Coin;
};
struct Decoration//饰品
{
    float ATK;
    float HP;
    float DF;
    int Coin;
};
struct ELIXIR//丹药 
{
    float rate;
    int Coin;
};
// 定义 Node 结构体，包含联合体和类型标识
struct Node {
    union ItemData {
        Weapon weapon;
        Armor armor;
        Decoration decoration;
        ELIXIR elixir;
    } item;
    int Type;
    struct Node* next;
} ;
void insertAtHead(Node** head, Node* newNode);
Node* createNode(int Type);
void Save_NodeList(Node* HeadNode);
void Load_Nodes(Node** L);
#endif // !SHOP_H