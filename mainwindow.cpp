
#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Properties_Timer = new QTimer;
    Properties_Counter = Properties_View_Width * -1;
    Properties_Pressed = 0;

    connect(Properties_Timer, SIGNAL(timeout()), this, SLOT(Properties_View_Move()));

    Set_Text_Sun();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete Properties_Timer;
}

void MainWindow::on_Properties_Button_clicked()
{
    Properties_Timer->start(Properties_View_Movement_Speed);
    Properties_Pressed = !Properties_Pressed;
}

void MainWindow::Properties_View_Move()
{
    if (Properties_Counter < Properties_View_Pos_x_final && Properties_Pressed){
        if (ui->Properties_View->x() < Properties_View_Pos_x_final){
            ui->Properties_View->setGeometry(ui->Properties_View->x() + Properties_View_Move_Speed, Properties_View_Pos_y, ui->Properties_View->width(), ui->Properties_View->height());
            Properties_Counter += Properties_View_Move_Speed;

            if (Properties_Counter == Properties_View_Pos_x_final){
                Properties_Timer->stop();
            }
        }
    }
    else if (Properties_Counter > (Properties_View_Width) * -1 && !Properties_Pressed){
        if (ui->Properties_View->x() > (Properties_View_Width * -1)){
            ui->Properties_View->setGeometry(ui->Properties_View->x() - Properties_View_Move_Speed, Properties_View_Pos_y, ui->Properties_View->width(), ui->Properties_View->height());
            Properties_Counter -= Properties_View_Move_Speed;

            if (Properties_Counter == (Properties_View_Width * -1)){
                Properties_Timer->stop();
            }
        }
    }

}


void MainWindow::on_comboBox_currentIndexChanged(int index)
{

}


void MainWindow::on_pushButton_clicked()
{
    short num = ui->comboBox->count() + 1;


    Combobox_text(num);
}

void MainWindow::Set_Text_Sun()
{
    QString texto_sun = Sun_Text();

    ui->Sun->setText(texto_sun);
}

void MainWindow::Combobox_text(short num)
{
    std::string texto = "Planeta ";

    texto = texto + std::to_string(num);
    QString qtexto = QString::fromStdString(texto);
    ui->comboBox->addItem(qtexto);
}

