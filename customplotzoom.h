#ifndef CUSTOMPLOTZOOM_H
#define CUSTOMPLOTZOOM_H
#include <QPoint>
#include "qcustomplot.h"

class QRubberBand;
class QMouseEvent;
class QWidget;

/**
 * @brief The CustomPlotZoom class Subclass of the QCustomPlot to allow zooming in.
 * The class overrides mouse event methods to allow interactive zooming with right mourse key.
 */
class CustomPlotZoom : public QCustomPlot
{
    Q_OBJECT

public:
    CustomPlotZoom(QWidget * parent = 0);
    virtual ~CustomPlotZoom();

    void setZoomMode(bool mode);

private slots:
    void mousePressEvent(QMouseEvent * event) override;
    void mouseMoveEvent(QMouseEvent * event) override;
    void mouseReleaseEvent(QMouseEvent * event) override;

private:
    bool mZoomMode; // Zoom activation trigger
    QRubberBand * mRubberBand; // Rectangule - zooming area visual aid
    QPoint mOrigin; // Coordinates of the rectangule

};

#endif // CUSTOMPLOTZOOM_H
