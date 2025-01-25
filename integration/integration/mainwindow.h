#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableView>
#include <QMessageBox>
#include <QDate>


#include "arduino.h"
//employee

#include <QSqlTableModel>
#include <QListWidget>
#include <QMainWindow>
/*#include <Qt3DCore/QEntity>
#include <Qt3DCore/QComponent>
#include <Qt3DExtras/QCuboidMesh>
#include <Qt3DCore/QTransform>*/

#include <QAction>  // Inclure QAction pour les actions de la barre d'outils
#include <QCamera>
//#include <QCameraImageCapture>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>

#include "employee.h"

#include "client.h"
#include <QComboBox>
#include<QTableView>
#include<QStackedWidget>




#include <QProcess>


class client;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void sortEmployees();
    //void runEmotionDetection();
    void resetTable();
    QString respondToQuestion(const QString &question);

     //QString readEmotionFromFile(const QString &filePath);

private slots:
    void on_ajouter_clicked();
    void on_tableView_activated(const QModelIndex &index);
    void on_modifier_clicked();
    void update_label();

    void on_page3Button_4_clicked();

    void navigateToPage(int pageIndex);
    void exportToPDF();
    void exportToExcel();
    void Rechercherclient(const QString &text);
    void on_sortComboBox_currentIndexChanged(int index);
    void displayCharts_clientByGender();
    void on_gostat_clicked();


    void on_calendrier_reserv_clicked(const QDate &date);
    void updateCalendarAndEventDetails(const QDate &date);

    void on_calendrier_clicked();

    void on_Back_clicked();

    void on_supprimerbtn_clicked();





        //employee


    void on_buttonRechercher_clicked();
    void on_add_btn_4_clicked();
    //void on_sort_btn_clicked();
    void on_delete_btn_4_clicked();
    void on_pushButton_export_pdf_clicked();
    void on_pushButton_send_4_clicked();
    void onTableViewClicked(const QModelIndex &index);

    void onEmotionDetection_3Clicked();


    //void displayCroppedImage(const QString &imagePath);


    void RechercherEmploye(const QString &text);
    void on_buttonUpdate_3_clicked();
    void on_stats_btn_clicked();
    //void onImageGenerated();

    //void on_buttonUpdate_3_clicked();
    //void sortEmployees();
    // Ajoutez d'autres slots si nécessaire

private:
    Ui::MainWindow *ui;

    employee Etmp;
    QSqlTableModel *employeeModel;  // Pour récupérer les données des employés
    QStringList previousQuestions;  // Stocker les questions précédentes pour "l'apprentissage"
    QMap<QString, QString> knowledgeBase;
    Arduino A;
    QString data;
    QProcess *process;
    QString test = "1";









    // Fonction pour répondre aux questions
    void addEmployeeInfoToChat();    // Ajouter les informations des employés au chat
    void saveKnowledgeBase();
    void loadKnowledgeBase();
    void afficherTousLesEmployes();
    void trierNomsEmployes();




    //void keyPressEvent(QKeyEvent *event);


    //void generateAnswerFromAPI(const QString &question);
    //void onAPIResponse(QNetworkReply *reply);
    //void generateImage(const QString &description);
    //void updateEmployee();

    // Membre pour la barre d'outils
    // Pointeur pour la barre d'outils
    QList<QMap<QString, QVariant>> deletedEntries;
};

#endif // MAINWINDOW_H
