#ifndef UNI_FUN_H_INCLUDED
#define UNI_FUN_H_INCLUDED
#include "class.h"
using namespace std;
//本头文件用于存放广泛用到的函数
extern void set_color(int fore = 7, int bac = 0);//设置局部字体颜色
extern void star(int fore = 7, int bac = 0);//打印分割线，可设置颜色
extern void HideCursor();//隐藏光标
extern void ShowCursor();//显示光标
extern void show_state(P& p);//展示玩家当前的状态
extern void show_state(P& p, R& r);//展示双方当前的状态
extern int fate_dice();//命运之骰，6面
extern int hidden_dice(int MAX);//隐藏之骰，非命运之骰就用它
extern void show_item(vector <Item>::iterator bag_it, vector <Item> bag);//输出已有装备
extern void random_fall(int Max, vector<Item>& bag, vector<Item>::iterator& item_it, vector<Item>& item, P& p);//随机掉落装备,展示之，并施加影响
extern void show_skill(vector <S>::iterator skill_bag_it, vector <S> skill_bag);//输出已有技能
extern void random_fall_skill(int Max, vector<S>& skill_bag, vector<S>::iterator& skill_it, vector<S>& skill, P& p);//随机掉落技能,展示之
extern void save_BossName(string BossName);//保存boss名
extern void read_BossName(vector <string>& BossName_bag, vector <string>& BossName);//读取boss名
extern void show_BossName(vector <string>::iterator BossName_bag_it, vector <string> BossName_bag);//输出已打败boss名
extern int judge(P& p, R& r);//根据血量判断胜负
//利用judge函数判断胜负，然后据此让游戏继续或停止
extern int win_or_lose(P& p, R& r, int noI, vector<Item> bag, vector<Item>::iterator item_it,
    vector<Item>item, int noS, vector<S>skill_bag, vector<S>::iterator skill_it, vector<S> skill);
extern int dicision(int quit, int limit, char enter);//排除玩家的非法输入,(合法的输入范围应为[0,limit])
extern int show_choose();//显示战斗时的选择界面,让用户选择,排除非法选择，并且返回用户的选择
extern void my_turn(P& p, R& r, vector<S>skill_bag, vector<S>::iterator skill_bag_it);//轮到玩家时的各种过程
extern float attack(C& c1, C& c2);//普攻,c1攻击c2,返回造成的伤害
extern void correct(float damage, C& c);//根据c的防御力修正c受到的伤害
extern void rival_turn(P& p, R& r, string order, int& index, vector<S>r_skill, vector<S>::iterator skill_it);//对手出招
//战斗函数，包括了一个关卡的大部分战斗过程
extern int fight(P& p, R& r, int index, vector<S>skill_bag, vector<S>::iterator skill_bag_it, vector<S> skill_set, int nOI, vector<Item>bag, vector<Item>item,
    vector<Item>::iterator item_it, int nOS, vector<S>skill, vector<S>::iterator skill_it);
extern void take_item(vector<Item>& bag, vector<Item>::iterator& item_it);//获取装备，自动检查是否重复
extern void take_skill(vector<S>& skill_bag, vector<S>::iterator& skill_it);//获取技能，自动检查是否重复
//仙境(商店加奇遇)
extern void cure(P& p);//恢复玩家的所有状态，关卡结束后用
extern void cure(R& r);//恢复boss的所有状态，关卡结束后用
extern void save_level(int level);//保存level
extern void read_level(int& level);//读取level
extern void save_item(vector<Item>::iterator item_it);//保存装备
extern void read_item(vector<Item>& bag, vector<Item>& item);//读取装备
extern void save_skill(vector<S>::iterator skill_it);//保存技能
extern void read_skill(vector<S>& skill_bag, vector<S>& skill);//读取技能
extern void delete_save();//清档

#endif // UNI_FUN_H_INCLUDED
