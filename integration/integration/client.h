#ifndef CLIENT_H
#define CLIENT_H

#include "connection.h"
#include <QString>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlQueryModel>
#include <QDate> // Include QDate for date management

class client
{
private:
    int ID_CLIENT;
    QString NOM_CL;
    QString PRENOM_CL;
    int TEL_CL;
    QString ADRESSE_CL;
    QString GENDER;
    QString NATIONALITY;
    QString EMAIL;
    QDate DATE_RESERVATION; // New attribute for reservation date
    int POINTS_FID;         // New attribute for loyalty points

public:
    client();
    client(int ID_CLIENT, QString NOM_CL, QString PRENOM_CL, int TEL_CL, QString ADRESSE_CL, QString GENDER, QString NATIONALITY, QString EMAIL, QDate DATE_RESERVATION, int POINTS_FID)
    {
        this->ID_CLIENT = ID_CLIENT;
        this->NOM_CL = NOM_CL;
        this->PRENOM_CL = PRENOM_CL;
        this->TEL_CL = TEL_CL;
        this->ADRESSE_CL = ADRESSE_CL;
        this->GENDER = GENDER;
        this->NATIONALITY = NATIONALITY;
        this->EMAIL = EMAIL;
        this->DATE_RESERVATION = DATE_RESERVATION;
        this->POINTS_FID = POINTS_FID;
    }

    // Setters
    void setID_CLIENT(int id_client) { ID_CLIENT = id_client; }
    void setNom(QString nom) { NOM_CL = nom; }
    void setPrenom(QString prenom) { PRENOM_CL = prenom; }
    void setTel(int tel) { TEL_CL = tel; }
    void setAdresse(QString adresse) { ADRESSE_CL = adresse; }
    void setGender(QString gender) { GENDER = gender; }
    void setNationality(QString nationality) { NATIONALITY = nationality; }
    void setEmail(QString email) { EMAIL = email; }
    void setDateReservation(QDate date) { DATE_RESERVATION = date; } // Setter for DATE_RESERVATION
    void setPointsFid(int points) { POINTS_FID = points; }           // Setter for POINTS_FID

    // Getters
    int getID_CLIENT() { return ID_CLIENT; }
    QString getNom() { return NOM_CL; }
    QString getPrenom() { return PRENOM_CL; }
    int getTel() { return TEL_CL; }
    QString getAdresse() { return ADRESSE_CL; }
    QString getGender() { return GENDER; }
    QString getNationality() { return NATIONALITY; }
    QString getEmail() { return EMAIL; }
    QDate getDateReservation() { return DATE_RESERVATION; }         // Getter for DATE_RESERVATION
    int getPointsFid() { return POINTS_FID; }                       // Getter for POINTS_FID

    bool Ajouterclient();
    QSqlQueryModel* Afficherclients();
    bool Modifierclient();
    bool Supprimerclients();
    QSqlQueryModel *Rechercherclient(const QString &text);

};

#endif // CLIENT_H
