#include "class.h"
using namespace std;
//���ļ����ڷǳ�Ա������ʵ��

//���þֲ�������ɫ
void set_color(int fore = 7, int bac = 0)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (bac << 4) + fore);
}
/* ����Ϸ���ܻ��õ�����ɫ
0-��   7-��   4-��   6-��   5-��
*/
void star(int fore = 7, int bac = 0)
{
    set_color(fore, bac);
    cout << endl << "*************************************************************" << endl;
    set_color();
}
//���ع��
void HideCursor()
{
    CONSOLE_CURSOR_INFO cur = { 1,0 };
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cur);
}
//��ʾ���
void ShowCursor()
{
    CONSOLE_CURSOR_INFO cur = { 1,1 };
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cur);
}
//����֮����6��
int fate_dice()
{
    int j;
    HideCursor();//���ع��
    int Dice;
    set_color(0xB, 0);
    cout << endl << "����֮������ת��������" << endl;
    Sleep(300);
    for (j = 0; j < 20; ++j)        //����������
    {

        Dice = rand() % 6 + 1;
        cout << Dice;
        Sleep(60);
        if (j < 19)
            cout << "\b";
    }
    set_color();
    ShowCursor();//��ʾ���
    cout << endl;
    return Dice;
}
//����֮��,�������[0,MAX)������������֮��������
int hidden_dice(int MAX)
{
    int dice = rand() % (MAX);
    return dice;
}
//չʾ��ҵ�״̬
void show_state(P& p)
{
    extern void set_color(int fore = 7, int bac = 0);
    star(2, 0);
    set_color(6, 0);
    cout << "��ҵ�ǰ״̬(������Ϊ����ֵ)" << endl;
    cout << "Ѫ��: " << p.get_hp() << "(" << p.get_hp_max() << ")  ������:" << p.get_damage_point() << "(" << p.get_damage_point_max() << "��";
    cout << "������: " << p.get_armor() << "(" << p.get_armor_max() << ")  ����:" << p.get_ap() << "(" << p.get_ap_max() << ")" << endl;
    set_color();
}
//չʾ˫����״̬
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
    //��ֹ�е���С����
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

    cout << "��ҵ�ǰ״̬" << endl;
    cout << "Ѫ��: " << p_hp << "  ������:" << p_dp;
    cout << "������: " << p_arm << "  ����:" << p_ap << endl;
    set_color(4, 0);
    cout << "���ֵ�ǰ״̬" << endl;
    cout << "Ѫ��: " << r_hp << "  ������:" << r_dp;
    cout << "������: " << r_arm << endl;
    set_color();
}
//չʾ������е�װ��
void show_item(vector <Item>::iterator bag_it, vector <Item> bag)
{
    int index;//����
    set_color(9, 0);
    cout << "���Ѿ�ӵ�е�װ��: " << endl;
    set_color(3, 0);
    for (index = 0, bag_it = bag.begin(); bag_it != bag.end(); ++bag_it, ++index)
    {
        cout << index << bag_it->get_name() << "(" << bag_it->get_discription() << ")" << endl;
    }
    set_color();
}
//�������װ����չʾ��һ�õ�װ��,������Ӱ��
void random_fall(int Max, vector<Item>& bag, vector<Item>::iterator& item_it, vector<Item>& item, P& p)
{
    extern void save_item(vector<Item>::iterator item_it);
    int dice;
    int flag = 0;//0�����ظ���1�����ظ�
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
    if (!flag)//�����ظ�
    {
        bag.push_back(*item_it);//������item����Ӧ��Ԫ�ظ��Ƹ�bag��������������һ����װ��
        save_item(item_it);
        cout << endl << "������װ��---- " << item_it->get_name() << "(" << item_it->get_discription() << ")" << endl;
        item_it->effect();
        item_it = item.begin();
    }
    else
    {
        cout << endl << "�����װ���ظ���" << endl;
    }
    set_color();
}

//������似�ܣ�չʾ��һ�õļ���,������Ӱ��
void random_fall_skill(int Max, vector<S>& skill_bag, vector<S>::iterator& skill_it, vector<S>& skill, P& p)
{
    extern void save_skill(vector<S>::iterator skill_it);
    int dice;
    int flag = 0;//0Ϊ���ظ���1���ظ�
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
        skill_bag.push_back(*skill_it);//������item����Ӧ��Ԫ�ظ��Ƹ�bag��������������һ���˼���
        save_skill(skill_it);
        cout << endl << "�����˼���---- " << skill_it->show_name() << "(" << skill_it->show_discription() << ")" << endl;
        skill_it = skill.begin();
    }
    else
    {
        cout << "����ļ����ظ���" << endl;
    }
    set_color();

}

//���������еļ���
void show_skill(vector <S>::iterator skill_bag_it, vector <S> skill_bag)
{
    int index;//����
    cout << endl;
    set_color(9, 0);
    cout << "���Ѿ�ӵ�еļ���: " << endl;
    set_color(3, 0);
    for (index = 0, skill_bag_it = skill_bag.begin(); skill_bag_it != skill_bag.end(); ++skill_bag_it, ++index)
    {
        cout << index << ". " << skill_bag_it->show_name() << "(" << skill_bag_it->show_discription() << ")" << endl;
    }
    set_color();
}
//����Ѫ���ж�ʤ����
int judge(P& p, R& r)//����ֵ��0.δ�ֳ�ʤ����1.���ʤ��2.����ʤ
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
//����boss��
void save_BossName(string BossName)
{
    ofstream out("BossName.txt", ios::app);
    out << BossName << "\n";
    out.close();
}
//��ȡboss��
void read_BossName(vector <string>& BossName_bag, vector <string>& BossName)
{
    string b_name_temp;//�Ƚ��浵���boss���ƶ���ʱ��������
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
//����Ѵ��boss��
void show_BossName(vector <string>::iterator BossName_bag_it, vector <string> BossName_bag)
{
    int index;//����
    set_color(9, 0);
    cout << "�����ó��У����Ѵ����" << endl;
    set_color(3, 0);
    for (index = 0, BossName_bag_it = BossName_bag.begin(); BossName_bag_it != BossName_bag.end(); ++BossName_bag_it, ++index)
    {
        cout << index << " " << *BossName_bag_it << endl;
    }
    cout << endl;
    set_color();
}


//���ݳ�������Ѫ������Ϸֹͣ���Ǽ���
int win_or_lose(P& p, R& r, int noI, vector<Item> bag, vector<Item>::iterator item_it,
    vector<Item>item, int noS, vector<S>skill_bag, vector<S>::iterator skill_it,
    vector<S> skill)
{
    extern int dicision(int quit, int limit, char enter);
    char char_dicision_ = '0';
    int judge_ = 0;//�ú���Ҫ���ص��ж�ֵ��0��δ��ʤ����1�����ʤ��2���������ѡ�����¿�ʼ
    switch (judge(p, r))
    {
    /*δ��ʤ��*/case 0:break;
    /*���ʤ*/  case 1:judge_++;
        break;
    /*����ʤ*/  case 2:cout << "��Ϸ����" << endl << "��ϣ������һ����" << endl
        << "0.����һ�� 1.�ر���Ϸ" << endl;
        int dicision_;
        cin >> char_dicision_;
        dicision_ = dicision(0, 2, char_dicision_);
        if (!dicision_)judge_ = 2;
        else exit(0);
        break;
    }
    return judge_;
}
//��������ķ�Χ:[0,limit],enter���û������룬������Ϸ��򷵻�֮
int dicision(int quit, int limit, char enter)//��quitΪ0����˵�����ﲻ���˳�ѡ�񣬵�quitΪ1�����û����԰�'q'�˳�����һ��
{
    if (quit)//�����˵���һ��
    {
        if (enter == 'q')
            return -1;
        char enter2 = enter;
        while (enter2<'0' || enter2>limit + 48)
        {
            cout << "��������������߰���Ķ������밴��Χ���룡���·�������Ժ�����һλ����û������˵��" << endl;
            cin >> enter2;
            fflush(stdin);
            if (enter2 == 'q')
                return -1;
        }
        int good_enter = enter2 - 48;
        return good_enter;
    }
    else//�����˵���һ��
    {
        char enter2 = enter;
        while (enter2<'0' || enter2>limit + 48)
        {

            cout << "��������������߰���Ķ������밴��Χ���룡���·�������Ժ�����һλ����û������˵��" << endl;
            cin >> enter2;
            fflush(stdin);

        }
        int good_enter = enter2 - 48;
        return good_enter;
    }
}
//��ʾ��ս��ʱ��ѡ����棬���û�ѡ��,�ų��Ƿ�ѡ�񣬲��ҷ����û���ѡ��
int show_choose()
{
    cout << endl << "�������ѡ��" << endl << "0.�չ�  1.����" << endl;
    char char_choose_;
    int choose_;
    cin >> char_choose_;
    fflush(stdin);
    choose_ = dicision(0, 1, char_choose_);
    return choose_;
}
//�ֵ����ʱ�ĸ��ֹ���
void my_turn(P& p, R& r, vector<S>skill_bag, vector<S>::iterator skill_bag_it)
{
    extern float attack(C & c1, C & c2);
    extern void correct(float damage, C & c);
    int check = 0;//�����������Ƿ����,0��,1��
    int dici;//ѡ�����ר��
    show_state(p, r);
    Sleep(500);
    while (!check)
    {
        dici = show_choose();
        if (dici == 0)//�����չ�
        {
            //�����к���Ҫ�����Զ���ɵ��˺���������������attack()������ɵ��˺�������correc()�����˺�����
            float damage = attack(p, r);
            cout << r.get_name();
            correct(damage, r);
            Sleep(800);
            show_state(p, r);
            check = 1;
        }
        else //ʹ�ü���
        {
            if (skill_bag.size() == 0)
            {
                cout << "�㻹û�м���,������ѡ��";
                Sleep(500);
            }
            else
            {
                show_skill(skill_bag_it, skill_bag);
                cout << endl << "����ݱ��ѡ����ļ��ܣ���Ҳ��������'q'�˳�" << endl;
                int li = skill_bag.size() - 1;//�ñ�����ļ�������Ϊѡ�������
                char char_en;
                int en;//��ҵ�ѡ��
                int di;//��������֮���ĵ���
                cin >> char_en;
                fflush(stdin);
                en = dicision(1, li, char_en);
                if (en >= 0)//ѡ��ĳ������
                {
                    while (!check)
                    {
                        skill_bag_it = skill_bag.begin();
                        skill_bag_it += en;
                        if (skill_bag_it->show_cost() > p.get_ap())
                        {
                            cout << "��ʣ�������������ʹ��������ܣ�������ѡ���ܣ���'q'�˳�" << endl;
                            cin >> char_en;
                            fflush(stdin);
                            en = dicision(1, li, char_en);
                            if (en < 0)
                                break;
                            continue;
                        }
                        Sleep(500);
                        cout << "��ʹ����" << skill_bag_it->show_name() << "(" << skill_bag_it->show_discription() << ")" << endl;
                        Sleep(1000);
                        di = fate_dice();//����֮��
                        Sleep(1000);
                        float ini = r.get_hp();
                        skill_bag_it->effect(p, r, 0, di);
                        cout << "����Ч��:";
                        skill_bag_it->say_discription(di);//��ʾ���ܲ�����Ч��
                        if (r.get_hp() <= 0)
                        {
                            float mid = r.get_hp();
                            mid = -mid;
                            if (mid >= r.get_armor())
                            {
                                r.change_hp(0, 0);
                                cout << "�Է���ס��" << r.get_armor() << "���˺�,ʵ���ܵ�" << ini + mid - r.get_armor() << "���˺�" << endl;
                            }
                            else
                            {
                                r.change_hp(0, r.get_armor());
                                cout << "�Է���ס��" << r.get_armor() << "���˺�,ʵ���ܵ�" << ini - r.get_hp() << "���˺�" << endl;
                            }
                        }
                        else
                        {
                            ini -= r.get_hp();
                            Sleep(900);
                            if (ini)
                            {
                                cout << endl << "�Է�";
                                correct(ini, r);
                            }
                        }

                        check = 1;
                    }
                }
                else//ѡ���˵���һ��
                    ;
            }
        }

    }
}
//�չ�,c1����c2
float attack(C& c1, C& c2)
{
    float damage = -c1.get_damage_point();//��ɵ��˺������ܻ����ķ���ֵ��ȥ�������Ĺ���ֵ
    c2.change_hp(1, damage);
    return -damage;
}
//�˺���������,����c�ķ���������c�ܵ����˺�
void correct(float damage, C& c)
{
    int whole;//�Ƿ���ȫ�����˺���0��1��
    float add = c.get_armor();
    if (damage == 0)//��������˺�������������
        ;
    else if (damage < add)//���ܵ��˺��ҷ������㹻�����ܵ����˺�������
    {
        c.change_hp(1, damage);
        cout << "�����������˺�!" << endl;

    }
    else//���ܵ��˺��ҷ��������㣬��ֻ���Ϸ�������ֵ
    {
        c.change_hp(1, add);
        cout << "�ķ�����ס��" << add << "���˺���ʵ���ܵ� " << damage - add << "���˺�" << endl;
    }
}
//���ֳ���
void rival_turn(P& p, R& r, string order, int& index, vector<S>r_skill, vector<S>::iterator skill_it)
{
    Sleep(1000);
    cout << endl << "�����ֵ��������";
    Sleep(700);
    int j;
    for (j = 0; j < 4; ++j)
    {
        cout << ".";
        Sleep(300);
    }
    cout << endl;
    skill_it = r_skill.begin();//һ��Ҫ���õ�����
    int choice = order[index++] - 48;
    if (index == order.size())
        index = 0;
    if (choice)//����ü���
    {
        skill_it += choice;
        cout << r.get_name() << "ʹ���� " << skill_it->show_name() << "(" << skill_it->show_discription() << ")" << endl;
        Sleep(1500);
        int di = fate_dice();
        int damage = p.get_hp();
        skill_it->effect(p, r, 1, di);
        damage -= p.get_hp();
        cout << "����Ч����";
        skill_it->say_discription(di);
        if (damage)
            cout << p.get_name();
        correct(damage, p);

    }
    else//������չ�
    {
        float damage = attack(r, p);
        cout << r.get_name() << "ʹ�����չ�" << endl;
        cout << p.get_name();
        correct(damage, p);

    }
}
//ս��������������һ���ؿ��Ĵ󲿷�ս������
int fight(P& p, R& r, int index, vector<S>skill_bag, vector<S>::iterator skill_bag_it, vector<S> skill_set,
    int nOI, vector<Item>bag, vector<Item>item, vector<Item>::iterator item_it, int nOS, vector<S>skill, vector<S>::iterator skill_it)
{       //չʾѡ�����
    while (1)
    {
        my_turn(p, r, skill_bag, skill_bag_it);
        vector<S>::iterator s_it = skill_set.begin();
        int judge_ = win_or_lose(p, r, nOI, bag, item_it, item, nOS, skill_bag, skill_it, skill);
        if (!judge_)//δ��ʤ��ʱ���ֵ�boss����
        {
            rival_turn(p, r, r.show_order(), index, skill_set, s_it);//boss����
        }
        else if (judge_ == 1)//���ʤ���������ѭ��
        {
            break;//����whileѭ��
        }
        else if (judge_ == 2)//ѡ����������
        {
            return 2;
        }
        else
        {
            exit(0);
        }
        judge_ = win_or_lose(p, r, numOfItem_1, bag, item_it, item, numOfSkill_1, skill_bag, skill_it, skill);
        if (!judge_)//��δ�ֳ�ʤ�������ֵ���ҳ���
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
//��ȡװ�����Զ�����Ƿ��ظ�
void take_item(vector<Item>& bag, vector<Item>::iterator& item_it)
{
    extern void save_item(vector<Item>::iterator item_it);//����װ��
    int flag = 0;//0�����ظ���1�����ظ�
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
        cout << "�����ź����ظ��ˡ�����ҡ��ҡͷ������Ц������������������ã���Ͳ������Ϸ������𣿡�" << endl;
        Sleep(2000);
        cout << "���ʱ����" << endl;
        Sleep(800);
    }
    else
    {
        bag.push_back(*item_it);
        item_it->effect();
        save_item(item_it);
        cout << "�����˼��������Ǻá���������" << item_it->get_name() << "(" << item_it->get_discription() << ")" << endl;
    }
}
//��ȡ���ܣ��Զ�����Ƿ��ظ�
void take_skill(vector<S>& skill_bag, vector<S>::iterator& skill_it)
{
    extern void save_skill(vector<S>::iterator skill_it);//���漼��
    int flag = 0;//0�����ظ���1�����ظ�
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
        cout << "�����ź����ظ��ˡ�����ҡ��ҡͷ������Ц������������������ã���Ͳ������Ϸ������𣿡�" << endl;
    }
    else
    {
        skill_bag.push_back(*skill_it);
        save_skill(skill_it);
        cout << "�����˼��������Ǻá���������" << skill_it->show_name() << "(" << skill_it->show_discription() << ")" << endl;
    }
}

//�ָ���ҵ�����״̬���ؿ���������
void cure(P& p)
{
    p.same_hp();
    p.same_damage_point();
    p.same_armor();
    p.same_ap();
}

//�ָ�boss������״̬���ؿ���������
void cure(R& r)
{
    r.same_hp();
    r.same_damage_point();
    r.same_armor();
}
//����level
void save_level(int level)
{
    ofstream out("level.txt", ios::trunc);//Ҫ��д������trunc
    out << level;
    out.close();
}
//��ȡlevel
void read_level(int& level)
{
    ifstream in("level.txt");
    in >> level;
}
//����װ��
void save_item(vector<Item>::iterator item_it)
{
    ofstream out("item.txt", ios::app);
    out << item_it->get_name() << "\n";
    out.close();
}
//���漼��
void save_skill(vector<S>::iterator skill_it)
{
    ofstream out("skill.txt", ios::app);
    out << skill_it->show_name() << "\n";
    out.close();
}
//��ȡװ��
void read_item(vector<Item>& bag, vector<Item>& item)
{
    string item_temp;//�Ƚ��浵���װ�����ƶ���ʱ��������
    ifstream in("item.txt");
    while (!in.eof())
    {
        getline(in, item_temp);
        /*��ʵ����ȥ���س���...*/
        /*item_temp=item_temp.replace(item_temp.begin(),item_temp.end(),"\n","");//ȥ���س���*/
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
//��ȡ����
void read_skill(vector<S>& skill_bag, vector<S>& skill)
{
    string skill_temp;//�Ƚ��浵��ļ������ƶ���ʱ��������
    ifstream in("skill.txt");
    while (!in.eof())
    {
        getline(in, skill_temp);
        /*��ʵ����ȥ���س���...*/
        /*item_temp=item_temp.replace(item_temp.begin(),item_temp.end(),"\n","");//ȥ���س���*/
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
//�嵵
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