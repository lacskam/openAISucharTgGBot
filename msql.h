#ifndef MSQL_H
#define MSQL_H
#include<QtSql>
#include<iostream>
#include<QSqlDatabase>
#include<QSqlQuery>


class DB {
    private:
        QSqlDatabase db;
        QString str=" ";
    public:
        void resetRq();
        void insert(const qlonglong *id, const QString *username);            //добавление пользователя в бд
        int chekStat(const qlonglong *id);                                    //проверка статуса пользователя 1-обычный 2-расширенный 3-блатной 0-лох
        void changeNeiro(const qlonglong *id, const QString neiro);           //смена нейронки
        int checkNeiro(const qlonglong *id);                                  //проверка выбранной нейронки
        bool chekAv(const qlonglong *id);                                     //проверка авторизации пользователя в бд
        int numOfReq(const qlonglong *id);                                    //проверка количества оставшихся запросов пользователя
        void reqDecriment(const qlonglong *id);                               //декримент запросов
        void addLimReq(const QString *id);                                    //
        void uvedSwap(const qlonglong *id,int m);
        int getLimReq(const qlonglong *id);
        //admin
        QString usersinfo();

        //context and role
        QString checkCOntext(const qlonglong *id);
        void clearContext(const qlonglong *id);
        void addcontext(const qlonglong *id,const QString *messageuser,const QString *messagebot);                 //добавление сообщений в бд для учета контекста
        bool isContext(const qlonglong *id);
        void changeCont(const qlonglong *id,bool stat);


        DB();
        ~DB();

};


#endif // MSQL_H
