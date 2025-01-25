#include "employee.h"
#include <QSqlQuery>
#include<qDebug>
#include<QSqlError>
#include <QRegularExpression>

employee::employee(int id, QString nom, QString prenom, QString mail, QString dateembauche, QString certificats, QString diplomes,QString salaire, QString assurance) {
    this->id = id;
    this->nom = nom;
    this->prenom = prenom;
    this->mail = mail;
    this->dateembauche = dateembauche;
    this->certificats = certificats;
    this->diplomes = diplomes;
    this->salaire = salaire;
    this->assurance = assurance;
}


/*bool employee::Modifieremployee()
{
    QSqlQuery query;

    if (!query.prepare("UPDATE TABLE4 SET NOM = :NOM, PRENOM = :PRENOM, MAIL = :MAIL, DATEEMBAUCHE = :DATEEMBAUCHE, CERTIFICATS = :CERTIFICATS, SALAIRE = :SALAIRE, ASSURANCE = :ASSURANCE,DIPLOMES = :DIPLOMES")) {
        qDebug() << "Prepare failed:" << query.lastError();
        return false;
    }


    query.bindValue(":NOM", nom);
    query.bindValue(":PRENOM", prenom);
    query.bindValue(":MAIL", mail);
    query.bindValue(":DATEEMBAUCHE", dateembauche);
    query.bindValue(":CERTIFICATS", certificats);
    query.bindValue(":SALAIRE",salaire);
    query.bindValue(":ASSURANCE", assurance);
    query.bindValue(":DIPLOMES", diplomes);

    if (!query.exec()) {
        qDebug() << "Exec failed:" << query.lastError();
        return false;
    }

    return true;
}

*/
bool employee::supprimer(int id){

    QSqlQuery query;
    QString res=QString::number(id);

    query.prepare("Delete from TABLE4 where id= :id");

    query.bindValue(":id",res);

    return query.exec();
}


int employee::getNextId() {
    QSqlQuery query;
    query.exec("SELECT MAX(ID) FROM TABLE4");
    if (query.next()) {
        return query.value(0).toInt() + 1; // Return next ID
    }
    return 1; // Start at 1 if the table is empty
}


bool employee::ajouter() {
    id = getNextId();  // Récupère l'ID suivant

    // Vérification que le champ mail contient bien un '@'
    QRegularExpression emailRegex(".+@.+\\..+");  // Regex basique pour valider un e-mail
    if (!emailRegex.match(mail).hasMatch()) {
        qDebug() << "Erreur : l'adresse e-mail n'est pas valide, elle doit contenir '@' et un domaine valide.";
        return false;
    }

    QSqlQuery query;
    query.prepare("INSERT INTO TABLE4 (ID, NOM, PRENOM, MAIL, DATEEMBAUCHE, CERTIFICATS, SALAIRE, ASSURANCE, DIPLOMES) "
                  "VALUES (:ID, :NOM, :PRENOM, :MAIL, :DATEEMBAUCHE, :CERTIFICATS, :SALAIRE, :ASSURANCE, :DIPLOMES)");

    query.bindValue(":ID", id);  // Ajout de l'ID récupéré
    query.bindValue(":NOM", nom);
    query.bindValue(":PRENOM", prenom);
    query.bindValue(":MAIL", mail);
    query.bindValue(":DATEEMBAUCHE", dateembauche);
    query.bindValue(":CERTIFICATS", certificats);
    query.bindValue(":SALAIRE", salaire);
    query.bindValue(":ASSURANCE", assurance);
    query.bindValue(":DIPLOMES", diplomes);

    if (!query.exec()) {
        qDebug() << "Erreur d'insertion : " << query.lastError().text();
        return false;  // Retourner false si l'insertion échoue
    }

    return true;
}

QSqlQueryModel * employee::afficher(){
    QSqlQueryModel * model=new  QSqlQueryModel();
    model->setQuery("select * from TABLE4");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("email"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("date embauche"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("certificats"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("salaire"));
    model->setHeaderData(7,Qt::Horizontal,QObject::tr("assurance"));
    model->setHeaderData(8,Qt::Horizontal,QObject::tr("diplomes"));
    return model;
}

QSqlQueryModel * employee::afficher2() {
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM TABLE4 ORDER BY ID ASC");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Email"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Date d'embauche"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Certificats"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Diplômes"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("Salaire"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("Assurance"));
    return model;
}



QSqlQueryModel* employee::rechercherParNom(const QString &nomRecherche) {
    QSqlQueryModel* model = new QSqlQueryModel();
    QSqlQuery query;

    query.prepare("SELECT * FROM TABLE4 WHERE NOM LIKE :nom");
    query.bindValue(":nom", "%" + nomRecherche + "%");

    if (!query.exec()) {
        qDebug() << "Erreur lors de la recherche : " << query.lastError().text();
        return nullptr;
    }

    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Email"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Date d'embauche"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Certificats"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Diplômes"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("Salaire"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("Assurance"));

    return model;
}





QSqlQueryModel* employee::RechercherEmploye(const QString &text)
{
    QSqlQueryModel *modal = new QSqlQueryModel();

    // Requête SQL pour rechercher un employé avec le critère spécifié
    QString queryStr = QString("SELECT  NOM, PRENOM, MAIL, DATEEMBAUCHE, CERTIFICATS, SALAIRE, ASSURANCE, DIPLOMES "
                               "FROM TABLE4 WHERE  NOM LIKE '%%1%' OR PRENOM LIKE '%%1%' OR MAIL LIKE '%%1%' OR DATEEMBAUCHE LIKE '%%1%' OR CERTIFICATS LIKE '%%1%' OR SALAIRE LIKE '%%1%' OR ASSURANCE LIKE '%%1%' OR DIPLOMES LIKE '%%1%'")
                           .arg(text);  // Utilisation de LIKE pour une recherche partielle

    // Exécution de la requête
    modal->setQuery(queryStr);

    // Définition des en-têtes pour chaque colonne

    modal->setHeaderData(0, Qt::Horizontal, QObject::tr("Nom"));
    modal->setHeaderData(1, Qt::Horizontal, QObject::tr("Prénom"));
    modal->setHeaderData(2, Qt::Horizontal, QObject::tr("Email"));
    modal->setHeaderData(3, Qt::Horizontal, QObject::tr("Date d'Embauche"));
    modal->setHeaderData(4, Qt::Horizontal, QObject::tr("Certificats"));
    modal->setHeaderData(5, Qt::Horizontal, QObject::tr("Salaire"));
    modal->setHeaderData(6, Qt::Horizontal, QObject::tr("Assurance"));
    modal->setHeaderData(7, Qt::Horizontal, QObject::tr("Diplômes"));


    return modal;
}




bool employee::modifier() {
    QSqlQuery query;
    query.prepare("UPDATE TABLE4 SET nom = :nom, prenom = :prenom, mail = :mail, "
                  "dateembauche = :dateembauche, certificats = :certificats, diplomes = :diplomes, "
                  "salaire = :salaire, assurance = :assurance WHERE id = :id");

    // Bind values to the query
    query.bindValue(":id", this->id);
    query.bindValue(":nom", this->nom);
    query.bindValue(":prenom", this->prenom);
    query.bindValue(":mail", this->mail);
    query.bindValue(":dateembauche", this->dateembauche);
    query.bindValue(":certificats", this->certificats);
    query.bindValue(":diplomes", this->diplomes);
    query.bindValue(":salaire", this->salaire);
    query.bindValue(":assurance", this->assurance);

    // Execute the query and check if it succeeded
    if (!query.exec()) {
        qDebug() << "Update failed:" << query.lastError();
        return false;
    }
    return true;
}
