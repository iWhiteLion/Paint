#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QImage>
#include <QPainter>
#include <QPaintEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class Principal; }
QT_END_NAMESPACE

class Principal : public QMainWindow
{
    Q_OBJECT

public:
    Principal(QWidget *parent = nullptr);
    ~Principal();

protected:

    void paintEvent(QPaintEvent *event ) override;

    void mousePressEvent(QMouseEvent *event )override;

    void mouseMoveEvent(QMouseEvent *event) override; //metodo para mantener presionado y mover


private:
    Ui::Principal *ui;

    QImage *m_imagen;       //es la imagen sobre la cual se va adibujar
    QPainter *m_painter;    //objeto painter

    QPoint m_ptInicial;     //Punto inicial para dibujar
    QPoint m_ptFinal;       //Puto final para dibujar
    
    QColor m_color;         //Para definir color de los proximos parametros 
};
#endif // PRINCIPAL_H
