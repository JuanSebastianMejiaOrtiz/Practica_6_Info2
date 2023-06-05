
#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Properties_Timer = new QTimer;

    connect(solar_system::timer, SIGNAL(timeout()), this, SLOT(Fisicas()));
    connect(Properties_Timer, SIGNAL(timeout()), this, SLOT(Properties_View_Move()));

    Set_Properties_Default();
    Set_Text_Sun();
    sun_center_x = ui->Sun->x() + ui->Sun->width()/2;
    sun_center_y = ui->Sun->y() + ui->Sun->height()/2;

    maxvx = 50;
    maxvy = 50;

    T = 0.01;
    ui->PERIODO->setValue(T);

    solar_system::timer->start(T*1000);

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

    ui->Sun->setText(texto_sun);

    ui->Sun->setStyleSheet("color: red;");
}

void MainWindow::Combobox_text(short num)
{
    std::string texto = "Planeta ";

    texto = texto + std::to_string(num);
    QString qtexto = QString::fromStdString(texto);
    ui->comboBox->addItem(qtexto);
}


void MainWindow::Fisicas()
{
    calcular_fisicas(T, Sim_Speed);
    aplicar_fisicas();
}

void MainWindow::calcular_fisicas(float Periodo, float Simulation_Speed)
{
    std::vector<planeta>::iterator i;
    std::vector<planeta>::iterator j;
    float ax, ay, vx, vy, x, y;
    float dx, dy, r, teta, m2;
    float ax1, ay1;
    float G;
    G = 6.6738 * std::pow(10, -11);  //Constante de Gravedad Universal

    for (i = planets.begin(); i != planets.end(); ++i) {
        ax = i->getAX();
        ay = i->getAY();
        vx = i->getVX();
        vy = i->getVY();
        x = i->getX();
        y = i->getY();

        for (j = planets.begin(); j != planets.end(); ++j) {
            if (i != j) {
                dx = j->getX() - x;  //Posicion del otro cuerpo X
                dy = j->getY() - y;  //Posicion del otro cuerpo Y
                r = std::sqrt((dx * dx) + (dy * dy));  //Distancia entre 2 cuerpos
                teta = std::atan2(dy, dx);  //Angulo vector de direccion
                m2 = j->getMass();  //Masa del otro objeto

                ax1 = (G * m2 / (r * r)) * (1/std::sin(teta));  //Aceleracion Gravitacional X
                ay1 = (G * m2 / (r * r)) * std::sin(teta);  //Aceleracion Gravitacional Y

//                if (ax < maxvx){
//                    ax += ax1;
//                }
//                else vx *= -1;

//                if (ay < maxvy){
//                    ay += ay1;
//                }
//                else vy *= -1;

                ax += ax1;
                ay += ay1;

                i->setAX(ax);
                i->setAY(ay);
            }
        }

        // Actualizar las velocidades y posiciones del planeta
        vx += ax * Periodo * Simulation_Speed;
        vy += ay * Periodo * Simulation_Speed;
        x += vx * Periodo * Simulation_Speed + (0.5 * ax * std::pow(Periodo * Simulation_Speed, 2));
        y += vy * Periodo * Simulation_Speed + (0.5 * ay * std::pow(Periodo * Simulation_Speed, 2));

        i->setVX(vx);
        i->setVY(vy);
        i->setX(x);
        i->setY(y);

        std::cout << "X " << i->getX() << '\n';
        std::cout << "Y " << i->getY() << '\n';
        std::cout << "VX " << i->getVX() << '\n';
        std::cout << "VY " << i->getVY() << '\n';
        std::cout << "AX " << i->getAX() << '\n';
        std::cout << "AY " << i->getAY() << '\n';
    }
}

void MainWindow::aplicar_fisicas()
{
    for (int i = 0; i < planets.size(); ++i) {
        QLabel* label = planets[i].planet;

        float x = planets[i].getX();
        float y = planets[i].getY();
        //int width = Planeta_Width;
        //int height = Planeta_Height;

        //label->setGeometry(static_cast<int>(x), static_cast<int>(y), width, height);
        label->move(static_cast<int>(x), static_cast<int>(y));
        label->show();

        std::cout << "Label X " << label->y() << '\n';
        std::cout << "Label Y " << label->x() << '\n';
    }
}

//Para conectar la interfaz grafica con las variables
void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    if (index >= 0 && index < planets.size())
    {
        planeta& planet = planets[index];

        ui->POS_X_INITIAL->setValue(planet.getX());
        ui->POS_Y_INITIAL->setValue(planet.getY());

        ui->VEL_X_INITIAL->setValue(planet.getVX());
        ui->VEL_Y_INITIAL->setValue(planet.getVY());

        ui->ACELERATION_X->setValue(planet.getAX());
        ui->ACELERATION_Y->setValue(planet.getAY());

        ui->MASA->setValue(planet.getMass());
    }
}

void MainWindow::on_pushButton_clicked()
{
    short num = ui->comboBox->count() + 1;

    add_Planet(num);
    Combobox_text(num);

    QLabel *planetLabel = new QLabel(ui->Main_View);
    planetLabel->setText(planets.back().get_planet_Shape());

    int x = 0;
    int y = 0;
    int width = Planeta_Width;
    int height = Planeta_Height;
    planetLabel->setGeometry(x, y, width, height);

    planetLabel->show();
}

void MainWindow::on_POS_X_INITIAL_valueChanged(double arg1)
{
    int index = ui->comboBox->currentIndex();
    if (index >= 0 && index < planets.size())
    {
        planeta& planet = planets[index];

        planet.setX(arg1);
    }
}


void MainWindow::on_POS_Y_INITIAL_valueChanged(double arg1)
{
    unsigned int index = ui->comboBox->currentIndex();
    if (index >= 0 && index < planets.size())
    {
        planeta& planet = planets[index];

        planet.setY(arg1);
    }
}


void MainWindow::on_VEL_X_INITIAL_valueChanged(double arg1)
{
    unsigned int index = ui->comboBox->currentIndex();
    if (index >= 0 && index < planets.size())
    {
        planeta& planet = planets[index];

        planet.setVX(arg1);
    }
}


void MainWindow::on_VEL_Y_INITIAL_valueChanged(double arg1)
{
    unsigned int index = ui->comboBox->currentIndex();
    if (index >= 0 && index < planets.size())
    {
        planeta& planet = planets[index];

        planet.setVY(arg1);
    }
}


void MainWindow::on_ACELERATION_X_valueChanged(double arg1)
{
    unsigned int index = ui->comboBox->currentIndex();
    if (index >= 0 && index < planets.size())
    {
        planeta& planet = planets[index];

        planet.setAX(arg1);
    }
}


void MainWindow::on_ACELERATION_Y_valueChanged(double arg1)
{
    unsigned int index = ui->comboBox->currentIndex();
    if (index >= 0 && index < planets.size())
    {
        planeta& planet = planets[index];

        planet.setAY(arg1);
    }
}


void MainWindow::on_MASA_valueChanged(double arg1)
{
    unsigned int index = ui->comboBox->currentIndex();
    if (index >= 0 && index < planets.size())
    {
        planeta& planet = planets[index];

        planet.setMass(arg1);
    }
}


void MainWindow::on_PERIODO_valueChanged(double arg1)
{
    T = arg1;
    timer->start(T*1000);
}


void MainWindow::on_SIMULACION_VELOCIDAD_valueChanged(double arg1)
{
    Sim_Speed = arg1;
}

