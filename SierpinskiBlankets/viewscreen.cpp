#include "viewscreen.h"
#include "star.h"
#include "circle.h"
#include "gasket.h"
#include "carpet.h"
#include "options.h"
#include "point.h"

ViewScreen::ViewScreen(QWidget *parent) : QWidget(parent),
mBackgroundColor (0,0,0), mNoActiveDialog(true)
{
    mSizeX = 800;
    mSizeY = 800;
    mImage = QPixmap(mSizeX, mSizeY).toImage();
    QPainter painter(&mImage);
    mPainter = &painter;
    mPainter->setRenderHint(QPainter::Antialiasing, true);
    launchDialog();
}

void ViewScreen::launchDialog(void) {
    if(mNoActiveDialog) {
        mOptions = new OptionsDialog(this);
        QObject::connect(mOptions, SIGNAL(dialogPressed(int)), this, SLOT(dialogButton(int)));
        mOptions->show();
        mNoActiveDialog = false;
    }
}

void ViewScreen::mousePressEvent(QMouseEvent *event) {
    Q_UNUSED(event);
    launchDialog();
}

void ViewScreen::resizeEvent(QResizeEvent *event) {
    mSizeX = width();
    mSizeY = height();
    if (mSizeX>mImage.width()||mSizeY>mImage.height()) {
        int newWidth = qMax(mSizeX + 128, mImage.width());
        int newHeight = qMax(mSizeY + 128, mImage.height());
        resizeImage(&mImage, QSize(newWidth, newHeight));
        update();
    }
    QWidget::resizeEvent(event);
}

void ViewScreen::resizeImage(QImage *image, const QSize &newSize) {
    if (image->size() == newSize) return;
    QImage newImage(newSize, QImage::Format_RGB32);
    newImage.fill(qRgb(0, 0, 0));
    QPainter painter(&newImage);
    painter.drawImage(QPoint(0, 0), *image);
    *image = newImage;
}

void ViewScreen::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);
    QPainter painter(this);
    QRect touched = event->rect();
    painter.drawImage(touched, mImage, touched);
}

void ViewScreen::dialogButton(int dialogPressed) {
    int showstring = dialogPressed;
    ShapeType type = mOptions->m_options.getType();
    switch (showstring) {
    case 0:
        switch (type) {
        case ShapeType::star:
            paintStar();
            break;
        case ShapeType::reverse_star:
            paintReverseStar();
            break;
        case ShapeType::circle:
            paintCircle();
            break;
        case ShapeType::reverse_circle:
            paintReverseCircle();
            break;
        case ShapeType::gasket:
            paintGasket();
            break;
        case ShapeType::carpet:
            paintCarpet();
            break;
        case ShapeType::reverse_gasket:
            paintReverseGasket();
            break;
        case ShapeType::reverse_carpet:
            paintReverseCarpet();
            break;
        }
        break;
    case 1:
        clearScreen();
        break;
    default:
        break;
    }
}

void ViewScreen::clearScreen(void) {
    QPainter painter(&mImage);
    painter.setBrush(mBackgroundColor);
    painter.drawRect(this->rect());
    QWidget::update();
}

void ViewScreen::paintStar(void) {
    Star star;
    star.setMaxLevel(mOptions->m_options.getLevel());
    star.setInitiator(mPainter, &mImage);
    star.draw();

    QWidget::update();
}

void ViewScreen::paintReverseStar(void) {
    Star star;
    star.setMaxLevel(mOptions->m_options.getLevel());
    star.setEraseInitiator(mPainter, &mImage);
    star.rdraw();
    QWidget::update();
}

void ViewScreen::paintCircle(void) {
    Circle circle(ShapeType::gasket);
    circle.setMaxLevel(mOptions->m_options.getLevel());
    circle.setInitiator(mPainter, &mImage);
    circle.draw();
    QWidget::update();
}
void ViewScreen::paintReverseCircle(void) {
    Circle circle(ShapeType::carpet);
    circle.setMaxLevel(mOptions->m_options.getLevel());
    circle.setReverseInitiator(mPainter, &mImage);
    circle.setEraseInitiator(mPainter, &mImage);
    circle.rdraw();
    QWidget::update();
}

void ViewScreen::paintGasket(void) {
    Gasket gasket;
    gasket.setMaxLevel(mOptions->m_options.getLevel());
    gasket.setInitiator(mPainter, &mImage);
    gasket.draw();
    QWidget::update();
}

void ViewScreen::paintReverseGasket(void) {
    Gasket gasket;
    gasket.setMaxLevel(mOptions->m_options.getLevel());
    gasket.setInitiator(mPainter, &mImage);
    gasket.setEraseInitiator(mPainter, &mImage);
    gasket.rdraw();
    QWidget::update();
}

void ViewScreen::paintCarpet(void) {
    Carpet carpet;
    carpet.setMaxLevel(mOptions->m_options.getLevel());
    carpet.setInitiator(mPainter, &mImage);
    carpet.draw();
    QWidget::update();
}

void ViewScreen::paintReverseCarpet(void) {
    Carpet carpet;
    carpet.setMaxLevel(mOptions->m_options.getLevel());
    carpet.setInitiator(mPainter, &mImage);
    carpet.setEraseInitiator(mPainter, &mImage);
    carpet.rdraw();
    QWidget::update();
}
