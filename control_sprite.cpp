
#include "control_sprite.h"

control_sprite::control_sprite()
{
    //Assign Memory for Attributes
    full = new QPixmap;
    actual = new QPixmap;
    width_sprite = new int;
    height_sprite = new int;

    //Set Default Values
    *width_sprite = Sprite_Width;
    *height_sprite = Sprite_Height;
}

control_sprite::~control_sprite()
{
    delete full;
    delete actual;
    delete width_sprite;
    delete height_sprite;
}

void control_sprite::Select_sprite(int x, int y)
{
    *actual = full->copy((*width_sprite)*x, (*height_sprite)*y, (*width_sprite), (*height_sprite));
}

void control_sprite::Scale_sprite(float scale)
{
    *actual = actual->scaled(actual->width()*scale, actual->height()*scale);
}

void control_sprite::Show_Sprite(bool appear)
{
    if(appear){
        setPixmap(*actual);
        setVisible(1);
    }
    else setVisible(0);
}

void control_sprite::Set_Width_Sprite(int width)
{
    *width_sprite = width;
}

int control_sprite::Get_Width_Sprite()
{
    return *width_sprite;
}

void control_sprite::Set_Height_Sprite(int height)
{
    *height_sprite = height;
}

int control_sprite::Get_Height_Sprite()
{
    return *height_sprite;
}

