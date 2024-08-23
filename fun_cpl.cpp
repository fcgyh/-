#include "class.h"
using namespace std;
//本文件用于非成员函数的实现

//设置局部字体颜色
void set_color(int fore = 7, int bac = 0)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (bac << 4) + fore);
}
/* 本游戏可能会用到的颜色
0-黑   7-白   4-红   6-黄   5-紫
*/
void star(int fore = 7, int bac = 0)
{
    set_color(fore, bac);
    cout << endl << "*************************************************************" << endl;
    set_color();
}
//隐藏光标
void HideCursor()
{
    CONSOLE_CURSOR_INFO cur = { 1,0 };
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cur);
}
//显示光标
void ShowCursor()
{
    CONSOLE_CURSOR_INFO cur = { 1,1 };
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cur);
}
//命运之骰，6面
int fate_dice()
{
    int j;
    HideCursor();//隐藏光标
    int Dice;
    set_color(0xB, 0);
    cout << endl << "命运之骰正在转动！！！" << endl;
    Sleep(300);
    for (j = 0; j < 20; ++j)        //点数的闪现
    {

        Dice = rand() % 6 + 1;
        cout << Dice;
        Sleep(60);
        if (j < 19)
            cout << "\b";
    }
    set_color();
    ShowCursor();//显示光标
    cout << endl;
    return Dice;
}
//隐藏之骰,随机生成[0,MAX)的数，非命运之骰就用它
int hidden_dice(int MAX)
{
    int dice = rand() % (MAX);
    return dice;
}
//展示玩家的状态
void show_state(P& p)
{
    extern void set_color(int fore = 7, int bac = 0);
    star(2, 0);
    set_color(6, 0);
    cout << "玩家当前状态(括号内为上限值)" << endl;
    cout << "血量: " << p.get_hp() << "(" << p.get_hp_max() << ")  攻击力:" << p.get_damage_point() << "(" << p.get_damage_point_max() << "）";
    cout << "防御力: " << p.get_armor() << "(" << p.get_armor_max() << ")  体力:" << p.get_ap() << "(" << p.get_ap_max() << ")" << endl;
    set_color();
}
//展示双方的状态
void show_state(P& p, R& r)
{
    extern void set_color(int fore = 7, int bac = 0);
    star(2, 0);
    set_color(6, 0);
    float p_hp = p.get_hp();
    float p_dp = p.get_damage_point();
    float p_arm = p.get_armor();
    float p_ap = p.get_ap();

    float r_hp = r.get_hp();
    float r_dp = r.get_damage_point();
    float r_arm = r.get_armor();
    //防止有的量小于零
    if (p_hp < 0)
        p_hp = 0;
    if (p_dp < 0)
        p_dp = 0;
    if (p_arm < 0)
        p_arm = 0;
    if (p_ap < 0)
        p_ap = 0;

    if (r_hp < 0)
        r_hp = 0;
    if (r_dp < 0)
        r_dp = 0;
    if (r_arm < 0)
        r_arm = 0;

    cout << "玩家当前状态" << endl;
    cout << "血量: " << p_hp << "  攻击力:" << p_dp;
    cout << "防御力: " << p_arm << "  体力:" << p_ap << endl;
    set_color(4, 0);
    cout << "对手当前状态" << endl;
    cout << "血量: " << r_hp << "  攻击力:" << r_dp;
    cout << "防御力: " << r_arm << endl;
    set_color();
}
//展示玩家所有的装备
void show_item(vector <Item>::iterator bag_it, vector <Item> bag)
{
    int index;//索引
    set_color(9, 0);
    cout << "你已经拥有的装备: " << endl;
    set_color(3, 0);
    for (index = 0, bag_it = bag.begin(); bag_it != bag.end(); ++bag_it, ++index)
    {
        cout << index << bag_it->get_name() << "(" << bag_it->get_discription() << ")" << endl;
    }
    set_color();
}
//随机掉落装备，展示玩家获得的装备,并附上影响
void random_fall(int Max, vector<Item>& bag, vector<Item>::iterator& item_it, vector<Item>& item, P& p)
{
    extern void save_item(vector<Item>::iterator item_it);
    int dice;
    int flag = 0;//0代表不重复，1代表重复
    item_it = item.begin();
    dice = hidden_dice(Max);
    item_it += dice;
    set_color(3, 0);
    for (auto i : bag)
    {
        if (i.get_name() == item_it->get_name())
        {
            flag++;
            break;
        }
    }
    if (!flag)//若不重复
    {
        bag.push_back(*item_it);//将容器item中相应的元素复制给bag的容器，所以玩家获得了装备
        save_item(item_it);
        cout << endl << "你获得了装备---- " << item_it->get_name() << "(" << item_it->get_discription() << ")" << endl;
        item_it->effect();
        item_it = item.begin();
    }
    else
    {
        cout << endl << "掉落的装备重复了" << endl;
    }
    set_color();
}

//随机掉落技能，展示玩家获得的技能,并附上影响
void random_fall_skill(int Max, vector<S>& skill_bag, vector<S>::iterator& skill_it, vector<S>& skill, P& p)
{
    extern void save_skill(vector<S>::iterator skill_it);
    int dice;
    int flag = 0;//0为不重复，1是重复
    skill_it = skill.begin();
    dice = hidden_dice(Max);
    skill_it += dice;
    for (auto i : skill_bag)
    {
        if (i.show_name() == skill_it->show_name())
        {
            flag++;
            break;
        }
    }
    set_color(3, 0);
    if (!flag)
    {
        skill_bag.push_back(*skill_it);//将容器item中相应的元素复制给bag的容器，所以玩家获得了技能
        save_skill(skill_it);
        cout << endl << "你获得了技能---- " << skill_it->show_name() << "(" << skill_it->show_discription() << ")" << endl;
        skill_it = skill.begin();
    }
    else
    {
        cout << "掉落的技能重复了" << endl;
    }
    set_color();

}

//输出玩家已有的技能
void show_skill(vector <S>::iterator skill_bag_it, vector <S> skill_bag)
{
    int index;//索引
    cout << endl;
    set_color(9, 0);
    cout << "你已经拥有的技能: " << endl;
    set_color(3, 0);
    for (index = 0, skill_bag_it = skill_bag.begin(); skill_bag_it != skill_bag.end(); ++skill_bag_it, ++index)
    {
        cout << index << ". " << skill_bag_it->show_name() << "(" << skill_bag_it->show_discription() << ")" << endl;
    }
    set_color();
}
//根据血量判断胜负，
int judge(P& p, R& r)//返回值：0.未分出胜负，1.玩家胜，2.对手胜
{
    if (p.get_hp() <= 0)
    {
        return 2;
    }
    else if (r.get_hp() <= 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
//保存boss名
void save_BossName(string BossName)
{
    ofstream out("BossName.txt", ios::app);
    out << BossName << "\n";
    out.close();
}
//读取boss名
void read_BossName(vector <string>& BossName_bag, vector <string>& BossName)
{
    string b_name_temp;//先将存档里的boss名称都暂时存在这里
    ifstream in("BossName.txt");
    in.seekg(ios::beg);
    while (!in.eof())
    {
        getline(in, b_name_temp);
        for (auto i : BossName)
        {
            if (b_name_temp == i)
            {
                BossName_bag.push_back(i);
            }
        }
    }
    in.close();
}
//输出已打败boss名
void show_BossName(vector <string>::iterator BossName_bag_it, vector <string> BossName_bag)
{
    int index;//索引
    set_color(9, 0);
    cout << "本次旅程中，你已打败了" << endl;
    set_color(3, 0);
    for (index = 0, BossName_bag_it = BossName_bag.begin(); BossName_bag_it != BossName_bag.end(); ++BossName_bag_it, ++index)
    {
        cout << index << " " << *BossName_bag_it << endl;
    }
    cout << endl;
    set_color();
}


//根据场上人物血量让游戏停止还是继续
int win_or_lose(P& p, R& r, int noI, vector<Item> bag, vector<Item>::iterator item_it,
    vector<Item>item, int noS, vector<S>skill_bag, vector<S>::iterator skill_it,
    vector<S> skill)
{
    extern int dicision(int quit, int limit, char enter);
    char char_dicision_ = '0';
    int judge_ = 0;//该函数要返回的判断值，0是未分胜负，1是玩家胜，2是玩家输了选择重新开始
    switch (judge(p, r))
    {
    /*未分胜负*/case 0:break;
    /*玩家胜*/  case 1:judge_++;
        break;
    /*对手胜*/  case 2:cout << "游戏结束" << endl << "你希望再来一次吗？" << endl
        << "0.再来一次 1.关闭游戏" << endl;
        int dicision_;
        cin >> char_dicision_;
        dicision_ = dicision(0, 2, char_dicision_);
        if (!dicision_)judge_ = 2;
        else exit(0);
        break;
    }
    return judge_;
}
//限制输入的范围:[0,limit],enter是用户的输入，当输入合法则返回之
int dicision(int quit, int limit, char enter)//当quit为0，则说明这里不能退出选择，当quit为1，则用户可以按'q'退出到上一步
{
    if (quit)//允许退到上一步
    {
        if (enter == 'q')
            return -1;
        char enter2 = enter;
        while (enter2<'0' || enter2>limit + 48)
        {
            cout << "“别给我输入乱七八糟的东西，请按范围输入！”仿佛在你的脑海中有一位老者没好气地说道" << endl;
            cin >> enter2;
            fflush(stdin);
            if (enter2 == 'q')
                return -1;
        }
        int good_enter = enter2 - 48;
        return good_enter;
    }
    else//不能退到上一步
    {
        char enter2 = enter;
        while (enter2<'0' || enter2>limit + 48)
        {

            cout << "“别给我输入乱七八糟的东西，请按范围输入！”仿佛在你的脑海中有一位老者没好气地说道" << endl;
            cin >> enter2;
            fflush(stdin);

        }
        int good_enter = enter2 - 48;
        return good_enter;
    }
}
//显示出战斗时的选择界面，让用户选择,排除非法选择，并且返回用户的选择
int show_choose()
{
    cout << endl << "做出你的选择" << endl << "0.普攻  1.技能" << endl;
    char char_choose_;
    int choose_;
    cin >> char_choose_;
    fflush(stdin);
    choose_ = dicision(0, 1, char_choose_);
    return choose_;
}
//轮到玩家时的各种过程
void my_turn(P& p, R& r, vector<S>skill_bag, vector<S>::iterator skill_bag_it)
{
    extern float attack(C & c1, C & c2);
    extern void correct(float damage, C & c);
    int check = 0;//用来检查玩家是否出招,0否,1是
    int dici;//选择界面专用
    show_state(p, r);
    Sleep(500);
    while (!check)
    {
        dici = show_choose();
        if (dici == 0)//进行普攻
        {
            //这两行很重要，可以对造成的伤害进行修正：先由attack()返回造成的伤害，再由correc()进行伤害修正
            float damage = attack(p, r);
            cout << r.get_name();
            correct(damage, r);
            Sleep(800);
            show_state(p, r);
            check = 1;
        }
        else //使用技能
        {
            if (skill_bag.size() == 0)
            {
                cout << "你还没有技能,请重新选择";
                Sleep(500);
            }
            else
            {
                show_skill(skill_bag_it, skill_bag);
                cout << endl << "请根据编号选择你的技能，你也可以输入'q'退出" << endl;
                int li = skill_bag.size() - 1;//让背包里的技能数成为选择的上限
                char char_en;
                int en;//玩家的选择
                int di;//储存命运之骰的点数
                cin >> char_en;
                fflush(stdin);
                en = dicision(1, li, char_en);
                if (en >= 0)//选了某个技能
                {
                    while (!check)
                    {
                        skill_bag_it = skill_bag.begin();
                        skill_bag_it += en;
                        if (skill_bag_it->show_cost() > p.get_ap())
                        {
                            cout << "你剩余的体力不足以使用这个技能，请重新选择技能，或按'q'退出" << endl;
                            cin >> char_en;
                            fflush(stdin);
                            en = dicision(1, li, char_en);
                            if (en < 0)
                                break;
                            continue;
                        }
                        Sleep(500);
                        cout << "你使用了" << skill_bag_it->show_name() << "(" << skill_bag_it->show_discription() << ")" << endl;
                        Sleep(1000);
                        di = fate_dice();//命运之骰
                        Sleep(1000);
                        float ini = r.get_hp();
                        skill_bag_it->effect(p, r, 0, di);
                        cout << "产生效果:";
                        skill_bag_it->say_discription(di);//显示技能产生的效果
                        if (r.get_hp() <= 0)
                        {
                            float mid = r.get_hp();
                            mid = -mid;
                            if (mid >= r.get_armor())
                            {
                                r.change_hp(0, 0);
                                cout << "对方挡住了" << r.get_armor() << "的伤害,实际受到" << ini + mid - r.get_armor() << "的伤害" << endl;
                            }
                            else
                            {
                                r.change_hp(0, r.get_armor());
                                cout << "对方挡住了" << r.get_armor() << "的伤害,实际受到" << ini - r.get_hp() << "的伤害" << endl;
                            }
                        }
                        else
                        {
                            ini -= r.get_hp();
                            Sleep(900);
                            if (ini)
                            {
                                cout << endl << "对方";
                                correct(ini, r);
                            }
                        }

                        check = 1;
                    }
                }
                else//选择退到上一步
                    ;
            }
        }

    }
}
//普攻,c1攻击c2
float attack(C& c1, C& c2)
{
    float damage = -c1.get_damage_point();//造成的伤害是用受击方的防御值减去进攻方的攻击值
    c2.change_hp(1, damage);
    return -damage;
}
//伤害修正函数,根据c的防御力修正c受到的伤害
void correct(float damage, C& c)
{
    int whole;//是否完全挡下伤害；0否，1是
    float add = c.get_armor();
    if (damage == 0)//若不造成伤害，则无需修正
        ;
    else if (damage < add)//若受到伤害且防御力足够，则将受到的伤害补回来
    {
        c.change_hp(1, damage);
        cout << "挡下了所有伤害!" << endl;

    }
    else//若受到伤害且防御力不足，则只补上防御力的值
    {
        c.change_hp(1, add);
        cout << "的防御挡住了" << add << "的伤害，实际受到 " << damage - add << "的伤害" << endl;
    }
}
//对手出招
void rival_turn(P& p, R& r, string order, int& index, vector<S>r_skill, vector<S>::iterator skill_it)
{
    Sleep(1000);
    cout << endl << "下面轮到对面出击";
    Sleep(700);
    int j;
    for (j = 0; j < 4; ++j)
    {
        cout << ".";
        Sleep(300);
    }
    cout << endl;
    skill_it = r_skill.begin();//一定要重置迭代器
    int choice = order[index++] - 48;
    if (index == order.size())
        index = 0;
    if (choice)//如果用技能
    {
        skill_it += choice;
        cout << r.get_name() << "使用了 " << skill_it->show_name() << "(" << skill_it->show_discription() << ")" << endl;
        Sleep(1500);
        int di = fate_dice();
        int damage = p.get_hp();
        skill_it->effect(p, r, 1, di);
        damage -= p.get_hp();
        cout << "技能效果：";
        skill_it->say_discription(di);
        if (damage)
            cout << p.get_name();
        correct(damage, p);

    }
    else//如果用普攻
    {
        float damage = attack(r, p);
        cout << r.get_name() << "使用了普攻" << endl;
        cout << p.get_name();
        correct(damage, p);

    }
}
//战斗函数，包括了一个关卡的大部分战斗过程
int fight(P& p, R& r, int index, vector<S>skill_bag, vector<S>::iterator skill_bag_it, vector<S> skill_set,
    int nOI, vector<Item>bag, vector<Item>item, vector<Item>::iterator item_it, int nOS, vector<S>skill, vector<S>::iterator skill_it)
{       //展示选择界面
    while (1)
    {
        my_turn(p, r, skill_bag, skill_bag_it);
        vector<S>::iterator s_it = skill_set.begin();
        int judge_ = win_or_lose(p, r, nOI, bag, item_it, item, nOS, skill_bag, skill_it, skill);
        if (!judge_)//未分胜负时，轮到boss出招
        {
            rival_turn(p, r, r.show_order(), index, skill_set, s_it);//boss出招
        }
        else if (judge_ == 1)//玩家胜则跳出这个循环
        {
            break;//跳出while循环
        }
        else if (judge_ == 2)//选择重新游玩
        {
            return 2;
        }
        else
        {
            exit(0);
        }
        judge_ = win_or_lose(p, r, numOfItem_1, bag, item_it, item, numOfSkill_1, skill_bag, skill_it, skill);
        if (!judge_)//若未分出胜负，则轮到玩家出招
            continue;
        else if (judge_ == 1)
        {
            break;
        }
        else if (judge_ == 2)
            return 2;
        else
        {
            exit(0);
        }
    }
    return 0;
}
//获取装备，自动检查是否重复
void take_item(vector<Item>& bag, vector<Item>::iterator& item_it)
{
    extern void save_item(vector<Item>::iterator item_it);//保存装备
    int flag = 0;//0代表不重复，1代表重复
    for (auto i : bag)
    {
        if (i.get_name() == item_it->get_name())
        {
            flag++;
            break;
        }
    }
    if (flag)
    {
        cout << "“很遗憾，重复了”老者摇了摇头，旋即笑道“就算你记忆力不好，你就不会往上翻翻看吗？”" << endl;
        Sleep(2000);
        cout << "你顿时语塞" << endl;
        Sleep(800);
    }
    else
    {
        bag.push_back(*item_it);
        item_it->effect();
        save_item(item_it);
        cout << "年轻人记忆力就是好。喏，给你" << item_it->get_name() << "(" << item_it->get_discription() << ")" << endl;
    }
}
//获取技能，自动检查是否重复
void take_skill(vector<S>& skill_bag, vector<S>::iterator& skill_it)
{
    extern void save_skill(vector<S>::iterator skill_it);//保存技能
    int flag = 0;//0代表不重复，1代表重复
    for (auto i : skill_bag)
    {
        if (i.show_name() == skill_it->show_name())
        {
            flag++;
            break;
        }
    }
    if (flag)
    {
        cout << "“很遗憾，重复了”老者摇了摇头，旋即笑道“就算你记忆力不好，你就不会往上翻翻看吗？”" << endl;
    }
    else
    {
        skill_bag.push_back(*skill_it);
        save_skill(skill_it);
        cout << "年轻人记忆力就是好。喏，给你" << skill_it->show_name() << "(" << skill_it->show_discription() << ")" << endl;
    }
}

//恢复玩家的所有状态，关卡结束后用
void cure(P& p)
{
    p.same_hp();
    p.same_damage_point();
    p.same_armor();
    p.same_ap();
}

//恢复boss的所有状态，关卡结束后用
void cure(R& r)
{
    r.same_hp();
    r.same_damage_point();
    r.same_armor();
}
//保存level
void save_level(int level)
{
    ofstream out("level.txt", ios::trunc);//要改写所以用trunc
    out << level;
    out.close();
}
//读取level
void read_level(int& level)
{
    ifstream in("level.txt");
    in >> level;
}
//保存装备
void save_item(vector<Item>::iterator item_it)
{
    ofstream out("item.txt", ios::app);
    out << item_it->get_name() << "\n";
    out.close();
}
//保存技能
void save_skill(vector<S>::iterator skill_it)
{
    ofstream out("skill.txt", ios::app);
    out << skill_it->show_name() << "\n";
    out.close();
}
//读取装备
void read_item(vector<Item>& bag, vector<Item>& item)
{
    string item_temp;//先将存档里的装备名称都暂时存在这里
    ifstream in("item.txt");
    while (!in.eof())
    {
        getline(in, item_temp);
        /*其实不用去掉回车键...*/
        /*item_temp=item_temp.replace(item_temp.begin(),item_temp.end(),"\n","");//去掉回车键*/
        for (auto i : item)
        {
            if (item_temp == i.get_name())
            {
                bag.push_back(i);
                i.effect();
            }
        }
    }
    in.close();
}
//读取技能
void read_skill(vector<S>& skill_bag, vector<S>& skill)
{
    string skill_temp;//先将存档里的技能名称都暂时存在这里
    ifstream in("skill.txt");
    while (!in.eof())
    {
        getline(in, skill_temp);
        /*其实不用去掉回车键...*/
        /*item_temp=item_temp.replace(item_temp.begin(),item_temp.end(),"\n","");//去掉回车键*/
        for (auto i : skill)
        {
            if (skill_temp == i.show_name())
            {
                skill_bag.push_back(i);
            }
        }
    }
    in.close();
}
//清档
void delete_save()
{
    ofstream out;
    out.open("level.txt", ios::trunc);
    out << 0;
    out.close();

    out.open("item.txt", ios::trunc);
    out << "";
    out.close();

    out.open("skill.txt", ios::trunc);
    out << "";
    out.close();

    out.open("BossName.txt", ios::trunc);
    out << "";
    out.close();
}