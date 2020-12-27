#ifndef VIEWSCREEN_H
#define VIEWSCREEN_H
#include "optionsdialog.h"
#include <QtWidgets>
#include <QColor>
#include <QPaintEvent>
#include <QPointer>

class ViewScreen : public QWidget
{
    Q_OBJECT

private:
    QColor mBackgroundColor;
    int mSizeX;
    int mSizeY;
    OptionsDialog* mOptions;
    bool mNoActiveDialog;
    void launchDialog(void);
    void mousePressEvent(QMouseEvent *event) override;

protected:
    QImage mImage;
    QPainter *mPainter;
    void paintEvent(QPaintEvent *event) override;
    void clearScreen(void);
    void paintStar(void);
    void paintReverseStar(void);
    void paintCircle(void);
    void paintReverseCircle(void);
    void paintGasket(void);
    void paintCarpet(void);
    void paintReverseGasket(void);
    void paintReverseCarpet(void);
    void resizeEvent(QResizeEvent *event) override;
    void resizeImage(QImage *, const QSize &);


public:
    ViewScreen(QWidget *parent = nullptr);

public slots:
    void setNoActiveDialog(void){ mNoActiveDialog = true; };
    void dialogButton(int);
};

#endif
