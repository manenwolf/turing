#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    std::string s = QFileDialog::getOpenFileName().toStdString();
    std::cout << "loading in file: " << s << std::endl;
    M.loadxml(s);
    redraw();
}
void MainWindow::redraw(){
    //clear all
    ui->inputalphabet->clear();
    ui->tapealphabet->clear();
    ui->blank->clear();
    ui->states->clear();
    ui->acceptingstates->clear();
    ui->startstate->clear();
    ui->transitions->clear();
    ui->fromstate->clear();
    ui->tostate->clear();

    std::vector<std::string> temp = M.getinputsymbols();
    //std::cout << temp.size() << std::endl;
    //draw the inputalphabet
    for(unsigned int i = 0;i <  temp.size();i++){
        ui->inputalphabet->append(QString::fromStdString( temp[i]));
   }
    //draw the tapealphabet
    temp = M.gettapesymbols();
    for(unsigned int i = 0;i <  temp.size();i++){
        ui->tapealphabet->append(QString::fromStdString( temp[i]));
   }
    //draw the blanksymbol
    ui->blank->append(QString::fromStdString(M.getblank()));
    //draw the states
    temp = M.getstates();
    for(unsigned int i = 0;i <  temp.size();i++){
        ui->states->append(QString::fromStdString( temp[i]));
        //add to dropdowns
        ui->fromstate->addItem(QString::fromStdString( temp[i]));
        ui->tostate->addItem(QString::fromStdString( temp[i]));

   }
    //draw the acceptingstates
    temp = M.getacceptingstates();
    for(unsigned int i = 0;i <  temp.size();i++){
        ui->acceptingstates->append(QString::fromStdString( temp[i]));
   }
   //draw the startstate
    ui->startstate->append((QString::fromStdString(M.getstartstate())));
    //drawing transitions
    temp = M.gettransitions();
    for(unsigned int i = 0;i <  temp.size();i++){
        ui->transitions->append(QString::fromStdString( temp[i]));
   }
    ui->input->setText(QString::fromStdString(M.gettape()));

    //making the graph
    M.todot();
    QProcess p;
    std::cout << "drawing dot" << std::endl;
    std::cout <<"\"c:\\Program Files (x86)\\Graphviz2.38\\bin\\dot.exe\" -Tpng out.dot -o out.png" << std::endl;
    p.start("\"c:\\Program Files (x86)\\Graphviz2.38\\bin\\dot.exe\" -Tpng out.dot -o out.png");
    p.waitForFinished();
    //p.start("dot -Tpng out.dot -o out.png");
    QPixmap picture = QPixmap(QString::fromUtf8("out.png"));
    //picture = picture.scaledToHeight(400);
   // picture = picture.scaledToWidth(500);
    ui->graph->setFixedHeight(picture.height());

    ui->graph->setFixedWidth(picture.width());
    ui->graph->setPixmap(picture);

    ui->scrollArea->setBackgroundRole(QPalette::Dark);
    ui->scrollArea->setWidget(ui->graph);




}

void MainWindow::on_pushButton_2_clicked()
{
    M.setinput(ui->input->text().toStdString());
    std::string s = M.run();
    ui->input->setText(QString::fromStdString(s));
}

void MainWindow::on_pushButton_3_clicked()
{
    try{
        M = M.tosingletape();
        redraw();
    }catch(singletape){
        std::cout << "already a singletap " << std::endl;
        QMessageBox msgBox;
        msgBox.setText("alrady a singletape");
        msgBox.exec();

    }
}

void MainWindow::on_pushButton_4_clicked()
{
    if(M.end()){
        std::cout << "end " << std::endl;
        QMessageBox msgBox;
        msgBox.setText("accepting state reached");
        msgBox.exec();
        return;
    }
   static bool i = false;
   if(!i){
   M.setinput(ui->input->text().toStdString());
   i = true;
   }
   std::string r;
   try{
   M.onestep();
   r = M.gettape();
   }catch(std::string s){
       r = "fail";
   }
       ui->input->setText(QString::fromStdString(r+"   -"+std::to_string(M.finitecontrol[0])));
   redraw();
}

void MainWindow::on_pushButton_5_clicked()
{
    std::string s = QFileDialog::getOpenFileName().toStdString();
    std::string from = ui->fromstate->currentText().toStdString();
    std::string to = ui->tostate->currentText().toStdString();
    M.addsubroutine(from,to,s);
    std::cout << "-------" << from << " " << to << " +0" << s << std::endl;
    redraw();
}
