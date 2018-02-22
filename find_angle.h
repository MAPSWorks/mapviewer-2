#ifndef FIND_ANGLE_H
#define FIND_ANGLE_H

#include <QObject>
#include<QUrl>
#include <QtSql>
class Find_Angle : public QObject
{
    Q_OBJECT
public:
    explicit Find_Angle(QObject *parent = 0);

    QString Line_filePath;
    QSqlDatabase Line_Db;
    QSqlDatabase serverdb;
    QStringList line_list;
    int line_size;
    QStringList    stop_id_list;
    int stop_id_size;
    QStringList latitudeList;
    QStringList longitudeList;

    bool Select_LineDb_State=false;
    bool Line_Db_Open(QString s);
    bool Find_Line();
    bool Find_Stop_id(QString line_id);
    bool Find_Coordinate(QString stop_id);

    bool  Server();

signals:
    void send_Line(QString line );
    void send_Coordinate(QString lati,QString longi);
    void route_update();

public slots:
    void Take_Path(QString path);
    void Take_Line(QString line_str);
};

#endif // FIND_ANGLE_H


