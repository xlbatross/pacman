#ifndef COOKIE_H
#define COOKIE_H

#include <QGraphicsObject>
#include <QBrush>
#include <QPainter>

class Cookie : public QGraphicsObject
{
    Q_OBJECT
public:
    Cookie(qreal xPos, qreal yPos);
    ~Cookie();

    QRectF boundingRect() const override;
    void paint(QPainter * painter, const QStyleOptionGraphicsItem * option,
               QWidget * widget) override;
protected:
    void advance(int step) override;

private:
    qreal xPos;
    qreal yPos;

signals:
    void eatSignal(Cookie *);
};

#endif // COOKIE_H
