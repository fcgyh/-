#include "class.h"
//本文件用于类及其成员函数的实现

void Item::effect()
{

    switch (index)
    {
    case 1:player.change_hp_max(factor1, add1); player.same_hp(); break;
    case 2:player.change_damage_point_max(factor1, add1); player.same_damage_point(); break;
    case 3:player.change_armor_max(factor1, add1); player.same_armor(); break;
    case 4:player.change_ap_max(factor1, add1); player.same_ap(); break;
    case 5:player.change_hp_max(factor1, add1);
        player.same_hp();
        player.change_damage_point_max(factor2, add2);
        player.same_damage_point();
        break;
    case 6:player.change_hp_max(factor1, add1);
        player.same_hp();
        player.change_armor_max(factor2, add2);
        player.same_armor();
        break;
    case 7:player.change_hp_max(factor1, add1);
        player.same_hp();
        player.change_ap_max(factor2, add2);
        player.same_ap();
        break;
    case 8:player.change_damage_point_max(factor1, add1);
        player.same_damage_point();
        player.change_armor_max(factor2, add2);
        player.same_armor();
        break;
    case 9:player.change_damage_point_max(factor1, add1);
        player.same_damage_point();
        player.change_ap_max(factor2, add2);
        player.same_ap();
        break;
    case 10:player.change_armor_max(factor1, add1);
        player.same_armor();
        player.change_ap_max(factor2, add2);
        player.same_ap();
        break;

    }
}
//技能类的函数实现
S::S(const string name, int choice, int target1, int index1, float factor1, float add1, int dice, int target2, int index2, float factor2, float add2, float cost)
    :name(name)
{
    this->target1 = target1;
    this->choice = choice;
    this->index1 = index1;
    this->factor1 = factor1;
    this->add1 = add1;
    this->dice = dice;
    this->index2 = index2;
    this->target2 = target2;
    this->factor2 = factor2;
    this->add2 = add2;
    this->cost = cost;
}
float S::effect(P& p, R& r, int user, int di)//当user 与target相同时，影响的是玩家，否则影响对手
{                                         //让di与dice作比较，小于则由第一类参数起作用，否则由第二类参数起作用
    float change = 0;//记录发生的效果，如果两个效果同时发生，记录第一个效果
    float change2 = 0;//专用于当两个效果同时发生时，记录第二个效果
    if (choice == 1)
    {
        if (di < dice)//第一类参数起作用
        {
            if (user == target1)//第一类参数影响玩家
            {
                switch (index1)
                {
                case 1:p.change_hp(factor1, add1); break;
                case 2:p.change_hp_max(factor1, add1); p.same_hp(); break;
                case 3:p.change_damage_point(factor1, add1);
                    if (p.get_damage_point() < 0)p.change_damage_point(0, 0);
                    break;
                case 4:p.change_damage_point_max(factor1, add1); p.same_damage_point(); break;
                case 5:p.change_armor(factor1, add1);
                    if (p.get_armor() < 0)p.change_armor(0, 0);
                    break;
                case 6:p.change_armor_max(factor1, add1); p.same_armor(); break;
                case 7:p.change_ap(factor1, add1);
                    if (p.get_ap() < 0)p.change_ap(0, 0);
                    break;
                case 8:p.change_ap_max(factor1, add1); p.same_ap(); break;
                }
            }
            else//第一类参数影响对手
            {
                switch (index1)
                {
                case 1:r.change_hp(factor1, add1); break;
                case 2:r.change_hp_max(factor1, add1); r.same_hp(); break;
                case 3:r.change_damage_point(factor1, add1);
                    if (r.get_damage_point() < 0)r.change_damage_point(0, 0);
                    break;
                case 4:r.change_damage_point_max(factor1, add1); r.same_damage_point(); break;
                case 5:r.change_armor(factor1, add1);
                    if (r.get_armor() < 0)r.change_armor(0, 0);
                    break;
                case 6:r.change_armor_max(factor1, add1); r.same_armor(); break;
                }
            }

        }
        else//第二类参数起作用
        {
            if (user == target2)//第二类参数影响玩家
            {
                switch (index2)
                {
                case 1:p.change_hp(factor2, add2); break;
                case 2:p.change_hp_max(factor2, add2); p.same_hp(); break;
                case 3:p.change_damage_point(factor2, add2);
                    if (p.get_damage_point() < 0)p.change_damage_point(0, 0);
                    break;
                case 4:p.change_damage_point_max(factor2, add2); p.same_damage_point(); break;
                case 5:p.change_armor(factor2, add2);
                    if (p.get_armor() < 0)p.change_armor(0, 0);
                    break;
                case 6:p.change_armor_max(factor2, add2); p.same_armor(); break;
                case 7:p.change_ap(factor2, add2);
                    if (p.get_ap() < 0)p.change_ap(0, 0);
                    break;
                case 8:p.change_ap_max(factor2, add2); p.same_ap(); break;
                }
            }
            else//第二类参数影响对手
            {
                switch (index2)
                {
                case 1:r.change_hp(factor2, add2); break;
                case 2:r.change_hp_max(factor2, add2); r.same_hp(); break;
                case 3:r.change_damage_point(factor2, add2);
                    if (r.get_damage_point() < 0)r.change_damage_point(0, 0);
                    break;
                case 4:r.change_damage_point_max(factor2, add2); r.same_damage_point(); break;
                case 5:r.change_armor(factor2, add2);
                    if (r.get_armor() < 0)r.change_armor(0, 0);
                    break;
                case 6:r.change_armor_max(factor2, add2); r.same_armor(); break;
                }
            }
        }
    }
    else
    {
        if (user == target1)//第一类参数影响玩家
        {
            switch (index1)
            {
            case 1:p.change_hp(factor1, add1); break;
            case 2:p.change_hp_max(factor1, add1); p.same_hp(); break;
            case 3:p.change_damage_point(factor1, add1);
                if (p.get_damage_point() < 0)p.change_damage_point(0, 0);
                break;
            case 4:p.change_damage_point_max(factor1, add1); p.same_damage_point(); break;
            case 5:p.change_armor(factor1, add1);
                if (p.get_armor() < 0)p.change_armor(0, 0);
                break;
            case 6:p.change_armor_max(factor1, add1); p.same_armor(); break;
            case 7:p.change_ap(factor1, add1);
                if (p.get_ap() < 0)p.change_ap(0, 0);
                break;
            case 8:p.change_ap_max(factor1, add1); p.same_ap(); break;
            }
        }
        else//第一类参数影响对手
        {
            switch (index1)
            {
            case 1:r.change_hp(factor1, add1); break;
            case 2:r.change_hp_max(factor1, add1); r.same_hp(); break;
            case 3:r.change_damage_point(factor1, add1);
                if (r.get_damage_point() < 0)r.change_damage_point(0, 0);
                break;
            case 4:r.change_damage_point_max(factor1, add1); r.same_damage_point(); break;
            case 5:r.change_armor(factor1, add1);
                if (r.get_armor() < 0)r.change_armor(0, 0);
                break;
            case 6:r.change_armor_max(factor1, add1); r.same_armor(); break;
            }
        }
        if (di >= dice)
        {
            if (user == target2)//第二类参数影响玩家
            {
                switch (index2)
                {
                case 1:p.change_hp(factor2, add2); break;
                case 2:p.change_hp_max(factor2, add2); p.same_hp(); break;
                case 3:p.change_damage_point(factor2, add2);
                    if (p.get_damage_point() < 0)p.change_damage_point(0, 0);
                    break;
                case 4:p.change_damage_point_max(factor2, add2); p.same_damage_point(); break;
                case 5:p.change_armor(factor2, add2);
                    if (p.get_armor() < 0)p.change_armor(0, 0);
                    break;
                case 6:p.change_armor_max(factor2, add2); p.same_armor(); break;
                case 7:p.change_ap(factor2, add2);
                    if (p.get_ap() < 0)p.change_ap(0, 0);
                    break;
                case 8:p.change_ap_max(factor2, add2); p.same_ap(); break;
                }
            }
            else//第二类参数影响对手
            {
                switch (index2)
                {
                case 1:r.change_hp(factor2, add2); break;
                case 2:r.change_hp_max(factor2, add2); r.same_hp(); break;
                case 3:r.change_damage_point(factor2, add2);
                    if (r.get_damage_point() < 0)r.change_damage_point(0, 0);
                    break;
                case 4:r.change_damage_point_max(factor2, add2); r.same_damage_point(); break;
                case 5:r.change_armor(factor2, add2);
                    if (r.get_armor() < 0)r.change_armor(0, 0);
                    break;
                case 6:r.change_armor_max(factor2, add2); r.same_armor(); break;
                }
            }
        }
    }
    if (!user)
        p.change_ap(1, -cost);
    return change + change2;
}
void S::say_discription(int di)
{
    if (choice == 1)
    {
        if (di < dice)
        {
            cout << endl << discription1 << endl;
        }
        else
        {
            cout << endl << discription2 << endl;
        }
    }
    else
    {
        if (di < dice)
        {
            cout << endl << discription1 << endl;
        }
        else
        {
            cout << endl << discription1 + discription_ + discription2 << endl;
        }
    }
}