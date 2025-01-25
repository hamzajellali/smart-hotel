#include "client.h"
#include <QDebug>
#include <QSqlError>

client::client() {}

// Add `DATE_RESERVATION` and `POINTS_FID` to the INSERT query
bool client::Ajouterclient()
{
    QSqlQuery query;

    query.prepare("INSERT INTO client (NOM_CL, PRENOM_CL, TEL_CL, ADRESSE_CL, GENDER, NATIONALITY, EMAIL, DATE_RESERVATION) "
                  "VALUES (:NOM_CL, :PRENOM_CL, :TEL_CL, :ADRESSE_CL, :GENDER, :NATIONALITY, :EMAIL, :DATE_RESERVATION)");

    query.bindValue(":NOM_CL", NOM_CL);
    query.bindValue(":PRENOM_CL", PRENOM_CL);
    query.bindValue(":TEL_CL", TEL_CL);
    query.bindValue(":ADRESSE_CL", ADRESSE_CL);
    query.bindValue(":GENDER", GENDER);
    query.bindValue(":NATIONALITY", NATIONALITY);
    query.bindValue(":EMAIL", EMAIL);
    query.bindValue(":DATE_RESERVATION", DATE_RESERVATION);

    return query.exec();
}

// Add `DATE_RESERVATION` and `POINTS_FID` to the SELECT query
QSqlQueryModel *client::Afficherclients()
{
    QSqlQueryModel *modal = new QSqlQueryModel();

    modal->setQuery("SELECT ID_CLIENT, NOM_CL, PRENOM_CL, TEL_CL, ADRESSE_CL, GENDER, NATIONALITY, EMAIL, DATE_RESERVATION, POINTS_FID "
                    "FROM client");

    modal->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_CLIENT"));
    modal->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_CL"));
    modal->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM_CL"));
    modal->setHeaderData(3, Qt::Horizontal, QObject::tr("TEL_CL"));
    modal->setHeaderData(4, Qt::Horizontal, QObject::tr("ADRESSE_CL"));
    modal->setHeaderData(5, Qt::Horizontal, QObject::tr("GENDER"));
    modal->setHeaderData(6, Qt::Horizontal, QObject::tr("NATIONALITY"));
    modal->setHeaderData(7, Qt::Horizontal, QObject::tr("EMAIL"));
    modal->setHeaderData(8, Qt::Horizontal, QObject::tr("DATE_RESERVATION"));
    modal->setHeaderData(9, Qt::Horizontal, QObject::tr("POINTS_FID"));

    return modal;
}

// Add `DATE_RESERVATION` and `POINTS_FID` to the UPDATE query
bool client::Modifierclient()
{
    QSqlQuery query;

    if (!query.prepare("UPDATE client SET NOM_CL = :NOM_CL, PRENOM_CL = :PRENOM_CL, TEL_CL = :TEL_CL, ADRESSE_CL = :ADRESSE_CL, GENDER = :GENDER, "
                       "NATIONALITY = :NATIONALITY, EMAIL = :EMAIL, DATE_RESERVATION = :DATE_RESERVATION "
                       "WHERE ID_CLIENT = :ID_CLIENT")) {
        qDebug() << "Prepare failed:" << query.lastError();
        return false;
    }

    query.bindValue(":NOM_CL", NOM_CL);
    query.bindValue(":PRENOM_CL", PRENOM_CL);
    query.bindValue(":TEL_CL", TEL_CL);
    query.bindValue(":ADRESSE_CL", ADRESSE_CL);
    query.bindValue(":GENDER", GENDER);
    query.bindValue(":NATIONALITY", NATIONALITY);
    query.bindValue(":EMAIL", EMAIL);
    query.bindValue(":DATE_RESERVATION", DATE_RESERVATION);
    query.bindValue(":ID_CLIENT", ID_CLIENT);

    if (!query.exec()) {
        qDebug() << "Exec failed:" << query.lastError();
        return false;
    }

    return true;
}
bool client::Supprimerclients()
{
    QSqlQuery query;

    query.prepare("DELETE FROM CLIENT WHERE ID_CLIENT = :ID_CLIENT");
    query.bindValue(":ID_CLIENT", ID_CLIENT);

    return query.exec();
}

// Add `DATE_RESERVATION` and `POINTS_FID` to the search functionality
QSqlQueryModel *client::Rechercherclient(const QString &text)
{
    QSqlQueryModel *modal = new QSqlQueryModel();

    QString queryStr = QString("SELECT ID_CLIENT, NOM_CL, PRENOM_CL, TEL_CL, ADRESSE_CL, GENDER, NATIONALITY, EMAIL, DATE_RESERVATION, POINTS_FID "
                               "FROM client WHERE ID_CLIENT LIKE '%%1%' OR NOM_CL LIKE '%%1%' OR PRENOM_CL LIKE '%%1%' OR TEL_CL LIKE '%%1%' OR ADRESSE_CL LIKE '%%1%' "
                               "OR GENDER LIKE '%%1%' OR NATIONALITY LIKE '%%1%' OR EMAIL LIKE '%%1%' OR DATE_RESERVATION LIKE '%%1%' OR POINTS_FID LIKE '%%1%'")
                           .arg(text);

    modal->setQuery(queryStr);

    modal->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_CLIENT"));
    modal->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_CL"));
    modal->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM_CL"));
    modal->setHeaderData(3, Qt::Horizontal, QObject::tr("TEL_CL"));
    modal->setHeaderData(4, Qt::Horizontal, QObject::tr("ADRESSE_CL"));
    modal->setHeaderData(5, Qt::Horizontal, QObject::tr("GENDER"));
    modal->setHeaderData(6, Qt::Horizontal, QObject::tr("NATIONALITY"));
    modal->setHeaderData(7, Qt::Horizontal, QObject::tr("EMAIL"));
    modal->setHeaderData(8, Qt::Horizontal, QObject::tr("DATE_RESERVATION"));
    modal->setHeaderData(9, Qt::Horizontal, QObject::tr("POINTS_FID"));

    return modal;
}
