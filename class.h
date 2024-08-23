#ifndef CLASS_H_INCLUDED
#define CLASS_H_INCLUDED
#include <string>
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <fstream>

using namespace std;
//本头文件用于类的声明,以及全局变量的设定
class C;
class M;
class P;
class R;
class Item;

//全局变量
const int name_lenth = 10; //名字最大长度
const int numOfItem_1 = 9;//三国主题的装备数
const int numOfItem_2 = 6;//英雄联盟主题的装备数
const int numOfItem_3 = 10;//西游记主题的装备数
const int numOfSkill_1 = 9;//三国主题的技能数
const int numOfSkill_2 = 10;//英雄联盟主题的技能数
const int numOfSkill_3 = 9;//西游记主题的技能数
const int numOfItem_All = 25;//所有装备数
const int numOfSkill_All = 28;//所有技能数
extern int hidden_dice(int MAX);//隐藏之骰，非命运之骰就用它



//角色类
class C
{
public:
    C(const string name, float hp_max, float damage_point_max, float armor_max) :name(name), hp_max(hp_max), damage_point_max(damage_point_max), armor_max(armor_max)
    {
        hp = hp_max;
        damage_point = damage_point_max;
        armor = armor_max;

    }
    //name接口
    const string get_name() { return name; }
    //hp接口
    void change_hp(float factor, float add) { hp = hp * factor + add; }
    float get_hp() { return hp; }
    void same_hp() { hp = hp_max; }
    //hp_max接口
    void change_hp_max(float factor, float add)
    {
        hp_max = hp_max * factor + add;
        if (hp > hp_max)
        {
            hp = hp_max;
        }
    }
    float get_hp_max() { return hp_max; }
    //damage_point接口
    void change_damage_point(float factor, float add) { damage_point = damage_point * factor + add; }
    float get_damage_point() { return damage_point; }
    void same_damage_point() { damage_point = damage_point_max; }
    //damage_point_max接口
    void change_damage_point_max(float factor, float add)
    {
        damage_point_max = damage_point_max * factor + add;
        if (damage_point > damage_point_max)
        {
            damage_point = damage_point_max;
        }
    }
    float get_damage_point_max() { return damage_point_max; }
    //armor接口
    void change_armor(float factor, float add) { armor = armor * factor + add; }
    float get_armor() { return armor; }
    void same_armor() { armor = armor_max; }

    //armor_max接口
    void change_armor_max(float factor, float add)
    {
        armor_max = armor_max * factor + add;
        if (armor > armor_max)
        {
            armor = armor_max;
        }
    }
    float get_armor_max() { return armor_max; }
    //以上是接口
private:
    const string name;
    float hp;
    float hp_max;
    float damage_point;
    float damage_point_max;
    float armor;
    float armor_max;
};

//玩家类
class P :public C
{
public:
    P(const string name, float hp_max, float damage_point_max, float armor_max, float ap_max) :C(name, hp_max, damage_point_max, armor_max), ap_max(ap_max)
    {
        ap = ap_max;
    }
    //ap接口
    void change_ap(float factor, float add) { ap = ap * factor + add; }
    float get_ap() { return ap; }
    void same_ap() { ap = ap_max; }
    //ap_max接口
    void change_ap_max(float factor, float add) { ap_max = ap_max * factor + add; }
    float get_ap_max() { return ap_max; }
    void reset()
    {
        change_hp_max(0, 100); change_damage_point_max(0, 45); change_armor_max(0, 10); change_ap_max(0, 100);
    }
private:
    float ap;
    float ap_max;
};

//对手类
class R :public C
{
public:
    R(const string name, float hp_max, float damage_point_max, float armor_max) :C(name, hp_max, damage_point_max, armor_max) {}
    void attack(P& p) { float damage = get_damage_point(); damage = -damage; p.change_hp(1, damage); }
    void give_order(string order) { this->order += order; }//设定出招顺序
    string show_order() { return order; }//返回出招顺序
private:
    string order = "";//出招顺序
};

//关卡类
class M
{
public:
    M(P& p, R& r) :p(p), r(r) {}
private:
    P& p;
    R& r;
};

//物品类（包括了装备和药品之类的“永久加成”的东西，所以这些都是只加成上限的）
class Item
{
public:
    Item(const string name, const string discription, int index, float factor1, float add1, float factor2, float add2, P& player)
        :name(name), discription(discription), index(index), factor1(factor1), add1(add1), factor2(factor2), add2(add2), player(player) {}
    void effect();
    const string get_name() { return name; }
    const string get_discription() { return discription; }
private:
    const string name;
    const string discription;
    int index;    //作为索引：1.hp上限; 2.攻上限; 3.防上限;4.AP上限;5.hp&攻;6.hP&防;7. hp&ap;8.攻&防;9.攻&AP;10.防&AP;
    float factor1;
    float add1;
    float factor2;
    float add2;
    P& player;
};
//技能类
class S
{
public:
    S(const string name, int choice, int target1, int index1, float factor1, float add1, int dice, int target2, int index2, float factor2, float add2, float cost);
    //设定技能描述
    void give_discription(string cost_dis, string discription1, string discription2)
    {
        this->discription1 += discription1;
        this->discription2 += discription2;
        this->cost_dis += cost_dis;
    }
    //技能产生的效果
    float effect(P& p, R& r, int user, int di);
    string show_name() { return name; }
    string show_discription() { return cost_dis + discription_ + discription1 + discription_ + discription2; }
    void say_discription(int di);//cout实际产生的效果，待改动
    float show_cost() { return cost; }//返回消耗的体力值
private:
    const string name;
    string discription1 = "";
    string discription2 = "";
    string cost_dis = "";
    string discription_ = ",";
    /*
    P &p;
    R &r;
    int user;//技能的使用者:0是玩家，1是对手
    */
    int choice;//当choice==1时，两种效果只执行一种，当choice==0时，同时执行
    int target1;//当 "骰子点数" ＜ "临界值" 时作用的对象：0是自己，1是对手
    int target2;//当 "骰子点数" ≥ "临界值" 时作用的对象：0是自己，1是对手
    int dice;//设定的骰子临界值
    int index1;//低点数时的索引
    int index2;//高点数时的索引
    //前两个是低点数的作用参数，后两个是高点数的作用参数
    float factor1;
    float add1;
    float factor2;
    float add2;
    float cost;//释放技能时消耗的体力
};


#endif // CLASS_H_INCLUDED
