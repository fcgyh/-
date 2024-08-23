#ifndef UNI_FUN_H_INCLUDED
#define UNI_FUN_H_INCLUDED
#include "class.h"
using namespace std;
//��ͷ�ļ����ڴ�Ź㷺�õ��ĺ���
extern void set_color(int fore = 7, int bac = 0);//���þֲ�������ɫ
extern void star(int fore = 7, int bac = 0);//��ӡ�ָ��ߣ���������ɫ
extern void HideCursor();//���ع��
extern void ShowCursor();//��ʾ���
extern void show_state(P& p);//չʾ��ҵ�ǰ��״̬
extern void show_state(P& p, R& r);//չʾ˫����ǰ��״̬
extern int fate_dice();//����֮����6��
extern int hidden_dice(int MAX);//����֮����������֮��������
extern void show_item(vector <Item>::iterator bag_it, vector <Item> bag);//�������װ��
extern void random_fall(int Max, vector<Item>& bag, vector<Item>::iterator& item_it, vector<Item>& item, P& p);//�������װ��,չʾ֮����ʩ��Ӱ��
extern void show_skill(vector <S>::iterator skill_bag_it, vector <S> skill_bag);//������м���
extern void random_fall_skill(int Max, vector<S>& skill_bag, vector<S>::iterator& skill_it, vector<S>& skill, P& p);//������似��,չʾ֮
extern void save_BossName(string BossName);//����boss��
extern void read_BossName(vector <string>& BossName_bag, vector <string>& BossName);//��ȡboss��
extern void show_BossName(vector <string>::iterator BossName_bag_it, vector <string> BossName_bag);//����Ѵ��boss��
extern int judge(P& p, R& r);//����Ѫ���ж�ʤ��
//����judge�����ж�ʤ����Ȼ��ݴ�����Ϸ������ֹͣ
extern int win_or_lose(P& p, R& r, int noI, vector<Item> bag, vector<Item>::iterator item_it,
    vector<Item>item, int noS, vector<S>skill_bag, vector<S>::iterator skill_it, vector<S> skill);
extern int dicision(int quit, int limit, char enter);//�ų���ҵķǷ�����,(�Ϸ������뷶ΧӦΪ[0,limit])
extern int show_choose();//��ʾս��ʱ��ѡ�����,���û�ѡ��,�ų��Ƿ�ѡ�񣬲��ҷ����û���ѡ��
extern void my_turn(P& p, R& r, vector<S>skill_bag, vector<S>::iterator skill_bag_it);//�ֵ����ʱ�ĸ��ֹ���
extern float attack(C& c1, C& c2);//�չ�,c1����c2,������ɵ��˺�
extern void correct(float damage, C& c);//����c�ķ���������c�ܵ����˺�
extern void rival_turn(P& p, R& r, string order, int& index, vector<S>r_skill, vector<S>::iterator skill_it);//���ֳ���
//ս��������������һ���ؿ��Ĵ󲿷�ս������
extern int fight(P& p, R& r, int index, vector<S>skill_bag, vector<S>::iterator skill_bag_it, vector<S> skill_set, int nOI, vector<Item>bag, vector<Item>item,
    vector<Item>::iterator item_it, int nOS, vector<S>skill, vector<S>::iterator skill_it);
extern void take_item(vector<Item>& bag, vector<Item>::iterator& item_it);//��ȡװ�����Զ�����Ƿ��ظ�
extern void take_skill(vector<S>& skill_bag, vector<S>::iterator& skill_it);//��ȡ���ܣ��Զ�����Ƿ��ظ�
//�ɾ�(�̵������)
extern void cure(P& p);//�ָ���ҵ�����״̬���ؿ���������
extern void cure(R& r);//�ָ�boss������״̬���ؿ���������
extern void save_level(int level);//����level
extern void read_level(int& level);//��ȡlevel
extern void save_item(vector<Item>::iterator item_it);//����װ��
extern void read_item(vector<Item>& bag, vector<Item>& item);//��ȡװ��
extern void save_skill(vector<S>::iterator skill_it);//���漼��
extern void read_skill(vector<S>& skill_bag, vector<S>& skill);//��ȡ����
extern void delete_save();//�嵵

#endif // UNI_FUN_H_INCLUDED
