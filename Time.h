#ifndef TIME_H
#define TIME_H
/**
    类名：时间类（Time）
    作者：thbin
    创建日期：2016-3-4
    修改日期：2016-3-4
    基本功能：表示时间数据类型，有时、分、秒组成，并包括各类与时间相关的操作
    版本变化：
        v0.1 包括基本数据成员、构造函数、析构函数、访问函数等基本功能
*/
class Time
{
    public:
        /*构造函数*/
        Time(); //缺省构造函数
        Time(int hr, int min, int sec);//三参数构造函数
        /*访问函数*/
        int getHour();  //获得小时信息
        int getMinute();//获得分钟信息
        int getSecond();//获得秒信息
        void setTime(int hr, int min, int sec);//同时设置时、分、秒信息
        void setHour(int hr);   //仅设置小时信息
        void setMinute(int min);//仅设置分钟信息
        void setSecond(int sec);//仅设置秒信息
        /*功能函数*/
        void printUniversal();//打印时间信息，格式：HH:MM:SS
        void printStandard();//打印时间信息，格式：HH:MM:SS AM or PM
    protected:
    private:
        int hour;   //小时
        int minute; //分钟
        int second; //秒
};

#endif // TIME_H
