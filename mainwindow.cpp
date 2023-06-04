
#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Properties_Timer = new QTimer;

    connect(Properties_Timer, SIGNAL(timeout()), this, SLOT(Properties_View_Move()));

    Set_Properties_Default();
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

void MainWindow::Set_Properties_Default()
{
    Properties_Counter = Properties_View_Width * -1;
    Properties_Pressed = 0;
}

void MainWindow::Set_Text_Sun()
{
    QString texto_sun = Sun_Text();

    std::string st = texto_sun.toStdString();

    ui->Sun->setText(texto_sun);
}

void MainWindow::Combobox_text(short num)
{
    std::string texto = "Planeta ";

    texto = texto + std::to_string(num);
    QString qtexto = QString::fromStdString(texto);
    ui->comboBox->addItem(qtexto);
}

void MainWindow::calcular_fisicas(float Periodo, float Simulation_Speed)
{
    std::vector<planeta>::iterator i;
    std::vector<planeta>::iterator j;
    float ax, ay, vx, vy, x, y;
    float vx0, vy0, x0, y0;
    float dx, dy, r, teta, m2;
    float ax1, ay1;
    float G = 1;

    for (i = planets.begin(); i != planets.end(); ++i) {
        ax = i->getAX();
        ay = i->getAY();
        for (j = planets.begin(); j != planets.end(); ++j) {
            if (i != j) {
                dx = (j->getX()) - (i->getX());
                dy = (j->getY()) - (i->getY());
                r = std::sqrt((dx * dx) + (dy * dy));
                teta = std::atan2(dy, dx);
                m2 = j->getMass();

                ax1 = (G * m2 / std::pow(r, 2)) * std::sin(teta);
                ay1 = (G * m2 / std::pow(r, 2)) * std::cos(teta);

                ax += ax1;
                ay += ay1;
            }
        }

        // Actualizar las velocidades y posiciones del planeta
        vx0 = i->getVX();
        vy0 = i->getVY();
        x0 = i->getX();
        y0 = i->getY();

        vx = vx0 + ax * Periodo * Simulation_Speed;
        vy = vy0 + ay * Periodo * Simulation_Speed;
        x = x0 + vx0 * Periodo * Simulation_Speed + (0.5 * ax * std::pow(Periodo * Simulation_Speed, 2));
        y = y0 + vy0 * Periodo * Simulation_Speed + (0.5 * ay * std::pow(Periodo * Simulation_Speed, 2));

        i->setVX(vx);
        i->setVY(vy);
        i->setX(x);
        i->setY(y);
    }
}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{

}

void MainWindow::on_pushButton_clicked()
{
    short num = ui->comboBox->count() + 1;

    add_Planet(num);
    Combobox_text(num);


    QLabel *planetLabel = planets.back().planet;
    planetLabel->setText(planets.back().get_planet_Shape());

    QVBoxLayout *mainLayout = dynamic_cast<QVBoxLayout*>(ui->Main_View->layout());
    if (!mainLayout) {
        mainLayout = new QVBoxLayout(ui->Main_View);
        ui->Main_View->setLayout(mainLayout);
    }

    mainLayout->addWidget(planetLabel);
}
