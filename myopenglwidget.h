#ifndef OPENGLWIDGET_H
#define OPENGLWIDGET_H

#include <QColor>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>

#define RGB_MIN 1
#define RGB_MAX 255

class MyOpenGLWidget : public QOpenGLWidget, public QOpenGLFunctions
{
public:
    MyOpenGLWidget(QWidget *parent = nullptr);
protected:
    void initializeGL() override;
    void paintGL() override;
    void resizeGL(int w, int h) override;
private:
    void qColorToRGB(const QColor &color, float &r, float &g, float &b) const;
    float normalize_0_1(float value, float minValue, float maxValue) const;
};

#endif // OPENGLWIDGET_H
