#include "find_angle.h"
#include<QDebug>
#include<QSqlDatabase>
#include<QSqlDriver>

#include<ostream>
#include<iostream>
#include<QFile>
#include<QTime>
#include <stdio.h>
#include <QTextStream>
#include<QSqlQueryModel>

Find_Angle::Find_Angle(QObject *parent) : QObject(parent)
{

}




bool Find_Angle::Server()
{


    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC3");
    db.setDatabaseName("DRIVER={SQL Server};Server=192.168.0.251\\SQLEXPRESS,50087;Database=gpslogd;Uid=UretimTakip;Pwd=dtsis_sql1;WSID=.");
if(db.open())
{

    QSqlQueryModel *model = new QSqlQueryModel;
    QString query = "select * from states";
    model->setQuery(query, db);
    qDebug()<<  model->record(2).value(0).toString();
    qDebug()<<  model->record(2).value(1).toString();
    qDebug()<<  model->record(2).value(2).toString();
    qDebug()<<  model->record(2).value(3).toString();
    qDebug()<<  model->record(2).value(4).toString();
    qDebug()<<  model->record(2).value(5).toString();
    qDebug()<<  model->record(2).value(6).toString();
    qDebug()<<  model->record(2).value(7).toString();
    qDebug()<<  model->record(2).value(8).toString();
    qDebug()<<  model->record(2).value(9).toString();
    qDebug()<<  model->record(2).value(10).toString();
    qDebug()<<  model->record(2).value(11).toString();
    qDebug()<<  model->record(2).value(12).toString();

}
else
{
    qDebug()<<"not succes ";
}


}


void Find_Angle::Take_Path(QString path)
{

    line_list.clear();
     line_size=0;
    path=path.mid(8);

    Server();


    if(Line_Db_Open(path))
    {
        if(Find_Line())
        {
            for(int i=0;i<line_size;i++)
            {
                send_Line(line_list[i]);
            }
        }
    }

}

void Find_Angle::Take_Line(QString line_str )
{

    double lati;
    double longi;
    latitudeList.clear();
    longitudeList.clear();
    stop_id_list.clear();
    stop_id_size=0;


    qDebug()<<line_str;

    if(Find_Stop_id(line_str))
    {
        for(int i=0;i<stop_id_size;i++)
        {
            if(Find_Coordinate(stop_id_list[i]))
            {

            }
        }
        if(longitudeList.size()==stop_id_size & latitudeList.size()==stop_id_size)
            for(int j=0;j<stop_id_size;j++)
            {



                send_Coordinate(latitudeList[j],longitudeList[j]);
            }
        route_update();

    }
}



bool Find_Angle::Line_Db_Open(QString s)
{
    Line_Db=QSqlDatabase::addDatabase("QSQLITE", "SQLITE");
    Line_Db.setDatabaseName(s);
    if(Line_Db.open())
    {


        qDebug()<<"db open";
        return true;
    }
    else
    {
        // ui->information_text->append("Line Db not Open ");
        qDebug()<<"db not  open";

    }

}
bool Find_Angle::Find_Line()
{
    line_list.clear();
    QSqlQuery qry(Line_Db);
    if(qry.prepare("select line_id from lines  order by line_id asc; "))
    {
        if(qry.exec())
        {
            int idName = qry.record().indexOf("line_id");
            while (qry.next())
            {
                line_list << qry.value(idName).toString();

            }
            qry.last();
            line_size = qry.at() + 1;
            if(line_size>0)
            {

                return true;

            }
            else
            {
                return false;
            }
        }
    }
}



bool Find_Angle::Find_Stop_id(QString line_id)
{

    stop_id_list.clear();
    QSqlQuery qry(Line_Db);
    stop_id_size=0;
    if(qry.prepare("select stop_id from line_stops where line_id=  ' " + line_id+  " '  order by position asc;  "))
    {
        if(qry.exec())
        {
            int idName = qry.record().indexOf("stop_id");
            while (qry.next())
            {
                stop_id_list<< qry.value(idName).toString();

            }
            qry.last();
            stop_id_size= qry.at() + 1;
            if(stop_id_size>0)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
}


bool Find_Angle::Find_Coordinate(QString stop_id)
{
    QSqlQuery qry2(Line_Db);
    QString lat_min_str;
    QString long_min_str;
    if(qry2.prepare("select stop_id, lat_deg,lat_min,long_deg,long_min from stops where stop_id=  ' " + stop_id+  " '  "))
    {
        if(qry2.exec())
        {
            int idName6=qry2.record().indexOf("stop_id");
            int idName50=qry2.record().indexOf("lat_deg");
            int idName51=qry2.record().indexOf("lat_min");
            int idName52=qry2.record().indexOf("long_deg");
            int idName53=qry2.record().indexOf("long_min");

            while(qry2.next())
            {
                bool ok;
                stop_id=qry2.value(idName6).toString();
                long long int lat_deg=qry2.value(idName50).toInt(&ok);
                long long int lat_min=qry2.value(idName51).toInt(&ok);
                long int long_deg=qry2.value(idName52).toInt(&ok);
                long long int long_min=qry2.value(idName53).toInt(&ok);

                lat_min_str=QString::number(lat_min);
                 long_min_str=QString::number(long_min);
                 int lat_size=6-lat_min_str.size();
                 int log_size=6-long_min_str.size();

                 for(int i =0 ;i<lat_size;i++)
                 {
                     lat_min_str ="0"+lat_min_str;
                 }


                 for(int i =0 ;i<log_size;i++)
                 {
                     long_min_str ="0"+long_min_str;
                 }

                latitudeList << QString::number(lat_deg)+"."+lat_min_str;
                longitudeList << QString::number(long_deg)+"."+long_min_str;
            }

        }
    }
    else
    {
        qDebug()<< "undefined for  stop  " +stop_id+ " in stop tables ";
        return false;

    }
}
