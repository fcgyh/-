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
//��ͷ�ļ������������,�Լ�ȫ�ֱ������趨
class C;
class M;
class P;
class R;
class Item;

//ȫ�ֱ���
const int name_lenth = 10; //������󳤶�
const int numOfItem_1 = 9;//���������װ����
const int numOfItem_2 = 6;//Ӣ�����������װ����
const int numOfItem_3 = 10;//���μ������װ����
const int numOfSkill_1 = 9;//��������ļ�����
const int numOfSkill_2 = 10;//Ӣ����������ļ�����
const int numOfSkill_3 = 9;//���μ�����ļ�����
const int numOfItem_All = 25;//����װ����
const int numOfSkill_All = 28;//���м�����
extern int hidden_dice(int MAX);//����֮����������֮��������



//��ɫ��
class C
{
public:
    C(const string name, float hp_max, float damage_point_max, float armor_max) :name(name), hp_max(hp_max), damage_point_max(damage_point_max), armor_max(armor_max)
    {
        hp = hp_max;
        damage_point = damage_point_max;
        armor = armor_max;

    }
    //name�ӿ�
    const string get_name() { return name; }
    //hp�ӿ�
    void change_hp(float factor, float add) { hp = hp * factor + add; }
    float get_hp() { return hp; }
    void same_hp() { hp = hp_max; }
    //hp_max�ӿ�
    void change_hp_max(float factor, float add)
    {
        hp_max = hp_max * factor + add;
        if (hp > hp_max)
        {
            hp = hp_max;
        }
    }
    float get_hp_max() { return hp_max; }
    //damage_point�ӿ�
    void change_damage_point(float factor, float add) { damage_point = damage_point * factor + add; }
    float get_damage_point() { return damage_point; }
    void same_damage_point() { damage_point = damage_point_max; }
    //damage_point_max�ӿ�
    void change_damage_point_max(float factor, float add)
    {
        damage_point_max = damage_point_max * factor + add;
        if (damage_point > damage_point_max)
        {
            damage_point = damage_point_max;
        }
    }
    float get_damage_point_max() { return damage_point_max; }
    //armor�ӿ�
    void change_armor(float factor, float add) { armor = armor * factor + add; }
    float get_armor() { return armor; }
    void same_armor() { armor = armor_max; }

    //armor_max�ӿ�
    void change_armor_max(float factor, float add)
    {
        armor_max = armor_max * factor + add;
        if (armor > armor_max)
        {
            armor = armor_max;
        }
    }
    float get_armor_max() { return armor_max; }
    //�����ǽӿ�
private:
    const string name;
    float hp;
    float hp_max;
    float damage_point;
    float damage_point_max;
    float armor;
    float armor_max;
};

//�����
class P :public C
{
public:
    P(const string name, float hp_max, float damage_point_max, float armor_max, float ap_max) :C(name, hp_max, damage_point_max, armor_max), ap_max(ap_max)
    {
        ap = ap_max;
    }
    //ap�ӿ�
    void change_ap(float factor, float add) { ap = ap * factor + add; }
    float get_ap() { return ap; }
    void same_ap() { ap = ap_max; }
    //ap_max�ӿ�
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

//������
class R :public C
{
public:
    R(const string name, float hp_max, float damage_point_max, float armor_max) :C(name, hp_max, damage_point_max, armor_max) {}
    void attack(P& p) { float damage = get_damage_point(); damage = -damage; p.change_hp(1, damage); }
    void give_order(string order) { this->order += order; }//�趨����˳��
    string show_order() { return order; }//���س���˳��
private:
    string order = "";//����˳��
};

//�ؿ���
class M
{
public:
    M(P& p, R& r) :p(p), r(r) {}
private:
    P& p;
    R& r;
};

//��Ʒ�ࣨ������װ����ҩƷ֮��ġ����üӳɡ��Ķ�����������Щ����ֻ�ӳ����޵ģ�
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
    int index;    //��Ϊ������1.hp����; 2.������; 3.������;4.AP����;5.hp&��;6.hP&��;7. hp&ap;8.��&��;9.��&AP;10.��&AP;
    float factor1;
    float add1;
    float factor2;
    float add2;
    P& player;
};
//������
class S
{
public:
    S(const string name, int choice, int target1, int index1, float factor1, float add1, int dice, int target2, int index2, float factor2, float add2, float cost);
    //�趨��������
    void give_discription(string cost_dis, string discription1, string discription2)
    {
        this->discription1 += discription1;
        this->discription2 += discription2;
        this->cost_dis += cost_dis;
    }
    //���ܲ�����Ч��
    float effect(P& p, R& r, int user, int di);
    string show_name() { return name; }
    string show_discription() { return cost_dis + discription_ + discription1 + discription_ + discription2; }
    void say_discription(int di);//coutʵ�ʲ�����Ч�������Ķ�
    float show_cost() { return cost; }//�������ĵ�����ֵ
private:
    const string name;
    string discription1 = "";
    string discription2 = "";
    string cost_dis = "";
    string discription_ = ",";
    /*
    P &p;
    R &r;
    int user;//���ܵ�ʹ����:0����ң�1�Ƕ���
    */
    int choice;//��choice==1ʱ������Ч��ִֻ��һ�֣���choice==0ʱ��ͬʱִ��
    int target1;//�� "���ӵ���" �� "�ٽ�ֵ" ʱ���õĶ���0���Լ���1�Ƕ���
    int target2;//�� "���ӵ���" �� "�ٽ�ֵ" ʱ���õĶ���0���Լ���1�Ƕ���
    int dice;//�趨�������ٽ�ֵ
    int index1;//�͵���ʱ������
    int index2;//�ߵ���ʱ������
    //ǰ�����ǵ͵��������ò������������Ǹߵ��������ò���
    float factor1;
    float add1;
    float factor2;
    float add2;
    float cost;//�ͷż���ʱ���ĵ�����
};


#endif // CLASS_H_INCLUDED
