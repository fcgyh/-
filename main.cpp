#include "class.h"
#include "uni_fun.h"
#include<mmsystem.h>//��ý���豸�ӿ�ͷ�ļ�
#pragma comment(lib,"winmm.lib")
using namespace std;
int level = 0;//���˵ڼ��أ�������

int main()
{
    mciSendString("open ./music/BGM.mp3 alias BGM", 0, 0, 0);//���ý���豸�ӿڷ����ַ���
    mciSendString("play BGM repeat", 0, 0, 0);
    set_color();
    srand((unsigned int)time(nullptr));//��ʼ������
    int choose/*ѡ��ר��*/, dici/*ѡ�����ר��*/, dice, di, check = 0/*�������Ƿ����,0��,1��*/, index/*��Ϊboss���е�����*/;
    char char_choose;
    vector<Item> item;//��Ϸ����װ��������
    vector<Item>::iterator item_it = item.begin();//��Ϸ����װ���ĵ�����
    vector<Item> ThrKingItem;//����װ��������
    vector<Item>::iterator ThrKingItem_it = ThrKingItem.begin();//����װ���ĵ�����
    vector<Item> LOLItem;//Ӣ������װ��������
    vector<Item>::iterator LOLItem_it = LOLItem.begin();//Ӣ������װ���ĵ�����
    vector<Item> JourWestItem;//���μ�װ��������
    vector<Item>::iterator JourWestItem_it = JourWestItem.begin();//���μ�װ���ĵ�����
    vector<Item> bag;//��ұ���������װ��������)
    vector<Item>::iterator bag_it = bag.begin();//��ұ����ĵ�����

    vector<S> skill;//��Ϸ���м��ܵ�����
    vector<S>::iterator skill_it = skill.begin();//��Ϸ���м��ܵĵ�����
    vector<S> ThrKingSkill;//�������ܵ�����
    vector<S>::iterator ThrKingSkill_it = ThrKingSkill.begin();//�������ܵĵ�����
    vector<S> LOLSkill;//Ӣ�����˼��ܵ�����
    vector<S>::iterator LOLSkill_it = LOLSkill.begin();//Ӣ�����˼��ܵĵ�����
    vector<S> JourWestSkill;//���μǼ��ܵ�����
    vector<S>::iterator JourWestSkill_it = JourWestSkill.begin();//���μǼ��ܵĵ�����
    vector<S>skill_bag;//��Ҵ洢���ܵ�"����"
    vector<S>::iterator skill_bag_it;//���ܱ���������

    vector<string> BossName;//����boss��������
    vector<string>::iterator BossName_it = BossName.begin();//����boss���ĵ�����
    vector<string> BossName_bag;//�Ѵ��boss��������
    vector<string>::iterator BossName_bag_it = BossName_bag.begin();//�Ѵ��boss���ĵ�����

    //������ҽ�ɫ
    P p("��", 100, 45, 10, 100);

    //��������Ӧ��¼����װ���ͼ���֮��

    //¼��װ��
    //����װ��
    Item BaiYinShiZi("����ʨ��", "���ӷ���10", 3, 1, 10, 0, 0, p);
    Item ZhuGeLianNu("�������", "���ӹ���15", 2, 1, 15, 0, 0, p);
    Item ZhangBaSheMao("�ɰ���ì", "���ӹ���10������5", 8, 1, 10, 1, 5, p);
    Item TongYouJia("ͩ�ͼ�", "��������40%,��������20%", 7, 1.4, 0, 0.8, 0, p);
    Item HuXinJia("���ļ�", "��������25% ", 1, 1.25, 0, 0, 0, p);
    Item SanJianLiangRenDao("�������е�", "���ӹ���10������30", 9, 1, 10, 1, 30, p);
    Item QiBaoDao("�߱���", "��������15%������10", 5, 1.15, 0, 1, 10, p);
    Item LiRuMaoZi("�����ñ��", "��������50", 1, 1, 50, 0, 0, p);
    Item ChiTuMa("������", "��������100", 4, 1, 100, 0, 0, p);
    //Ӣ������װ��
    Item Blackcut("��ɫ�и��� ", "��������50������10", 5, 1, 50, 1, 10, p);
    Item Dlev("������֮�� ", "���ӹ���40%", 2, 1.4, 0, 0, 0, p);
    Item Bloodhand("Ѫ�� ", "��������30%������30%", 5, 1.3, 0, 1.3, 0, p);
    Item Hatelock("������� ", "���ӷ���50%", 3, 1.5, 0, 0, 0, p);
    Item Thriforce("����֮�� ", "���ӹ���30%������10% ", 8, 1.3, 0, 1.1, 0, p);
    Item Ckshi("��Ѫս�� ", "��������20%������35%", 6, 1.2, 0, 1.35, 0, p);
    //���μ�װ��
    Item JinGuBang("�𹿰�", "���ӹ���60", 2, 1, 60, 0, 0, p);
    Item ZiJinHongHuLu("�Ͻ���«", "��������250", 1, 1, 250, 0, 0, p);
    Item JinGangZhuo("�����", "���ӷ���50", 3, 1, 50, 0, 0, p);
    Item YangZhiYuJingPing("��֬��ƿ", "��������150", 4, 1, 150, 0, 0, p);
    Item HunTieGun("������", "��������100,����40", 5, 1, 100, 1, 40, p);
    Item QiXingJian("���ǽ�", "���ӹ���25,����100", 9, 1, 25, 1, 100, p);
    Item FeiLongZhang("������", "���ӹ���30,����30", 8, 1, 30, 1, 30, p);
    Item BiHuoZhao("�ܻ���", "��������200,����15", 6, 1, 200, 1, 15, p);
    Item DingFengZhu("������", "��������200������50", 7, 1, 200, 1, 50, p);
    Item ZiJinLingDang("�Ͻ�����", "���ӷ���30������80", 10, 1, 30, 1, 80, p);

    ThrKingItem.push_back(BaiYinShiZi);
    ThrKingItem.push_back(ZhuGeLianNu);
    ThrKingItem.push_back(ZhangBaSheMao);
    ThrKingItem.push_back(TongYouJia);
    ThrKingItem.push_back(HuXinJia);
    ThrKingItem.push_back(SanJianLiangRenDao);
    ThrKingItem.push_back(QiBaoDao);
    ThrKingItem.push_back(LiRuMaoZi);
    ThrKingItem.push_back(ChiTuMa);
    ThrKingItem_it = ThrKingItem.begin(); //push_back֮��һ��Ҫ�õ��������ã�����

    LOLItem.push_back(Blackcut);
    LOLItem.push_back(Dlev);
    LOLItem.push_back(Bloodhand);
    LOLItem.push_back(Hatelock);
    LOLItem.push_back(Thriforce);
    LOLItem.push_back(Ckshi);
    LOLItem_it = LOLItem.begin(); //push_back֮��һ��Ҫ�õ��������ã�����

    JourWestItem.push_back(JinGuBang);
    JourWestItem.push_back(ZiJinHongHuLu);
    JourWestItem.push_back(JinGangZhuo);
    JourWestItem.push_back(YangZhiYuJingPing);
    JourWestItem.push_back(HunTieGun);
    JourWestItem.push_back(QiXingJian);
    JourWestItem.push_back(FeiLongZhang);
    JourWestItem.push_back(BiHuoZhao);
    JourWestItem.push_back(DingFengZhu);
    JourWestItem.push_back(ZiJinLingDang);
    JourWestItem_it = JourWestItem.begin(); //push_back֮��һ��Ҫ�õ��������ã�����

    item.push_back(BaiYinShiZi);
    item.push_back(ZhuGeLianNu);
    item.push_back(ZhangBaSheMao);
    item.push_back(TongYouJia);
    item.push_back(HuXinJia);
    item.push_back(SanJianLiangRenDao);
    item.push_back(QiBaoDao);
    item.push_back(LiRuMaoZi);
    item.push_back(ChiTuMa);
    item.push_back(Blackcut);
    item.push_back(Dlev);
    item.push_back(Bloodhand);
    item.push_back(Hatelock);
    item.push_back(Thriforce);
    item.push_back(Ckshi);
    item.push_back(JinGuBang);
    item.push_back(ZiJinHongHuLu);
    item.push_back(JinGangZhuo);
    item.push_back(YangZhiYuJingPing);
    item.push_back(HunTieGun);
    item.push_back(QiXingJian);
    item.push_back(FeiLongZhang);
    item.push_back(BiHuoZhao);
    item.push_back(DingFengZhu);
    item.push_back(ZiJinLingDang);
    item_it = item.begin();//push_back֮��һ��Ҫ�õ��������ã�����

    /*����
    random_fall_1(9, bag, ThrKingItem_it, ThrKingItem, p);
    random_fall_2(6, bag, LOLItem_it, LOLItem, p);
    random_fall_3(10, bag, JourWestItem_it, JourWestItem, p);
    show_item(bag_it, bag);*/
    //¼�뼼��
   /*��ʽ(ÿ�����ܶ�Ҫ����������):
         S skill_name(name,choice,target1,index1,factor1,add1,dice,target2,index2,factor2,add2);
         skill_name.give_discription("string1","string2");
   */
   //���ɼ��ܶ���
    //��������
    S YangWei("����", 0, 1, 5, 0.4, 0, 4, 1, 5, 1, -5, 30);
    YangWei.give_discription("����30����", "���ͶԷ�60%����", "������4-6�����ͶԷ�5����");
    S YaoWu("ҫ��", 1, 0, 3, 1.2, 0, 5, 0, 3, 1.3, 0, 30);
    YaoWu.give_discription("����30����", "��������20%������", "������5-6����������30%������");
    S ShuangXiong("˫��", 0, 1, 1, 1, -50, 5, 0, 1, 1, 30, 30);
    ShuangXiong.give_discription("����30����", "���ͶԷ�50��Ѫ��", "������5-6����������30��Ѫ��");
    S WuShuang("��˫", 1, 1, 1, 1, -50, 4, 1, 1, 1, -75, 30);
    WuShuang.give_discription("����30����", "������1-3�����ͶԷ�50��Ѫ��", "������4-6�����ͶԷ�75��Ѫ��");
    S WuQian("��ǰ", 1, 1, 1, 1, -45, 5, 1, 1, 1, -80, 30);
    WuQian.give_discription("����30����", "������1-4�����ͶԷ�45��Ѫ��", "������5-6�����ͶԷ�80��Ѫ��");
    S DuSha("��ɱ", 0, 1, 1, 0.75, 0, 4, 0, 1, 1.2, 0, 40);
    DuSha.give_discription("����40����", "���ͶԷ�25%Ѫ��", "������4-6����������20%��Ѫ��");
    S FenCheng("�ٳ�", 0, 1, 1, 1, -50, 6, 0, 1, 1.4, 0, 30);
    FenCheng.give_discription("����30����", "���ͶԷ�50Ѫ��", "������6����������40%��Ѫ��");
    S XiongCan("�ײ�", 1, 1, 1, 1, -30, 5, 1, 1, 1, -100, 45);
    XiongCan.give_discription("����45����", "������1-4�����ͶԷ�30Ѫ��", "������5-6�����ͶԷ�100Ѫ��");
    S TanLan("̰��", 0, 1, 1, 0.7, 0, 4, 1, 1, 1, -40, 50);
    TanLan.give_discription("����50����", "���ͶԷ�30%Ѫ��", "������4-6�����ͶԷ�40��Ѫ��");
    //Ӣ�����˼���
    S DSSF("��ɱ�ķ�", 0, 1, 1, 1, -90, 4, 0, 1, 1.15, 0, 45);
    DSSF.give_discription("����45����", "���ͶԷ�90Ѫ��", "������4-6��������15%Ѫ");
    S XZFF("��ת�ɸ�", 1, 0, 3, 1.3, 0, 5, 0, 3, 1.5, 0, 60);
    XZFF.give_discription("����60����", "������1-4 ��������30%������", "������5-6��������50%������");
    S KDLF("��������", 0, 1, 1, 1, -80, 5, 0, 1, 1.25, 0, 50);
    KDLF.give_discription("����50����", "���ͶԷ�80Ѫ��", "������5-6��������25%Ѫ");
    S FSBXQ("����������", 1, 1, 1, 0.6, 0, 5, 1, 1, 1.2, 0, 70);
    FSBXQ.give_discription("����70����", "������1-4 ���ͶԷ�40%Ѫ��", "������5-6��������20%Ѫ");
    S KLCF("���ҳ��", 1, 1, 5, 1, -10, 5, 1, 5, 1, -15, 25);
    KLCF.give_discription("����25����", "������1-4 ���ͶԷ�10����", "������5-6 ���ͶԷ�15����");
    S JTZC("����֮��", 0, 1, 1, 1, -80, 5, 0, 1, 1, 50, 40);
    JTZC.give_discription("����40����", "���ͶԷ�80Ѫ��", "������5-6��������50Ѫ");
    S KSYQ("��ʳѻȺ", 0, 1, 5, 1, -15, 5, 0, 1, 1.25, 0, 40);
    KSYQ.give_discription("����40����", "���ͶԷ�15����", "������5-6��������25%Ѫ");
    S EMSH("��ħ����", 1, 0, 1, 1.5, 0, 5, 0, 5, 1.5, 0, 60);
    EMSH.give_discription("����60����", "������1-4 ��������50%Ѫ��", "������5 - 6��������50%����");
    S ZCDJ("�²д��", 0, 1, 5, 0.3, 0, 5, 1, 1, 0.8, 0, 35);
    ZCDJ.give_discription("����35����", "���ͶԷ�70%����", "������5-6���Ͷ���20%Ѫ��");
    S EMZY("��ħ֮ӵ", 0, 0, 1, 1.4, 0, 4, 0, 5, 1.4, 0, 50);
    EMZY.give_discription("����50����", "��������40%Ѫ��", "������4-6��������40%����");
    //���μǼ���
    S JGBH("��ղ���", 1, 0, 1, 1, 120, 4, 0, 5, 1, 30, 50);
    JGBH.give_discription("����50����", "������1-3��������������120", "������4-6�������������30");
    S LZGL("��֬��¶", 0, 0, 1, 1, 180, 4, 0, 5, 1, 25, 50);
    LZGL.give_discription("����50����", "������������180", "������4-6�������������25");
    S RLSZ("��������", 1, 1, 1, 1, -250, 5, 1, 1, 1, -400, 80);
    RLSZ.give_discription("����80����", "������1-4���ԶԷ�����˺�250", "������5-6���ԶԷ�����˺�400");
    S HFB("�Ʒ籩", 0, 1, 1, 1, -150, 4, 1, 5, 1, -25, 60);
    HFB.give_discription("����60����", "�ԶԷ�����˺�150", "������4-6�����ͶԷ�����25");
    S SMZH("�������", 0, 1, 1, 1, -150, 4, 1, 3, 1, -40, 60);
    SMZH.give_discription("����60����", "�ԶԷ�����˺�150", "������4-6�����ͶԷ�����40");
    S LSXF("�����ɷ�", 0, 1, 1, 1, -140, 4, 1, 7, 1, -80, 40);
    LSXF.give_discription("����40����", "�ԶԷ�����˺�140", "������4-6�����ͶԷ�����80");
    S PYTW("��������", 1, 1, 3, 1, -50, 4, 1, 7, 1, -80, 40);
    PYTW.give_discription("����40����", "������1-3�����ͶԷ�����50", "������4-6�����ͶԷ�����80");
    S DTYB("��ͷһ��", 0, 1, 1, 1, -180, 4, 1, 1, 1, -90, 50);
    DTYB.give_discription("����50����", "�ԶԷ�����˺�180", "������4-6����ɶ���50%�˺�");
    S JYBD("���㲻��", 0, 0, 1, 1, 250, 4, 0, 3, 1, -30, 70);
    JYBD.give_discription("����70����", "������������250", "������4-6������������30");

    ThrKingSkill.push_back(YangWei);
    ThrKingSkill.push_back(YaoWu);
    ThrKingSkill.push_back(ShuangXiong);
    ThrKingSkill.push_back(WuShuang);
    ThrKingSkill.push_back(WuQian);
    ThrKingSkill.push_back(DuSha);
    ThrKingSkill.push_back(FenCheng);
    ThrKingSkill.push_back(XiongCan);
    ThrKingSkill.push_back(TanLan);
    ThrKingSkill_it = ThrKingSkill.begin();//push_back֮��һ��Ҫ�õ��������ã�����

    LOLSkill.push_back(DSSF);
    LOLSkill.push_back(XZFF);
    LOLSkill.push_back(KDLF);
    LOLSkill.push_back(FSBXQ);
    LOLSkill.push_back(KLCF);
    LOLSkill.push_back(JTZC);
    LOLSkill.push_back(KSYQ);
    LOLSkill.push_back(EMSH);
    LOLSkill.push_back(ZCDJ);
    LOLSkill.push_back(EMZY);
    LOLSkill_it = LOLSkill.begin();//push_back֮��һ��Ҫ�õ��������ã�����

    JourWestSkill.push_back(JGBH);
    JourWestSkill.push_back(LZGL);
    JourWestSkill.push_back(RLSZ);
    JourWestSkill.push_back(HFB);
    JourWestSkill.push_back(SMZH);
    JourWestSkill.push_back(LSXF);
    JourWestSkill.push_back(PYTW);
    JourWestSkill.push_back(DTYB);
    JourWestSkill.push_back(JYBD);
    JourWestSkill_it = JourWestSkill.begin();//push_back֮��һ��Ҫ�õ��������ã�����

    skill.push_back(YangWei);
    skill.push_back(YaoWu);
    skill.push_back(ShuangXiong);
    skill.push_back(WuShuang);
    skill.push_back(WuQian);
    skill.push_back(DuSha);
    skill.push_back(FenCheng);
    skill.push_back(XiongCan);
    skill.push_back(TanLan);
    skill.push_back(DSSF);
    skill.push_back(XZFF);
    skill.push_back(KDLF);
    skill.push_back(FSBXQ);
    skill.push_back(KLCF);
    skill.push_back(JTZC);
    skill.push_back(KSYQ);
    skill.push_back(EMSH);
    skill.push_back(ZCDJ);
    skill.push_back(EMZY);
    skill.push_back(JGBH);
    skill.push_back(LZGL);
    skill.push_back(RLSZ);
    skill.push_back(HFB);
    skill.push_back(SMZH);
    skill.push_back(LSXF);
    skill.push_back(PYTW);
    skill.push_back(DTYB);
    skill.push_back(JYBD);
    skill_it = skill.begin();//push_back֮��һ��Ҫ�õ��������ã�����

    //����boss��
    //����boss��
    string HX = "����";
    string YLWC = "�����ĳ�";
    string LB = "����";
    string LR = "����";
    string DZ = "��׿";
    //Ӣ������boss��
    string DLES = "������˹";
    string DLW = "������";
    string BNQS = "��ŭ��ʿ";
    string SWY = "˹ά��";
    //���μ�boss��
    string JJDW = "��Ǵ���";
    string YJDW = "���Ǵ���";
    string NMW = "ţħ��";
    string HHE = "�캢��";
    string TSGZ = "���ȹ���";
    string LEMH = "����⨺�";

    BossName.push_back(HX);
    BossName.push_back(YLWC);
    BossName.push_back(LB);
    BossName.push_back(LR);
    BossName.push_back(DZ);
    BossName.push_back(DLES);
    BossName.push_back(DLW);
    BossName.push_back(BNQS);
    BossName.push_back(SWY);
    BossName.push_back(JJDW);
    BossName.push_back(YJDW);
    BossName.push_back(NMW);
    BossName.push_back(HHE);
    BossName.push_back(TSGZ);
    BossName.push_back(LEMH);
    BossName_it = BossName.begin();//push_back֮��һ��Ҫ�õ��������ã�����

    //¼��������һ��boss
    R r1[3] = { R("r_1",100,50,10),R("����",120,35,5),R("�����ĳ�",110,30,10) };//��һ��
    vector<S> r_1_skill;
    vector<S>::iterator r_1_skill_it = r_1_skill.begin();
    r_1_skill.push_back(YangWei);
    r_1_skill.push_back(YangWei);
    r_1_skill.push_back(YaoWu);
    r_1_skill_it = r_1_skill.begin();//push_back֮��һ��Ҫ�õ��������ã�����
    vector<S> HX_skill;
    vector<S>::iterator HX_skill_it = HX_skill.begin();
    HX_skill.push_back(YangWei);
    HX_skill.push_back(YangWei);
    HX_skill.push_back(YaoWu);
    HX_skill_it = HX_skill.begin();//push_back֮��һ��Ҫ�õ��������ã�����
    vector<S> YLWC_skill;
    vector<S>::iterator YLWC_skill_it = YLWC_skill.begin();
    YLWC_skill.push_back(YangWei);
    YLWC_skill.push_back(WuShuang);
    YLWC_skill_it = YLWC_skill.begin();//push_back֮��һ��Ҫ�õ��������ã�����
    r1[0].give_order("210");//���ó���˳��,������Ҫ��˫���ţ�����
    r1[1].give_order("0102");
    r1[2].give_order("01");
    vector<S> skill_set1[3] = { r_1_skill,HX_skill ,YLWC_skill };

    //¼�������ڶ���boss
    R r2[3] = { R("r_2",100,50,10),R("����",130,50,8),R("����",120,45,15) };//��һ��
    vector<S> r_2_skill;
    vector<S>::iterator r_2_skill_it = r_2_skill.begin();
    r_2_skill.push_back(YangWei);
    r_2_skill.push_back(YaoWu);
    r_2_skill.push_back(WuQian);
    r_2_skill_it = r_2_skill.begin();//push_back֮��һ��Ҫ�õ��������ã�����
    vector<S> LB_skill;
    vector<S>::iterator LB_skill_it = LB_skill.begin();
    LB_skill.push_back(WuShuang);
    LB_skill.push_back(WuShuang);
    LB_skill.push_back(WuQian);
    LB_skill_it = LB_skill.begin();//push_back֮��һ��Ҫ�õ��������ã�����
    vector<S> LR_skill;
    vector<S>::iterator LR_skill_it = LR_skill.begin();
    LR_skill.push_back(DuSha);
    LR_skill.push_back(DuSha);
    LR_skill.push_back(FenCheng);
    LR_skill_it = LR_skill.begin();//push_back֮��һ��Ҫ�õ��������ã�����
    r2[0].give_order("210");//���ó���˳��,������Ҫ��˫���ţ�����
    r2[1].give_order("0102");
    r2[2].give_order("1002");
    vector<S> skill_set2[3] = { r_2_skill,LB_skill ,LR_skill };

    //¼������������boss
    R r3[2] = { R("r_3",100,50,10),R("��׿",220,45,16) };//��һ��
    vector<S> r_3_skill;
    vector<S>::iterator r_3_skill_it = r_3_skill.begin();
    r_3_skill.push_back(YangWei);
    r_3_skill.push_back(XiongCan);
    r_3_skill.push_back(YaoWu);
    r_3_skill_it = r_3_skill.begin();//push_back֮��һ��Ҫ�õ��������ã�����
    vector<S> DZ_skill;
    vector<S>::iterator DZ_skill_it = DZ_skill.begin();
    DZ_skill.push_back(XiongCan);
    DZ_skill.push_back(XiongCan);
    DZ_skill.push_back(TanLan);
    DZ_skill_it = DZ_skill.begin();//push_back֮��һ��Ҫ�õ��������ã�����
    r3[0].give_order("210");//���ó���˳��,������Ҫ��˫���ţ�����
    r3[1].give_order("0102");
    vector<S> skill_set3[2] = { r_3_skill,DZ_skill };

    //¼��Ӣ�����˵�һ��boss
    R r4[2] = { R("r_4",100,50,10),R("������˹",200,50,15) };//��һ��
    vector<S> r_4_skill;
    vector<S>::iterator r_4_skill_it = r_4_skill.begin();
    r_4_skill.push_back(YangWei);
    r_4_skill.push_back(YangWei);
    r_4_skill.push_back(YaoWu);
    r_4_skill_it = r_4_skill.begin();//push_back֮��һ��Ҫ�õ��������ã�����
    vector<S> DLES_skill;
    vector<S>::iterator DLES_skill_it = DLES_skill.begin();
    DLES_skill.push_back(DSSF);
    DLES_skill.push_back(DSSF);
    DLES_skill.push_back(DSSF);
    DLES_skill_it = DLES_skill.begin();//push_back֮��һ��Ҫ�õ��������ã�����
    r4[0].give_order("210");//���ó���˳��,������Ҫ��˫���ţ�����
    r4[1].give_order("001");
    vector<S> skill_set4[2] = { r_1_skill,DLES_skill };

    //¼��Ӣ�����˵ڶ���boss
    R r5[3] = { R("r_5",100,50,10),R("������",180,80,10),R("��ŭ��ʿ",200,60,20) };//��һ��
    vector<S> r_5_skill;
    vector<S>::iterator r_5_skill_it = r_5_skill.begin();
    r_5_skill.push_back(YangWei);
    r_5_skill.push_back(YangWei);
    r_5_skill.push_back(YaoWu);
    r_5_skill_it = r_5_skill.begin();//push_back֮��һ��Ҫ�õ��������ã�����
    vector<S> DLW_skill;
    vector<S>::iterator DLW_skill_it = DLW_skill.begin();
    DLW_skill.push_back(XZFF);
    DLW_skill.push_back(XZFF);
    DLW_skill.push_back(XZFF);
    DLW_skill.push_back(KDLF);
    DLW_skill_it = DLW_skill.begin();//push_back֮��һ��Ҫ�õ��������ã�����
    vector<S> BNQS_skill;
    vector<S>::iterator BNQS_skill_it = BNQS_skill.begin();
    BNQS_skill.push_back(FSBXQ);
    BNQS_skill.push_back(FSBXQ);
    BNQS_skill.push_back(KLCF);
    BNQS_skill.push_back(KLCF);
    BNQS_skill_it = BNQS_skill.begin();//push_back֮��һ��Ҫ�õ��������ã�����
    r5[0].give_order("210");//���ó���˳��,������Ҫ��˫���ţ�����
    r5[1].give_order("1002");
    r5[2].give_order("0102");
    vector<S> skill_set5[3] = { r_5_skill,DLW_skill ,BNQS_skill };

    //¼��Ӣ�����˵�����boss
    R r6[2] = { R("r_6",100,50,10),R("˹ά��",300,70,20) };//��һ��
    vector<S> r_6_skill;
    vector<S>::iterator r_6_skill_it = r_6_skill.begin();
    r_6_skill.push_back(YangWei);
    r_6_skill.push_back(YangWei);
    r_6_skill.push_back(YaoWu);
    r_6_skill_it = r_6_skill.begin();//push_back֮��һ��Ҫ�õ��������ã�����
    vector<S> SWY_skill;
    vector<S>::iterator SWY_skill_it = SWY_skill.begin();
    SWY_skill.push_back(JTZC);
    SWY_skill.push_back(JTZC);
    SWY_skill.push_back(KSYQ);
    SWY_skill.push_back(EMSH);
    SWY_skill_it = SWY_skill.begin();//push_back֮��һ��Ҫ�õ��������ã�����
    r6[0].give_order("210");//���ó���˳��,������Ҫ��˫���ţ�����
    r6[1].give_order("0123");
    vector<S> skill_set6[2] = { r_6_skill,SWY_skill };

    //¼�����μǵ�һ��boss
    R r7[3] = { R("r_7",100,50,10),R("��Ǵ���",300,100,25),R("���Ǵ���",300,130,15) };//��һ��
    vector<S> r_7_skill;
    vector<S>::iterator r_7_skill_it = r_7_skill.begin();
    r_7_skill.push_back(YangWei);
    r_7_skill.push_back(YangWei);
    r_7_skill.push_back(YaoWu);
    r_7_skill_it = r_7_skill.begin();//push_back֮��һ��Ҫ�õ��������ã�����
    vector<S> JJDW_skill;
    vector<S>::iterator JJDW_skill_it = JJDW_skill.begin();
    JJDW_skill.push_back(JGBH);
    JJDW_skill.push_back(JGBH);
    JJDW_skill_it = JJDW_skill.begin();//push_back֮��һ��Ҫ�õ��������ã�����
    vector<S> YJDW_skill;
    vector<S>::iterator YJDW_skill_it = YJDW_skill.begin();
    YJDW_skill.push_back(PYTW);
    YJDW_skill.push_back(PYTW);
    YJDW_skill_it = YJDW_skill.begin();//push_back֮��һ��Ҫ�õ��������ã�����
    r7[0].give_order("210");//���ó���˳��,������Ҫ��˫���ţ�����
    r7[1].give_order("01");
    r7[2].give_order("01");
    vector<S> skill_set7[3] = { r_7_skill,JJDW_skill ,YJDW_skill };

    //¼�����μǵڶ���boss
    R r8[4] = { R("r_5",100,50,10),R("ţħ��",350,120,30),R("�캢��",250,160,10),R("���ȹ���",400,80,50) };//��һ��
    vector<S> r_8_skill;
    vector<S>::iterator r_8_skill_it = r_8_skill.begin();
    r_8_skill.push_back(YangWei);
    r_8_skill.push_back(YangWei);
    r_8_skill.push_back(YaoWu);
    r_8_skill_it = r_8_skill.begin();//push_back֮��һ��Ҫ�õ��������ã�����
    vector<S> NMW_skill;
    vector<S>::iterator NMW_skill_it = NMW_skill.begin();
    NMW_skill.push_back(HFB);
    NMW_skill.push_back(HFB);

    NMW_skill_it = NMW_skill.begin();//push_back֮��һ��Ҫ�õ��������ã�����
    vector<S> HHE_skill;
    vector<S>::iterator HHE_skill_it = HHE_skill.begin();
    HHE_skill.push_back(SMZH);
    HHE_skill.push_back(SMZH);
    HHE_skill_it = HHE_skill.begin();//push_back֮��һ��Ҫ�õ��������ã�����
    vector<S> TSGZ_skill;
    vector<S>::iterator TSGZ_skill_it = TSGZ_skill.begin();
    TSGZ_skill.push_back(LSXF);
    TSGZ_skill.push_back(LSXF);
    TSGZ_skill_it = TSGZ_skill.begin();//push_back֮��һ��Ҫ�õ��������ã�����
    r8[0].give_order("210");//���ó���˳��,������Ҫ��˫���ţ�����
    r8[1].give_order("100");
    r8[2].give_order("100");
    r8[3].give_order("100");
    vector<S> skill_set8[4] = { r_8_skill,NMW_skill ,HHE_skill ,TSGZ_skill };

    //¼�����μǵ�����boss
    R r9[2] = { R("r_9",100,50,10),R("����⨺�",500,160,50) };//��һ��
    vector<S> r_9_skill;
    vector<S>::iterator r_9_skill_it = r_9_skill.begin();
    r_9_skill.push_back(YangWei);
    r_9_skill.push_back(YangWei);
    r_9_skill.push_back(YaoWu);
    r_9_skill_it = r_9_skill.begin();//push_back֮��һ��Ҫ�õ��������ã�����
    vector<S> LEMH_skill;
    vector<S>::iterator LEMH_skill_it = LEMH_skill.begin();
    LEMH_skill.push_back(DTYB);
    LEMH_skill.push_back(DTYB);
    LEMH_skill.push_back(JYBD);
    LEMH_skill_it = LEMH_skill.begin();//push_back֮��һ��Ҫ�õ��������ã�����
    r9[0].give_order("210");//���ó���˳��,������Ҫ��˫���ţ�����
    r9[1].give_order("012");
    vector<S> skill_set9[2] = { r_9_skill,LEMH_skill };

    

    set_color(0xF, 0);
    cout << R"(       
            *    *                  *      *                                 *                     **
    *       ***  ***                ***    **                                ***                    **
    ***     **   **                 **      **                               **                      **
    **      **   **                 **      **                *     **       **              *       *        **
    **  *   **   ** **             **       *                 *********      **              ********************
   ****** ************             **            **           **    **       **             **               **
   **       **   **               *** **************          **    **       ** **          **               *
  **        **   **               ***                         **    ** ************        **     *    **   *
  *    *    **   **              ****   *      *              **    **       **                  ***     **
  *******   **   ** **          ** **   *      ***            **    **       **                 **        ***
 *  **   **************         *  **   **     **             ********  *    **                **          ***
    **                         *   **    *     **             **    **   *   **               **              **
    **  *  *      **               **    *     *              **    **   **  **              **                 *
 ********* **********              **    **    *              **    **   **  **                           **
    **     **     **               **    ***   *              **    **   **  **                **************
    **     **     **               **     **  **              **    **   *   **                      **
    **     **     **               **     **  *               **    **       **                      **
    **   * *********               **     **  *               ********       **                      **
    **  *  **     **               **     *   *               **    **       **                      **
    ** *   **     **               **        *                **    *        **                      **
    ***    **     **               **        *    **          *              **                      **
   ***     *********               ******************                    ******                      **
    *      **     **               **                                      ***                       **       **
           *      *                *                                        *              **********************)" << endl;
    set_color();
restart://goto ����ĵط�����Ϸ���¿�ʼ
    p.reset();
    int choice;
    char ch_choice;
    while (1)
    {
        ifstream in("level.txt");
        in >> level;
        in.close();
        cout << endl << "0.����Ϸ 1.���� 2.�嵵 3.�˳���Ϸ" << endl;
        cin >> ch_choice;
        choice = dicision(0, 4, ch_choice);
        //�����ý�ɫ��ʼ����������û�ѡ������Ļ�
        if (!choice)//����Ϸ
        {
            delete_save();//�Զ�ִ���嵵����
            bag.clear();
            skill_bag.clear();
            BossName_bag.clear();
            level = 1;
            //for test ������������һ������(����)
            cure(p);
            random_fall_skill(numOfSkill_1, skill_bag, ThrKingSkill_it, ThrKingSkill, p);
            Sleep(2000);
            cout << "����ʲô�����ܣ�����������" << endl;
            Sleep(1000);
            break;
        }
        else if (choice == 1)//����
        {
            if (!level)
            {
                cout << "��û�д浵�������ѡ��ʼ�µ���Ϸ" << endl;
            }
            else
            {
                bag.clear();
                skill_bag.clear();
                BossName_bag.clear();
                
                read_level(level);
                read_item(bag, item);
                read_skill(skill_bag, skill);
                read_BossName(BossName_bag, BossName);

                cure(p);
                break;
            }
        }
        else if (choice == 2)//�嵵
        {
            if (!level)
                cout << "��û�д浵���޷��嵵,�����ѡ��ʼ�µ���Ϸ" << endl;
            else
            {
                delete_save();
                cout << "�嵵�ɹ�" << endl;
            }
        }
        else if (choice == 3)
        {
            cout << "��л����~";
            exit(0);
        }
    }
    //������һ��
    if (level == 1)
    {
        save_level(level);
        cout << endl << " ���Ŵ���һ��ǿ�ҵ�ѣ�Σ��㻺���������۾����ƻ�Ĺ�â�������˫�ۣ���վ�����������ܣ������Լ��ƺ���һ�����䳡�ϣ����ҡ����������ģ��Ҳ��������ΰɣ���" << endl;
        Sleep(3000);
        cout << "��������и���������ӣ��㲻���ս��������Ժ���ͻȻ�����ĸ���" << endl;
        Sleep(2000);
        set_color(4, 0);
        cout << "����֮��" << endl;
        set_color();
        Sleep(2000);
        cout << "������ʲô����" << endl;
        Sleep(1000);
        cout << "���ŵš��ĽŲ���������ѭ����ȥ��ֻ����λ������װ�ı��δ���վ�ڲ�Զ���������뿪����Щʲô������һλȴ����һ��˵����"
            << "�����»��ۣ��������ĳ�һͬ�����˴����������ڴ˵ȴ�һλ����֮�˲���֮��ս��ֻ�д����������֮һ������ܼ�������ọ́��� " << endl;
        Sleep(5000);
        cout << "�����ۣ������ĳ��ⲻ������ʱ�ڵ���ô������ô���������ǣ��� �������Լ�һ�ѣ�ȴ���Լ��۵Ĵ������졣" << endl
            << "�����λ�ͦ��ʵ�ģ����Ҿ������������ǺúõĻ�һ�ᣡ��" << "�����������ӭ����ȥ��" << endl;
        Sleep(3000);
        cout << "�����˭���֣�" << endl << "0. ����   1. �����ĳ�" << endl;//�����������ûд
        //ÿһ�ؿ�ʼʱ��Ҫ����index
        index = 0;
        int choose;
        char char_choose;
        cin >> char_choose;
        fflush(stdin);
        //�ų��Ƿ�����
        choose = dicision(0, 1, char_choose) + 1;
        int con = fight(p, r1[choose], index, skill_bag, skill_bag_it, skill_set1[choose], numOfItem_1, bag, ThrKingItem, ThrKingItem_it, numOfSkill_1, ThrKingSkill, ThrKingSkill_it);
        cure(r1[choose]);
        if (con == 2)
        {
            delete_save();
            goto restart;
        }
        if (!con)
        {
            int fall_dice;
            cout << "��Ӯ�ˣ�ȴ��֪����������ʲô" << endl << endl;
            Sleep(2000);
            cout << "��С�ֵܹ�Ȼʵ��ǿ�����������ˡ�������Ϊʲô�����⣬����Ҳ���Ǻ��������ֻ֪���롰�����йء�����,��������ó̰ɣ���" << endl;
            Sleep(4000);
            cout << "������ʲô�ǡ�������������룬ֻ�����䳡����һ��Ѥ�������⻺������,�����е�";
            set_color(4, 0);
            cout << "����֮��";
            set_color();
            cout << "����������֣��ڿ��м�����ת" << endl;
            Sleep(6000);
            fall_dice = fate_dice();
            Sleep(1000);
            cout << "�����������������������۳���һ��װ��" << endl;
            Sleep(700);
            random_fall(numOfItem_1, bag, ThrKingItem_it, ThrKingItem, p);

            if (fall_dice > 4)
            {
                Sleep(2000);
                random_fall_skill(numOfSkill_1, skill_bag, ThrKingSkill_it, ThrKingSkill, p);
            }
            Sleep(2000);
            cout << "���ͬʱ������Ժ��������һ����" << endl;
            Sleep(2000);
            cout << "ÿ����һ�����ֶ��ؽ��������һ��װ��������";
            set_color(4, 0);
            cout << "����֮��";
            set_color();
            cout << "�ĵ�������4ʱ���㻹��������һ�����ܣ������õ�װ���ͼ��ܲ�������֮ǰ���ظ�" << endl;
            Sleep(6000);
        }
        BossName_bag.push_back(r1[choose].get_name());
        save_BossName(r1[choose].get_name());
        cure(p);
        show_state(p);
        level++;
        save_level(level);
    }

    //�����ڶ���
    if (level == 2)
    {
        cout << endl << "���ݡ�����ǰһ���������Լ�������һ����̻Ի͵Ĺ����С�";
        Sleep(2000);
        cout << "�����������һ�ͽ��������Ҳ��Ƕ�׿����ıʿ���塣" << endl << "�������ƿ�����ʱ�����ǿ�����";
        Sleep(2000);
        cout << "��С�ӣ��㾹����������������²�С�����������Ϊֹ�ˣ���Ȼ�����ǲ����Զ���٣�����һ���ɣ���" << endl;
        Sleep(3000);
        cout << endl << "�����˭���֣�" << endl;
        cout << "0. ����   1. ����" << endl;//�����������ûд
        //ÿһ�ؿ�ʼʱ��Ҫ����index
        index = 0;
        int choose;
        char char_choose;
        cin >> char_choose;
        fflush(stdin);
        //�ų��Ƿ�����
        choose = dicision(0, 1, char_choose) + 1;
        int con = fight(p, r2[choose], index, skill_bag, skill_bag_it, skill_set2[choose], numOfItem_1, bag, ThrKingItem, ThrKingItem_it, numOfSkill_1, ThrKingSkill, ThrKingSkill_it);
        cure(r2[choose]);
        if (con == 2)
        {
            delete_save();
            goto restart;
        }
        if (!con)
        {
            int fall_dice;
            cout << "����Ӯ�ˣ�����涨�ҵȱ�����ֹ���ǰ�����������������˵��" << endl;
            Sleep(2000);
            cout << "��������ʲô�������ʵ���" << endl;
            Sleep(1000);
            cout << "���˶�����һ��ҡ��ҡͷ���Ҳ�֪������Ҳ��֪��Ϊ���ҵȡ�Ϊ�λ�����������ǹ��������Ƭ�ռ�������ߣ�����Ҳֻ�ǰ��չ����ָʾ���¡���" << endl;
            Sleep(2000);
            cout << "����������Ҳ��֪���������ҵü�����ȥ�ˡ�����������ʧ��ԭ�أ�������������뵽" << endl;
            Sleep(2500);
            cout << "�㿴����������һ�Ź⻪���ڻ������ۣ�����֮��һԾ�����ڿ��м�����ת,��֪Ϊʲô����������ڴ����ӵ�������4������ڴ��ܻ��һ���¼���" << endl;
            Sleep(4000);
            fall_dice = fate_dice();
            Sleep(500);
            if (fall_dice > 4)
            {
                cout << "���ڴ���4�ˣ�" << endl;
            }
            else
            {
                cout << "��ϧ" << endl;
            }
            Sleep(600);
            cout << "���Ź⻪˲�����" << endl;
            Sleep(600);
            random_fall(numOfItem_1, bag, ThrKingItem_it, ThrKingItem, p);
            Sleep(2000);
            if (fall_dice > 4)
            {


                random_fall_skill(numOfSkill_1, skill_bag, ThrKingSkill_it, ThrKingSkill, p);
                Sleep(2000);
            }

        }
        BossName_bag.push_back(r2[choose].get_name());
        save_BossName(r2[choose].get_name());
        cout << "����������ڸղŵĵ�ʧʱ,һλ�����ڽ�ȴ�ޱ����ݵ���Ƥ���ߴ��ŷŵ���Ц��������" << endl;
        Sleep(3000);
        cout << "�������ˣ��Ϸ���������棬������ṩһ��СС�İ�������Σ���" << endl;
        Sleep(2000);
        cout << "û���㷴Ӧ������������˵�������Ҹ�������ѡ������㰴��0����ô�ҽ��ṩ����װ����������������ѡ����һ����������Ʒ��һ�㣬���Ҳ��ܺ����Ѿ�ӵ�е��ظ���" << endl;
        Sleep(4000);
        cout << "����㰴��1����ô�ҽ�������ҵĶ���A�οڴ�������ó�һ��װ�������ǵ�Ʒ���и��еͣ��ף������о�Ȼ�и�����֮���������ɣ������������4����ô�㻹��������һ�����ܡ�������������ṩ�����а����ˣ�" << endl;
        Sleep(5000);
        show_state(p);
        cout << "���ѡ����:" << endl << "0.����ѡ 1.������" << endl;
        int choose_;
        char char_choose_;
        cin >> char_choose_;
        fflush(stdin);
        choose_ = dicision(0, 2, char_choose_);
        Sleep(500);
        if (choose_ == 1)//��ѡ��������
        {
            cout << "��������������ν�ġ�����A�Ρ����ƿڴ��е����˼��£������ó���һ��װ��" << endl;
            Sleep(1200);
            random_fall(numOfItem_All, bag, item_it, item, p);
            Sleep(2000);
            int di = fate_dice();
            Sleep(500);
            if (di > 4)
            {
                cout << "����������������ˣ��⼼�ܾ�������ˣ���" << endl;
                Sleep(1000);
                random_fall_skill(numOfSkill_All, skill_bag, skill_it, skill, p);
            }
            else
                cout << "������������������ϧ��ϧ����������ʧ����֪�Ǹ��أ���" << endl;
        }
        else//��ѡ�����̵�
        {

            vector<Item> item_choose;
            vector<Item>::iterator item_c_it = item_choose.begin();
            vector<S> skill_choose;
            vector<S>::iterator skill_c_it = skill_choose.begin();
            int di_item_1, di_item_2;
            di_item_1 = hidden_dice(numOfItem_1);//�������װ����
            di_item_2 = hidden_dice(numOfItem_1);
            while (di_item_2 == di_item_1)//��ֹ�̵��װ�������ظ�
            {
                di_item_2 = hidden_dice(numOfItem_1);
            }
            int di_skill_1, di_skill_2;
            di_skill_1 = hidden_dice(numOfSkill_1);//������ļ�����
            di_skill_2 = hidden_dice(numOfSkill_1);
            while (di_skill_2 == di_skill_1)//��ֹ�����ظ�
            {
                di_skill_2 = hidden_dice(numOfSkill_1);
            }
            item_it = item.begin();
            //��װ���ͼ��ܡ�����",������
            item_choose.push_back(*(item_it += di_item_1));
            item_it = item.begin();
            item_choose.push_back(*(item_it += di_item_2));
            skill_it = skill.begin();
            skill_choose.push_back(*(skill_it += di_skill_1));
            skill_it = skill.begin();
            skill_choose.push_back(*(skill_it += di_skill_2));
            item_it = item.begin();
            skill_it = skill.begin();
            //չʾ����Ʒ��
            int shop_index = 0;
            cout << "���������������Ϸ����׼���ģ�Ҫע����ѡ�Ĳ�Ҫ����֮ǰ���ظ�Ŷ�����ߴ��Ž����Ц��ƽ̯˫�֣����и����ĵ���â" << endl;
            Sleep(3000);
            for (auto i : item_choose)
            {
                cout << shop_index << ". " << i.get_name() << "(" << i.get_discription() << ")" << endl;
                shop_index++;
            }
            for (auto j : skill_choose)
            {
                cout << shop_index << ". " << j.show_name() << " (" << j.show_discription() << ")" << endl;
                shop_index++;
            }
            Sleep(800);
            int choice;
            char ch_choice;
            cout << "�������ѡ���" << endl;
            cin >> ch_choice;
            fflush(stdin);
            choice = dicision(0, 3, ch_choice);
            item_c_it = item_choose.begin();
            skill_c_it = skill_choose.begin();
            switch (choice)
            {
            case 0:take_item(bag, item_c_it); break;
            case 1:take_item(bag, ++item_c_it); break;
            case 2:take_skill(skill_bag, skill_c_it); break;
            case 3:take_skill(skill_bag, ++skill_c_it); break;
            }
        }
        Sleep(1500);
        cout << "���æ��ǰ������������һ�о�������ô���£���ȴ��һ�����䣬��Ӱ�������޾��Ļƻ�֮�У�ڤڤ֮�д���������������������";
        cout << "�������ˣ�����Ԥ�����ǵ����˻����ٴν��㣬��Ĺ��»�Զδ��������" << endl;
        cure(p);
        show_state(p);
        level++;
        save_level(level);
    }

    //����������
    if (level == 3)
    {
        cout << "�����ԭ�أ���ǰ��Ȼ���ݡ���һ��������ǰ����ΰ����˲���Ϊһ�������ǳء�" << endl;
        Sleep(2000);
        cout << "��������ȴֻ��һ����Ӱ�������˳ߣ�����ʮΧ���������أ������ڷ��ֳ����࣬�߼�������ֻ��һ�ˣ��������ѹ�ȸ�ȴ��֮ǰ���������ж��ֶ�Ҫ��" << endl;
        Sleep(5000);
        cout << "�����Ƕ�׿��ȥ���ɣ�����˫ĿԲ�ɣ�û���㷢����������ֱ�����";
        //ÿһ�ؿ�ʼʱ��Ҫ����index
        index = 0;
        int con = fight(p, r3[1], index, skill_bag, skill_bag_it, skill_set3[1], numOfItem_1, bag, ThrKingItem, ThrKingItem_it, numOfSkill_1, ThrKingSkill, ThrKingSkill_it);
        cure(r3[1]);
        if (con == 2)
        {
            delete_save();
            goto restart;
        }
        if (!con)
        {
            int fall_dice;
            cout << "������һ����������Ӯ�ˡ�" << endl;
            Sleep(500);
            cout << "��������ô�᣿���������ö����𵴣������ȴ������������׿��ɬ��˵��" << endl;
            Sleep(2000);
            star(2, 0);
            cout << "��׿����Ӱ��ʧ��ȡ����֮����һ���������۵Ĺ⻪" << endl;
            Sleep(1000);
            fall_dice = fate_dice();
            Sleep(500);
            random_fall(numOfItem_1, bag, ThrKingItem_it, ThrKingItem, p);
            Sleep(1000);
            if (fall_dice > 4)
            {
                random_fall_skill(numOfSkill_1, skill_bag, ThrKingSkill_it, ThrKingSkill, p);
                Sleep(1000);
            }
        }
        BossName_bag.push_back(r3[1].get_name());
        save_BossName(r3[1].get_name());
        cure(p);
        show_state(p);
        level++;
        save_level(level);
    }

    //Ӣ�����˵�һ��
    if (level == 4)
    {
        cout << endl << "���ӹ�һ�٣��������װ������е������־,����Ҫ�ư���������" << endl;
        Sleep(1500);
        cout << "���ݡ���һ���������ɣ��ҵĺ�ͼ��ҵ��������ȵ��뵽��" << endl;
        Sleep(1500);
        cout << "�����任��֮ǰԤ�ϵ�����ʱ�ڵľ���û�г��֣�ȡ����֮����һ��������ʶ��Ͽ�ȡ���������Ǹ�ʲô��LOL���Ͽ�Ȱ���������һ��" << endl;
        Sleep(3000);
        cout << "����������֮�ʣ����澹Ȼ����һ��Ӣ�����˵�Ӣ�ۣ���������˹������ɣ���Ӣ�����˶����ˡ�����" << endl;
        Sleep(1500);
        cout << "�㾪�ȵ�ͬʱ������˼����ԭ���Ҹղ������������Ǹ������Ҳ�����Ϊ���Ǹ��������ˣ��ɳ�����������Ͽ�ȣ��ָ�����ӳ�ȥ����" << endl;
        Sleep(5000);
        //ÿһ�ؿ�ʼʱ��Ҫ����index
        index = 0;
        int con = fight(p, r4[1], index, skill_bag, skill_bag_it, skill_set4[1], numOfItem_2, bag, LOLItem, LOLItem_it, numOfSkill_2, LOLSkill, LOLSkill_it);
        cure(r4[1]);
        if (con == 2)
        {
            delete_save();
            goto restart;
        }
        if (!con)
        {
            int fall_dice;
            cout << "��սʤ�˵�����˹��������ض���˵��������ô������������Ǳ�����˭���������ʲô����" << endl;
            Sleep(3000);
            cout << "������˹���������İ��ĺ��У�ҡҡͷ����Ҳ��֪������ֻ�Ǹе������ڴ������㣬��һ�ж��ǹ���İ��š�" << endl;
            Sleep(2000);

            cout << "����ʧ��Ͽ�����룬ȡ����֮����һ���������۵Ĺ⻪" << endl;
            Sleep(1000);
            fall_dice = fate_dice();
            Sleep(500);
            random_fall(numOfItem_2, bag, LOLItem_it, LOLItem, p);
            Sleep(1000);
            if (fall_dice > 4)
            {
                random_fall_skill(numOfSkill_2, skill_bag, LOLSkill_it, LOLSkill, p);
                Sleep(1000);
            }
        }
        BossName_bag.push_back(r4[1].get_name());
        save_BossName(r4[1].get_name());
        cure(p);
        show_state(p);
        level++;
        save_level(level);
    }

    //Ӣ�����˵ڶ���
    if (level == 5)
    {
        cout << endl << "�㿴���˵��ϵ�С�������ڴ���������ǰ����������Ϊ��֪ȥ���δ�����ѡ���˸���" << endl;
        Sleep(1000);
        cout << "�н��䣬ͻȻ��������Ӱ��·�ԵĲݴ������˳�����һ������һֻ��ª�Ĵ������ϣ��ͳ���ǹ����һ���ӳ��ɸ����������Ե�С��ͳͳ�ɵ������Ǳ�ŭ��ʿ������ģ�" << endl;
        Sleep(3000);
        cout << "�����ǲ����Զ���٣���ѡһ���ɡ������պ���ǹ�ͷɸ��������ڷ�����ǰ" << endl;
        Sleep(2000);
        cout << "�����˭���֣�" << endl << "0. ������   1. ��ŭ��ʿ" << endl;
        //ÿһ�ؿ�ʼʱ��Ҫ����index
        index = 0;
        int choose;
        char char_choose;
        cin >> char_choose;
        fflush(stdin);
        //�ų��Ƿ�����
        choose = dicision(0, 1, char_choose) + 1;
        int con = fight(p, r5[choose], index, skill_bag, skill_bag_it, skill_set5[choose], numOfItem_2, bag, LOLItem, LOLItem_it, numOfSkill_2, LOLSkill, LOLSkill_it);
        cure(r5[choose]);
        if (con == 2)
        {
            delete_save();
            goto restart;
        }
        if (!con)
        {
            int fall_dice;
            cout << "����ǿ������Ϊ���������˰�����λսʿ��ˬ�ش�Ц�����㽻������ʹ�죡��" << endl;
            Sleep(2000);
            cout << "���ǻ�Ϊһ�����۵Ĺ⻪������֮�������˿���" << endl;
            Sleep(1200);
            fall_dice = fate_dice();
            random_fall(numOfItem_2, bag, LOLItem_it, LOLItem, p);
            Sleep(1000);
            if (fall_dice > 4)
            {
                random_fall_skill(numOfSkill_2, skill_bag, LOLSkill_it, LOLSkill, p);
                Sleep(1000);
            }
        }
        BossName_bag.push_back(r5[choose].get_name());
        save_BossName(r5[choose].get_name());
        cout << "��������Ϊ�����¶��ֳ���ʱ��һλͷ����ʦñ���ֳּ��罣�е����߼�Ԧ�ż�������������ǰ" << endl;
        Sleep(2000);
        cout << "���Ϸ�׷�����˵�ָ���������������ٴ������ˣ������ˡ�ԭ����������֮ǰ����������ͷ���ߣ�ֻ�ǲ�֪Ϊ�α�����⸱����" << endl;
        Sleep(3000);
        //���û�������������,����
        cout << "�������һ�����ֿ�ǰǿ���Ϸ�Ҫ����һ��֮�����Ϲ�أ����ѡ���ǣ���" << endl;
        show_state(p);
        cout << "0.����ѡ 1.������" << endl;
        int choose_;
        char char_choose_;
        cin >> char_choose_;
        fflush(stdin);
        choose_ = dicision(0, 2, char_choose_);
        if (choose_ == 1)//��ѡ��������
        {
            random_fall(numOfItem_All, bag, item_it, item, p);
            Sleep(1000);
            cout << "������֮����������4ʱ�㽫�����ü���" << endl;
            int di = fate_dice();
            Sleep(500);
            if (di > 4)
            {
                cout << "������������������������" << endl;
                Sleep(1500);
                random_fall_skill(numOfSkill_All, skill_bag, skill_it, skill, p);
            }
            else
                cout << "�Ǻǣ�����Ƿ�ѣ�����������������ȥ���ҵ��ӳ��������İ취" << endl;
        }
        else//��ѡ�����̵�
        {

            vector<Item> item_choose;
            vector<Item>::iterator item_c_it = item_choose.begin();
            vector<S> skill_choose;
            vector<S>::iterator skill_c_it = skill_choose.begin();
            int di_item_1, di_item_2;
            di_item_1 = hidden_dice(numOfItem_2);//�������װ����
            di_item_2 = hidden_dice(numOfItem_2);
            while (di_item_2 == di_item_1)//��ֹ�̵��װ�������ظ�
            {
                di_item_2 = hidden_dice(numOfItem_2);
            }
            int di_skill_1, di_skill_2;
            di_skill_1 = hidden_dice(numOfSkill_2);//������ļ�����
            di_skill_2 = hidden_dice(numOfSkill_2);
            while (di_skill_2 == di_skill_1)//��ֹ�����ظ�
            {
                di_skill_2 = hidden_dice(numOfSkill_2);
            }

            //��װ���ͼ��ܡ�����",������
            item_it = item.begin();
            item_choose.push_back(*(item_it += di_item_1 + numOfItem_1));
            item_it = item.begin();
            item_choose.push_back(*(item_it += di_item_2 + numOfItem_1));
            skill_it = skill.begin();
            skill_choose.push_back(*(skill_it += di_skill_1 + numOfSkill_1));
            skill_it = skill.begin();
            skill_choose.push_back(*(skill_it += di_skill_2 + numOfSkill_1));
            item_it = item.begin();
            skill_it = skill.begin();
            //չʾ����Ʒ��
            int shop_index = 0;
            for (auto i : item_choose)
            {
                cout << shop_index << ". " << i.get_name() << "(" << i.get_discription() << ")" << endl;
                shop_index++;
            }
            for (auto j : skill_choose)
            {
                cout << shop_index << ". " << j.show_name() << " (" << j.show_discription() << ")" << endl;
                shop_index++;
            }
            Sleep(800);
            cout << "�������ѡ��" << endl;
            int choice;
            char ch_choice;
            cin >> ch_choice;
            fflush(stdin);
            choice = dicision(0, 3, ch_choice);
            item_c_it = item_choose.begin();
            skill_c_it = skill_choose.begin();
            switch (choice)
            {
            case 0:take_item(bag, item_c_it); break;
            case 1:take_item(bag, ++item_c_it); break;
            case 2:take_skill(skill_bag, skill_c_it); break;
            case 3:take_skill(skill_bag, ++skill_c_it); break;
            }
        }
        cure(p);
        show_state(p);
        level++;
        save_level(level);
    }

    //Ӣ�����˵�����
    if (level == 6)
    {
        cout << endl << "�㱻���͵��˹�ľ������Ұ����һλ����ɭȻ֮���ĵ���Ӱ���������" << endl;
        Sleep(2000);
        cout << "������ŵ����˹ͳ�졪��˹ά��" << endl;
        Sleep(1500);
        cout << "���ñ��ĵ�Ŀ�⿴���㣬��������ֻ��ħ֮��" << endl;
        Sleep(1500);
        //ÿһ�ؿ�ʼʱ��Ҫ����index
        index = 0;
        int con = fight(p, r6[1], index, skill_bag, skill_bag_it, skill_set6[1], numOfItem_2, bag, LOLItem, LOLItem_it, numOfSkill_2, LOLSkill, LOLSkill_it);
        cure(r6[1]);
        if (con == 2)
        {
            delete_save();
            goto restart;
        }
        if (!con)
        {
            int fall_dice;
            cout << "���⣬��ô���ܣ���������˼��ؿ����㣬̾�˿������������ҵ�ʵ����������ͳ��ŵ����˹��" << endl;
            Sleep(3000);
            cout << "���Ķ�ħ֮������һ�Ź⻪����" << endl;
            Sleep(1000);
            fall_dice = fate_dice();
            random_fall(numOfItem_2, bag, LOLItem_it, LOLItem, p);
            Sleep(1000);
            if (fall_dice > 4)
            {
                random_fall_skill(numOfSkill_2, skill_bag, LOLSkill_it, LOLSkill, p);
                Sleep(1000);
            }
            cout << "�����߰ɣ�����Ҫ�����մ𰸻���ǰ����������Ӱ����������һͬ�䵭��������ʧ" << endl;
            Sleep(1000);
        }

        BossName_bag.push_back(r6[1].get_name());
        save_BossName(r6[1].get_name());
        cure(p);
        show_state(p);
        level++;
        save_level(level);
    }

    //���μǵ�һ��
    if (level == 7)
    {

        cout << endl << "��â�������㷢��������һ������֮�У�ͮ�����飬���ܵ�麣�����ׯ�ϣ����ܵ���������ҩ�㡣��Ī�������μ��еĶ��ʹ���" << endl;
        Sleep(3000);
        cout << "ֻ��һ�����Ž�Ǻ�һ���������ǵ��˴ӹ������߳���һ����ĸߴ���࣬һ������СһЩ�����ﵷ����һ��Сҩƿ��" << endl
            << "���ǽ�Ǵ��������Ǵ���" << endl;
        Sleep(2000);
        cout << "����Ȼ���Ǻ���һ���ϣ��������������ֻ�ܵ�������ѡһ���ɡ�" << endl;
        Sleep(1500);
        cout << "��ѡ���˭���֣�" << endl << "0.��Ǵ��� 1.���Ǵ���" << endl;
        //ÿһ�ؿ�ʼʱ��Ҫ����index
        index = 0;
        int choose;
        char char_choose;
        cin >> char_choose;
        fflush(stdin);
        //�ų��Ƿ�����
        choose = dicision(0, 1, char_choose) + 1;
        int con = fight(p, r7[choose], index, skill_bag, skill_bag_it, skill_set7[choose], numOfItem_3, bag, JourWestItem, JourWestItem_it, numOfSkill_3, JourWestSkill, JourWestSkill_it);
        cure(r7[choose]);
        if (con == 2)
        {
            delete_save();
            goto restart;
        }
        if (!con)
        {
            int fall_dice;
            cout << "���ð���Ӯ�ˣ��������װ��������Ǵ�������ֱۣ��⻪������������" << endl;
            Sleep(1500);
            fall_dice = fate_dice();
            random_fall(numOfItem_3, bag, JourWestItem_it, JourWestItem, p);
            Sleep(1000);
            if (fall_dice > 4)
            {
                random_fall_skill(numOfSkill_3, skill_bag, JourWestSkill_it, JourWestSkill, p);
                Sleep(1000);
            }
        }
        cout << "���������ò��ʵ����������㣬�����ֵ����Ц��������Ȼ��Ӯ�ˣ����������μǵ��������߲��˶�Զ���������������ڴ�Ц����ʧ,ֻ��������������ҩ��ζ�Ĺ����д���" << endl;
        Sleep(1500);
        BossName_bag.push_back(r7[choose].get_name());
        save_BossName(r7[choose].get_name());
        cure(p);
        show_state(p);
        level++;
        save_level(level);
    }

    //���μǵڶ���
    if (level == 8)
    {
        cout << endl << "��âһ������ͻȻ�������е�����Ǻ���ˣ��㶨��һ��������һƬȼ���Ż���ĳ��ɽ��" << endl;
        Sleep(2000);
        cout << "����ӭ�������ǻ���ɽ���͡����ȹ��������۶��������������˵��������������ţħ���ͺ캢��" << endl;
        Sleep(1500);
        cout << "����ϣ��˭���д����أ����캢�������Ц������������Ż������Ƶĺ�ӧǹ���о�ԾԾ����" << endl;
        cout << "ţħ�������������������������������ȹ������еİŽ����и���֮�������׸ô�˭�أ�" << endl;
        Sleep(1000);
        cout << "0. ţħ��   1. �캢��   2. ���ȹ���" << endl;//�����������ûд
        //ÿһ�ؿ�ʼʱ��Ҫ����index
        index = 0;
        int choose;
        char char_choose;
        cin >> char_choose;
        fflush(stdin);
        //�ų��Ƿ�����
        choose = dicision(0, 2, char_choose) + 1;
        int con = fight(p, r8[choose], index, skill_bag, skill_bag_it, skill_set8[choose], numOfItem_3, bag, JourWestItem, JourWestItem_it, numOfSkill_3, JourWestSkill, JourWestSkill_it);
        cure(r8[choose]);
        if (con == 2)
        {
            delete_save();
            goto restart;
        }
        if (!con)
        {
            int fall_dice;
            cout << "���ܾ�û�м�����ôʹ�������ս���ˡ�ţħ������δ����˵������ϧ���ǵ����ˣ�ף��һ·˳�磡��" << endl;
            Sleep(500);
            star(2, 0);
            cout << "�⻪������������" << endl;
            Sleep(800);
            fall_dice = fate_dice();
            random_fall(numOfItem_3, bag, JourWestItem_it, JourWestItem, p);
            Sleep(1000);
            if (fall_dice > 4)
            {
                random_fall_skill(numOfSkill_3, skill_bag, JourWestSkill_it, JourWestSkill, p);
                Sleep(1000);
            }
        }
        BossName_bag.push_back(r8[choose].get_name());
        save_BossName(r8[choose].get_name());
        cout << "����������Ҳ����һ����������յ����ò��ϵ�����˵�������ȿȣ��ҷ�������ô�ߵ�������������λ����" << endl;
        Sleep(2000);
        cout << "�����ǰ��Ӧ�þ������һ���ˣ��ð���������һ��֮�����Ϲ�أ����Լ�ѡ�ɣ������߽�����ģ������С��ͯ������" << endl;
        Sleep(2000);
        //���û�������������,����
        show_state(p);
        cout << "���ѡ����:" << endl << "0.����ѡ 1.������" << endl;
        int choose_;
        char char_choose_;
        cin >> char_choose_;
        fflush(stdin);
        choose_ = dicision(0, 2, char_choose_);
        if (choose_ == 1)//��ѡ��������
        {
            random_fall(numOfItem_All, bag, item_it, item, p);
            Sleep(1000);
            int di = fate_dice();
            Sleep(500);
            if (di > 4)
            {
                cout << "����������ϣ���ҵĶ����������ҵ��������Ĵ𰸣�" << endl;
                random_fall_skill(numOfSkill_All, skill_bag, skill_it, skill, p);
                Sleep(1000);
            }
            else
            {
                cout << "���ģ����ʵ���ѽ�����ȣ��Ϸ���������ͨ�أ��������ҵ��������Ĵ𰸣�" << endl;
                Sleep(1000);
            }
        }
        else//��ѡ�����̵�
        {

            vector<Item> item_choose;
            vector<Item>::iterator item_c_it = item_choose.begin();
            vector<S> skill_choose;
            vector<S>::iterator skill_c_it = skill_choose.begin();
            int di_item_1, di_item_2;
            di_item_1 = hidden_dice(numOfItem_3);//�������װ����
            di_item_2 = hidden_dice(numOfItem_3);
            while (di_item_2 == di_item_1)//��ֹ�̵��װ�������ظ�
            {
                di_item_2 = hidden_dice(numOfItem_3);
            }
            int di_skill_1, di_skill_2;
            di_skill_1 = hidden_dice(numOfSkill_3);//������ļ�����
            di_skill_2 = hidden_dice(numOfSkill_3);
            while (di_skill_2 == di_skill_1)//��ֹ�����ظ�
            {
                di_skill_2 = hidden_dice(numOfSkill_3);
            }
            item_it = item.begin();
            //��װ���ͼ��ܡ�����",������
            item_choose.push_back(*(item_it += di_item_1 + numOfItem_1 + numOfItem_2));
            item_it = item.begin();
            item_choose.push_back(*(item_it += di_item_2 + numOfItem_1 + numOfItem_2));
            skill_it = skill.begin();
            skill_choose.push_back(*(skill_it += di_skill_1 + numOfSkill_1 + numOfSkill_2));
            skill_it = skill.begin();
            skill_choose.push_back(*(skill_it += di_skill_2 + numOfSkill_1 + numOfSkill_2));
            item_it = item.begin();
            skill_it = skill.begin();
            //չʾ����Ʒ��
            int shop_index = 0;
            for (auto i : item_choose)
            {
                cout << shop_index << ". " << i.get_name() << "(" << i.get_discription() << ")" << endl;
                shop_index++;
            }
            for (auto j : skill_choose)
            {
                cout << shop_index << ". " << j.show_name() << " (" << j.show_discription() << ")" << endl;
                shop_index++;
            }
            Sleep(800);
            cout << "�������ѡ��" << endl;
            int choice;
            char ch_choice;
            cin >> ch_choice;
            fflush(stdin);
            choice = dicision(0, 3, ch_choice);
            item_c_it = item_choose.begin();
            skill_c_it = skill_choose.begin();
            switch (choice)
            {
            case 0:take_item(bag, item_c_it); break;
            case 1:take_item(bag, ++item_c_it); break;
            case 2:take_skill(skill_bag, skill_c_it); break;
            case 3:take_skill(skill_bag, ++skill_c_it); break;
            }
        }
        cure(p);
        show_state(p);
        //wonderland(p, bag, numOfItem_3, item, item_it, skill_bag, numOfSkill_3, skill, skill_it);
        level++;
        save_level(level);
        cout << "����˵ǰ���и�ð�ư�����ļһ���Ҵ������ϴ���ҵ�������������ץ��������˵" << endl;
        Sleep(1000);
    }

    //���μǵ�����
    if (level == 9)
    {
        cout << endl << "��â��������������ˮ������һ���������͵��Ӿ��ϵ������һģһ������Ӱ����������ǰ" << endl;
        Sleep(2000);
        cout << "�����������⨺�ɡ�����̽���ʵ�" << endl;
        Sleep(1500);
        cout << "��û�����Ǳ�����Է��Ӷ����ͳ��𹿰��������˼ɵ�˵,��ֻҪ��Ӯ���ң������������ܾͽ����㳨������" << endl;
        //ÿһ�ؿ�ʼʱ��Ҫ����index
        index = 0;
        int con = fight(p, r9[1], index, skill_bag, skill_bag_it, skill_set9[1], numOfItem_3, bag, JourWestItem, JourWestItem_it, numOfSkill_3, JourWestSkill, JourWestSkill_it);
        cure(r9[1]);
        if (con == 2)
        {
            delete_save();
            goto restart;
        }
        if (!con)
        {
            cout << "����⨺���ʧ�ˣ�һ���ֳ�����������Ժ�" << endl;
            Sleep(1500);
        }
        cout << "��ϲ��ͨ����!" << endl;
        Sleep(1000);
        cout << "����ʵ��ո������˴�λʱ�գ��ж��ʱ�վ����ڴˣ��������㾭�����ʱ�յ�ԭ������һ������Ա�������ڰ���ÿһ����ʧ�ߵ��߳������ͨ��������Щ��������ҷ������ʱ�յİ��أ���ֹ����ʧ�����λʱ�գ�������������ˣ���" << endl;
        Sleep(6000);
        cout << endl;
        star(0xF, 0);
        cout << endl;
        set_color(2, 0);
        cout << "�������" << endl;
        BossName_bag.push_back(r9[1].get_name());
        save_BossName(r9[1].get_name());
        show_BossName(BossName_bag_it, BossName_bag);
        Sleep(2000);
        show_item(bag_it, bag);
        Sleep(2000);
        show_skill(skill_bag_it, skill_bag);
        Sleep(4000);
        cout << "��âһ���������ڻص�����ʵ����(��)";
    }
    delete_save();
    return 0;
}