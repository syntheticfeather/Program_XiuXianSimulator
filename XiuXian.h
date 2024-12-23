#pragma once
#ifndef TTT
#define TTT

struct Weapon* CreateWeapon(struct Player_* Player_1);
struct Armor* CreatArmor(struct Player_* Player_1);
struct Decoration* CreateDecoration(struct Player_* Player_1);
struct ELIXIR* CreateElixir(struct Player_* Player_1);
void* AddExp(void* args, struct Player_* Player_1);
void* AddAge(void* args, struct Player_* Player_1);
int UnLoad(struct Player_* Player_1, int);
int Wearing(struct Node* current, struct Player_* Player_1);


#endif // !TTT
