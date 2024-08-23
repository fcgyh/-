#include "class.h"
#include "uni_fun.h"
#include<mmsystem.h>//多媒体设备接口头文件
#pragma comment(lib,"winmm.lib")
using namespace std;
int level = 0;//打到了第几关，读档用

int main()
{
    mciSendString("open ./music/BGM.mp3 alias BGM", 0, 0, 0);//向多媒体设备接口发送字符串
    mciSendString("play BGM repeat", 0, 0, 0);
    set_color();
    srand((unsigned int)time(nullptr));//初始化种子
    int choose/*选怪专用*/, dici/*选择界面专用*/, dice, di, check = 0/*检查玩家是否出招,0否,1是*/, index/*作为boss出招的索引*/;
    char char_choose;
    vector<Item> item;//游戏所有装备的容器
    vector<Item>::iterator item_it = item.begin();//游戏所有装备的迭代器
    vector<Item> ThrKingItem;//三国装备的容器
    vector<Item>::iterator ThrKingItem_it = ThrKingItem.begin();//三国装备的迭代器
    vector<Item> LOLItem;//英雄联盟装备的容器
    vector<Item>::iterator LOLItem_it = LOLItem.begin();//英雄联盟装备的迭代器
    vector<Item> JourWestItem;//西游记装备的容器
    vector<Item>::iterator JourWestItem_it = JourWestItem.begin();//西游记装备的迭代器
    vector<Item> bag;//玩家背包（已有装备的容器)
    vector<Item>::iterator bag_it = bag.begin();//玩家背包的迭代器

    vector<S> skill;//游戏所有技能的容器
    vector<S>::iterator skill_it = skill.begin();//游戏所有技能的迭代器
    vector<S> ThrKingSkill;//三国技能的容器
    vector<S>::iterator ThrKingSkill_it = ThrKingSkill.begin();//三国技能的迭代器
    vector<S> LOLSkill;//英雄联盟技能的容器
    vector<S>::iterator LOLSkill_it = LOLSkill.begin();//英雄联盟技能的迭代器
    vector<S> JourWestSkill;//西游记技能的容器
    vector<S>::iterator JourWestSkill_it = JourWestSkill.begin();//西游记技能的迭代器
    vector<S>skill_bag;//玩家存储技能的"背包"
    vector<S>::iterator skill_bag_it;//技能背包迭代器

    vector<string> BossName;//所有boss名的容器
    vector<string>::iterator BossName_it = BossName.begin();//所有boss名的迭代器
    vector<string> BossName_bag;//已打败boss名的容器
    vector<string>::iterator BossName_bag_it = BossName_bag.begin();//已打败boss名的迭代器

    //创建玩家角色
    P p("你", 100, 45, 10, 100);

    //创建怪物应在录入完装备和技能之后

    //录入装备
    //三国装备
    Item BaiYinShiZi("白银狮子", "增加防御10", 3, 1, 10, 0, 0, p);
    Item ZhuGeLianNu("诸葛连弩", "增加攻击15", 2, 1, 15, 0, 0, p);
    Item ZhangBaSheMao("丈八蛇矛", "增加攻击10，防御5", 8, 1, 10, 1, 5, p);
    Item TongYouJia("桐油甲", "增加生命40%,降低体力20%", 7, 1.4, 0, 0.8, 0, p);
    Item HuXinJia("护心甲", "增加生命25% ", 1, 1.25, 0, 0, 0, p);
    Item SanJianLiangRenDao("三尖两刃刀", "增加攻击10，体力30", 9, 1, 10, 1, 30, p);
    Item QiBaoDao("七宝刀", "增加生命15%，攻击10", 5, 1.15, 0, 1, 10, p);
    Item LiRuMaoZi("李儒的帽子", "增加生命50", 1, 1, 50, 0, 0, p);
    Item ChiTuMa("赤兔马", "增加体力100", 4, 1, 100, 0, 0, p);
    //英雄联盟装备
    Item Blackcut("黑色切割者 ", "增加生命50，攻击10", 5, 1, 50, 1, 10, p);
    Item Dlev("德莱文之斧 ", "增加攻击40%", 2, 1.4, 0, 0, 0, p);
    Item Bloodhand("血手 ", "增加生命30%，攻击30%", 5, 1.3, 0, 1.3, 0, p);
    Item Hatelock("厌恨锁链 ", "增加防御50%", 3, 1.5, 0, 0, 0, p);
    Item Thriforce("三项之力 ", "增加攻击30%，防御10% ", 8, 1.3, 0, 1.1, 0, p);
    Item Ckshi("咳血战斧 ", "增加生命20%，防御35%", 6, 1.2, 0, 1.35, 0, p);
    //西游记装备
    Item JinGuBang("金箍棒", "增加攻击60", 2, 1, 60, 0, 0, p);
    Item ZiJinHongHuLu("紫金红葫芦", "增加生命250", 1, 1, 250, 0, 0, p);
    Item JinGangZhuo("金刚琢", "增加防御50", 3, 1, 50, 0, 0, p);
    Item YangZhiYuJingPing("羊脂玉净瓶", "增加体力150", 4, 1, 150, 0, 0, p);
    Item HunTieGun("混铁棍", "增加生命100,攻击40", 5, 1, 100, 1, 40, p);
    Item QiXingJian("七星剑", "增加攻击25,体力100", 9, 1, 25, 1, 100, p);
    Item FeiLongZhang("飞龙杖", "增加攻击30,防御30", 8, 1, 30, 1, 30, p);
    Item BiHuoZhao("避火罩", "增加生命200,防御15", 6, 1, 200, 1, 15, p);
    Item DingFengZhu("定风珠", "增加生命200，体力50", 7, 1, 200, 1, 50, p);
    Item ZiJinLingDang("紫金铃铛", "增加防御30，体力80", 10, 1, 30, 1, 80, p);

    ThrKingItem.push_back(BaiYinShiZi);
    ThrKingItem.push_back(ZhuGeLianNu);
    ThrKingItem.push_back(ZhangBaSheMao);
    ThrKingItem.push_back(TongYouJia);
    ThrKingItem.push_back(HuXinJia);
    ThrKingItem.push_back(SanJianLiangRenDao);
    ThrKingItem.push_back(QiBaoDao);
    ThrKingItem.push_back(LiRuMaoZi);
    ThrKingItem.push_back(ChiTuMa);
    ThrKingItem_it = ThrKingItem.begin(); //push_back之后一定要让迭代器重置！！！

    LOLItem.push_back(Blackcut);
    LOLItem.push_back(Dlev);
    LOLItem.push_back(Bloodhand);
    LOLItem.push_back(Hatelock);
    LOLItem.push_back(Thriforce);
    LOLItem.push_back(Ckshi);
    LOLItem_it = LOLItem.begin(); //push_back之后一定要让迭代器重置！！！

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
    JourWestItem_it = JourWestItem.begin(); //push_back之后一定要让迭代器重置！！！

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
    item_it = item.begin();//push_back之后一定要让迭代器重置！！！

    /*测试
    random_fall_1(9, bag, ThrKingItem_it, ThrKingItem, p);
    random_fall_2(6, bag, LOLItem_it, LOLItem, p);
    random_fall_3(10, bag, JourWestItem_it, JourWestItem, p);
    show_item(bag_it, bag);*/
    //录入技能
   /*格式(每个技能都要这两个函数):
         S skill_name(name,choice,target1,index1,factor1,add1,dice,target2,index2,factor2,add2);
         skill_name.give_discription("string1","string2");
   */
   //生成技能对象
    //三国技能
    S YangWei("扬威", 0, 1, 5, 0.4, 0, 4, 1, 5, 1, -5, 30);
    YangWei.give_discription("消耗30体力", "降低对方60%防御", "骰子数4-6，降低对方5防御");
    S YaoWu("耀武", 1, 0, 3, 1.2, 0, 5, 0, 3, 1.3, 0, 30);
    YaoWu.give_discription("消耗30体力", "增加自身20%攻击力", "骰子数5-6，增加自身30%攻击力");
    S ShuangXiong("双雄", 0, 1, 1, 1, -50, 5, 0, 1, 1, 30, 30);
    ShuangXiong.give_discription("消耗30体力", "降低对方50的血量", "骰子数5-6，增加自身30的血量");
    S WuShuang("无双", 1, 1, 1, 1, -50, 4, 1, 1, 1, -75, 30);
    WuShuang.give_discription("消耗30体力", "骰子数1-3，降低对方50的血量", "骰子数4-6，降低对方75的血量");
    S WuQian("无前", 1, 1, 1, 1, -45, 5, 1, 1, 1, -80, 30);
    WuQian.give_discription("消耗30体力", "骰子数1-4，降低对方45的血量", "骰子数5-6，降低对方80的血量");
    S DuSha("毒杀", 0, 1, 1, 0.75, 0, 4, 0, 1, 1.2, 0, 40);
    DuSha.give_discription("消耗40体力", "降低对方25%血量", "骰子数4-6，增加自身20%的血量");
    S FenCheng("焚城", 0, 1, 1, 1, -50, 6, 0, 1, 1.4, 0, 30);
    FenCheng.give_discription("消耗30体力", "降低对方50血量", "骰子数6，增加自身40%的血量");
    S XiongCan("凶残", 1, 1, 1, 1, -30, 5, 1, 1, 1, -100, 45);
    XiongCan.give_discription("消耗45体力", "骰子数1-4，降低对方30血量", "骰子数5-6，降低对方100血量");
    S TanLan("贪婪", 0, 1, 1, 0.7, 0, 4, 1, 1, 1, -40, 50);
    TanLan.give_discription("消耗50体力", "降低对方30%血量", "骰子数4-6，降低对方40的血量");
    //英雄联盟技能
    S DSSF("大杀四方", 0, 1, 1, 1, -90, 4, 0, 1, 1.15, 0, 45);
    DSSF.give_discription("消耗45体力", "降低对方90血量", "骰子数4-6增加自身15%血");
    S XZFF("旋转飞斧", 1, 0, 3, 1.3, 0, 5, 0, 3, 1.5, 0, 60);
    XZFF.give_discription("消耗60体力", "骰子数1-4 增加自身30%攻击力", "骰子数5-6增加自身50%攻击力");
    S KDLF("开道利斧", 0, 1, 1, 1, -80, 5, 0, 1, 1.25, 0, 50);
    KDLF.give_discription("消耗50体力", "降低对方80血量", "骰子数5-6增加自身25%血");
    S FSBXQ("飞索捕熊器", 1, 1, 1, 0.6, 0, 5, 1, 1, 1.2, 0, 70);
    FSBXQ.give_discription("消耗70体力", "骰子数1-4 降低对方40%血量", "骰子数5-6增加自身20%血");
    S KLCF("克烈冲锋", 1, 1, 5, 1, -10, 5, 1, 5, 1, -15, 25);
    KLCF.give_discription("消耗25体力", "骰子数1-4 降低对方10防御", "骰子数5-6 降低对方15防御");
    S JTZC("解脱之触", 0, 1, 1, 1, -80, 5, 0, 1, 1, 50, 40);
    JTZC.give_discription("消耗40体力", "降低对方80血量", "骰子数5-6增加自身50血");
    S KSYQ("狂食鸦群", 0, 1, 5, 1, -15, 5, 0, 1, 1.25, 0, 40);
    KSYQ.give_discription("消耗40体力", "降低对方15防御", "骰子数5-6增加自身25%血");
    S EMSH("恶魔升华", 1, 0, 1, 1.5, 0, 5, 0, 5, 1.5, 0, 60);
    EMSH.give_discription("消耗60体力", "骰子数1-4 增加自身50%血量", "骰子数5 - 6增加自身50%防御");
    S ZCDJ("致残打击", 0, 1, 5, 0.3, 0, 5, 1, 1, 0.8, 0, 35);
    ZCDJ.give_discription("消耗35体力", "降低对方70%防御", "骰子数5-6降低对手20%血量");
    S EMZY("恶魔之拥", 0, 0, 1, 1.4, 0, 4, 0, 5, 1.4, 0, 50);
    EMZY.give_discription("消耗50体力", "增加自身40%血量", "骰子数4-6增加自身40%防御");
    //西游记技能
    S JGBH("金刚不坏", 1, 0, 1, 1, 120, 4, 0, 5, 1, 30, 50);
    JGBH.give_discription("消耗50体力", "骰子数1-3，增加自身生命120", "骰子数4-6，增加自身防御30");
    S LZGL("灵脂甘露", 0, 0, 1, 1, 180, 4, 0, 5, 1, 25, 50);
    LZGL.give_discription("消耗50体力", "增加自身生命180", "骰子数4-6，增加自身防御25");
    S RLSZ("如来神掌", 1, 1, 1, 1, -250, 5, 1, 1, 1, -400, 80);
    RLSZ.give_discription("消耗80体力", "骰子数1-4，对对方造成伤害250", "骰子数5-6，对对方造成伤害400");
    S HFB("黄风暴", 0, 1, 1, 1, -150, 4, 1, 5, 1, -25, 60);
    HFB.give_discription("消耗60体力", "对对方造成伤害150", "骰子数4-6，降低对方防御25");
    S SMZH("三昧真火", 0, 1, 1, 1, -150, 4, 1, 3, 1, -40, 60);
    SMZH.give_discription("消耗60体力", "对对方造成伤害150", "骰子数4-6，降低对方攻击40");
    S LSXF("灵扇仙风", 0, 1, 1, 1, -140, 4, 1, 7, 1, -80, 40);
    LSXF.give_discription("消耗40体力", "对对方造成伤害140", "骰子数4-6，降低对方法力80");
    S PYTW("喷云吐雾", 1, 1, 3, 1, -50, 4, 1, 7, 1, -80, 40);
    PYTW.give_discription("消耗40体力", "骰子数1-3，降低对方攻击50", "骰子数4-6，降低对方法力80");
    S DTYB("当头一棒", 0, 1, 1, 1, -180, 4, 1, 1, 1, -90, 50);
    DTYB.give_discription("消耗50体力", "对对方造成伤害180", "骰子数4-6，造成额外50%伤害");
    S JYBD("坚毅不倒", 0, 0, 1, 1, 250, 4, 0, 3, 1, -30, 70);
    JYBD.give_discription("消耗70体力", "增加自身生命250", "骰子数4-6，降低自身攻击30");

    ThrKingSkill.push_back(YangWei);
    ThrKingSkill.push_back(YaoWu);
    ThrKingSkill.push_back(ShuangXiong);
    ThrKingSkill.push_back(WuShuang);
    ThrKingSkill.push_back(WuQian);
    ThrKingSkill.push_back(DuSha);
    ThrKingSkill.push_back(FenCheng);
    ThrKingSkill.push_back(XiongCan);
    ThrKingSkill.push_back(TanLan);
    ThrKingSkill_it = ThrKingSkill.begin();//push_back之后一定要让迭代器重置！！！

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
    LOLSkill_it = LOLSkill.begin();//push_back之后一定要让迭代器重置！！！

    JourWestSkill.push_back(JGBH);
    JourWestSkill.push_back(LZGL);
    JourWestSkill.push_back(RLSZ);
    JourWestSkill.push_back(HFB);
    JourWestSkill.push_back(SMZH);
    JourWestSkill.push_back(LSXF);
    JourWestSkill.push_back(PYTW);
    JourWestSkill.push_back(DTYB);
    JourWestSkill.push_back(JYBD);
    JourWestSkill_it = JourWestSkill.begin();//push_back之后一定要让迭代器重置！！！

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
    skill_it = skill.begin();//push_back之后一定要让迭代器重置！！！

    //生成boss名
    //三国boss名
    string HX = "华雄";
    string YLWC = "颜良文丑";
    string LB = "吕布";
    string LR = "李儒";
    string DZ = "董卓";
    //英雄联盟boss名
    string DLES = "德莱厄斯";
    string DLW = "德莱文";
    string BNQS = "暴怒骑士";
    string SWY = "斯维因";
    //西游记boss名
    string JJDW = "金角大王";
    string YJDW = "银角大王";
    string NMW = "牛魔王";
    string HHE = "红孩儿";
    string TSGZ = "铁扇公主";
    string LEMH = "六耳猕猴";

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
    BossName_it = BossName.begin();//push_back之后一定要让迭代器重置！！！

    //录入三国第一关boss
    R r1[3] = { R("r_1",100,50,10),R("华雄",120,35,5),R("颜良文丑",110,30,10) };//第一关
    vector<S> r_1_skill;
    vector<S>::iterator r_1_skill_it = r_1_skill.begin();
    r_1_skill.push_back(YangWei);
    r_1_skill.push_back(YangWei);
    r_1_skill.push_back(YaoWu);
    r_1_skill_it = r_1_skill.begin();//push_back之后一定要让迭代器重置！！！
    vector<S> HX_skill;
    vector<S>::iterator HX_skill_it = HX_skill.begin();
    HX_skill.push_back(YangWei);
    HX_skill.push_back(YangWei);
    HX_skill.push_back(YaoWu);
    HX_skill_it = HX_skill.begin();//push_back之后一定要让迭代器重置！！！
    vector<S> YLWC_skill;
    vector<S>::iterator YLWC_skill_it = YLWC_skill.begin();
    YLWC_skill.push_back(YangWei);
    YLWC_skill.push_back(WuShuang);
    YLWC_skill_it = YLWC_skill.begin();//push_back之后一定要让迭代器重置！！！
    r1[0].give_order("210");//设置出招顺序,别忘了要用双引号！！！
    r1[1].give_order("0102");
    r1[2].give_order("01");
    vector<S> skill_set1[3] = { r_1_skill,HX_skill ,YLWC_skill };

    //录入三国第二关boss
    R r2[3] = { R("r_2",100,50,10),R("吕布",130,50,8),R("李儒",120,45,15) };//第一关
    vector<S> r_2_skill;
    vector<S>::iterator r_2_skill_it = r_2_skill.begin();
    r_2_skill.push_back(YangWei);
    r_2_skill.push_back(YaoWu);
    r_2_skill.push_back(WuQian);
    r_2_skill_it = r_2_skill.begin();//push_back之后一定要让迭代器重置！！！
    vector<S> LB_skill;
    vector<S>::iterator LB_skill_it = LB_skill.begin();
    LB_skill.push_back(WuShuang);
    LB_skill.push_back(WuShuang);
    LB_skill.push_back(WuQian);
    LB_skill_it = LB_skill.begin();//push_back之后一定要让迭代器重置！！！
    vector<S> LR_skill;
    vector<S>::iterator LR_skill_it = LR_skill.begin();
    LR_skill.push_back(DuSha);
    LR_skill.push_back(DuSha);
    LR_skill.push_back(FenCheng);
    LR_skill_it = LR_skill.begin();//push_back之后一定要让迭代器重置！！！
    r2[0].give_order("210");//设置出招顺序,别忘了要用双引号！！！
    r2[1].give_order("0102");
    r2[2].give_order("1002");
    vector<S> skill_set2[3] = { r_2_skill,LB_skill ,LR_skill };

    //录入三国第三关boss
    R r3[2] = { R("r_3",100,50,10),R("董卓",220,45,16) };//第一关
    vector<S> r_3_skill;
    vector<S>::iterator r_3_skill_it = r_3_skill.begin();
    r_3_skill.push_back(YangWei);
    r_3_skill.push_back(XiongCan);
    r_3_skill.push_back(YaoWu);
    r_3_skill_it = r_3_skill.begin();//push_back之后一定要让迭代器重置！！！
    vector<S> DZ_skill;
    vector<S>::iterator DZ_skill_it = DZ_skill.begin();
    DZ_skill.push_back(XiongCan);
    DZ_skill.push_back(XiongCan);
    DZ_skill.push_back(TanLan);
    DZ_skill_it = DZ_skill.begin();//push_back之后一定要让迭代器重置！！！
    r3[0].give_order("210");//设置出招顺序,别忘了要用双引号！！！
    r3[1].give_order("0102");
    vector<S> skill_set3[2] = { r_3_skill,DZ_skill };

    //录入英雄联盟第一关boss
    R r4[2] = { R("r_4",100,50,10),R("德莱厄斯",200,50,15) };//第一关
    vector<S> r_4_skill;
    vector<S>::iterator r_4_skill_it = r_4_skill.begin();
    r_4_skill.push_back(YangWei);
    r_4_skill.push_back(YangWei);
    r_4_skill.push_back(YaoWu);
    r_4_skill_it = r_4_skill.begin();//push_back之后一定要让迭代器重置！！！
    vector<S> DLES_skill;
    vector<S>::iterator DLES_skill_it = DLES_skill.begin();
    DLES_skill.push_back(DSSF);
    DLES_skill.push_back(DSSF);
    DLES_skill.push_back(DSSF);
    DLES_skill_it = DLES_skill.begin();//push_back之后一定要让迭代器重置！！！
    r4[0].give_order("210");//设置出招顺序,别忘了要用双引号！！！
    r4[1].give_order("001");
    vector<S> skill_set4[2] = { r_1_skill,DLES_skill };

    //录入英雄联盟第二关boss
    R r5[3] = { R("r_5",100,50,10),R("德莱文",180,80,10),R("暴怒骑士",200,60,20) };//第一关
    vector<S> r_5_skill;
    vector<S>::iterator r_5_skill_it = r_5_skill.begin();
    r_5_skill.push_back(YangWei);
    r_5_skill.push_back(YangWei);
    r_5_skill.push_back(YaoWu);
    r_5_skill_it = r_5_skill.begin();//push_back之后一定要让迭代器重置！！！
    vector<S> DLW_skill;
    vector<S>::iterator DLW_skill_it = DLW_skill.begin();
    DLW_skill.push_back(XZFF);
    DLW_skill.push_back(XZFF);
    DLW_skill.push_back(XZFF);
    DLW_skill.push_back(KDLF);
    DLW_skill_it = DLW_skill.begin();//push_back之后一定要让迭代器重置！！！
    vector<S> BNQS_skill;
    vector<S>::iterator BNQS_skill_it = BNQS_skill.begin();
    BNQS_skill.push_back(FSBXQ);
    BNQS_skill.push_back(FSBXQ);
    BNQS_skill.push_back(KLCF);
    BNQS_skill.push_back(KLCF);
    BNQS_skill_it = BNQS_skill.begin();//push_back之后一定要让迭代器重置！！！
    r5[0].give_order("210");//设置出招顺序,别忘了要用双引号！！！
    r5[1].give_order("1002");
    r5[2].give_order("0102");
    vector<S> skill_set5[3] = { r_5_skill,DLW_skill ,BNQS_skill };

    //录入英雄联盟第三关boss
    R r6[2] = { R("r_6",100,50,10),R("斯维因",300,70,20) };//第一关
    vector<S> r_6_skill;
    vector<S>::iterator r_6_skill_it = r_6_skill.begin();
    r_6_skill.push_back(YangWei);
    r_6_skill.push_back(YangWei);
    r_6_skill.push_back(YaoWu);
    r_6_skill_it = r_6_skill.begin();//push_back之后一定要让迭代器重置！！！
    vector<S> SWY_skill;
    vector<S>::iterator SWY_skill_it = SWY_skill.begin();
    SWY_skill.push_back(JTZC);
    SWY_skill.push_back(JTZC);
    SWY_skill.push_back(KSYQ);
    SWY_skill.push_back(EMSH);
    SWY_skill_it = SWY_skill.begin();//push_back之后一定要让迭代器重置！！！
    r6[0].give_order("210");//设置出招顺序,别忘了要用双引号！！！
    r6[1].give_order("0123");
    vector<S> skill_set6[2] = { r_6_skill,SWY_skill };

    //录入西游记第一关boss
    R r7[3] = { R("r_7",100,50,10),R("金角大王",300,100,25),R("银角大王",300,130,15) };//第一关
    vector<S> r_7_skill;
    vector<S>::iterator r_7_skill_it = r_7_skill.begin();
    r_7_skill.push_back(YangWei);
    r_7_skill.push_back(YangWei);
    r_7_skill.push_back(YaoWu);
    r_7_skill_it = r_7_skill.begin();//push_back之后一定要让迭代器重置！！！
    vector<S> JJDW_skill;
    vector<S>::iterator JJDW_skill_it = JJDW_skill.begin();
    JJDW_skill.push_back(JGBH);
    JJDW_skill.push_back(JGBH);
    JJDW_skill_it = JJDW_skill.begin();//push_back之后一定要让迭代器重置！！！
    vector<S> YJDW_skill;
    vector<S>::iterator YJDW_skill_it = YJDW_skill.begin();
    YJDW_skill.push_back(PYTW);
    YJDW_skill.push_back(PYTW);
    YJDW_skill_it = YJDW_skill.begin();//push_back之后一定要让迭代器重置！！！
    r7[0].give_order("210");//设置出招顺序,别忘了要用双引号！！！
    r7[1].give_order("01");
    r7[2].give_order("01");
    vector<S> skill_set7[3] = { r_7_skill,JJDW_skill ,YJDW_skill };

    //录入西游记第二关boss
    R r8[4] = { R("r_5",100,50,10),R("牛魔王",350,120,30),R("红孩儿",250,160,10),R("铁扇公主",400,80,50) };//第一关
    vector<S> r_8_skill;
    vector<S>::iterator r_8_skill_it = r_8_skill.begin();
    r_8_skill.push_back(YangWei);
    r_8_skill.push_back(YangWei);
    r_8_skill.push_back(YaoWu);
    r_8_skill_it = r_8_skill.begin();//push_back之后一定要让迭代器重置！！！
    vector<S> NMW_skill;
    vector<S>::iterator NMW_skill_it = NMW_skill.begin();
    NMW_skill.push_back(HFB);
    NMW_skill.push_back(HFB);

    NMW_skill_it = NMW_skill.begin();//push_back之后一定要让迭代器重置！！！
    vector<S> HHE_skill;
    vector<S>::iterator HHE_skill_it = HHE_skill.begin();
    HHE_skill.push_back(SMZH);
    HHE_skill.push_back(SMZH);
    HHE_skill_it = HHE_skill.begin();//push_back之后一定要让迭代器重置！！！
    vector<S> TSGZ_skill;
    vector<S>::iterator TSGZ_skill_it = TSGZ_skill.begin();
    TSGZ_skill.push_back(LSXF);
    TSGZ_skill.push_back(LSXF);
    TSGZ_skill_it = TSGZ_skill.begin();//push_back之后一定要让迭代器重置！！！
    r8[0].give_order("210");//设置出招顺序,别忘了要用双引号！！！
    r8[1].give_order("100");
    r8[2].give_order("100");
    r8[3].give_order("100");
    vector<S> skill_set8[4] = { r_8_skill,NMW_skill ,HHE_skill ,TSGZ_skill };

    //录入西游记第三关boss
    R r9[2] = { R("r_9",100,50,10),R("六耳猕猴",500,160,50) };//第一关
    vector<S> r_9_skill;
    vector<S>::iterator r_9_skill_it = r_9_skill.begin();
    r_9_skill.push_back(YangWei);
    r_9_skill.push_back(YangWei);
    r_9_skill.push_back(YaoWu);
    r_9_skill_it = r_9_skill.begin();//push_back之后一定要让迭代器重置！！！
    vector<S> LEMH_skill;
    vector<S>::iterator LEMH_skill_it = LEMH_skill.begin();
    LEMH_skill.push_back(DTYB);
    LEMH_skill.push_back(DTYB);
    LEMH_skill.push_back(JYBD);
    LEMH_skill_it = LEMH_skill.begin();//push_back之后一定要让迭代器重置！！！
    r9[0].give_order("210");//设置出招顺序,别忘了要用双引号！！！
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
restart://goto 到达的地方，游戏重新开始
    p.reset();
    int choice;
    char ch_choice;
    while (1)
    {
        ifstream in("level.txt");
        in >> level;
        in.close();
        cout << endl << "0.新游戏 1.读档 2.清档 3.退出游戏" << endl;
        cin >> ch_choice;
        choice = dicision(0, 4, ch_choice);
        //创建好角色后开始读档，如果用户选择读档的话
        if (!choice)//新游戏
        {
            delete_save();//自动执行清档操作
            bag.clear();
            skill_bag.clear();
            BossName_bag.clear();
            level = 1;
            //for test 开局随机给玩家一个技能(待定)
            cure(p);
            random_fall_skill(numOfSkill_1, skill_bag, ThrKingSkill_it, ThrKingSkill, p);
            Sleep(2000);
            cout << "这是什么，技能？我在做梦吗？" << endl;
            Sleep(1000);
            break;
        }
        else if (choice == 1)//读档
        {
            if (!level)
            {
                cout << "你没有存档，你可以选择开始新的游戏" << endl;
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
        else if (choice == 2)//清档
        {
            if (!level)
                cout << "你没有存档，无法清档,你可以选择开始新的游戏" << endl;
            else
            {
                delete_save();
                cout << "清档成功" << endl;
            }
        }
        else if (choice == 3)
        {
            cout << "感谢游玩~";
            exit(0);
        }
    }
    //三国第一关
    if (level == 1)
    {
        save_level(level);
        cout << endl << " 随着大脑一阵强烈的眩晕，你缓缓睁开了眼睛，黄昏的光芒刺入你的双眼，你站起来打量四周，发现自己似乎身处一座演武场上，“我……这是在哪，我不是在做梦吧？”" << endl;
        Sleep(3000);
        cout << "你的手上有个发光的骰子，你不禁握紧了它，脑海里突然浮现四个字" << endl;
        Sleep(2000);
        set_color(4, 0);
        cout << "命运之骰" << endl;
        set_color();
        Sleep(2000);
        cout << "“这是什么？”" << endl;
        Sleep(1000);
        cout << "“蹬蹬”的脚步声响起，你循声望去，只见三位将军着装的彪形大汉正站在不远处。你正想开口问些什么，对面一位却抢先一步说道："
            << "“在下华雄，与颜良文丑一同来到此处，我们两在此等待一位天命之人并与之交战，只有打败我们其中之一，你才能继续你的旅程！” " << endl;
        Sleep(5000);
        cout << "“华雄，颜良文丑？这不是三国时期的人么，我怎么会碰到他们？” 你掐了自己一把，却将自己疼的次牙咧嘴。" << endl
            << "“这梦还挺真实的，那我就在梦中与你们好好的会一会！”" << "你豪气顿生，迎了上去。" << endl;
        Sleep(3000);
        cout << "你想和谁交手？" << endl << "0. 华雄   1. 颜良文丑" << endl;//怪物的描述还没写
        //每一关开始时都要重置index
        index = 0;
        int choose;
        char char_choose;
        cin >> char_choose;
        fflush(stdin);
        //排除非法输入
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
            cout << "你赢了，却不知接下来该做什么" << endl << endl;
            Sleep(2000);
            cout << "“小兄弟果然实力强劲，是我输了。对于你为什么来到这，我们也不是很清楚，我只知道与“规则”有关。现在,继续你的旅程吧！”" << endl;
            Sleep(4000);
            cout << "“规则？什么是……”不等你多想，只见演武场中央一团绚丽的流光缓缓凝聚,你手中的";
            set_color(4, 0);
            cout << "命运之骰";
            set_color();
            cout << "挣脱了你的手，在空中急速旋转" << endl;
            Sleep(6000);
            fall_dice = fate_dice();
            Sleep(1000);
            cout << "场地中央那团流光最终凝聚成了一个装备" << endl;
            Sleep(700);
            random_fall(numOfItem_1, bag, ThrKingItem_it, ThrKingItem, p);

            if (fall_dice > 4)
            {
                Sleep(2000);
                random_fall_skill(numOfSkill_1, skill_bag, ThrKingSkill_it, ThrKingSkill, p);
            }
            Sleep(2000);
            cout << "与此同时，你的脑海里出现了一行字" << endl;
            Sleep(2000);
            cout << "每击败一个对手都必将随机掉落一个装备，而当";
            set_color(4, 0);
            cout << "命运之骰";
            set_color();
            cout << "的点数大于4时，你还能随机获得一个技能，但你获得的装备和技能不可以与之前的重复" << endl;
            Sleep(6000);
        }
        BossName_bag.push_back(r1[choose].get_name());
        save_BossName(r1[choose].get_name());
        cure(p);
        show_state(p);
        level++;
        save_level(level);
    }

    //三国第二关
    if (level == 2)
    {
        cout << endl << "“咻”你眼前一花，发现自己来到了一座金碧辉煌的宫殿中。";
        Sleep(2000);
        cout << "左侧是三国第一猛将吕布，右侧是董卓手下谋士李儒。" << endl << "正当你哑口无言时，他们开口了";
        Sleep(2000);
        cout << "“小子！你竟能来到这里，看来本事不小嘛，不过，到此为止了！当然，我们不会以多打少，你挑一个吧！”" << endl;
        Sleep(3000);
        cout << endl << "你想和谁交手？" << endl;
        cout << "0. 吕布   1. 李儒" << endl;//怪物的描述还没写
        //每一关开始时都要重置index
        index = 0;
        int choose;
        char char_choose;
        cin >> char_choose;
        fflush(stdin);
        //排除非法输入
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
            cout << "“你赢了，规则规定我等必须阻止你的前进”吕布和李儒对你说。" << endl;
            Sleep(2000);
            cout << "“规则是什么？”你问道。" << endl;
            Sleep(1000);
            cout << "两人动作划一地摇了摇头“我不知道，我也不知道为何我等”为何会来到这里。但是规则就是这片空间的主宰者，我们也只是按照规则的指示办事。”" << endl;
            Sleep(2000);
            cout << "“就连他们也不知道，看来我得继续下去了”看着他们消失在原地，你心有彷徨地想到" << endl;
            Sleep(2500);
            cout << "你看到宫殿中有一团光华正在缓缓凝聚，命运之骰一跃而起，在空中急速旋转,不知为什么，你是如此期待骰子点数超过4，如此期待能获得一个新技能" << endl;
            Sleep(4000);
            fall_dice = fate_dice();
            Sleep(500);
            if (fall_dice > 4)
            {
                cout << "终于大于4了！" << endl;
            }
            else
            {
                cout << "可惜" << endl;
            }
            Sleep(600);
            cout << "那团光华瞬间变亮" << endl;
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
        cout << "正当你沉浸于刚才的得失时,一位羽扇纶巾却无比邋遢的顽皮老者带着放荡的笑声出现了" << endl;
        Sleep(3000);
        cout << "“年轻人，老夫看你骨骼惊奇，想给你提供一点小小的帮助，如何？”" << endl;
        Sleep(2000);
        cout << "没等你反应过来，他抢先说道：“我给你两个选择：如果你按下0，那么我将提供两个装备，两个技能任你选择其一，但是他们品级一般，而且不能和你已经拥有的重复”" << endl;
        Sleep(4000);
        cout << "如果你按下1，那么我将随机从我的哆啦A梦口袋中随机拿出一个装备，它们的品级有高有低，咦，你手中居然有个命运之骰。这样吧，如果点数大于4，那么你还能随机获得一个技能。这就是我所能提供的所有帮助了！" << endl;
        Sleep(5000);
        show_state(p);
        cout << "你的选择是:" << endl << "0.任我选 1.碰运气" << endl;
        int choose_;
        char char_choose_;
        cin >> char_choose_;
        fflush(stdin);
        choose_ = dicision(0, 2, char_choose_);
        Sleep(500);
        if (choose_ == 1)//若选择了奇遇
        {
            cout << "这老者在他那所谓的“哆啦A梦”的破口袋中倒腾了几下，最终拿出了一个装备" << endl;
            Sleep(1200);
            random_fall(numOfItem_All, bag, item_it, item, p);
            Sleep(2000);
            int di = fate_dice();
            Sleep(500);
            if (di > 4)
            {
                cout << "“运气不错嘛，年轻人，这技能就是你的了！”" << endl;
                Sleep(1000);
                random_fall_skill(numOfSkill_All, skill_bag, skill_it, skill, p);
            }
            else
                cout << "“啧，点数不够，可惜可惜，不过塞翁失马，焉知非福呢？”" << endl;
        }
        else//若选择了商店
        {

            vector<Item> item_choose;
            vector<Item>::iterator item_c_it = item_choose.begin();
            vector<S> skill_choose;
            vector<S>::iterator skill_c_it = skill_choose.begin();
            int di_item_1, di_item_2;
            di_item_1 = hidden_dice(numOfItem_1);//本主题的装备数
            di_item_2 = hidden_dice(numOfItem_1);
            while (di_item_2 == di_item_1)//防止商店的装备出现重复
            {
                di_item_2 = hidden_dice(numOfItem_1);
            }
            int di_skill_1, di_skill_2;
            di_skill_1 = hidden_dice(numOfSkill_1);//本主题的技能数
            di_skill_2 = hidden_dice(numOfSkill_1);
            while (di_skill_2 == di_skill_1)//防止出现重复
            {
                di_skill_2 = hidden_dice(numOfSkill_1);
            }
            item_it = item.begin();
            //将装备和技能“进货",有问题
            item_choose.push_back(*(item_it += di_item_1));
            item_it = item.begin();
            item_choose.push_back(*(item_it += di_item_2));
            skill_it = skill.begin();
            skill_choose.push_back(*(skill_it += di_skill_1));
            skill_it = skill.begin();
            skill_choose.push_back(*(skill_it += di_skill_2));
            item_it = item.begin();
            skill_it = skill.begin();
            //展示“商品”
            int shop_index = 0;
            cout << "“来来来，这是老夫给你准备的，要注意你选的不要和你之前的重复哦”老者带着狡黠的笑意平摊双手，空中浮现四道光芒" << endl;
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
            cout << "做出你的选择吧" << endl;
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
        cout << "你匆忙上前，想问问他这一切究竟是怎么回事，他却挥一挥衣袖，身影淡化在无尽的黄昏之中，冥冥之中传来他那缥缈又神棍的声音";
        cout << "“年轻人，我有预感我们的命运还会再次交汇，你的故事还远未结束！”" << endl;
        cure(p);
        show_state(p);
        level++;
        save_level(level);
    }

    //三国第三关
    if (level == 3)
    {
        cout << "你呆立原地，眼前果然“咻”地一声响起，眼前的雄伟宫殿瞬间变为一座繁华城池。" << endl;
        Sleep(2000);
        cout << "但是这里却只有一道身影，他身长八尺，腰大十围，肌肥肉重，面阔口方手抄飞燕，走及奔马。虽只身一人，带给你的压迫感却比之前遇到的所有对手都要重" << endl;
        Sleep(5000);
        cout << "“我是董卓，去死吧！”他双目圆瞪，没等你发话，就向你直冲过来";
        //每一关开始时都要重置index
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
            cout << "你松了一口气，终于赢了。" << endl;
            Sleep(500);
            cout << "“怎，怎么会？我昔日曾让东汉震荡，而如今却败在你的手里”董卓苦涩的说道" << endl;
            Sleep(2000);
            star(2, 0);
            cout << "董卓的身影消失，取而代之的是一团正在凝聚的光华" << endl;
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

    //英雄联盟第一关
    if (level == 4)
    {
        cout << endl << "你逃过一劫，还获得了装备。你感到踌躇满志,“我要称霸三国！”" << endl;
        Sleep(1500);
        cout << "“咻”地一声，“来吧，我的宏图大业！”你狂热地想到。" << endl;
        Sleep(1500);
        cout << "场景变换，之前预料的三国时期的景象并没有出现，取而代之的是一段似曾相识的峡谷。“这好像那个什么，LOL里的峡谷啊”你心中一惊" << endl;
        Sleep(3000);
        cout << "正当你疑虑之际，对面竟然走来一个英雄联盟的英雄！“德莱厄斯！不会吧，连英雄联盟都来了……”" << endl;
        Sleep(1500);
        cout << "你惊讶的同时若有所思，“原来我刚才所处的三国是个幻象！我差点就以为我是个三国人了，可出了又来到了峡谷，又该如何逃出去？”" << endl;
        Sleep(5000);
        //每一关开始时都要重置index
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
            cout << "你战胜了德莱厄斯，你严肃地对他说：“我怎么会来到这里？你们背后是谁？究竟想干什么？”" << endl;
            Sleep(3000);
            cout << "德莱厄斯抚摸着他心爱的黑切，摇摇头“我也不知道，我只是感到必须在此拦截你，这一切都是规则的安排”" << endl;
            Sleep(2000);

            cout << "他消失在峡谷中央，取而代之的是一团正在凝聚的光华" << endl;
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

    //英雄联盟第二关
    if (level == 5)
    {
        cout << endl << "你看到了地上的小兵们正在从你的身后向前进军，你因为不知去往何处，便选择了跟随" << endl;
        Sleep(1000);
        cout << "行进间，突然有两道身影从路旁的草丛中跳了出来，一个骑在一只丑陋的大蜥蜴上，掏出手枪开火，一个扔出飞斧，将你身旁的小兵统统干掉。正是暴怒骑士与德莱文！" << endl;
        Sleep(3000);
        cout << "“我们不会以多打少，你选一个吧”他们收好手枪和飞斧，伫立于防御塔前" << endl;
        Sleep(2000);
        cout << "你想和谁交手？" << endl << "0. 德莱文   1. 暴怒骑士" << endl;
        //每一关开始时都要重置index
        index = 0;
        int choose;
        char char_choose;
        cin >> char_choose;
        fflush(stdin);
        //排除非法输入
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
            cout << "“好强，还以为是塞恩来了啊”两位战士豪爽地大笑“和你交手真是痛快！”" << endl;
            Sleep(2000);
            cout << "他们化为一道凝聚的光华，命运之骰升上了空中" << endl;
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
        cout << "正当你以为又有新对手出现时，一位头戴巫师帽，手持疾风剑刃的老者驾驭着疾风出现在你的眼前" << endl;
        Sleep(2000);
        cout << "“老夫追随命运的指引而来，我们又再次相遇了，年轻人”原来他正是你之前碰见的无厘头老者，只是不知为何变成了这副摸样" << endl;
        Sleep(3000);
        //让用户点击任意键继续,待做
        cout << "“你的下一个对手空前强大，老夫要助你一臂之力。老规矩，你的选择是？”" << endl;
        show_state(p);
        cout << "0.任我选 1.碰运气" << endl;
        int choose_;
        char char_choose_;
        cin >> char_choose_;
        fflush(stdin);
        choose_ = dicision(0, 2, char_choose_);
        if (choose_ == 1)//若选择了奇遇
        {
            random_fall(numOfItem_All, bag, item_it, item, p);
            Sleep(1000);
            cout << "当命运之骰点数大于4时你将额外获得技能" << endl;
            int di = fate_dice();
            Sleep(500);
            if (di > 4)
            {
                cout << "“啧，你这次运气不错嘛，给”" << endl;
                Sleep(1500);
                random_fall_skill(numOfSkill_All, skill_bag, skill_it, skill, p);
            }
            else
                cout << "呵呵，运气欠佳，但我相信你能走下去，找到逃出这个世界的办法" << endl;
        }
        else//若选择了商店
        {

            vector<Item> item_choose;
            vector<Item>::iterator item_c_it = item_choose.begin();
            vector<S> skill_choose;
            vector<S>::iterator skill_c_it = skill_choose.begin();
            int di_item_1, di_item_2;
            di_item_1 = hidden_dice(numOfItem_2);//本主题的装备数
            di_item_2 = hidden_dice(numOfItem_2);
            while (di_item_2 == di_item_1)//防止商店的装备出现重复
            {
                di_item_2 = hidden_dice(numOfItem_2);
            }
            int di_skill_1, di_skill_2;
            di_skill_1 = hidden_dice(numOfSkill_2);//本主题的技能数
            di_skill_2 = hidden_dice(numOfSkill_2);
            while (di_skill_2 == di_skill_1)//防止出现重复
            {
                di_skill_2 = hidden_dice(numOfSkill_2);
            }

            //将装备和技能“进货",有问题
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
            //展示“商品”
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
            cout << "做出你的选择" << endl;
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

    //英雄联盟第三关
    if (level == 6)
    {
        cout << endl << "你被传送到了灌木丛生的野区，一位充满森然之气的的身影在那里等你" << endl;
        Sleep(2000);
        cout << "他便是诺克萨斯统领——斯维因！" << endl;
        Sleep(1500);
        cout << "他用鄙夷的目光看着你，举起了那只恶魔之手" << endl;
        Sleep(1500);
        //每一关开始时都要重置index
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
            cout << "“这，怎么可能！”他不可思议地看着你，叹了口气，“看来我的实力还不足以统领诺克萨斯”" << endl;
            Sleep(3000);
            cout << "他的恶魔之手中有一团光华凝聚" << endl;
            Sleep(1000);
            fall_dice = fate_dice();
            random_fall(numOfItem_2, bag, LOLItem_it, LOLItem, p);
            Sleep(1000);
            if (fall_dice > 4)
            {
                random_fall_skill(numOfSkill_2, skill_bag, LOLSkill_it, LOLSkill, p);
                Sleep(1000);
            }
            cout << "“你走吧，你想要的最终答案还在前方”他的身影和他的声音一同变淡，最终消失" << endl;
            Sleep(1000);
        }

        BossName_bag.push_back(r6[1].get_name());
        save_BossName(r6[1].get_name());
        cure(p);
        show_state(p);
        level++;
        save_level(level);
    }

    //西游记第一关
    if (level == 7)
    {

        cout << endl << "光芒闪过，你发现你身处于一座宫殿之中，彤壁朱扉，重檐丹楹，甚是庄严，四周到处弥漫着药香。这莫非是西游记中的兜率宫？" << endl;
        Sleep(3000);
        cout << "只见一个长着金角和一个长着银角的人从宫殿中走出。一个身材高大魁梧，一个则稍小一些，手里捣晃着一个小药瓶。" << endl
            << "正是金角大王和银角大王" << endl;
        Sleep(2000);
        cout << "“虽然我们很想一起上，但规则告诉我们只能单挑，你选一个吧”" << endl;
        Sleep(1500);
        cout << "你选择和谁交手？" << endl << "0.金角大王 1.银角大王" << endl;
        //每一关开始时都要重置index
        index = 0;
        int choose;
        char char_choose;
        cin >> char_choose;
        fflush(stdin);
        //排除非法输入
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
            cout << "“好吧你赢了，这是你的装备。”金角大王伸出手臂，光华在其手中凝聚" << endl;
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
        cout << "他们先是用不甘的眼神望着你，接着又得意地笑道：“虽然你赢了，但你在西游记的世界里走不了多远。哈哈哈”两人在大笑中消失,只留下了你在溢满药香味的宫殿中矗立" << endl;
        Sleep(1500);
        BossName_bag.push_back(r7[choose].get_name());
        save_BossName(r7[choose].get_name());
        cure(p);
        show_state(p);
        level++;
        save_level(level);
    }

    //西游记第二关
    if (level == 8)
    {
        cout << endl << "光芒一闪，你突然被空气中的硝烟呛到了，你定睛一看，正是一片燃烧着火焰的赤红山脉" << endl;
        Sleep(2000);
        cout << "“欢迎来到我们火焰山作客”铁扇公主用甜蜜而充满敌意的语气说道，她身旁正是牛魔王和红孩儿" << endl;
        Sleep(1500);
        cout << "“你希望谁来招待你呢？”红孩儿狡黠地笑道，手轻轻擦着火焰缭绕的红缨枪，感觉跃跃欲试" << endl;
        cout << "牛魔王看起来就威武霸气，而早就听闻铁扇公主手中的芭蕉扇有缚法之力，到底该打谁呢？" << endl;
        Sleep(1000);
        cout << "0. 牛魔王   1. 红孩儿   2. 铁扇公主" << endl;//怪物的描述还没写
        //每一关开始时都要重置index
        index = 0;
        int choose;
        char char_choose;
        cin >> char_choose;
        fflush(stdin);
        //排除非法输入
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
            cout << "“很久没有见过这么痛快淋漓的战斗了”牛魔王意犹未尽地说道“可惜我们得走了，祝你一路顺风！”" << endl;
            Sleep(500);
            star(2, 0);
            cout << "光华在他手中凝聚" << endl;
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
        cout << "“俺老孙来也！”一个形似孙悟空的人用苍老的声音说道，“咳咳，我发不了这么高的声音”正是那位老者" << endl;
        Sleep(2000);
        cout << "“你的前方应该就是最后一程了，让俺老孙助你一臂之力，老规矩，你自己选吧！”老者竭力地模仿着六小龄童的声音" << endl;
        Sleep(2000);
        //让用户点击任意键继续,待做
        show_state(p);
        cout << "你的选择是:" << endl << "0.任我选 1.碰运气" << endl;
        int choose_;
        char char_choose_;
        cin >> char_choose_;
        fflush(stdin);
        choose_ = dicision(0, 2, char_choose_);
        if (choose_ == 1)//若选择了奇遇
        {
            random_fall(numOfItem_All, bag, item_it, item, p);
            Sleep(1000);
            int di = fate_dice();
            Sleep(500);
            if (di > 4)
            {
                cout << "你运气不错，希望我的东西能助你找到这个世界的答案！" << endl;
                random_fall_skill(numOfSkill_All, skill_bag, skill_it, skill, p);
                Sleep(1000);
            }
            else
            {
                cout << "别担心，你的实力已今非昔比，老夫相信你能通关，啊不，找到这个世界的答案！" << endl;
                Sleep(1000);
            }
        }
        else//若选择了商店
        {

            vector<Item> item_choose;
            vector<Item>::iterator item_c_it = item_choose.begin();
            vector<S> skill_choose;
            vector<S>::iterator skill_c_it = skill_choose.begin();
            int di_item_1, di_item_2;
            di_item_1 = hidden_dice(numOfItem_3);//本主题的装备数
            di_item_2 = hidden_dice(numOfItem_3);
            while (di_item_2 == di_item_1)//防止商店的装备出现重复
            {
                di_item_2 = hidden_dice(numOfItem_3);
            }
            int di_skill_1, di_skill_2;
            di_skill_1 = hidden_dice(numOfSkill_3);//本主题的技能数
            di_skill_2 = hidden_dice(numOfSkill_3);
            while (di_skill_2 == di_skill_1)//防止出现重复
            {
                di_skill_2 = hidden_dice(numOfSkill_3);
            }
            item_it = item.begin();
            //将装备和技能“进货",有问题
            item_choose.push_back(*(item_it += di_item_1 + numOfItem_1 + numOfItem_2));
            item_it = item.begin();
            item_choose.push_back(*(item_it += di_item_2 + numOfItem_1 + numOfItem_2));
            skill_it = skill.begin();
            skill_choose.push_back(*(skill_it += di_skill_1 + numOfSkill_1 + numOfSkill_2));
            skill_it = skill.begin();
            skill_choose.push_back(*(skill_it += di_skill_2 + numOfSkill_1 + numOfSkill_2));
            item_it = item.begin();
            skill_it = skill.begin();
            //展示“商品”
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
            cout << "做出你的选择" << endl;
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
        cout << "“听说前面有个冒牌俺老孙的家伙，帮我打败它，洗清我的名声！”老者抓耳挠腮地说" << endl;
        Sleep(1000);
    }

    //西游记第三关
    if (level == 9)
    {
        cout << endl << "光芒又闪，你来到了水帘洞，一道看起来和电视剧上的孙悟空一模一样的身影出现在你眼前" << endl;
        Sleep(2000);
        cout << "“你便是六耳猕猴吧”你试探地问道" << endl;
        Sleep(1500);
        cout << "“没错，正是本猴！”对方从耳中掏出金箍棒，无所顾忌地说,“只要你赢了我，这个世界的秘密就将向你敞开！”" << endl;
        //每一关开始时都要重置index
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
            cout << "六耳猕猴消失了，一行字出现在在你的脑海" << endl;
            Sleep(1500);
        }
        cout << "恭喜你通关了!" << endl;
        Sleep(1000);
        cout << "“其实你刚刚误入了错位时空，有多个时空纠缠于此，这正是你经历多个时空的原因。我是一名程序员，致力于帮助每一个迷失者的走出这里。我通过设置这些来引导玩家发现这个时空的奥秘，防止其迷失在这错位时空，现在你可以走了！”" << endl;
        Sleep(6000);
        cout << endl;
        star(0xF, 0);
        cout << endl;
        set_color(2, 0);
        cout << "结算界面" << endl;
        BossName_bag.push_back(r9[1].get_name());
        save_BossName(r9[1].get_name());
        show_BossName(BossName_bag_it, BossName_bag);
        Sleep(2000);
        show_item(bag_it, bag);
        Sleep(2000);
        show_skill(skill_bag_it, skill_bag);
        Sleep(4000);
        cout << "光芒一闪，你终于回到了现实世界(完)";
    }
    delete_save();
    return 0;
}