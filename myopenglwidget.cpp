#include "myopenglwidget.h"

MyOpenGLWidget::MyOpenGLWidget(QWidget *parent)
    : QOpenGLWidget(parent)
{

}
void MyOpenGLWidget::initializeGL()
{
    float r, g, b, a = normalize_0_1(255.0f, RGB_MIN, RGB_MAX);
    initializeOpenGLFunctions();
    qColorToRGB(Qt::black, r, g, b);
    glClearColor(r, g, b, a);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);
    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
    glEnable(GL_COLOR_MATERIAL);
}
void MyOpenGLWidget::paintGL()
{
    float r, g, b;
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //X axis
    glBegin(GL_LINES);
    qColorToRGB(Qt::red, r, g, b);
    glColor3f(r, g, b);
    glVertex3f(-1.0f, 0.0f, 0.0f);
    glVertex3f(1.0f, 0.0f, 0.0f);
    glEnd();

    //Y axis
    glBegin(GL_LINES);
    qColorToRGB(Qt::blue, r, g, b);
    glColor3f(r, g, b);
    glVertex3f(0.0f, -1.0f, 0.0f);
    glVertex3f(0.0f, 1.0f, 0.0f);
    glEnd();

    //Z axis
    glBegin(GL_LINES);
    qColorToRGB(Qt::green, r, g, b);
    glColor3f(r, g, b);
    glVertex3f(0.0f, 0.0f, -1.0f);
    glVertex3f(0.0f, 0.0f, 1.0f);
    glEnd();

    //Triangle
    glBegin(GL_TRIANGLES);
    qColorToRGB(Qt::green, r, g, b);
    glColor3f(r, g, b);
    glVertex3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-0.5f, 0.0f, 0.0f);
    glVertex3f(0.5f, 0.0f, 0.0f);
    glEnd();
}
void MyOpenGLWidget::resizeGL(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void MyOpenGLWidget::qColorToRGB(const QColor &color, float &r, float &g, float &b) const
{
    int red = color.red();
    int green = color.green();
    int blue = color.blue();
    float minValue = RGB_MIN;
    float maxValue = RGB_MAX;
    r = normalize_0_1(red, minValue, maxValue);
    g = normalize_0_1(green, minValue, maxValue);
    b = normalize_0_1(blue, minValue, maxValue);
}

float MyOpenGLWidget::normalize_0_1(float value, float minValue, float maxValue) const
{
    return (value - minValue) / (maxValue - minValue);
}
