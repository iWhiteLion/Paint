#include "principal.h"
#include "ui_principal.h"

#include <QDebug>

Principal::Principal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Principal)
{
    ui->setupUi(this);

    //instancia del objeto imagen

    m_imagen = new QImage(this->size(),QImage::Format_ARGB32_Premultiplied); //tamaño y la imagen

    //Rellenar de blanco

    m_imagen->fill(Qt::white);

    //instanciamos el objeto painter

    m_painter = new QPainter(m_imagen);
}

Principal::~Principal()
{
    delete ui;
}
/**
 * @brief Principal::paintEvent Se ejecuta cada vez que se redibuja la interfaz
 * @param event
 */
void Principal::paintEvent(QPaintEvent *event)
{
    //Creamos un painter local

    QPainter painter (this); //Le mandamos la ventana como principal

    //dibujar la imagen

    painter.drawImage(0,0,*m_imagen);

    //Aceptamos el evento

    event->accept();

}

void Principal::mousePressEvent(QMouseEvent *event)
{
    //Comprobamos la posicion en pantalla

    qDebug() << event->pos();

    m_ptInicial = event->pos();

}

void Principal::mouseMoveEvent(QMouseEvent *event)
{
    m_ptFinal = event->pos();

    //creamos pincel

    QPen pincel ;

    //selciionamos el color

    pincel.setColor(Qt::red);

    //escribimso el pincel

    m_painter->setPen(pincel);

    //Dibujar un alinea

    m_painter->drawLine(m_ptInicial, m_ptFinal);

    //Redibujar ya que no mostraba nada en pantalla

    update();

    m_ptInicial  = m_ptFinal; //nos ayuda a resolver el error del mismo punto de inciio
}

