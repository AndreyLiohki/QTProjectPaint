#ifndef FIGURE_H
#define FIGURE_H
#include <QPointF> //Библиотека, которая представляет собой координаты точки на экране, представленные типом float
#include <QPolygonF> //Библиотека, которая представляет собой надор точек плоскости, координаты которых представлены типом float
#include <QPainter> //Библиотека,отвечающая за исполнение операций отрисовки
#include <QDataStream>

using namespace std;

enum class FigureType {Rectangle, Triangle, Ellipse, None};

//В данном файле мы создам абстрактный класс, который в общем описывает все фигуры, которые буду в нашем приложениие
class Figure{
protected:
    QPointF StarterPoint, FinalPoint; //Создаем две переменные типа QPointF, которые будут содержать координаты левого верхнего и правого нижнего углов бокса, в которых находится отображаемая фигура
    QPolygonF FigPolygon; //Содаем список точек плоскости
    FigureType figType; //Переменная, которая принимает значение той фигуры, которую мы хотим отрисовать
public:
    Figure() = default;
    virtual void updateFigureCoordinates() = 0;
    virtual bool isFigContainsPoint(const QPointF& pnt) const  = 0; // Функция, проверяющая, принадлежит ли входящая в качестве параметра точка фигуре
    virtual void drawFigure(QPainter& painter) const = 0; //Создаем функцию, которая будет отвечать за отрисовку нашей фигуры, делаем её виртуальной т.к. класс абстрактный
    virtual void UpdateStarterPoint(const QPointF& pnt) = 0; //Функция, отвечающая за сохранение в StarterPoint начальной точки фигуры (левый верхний угол бокса, в котором находится фигура)
    virtual QPointF GetCenterOfFigure() const = 0; //Создаем функцию для поиска центра фигуры,к которому будет привязываться конектор
    virtual ~Figure() = default; //Создаем виртуальный деструктор
    virtual void updateFinalPiont(const QPointF& pnt) = 0; // Функция, отвечающая за сохранение в FinalPoint конечной точки фигуры (правый нижний угол бокса, в котором находится фигура)
    virtual QPointF CalculateOffset(const QPointF& pnt) const = 0; //Функция, вычисляющая смещение относительно левого врехнего угла бокса в котором расположена фигура
    virtual void translate(const QPointF& currentPoint, const QPointF& offset) = 0;
    virtual void serialize(QDataStream& out) const = 0;
    virtual void deserialize(QDataStream& in) = 0;



};

#endif // FIGURE_H
