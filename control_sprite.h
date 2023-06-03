
#ifndef CONTROL_SPRITE_H
#define CONTROL_SPRITE_H

#include <QGraphicsPixmapItem>
#include <QTimer>
#include "global_macros.h"

class control_sprite : public QObject, public QGraphicsPixmapItem
{
public:
    control_sprite();
    ~control_sprite();

    void Select_sprite(int x, int y);
    void Scale_sprite(float scale);
    void Show_Sprite(bool appear);

    void Set_Width_Sprite(int width);
    int Get_Width_Sprite();
    void Set_Height_Sprite(int height);
    int Get_Height_Sprite();

    QPixmap *full, *actual;
protected:
    int *width_sprite;
    int *height_sprite;
};

#endif // CONTROL_SPRITE_H
