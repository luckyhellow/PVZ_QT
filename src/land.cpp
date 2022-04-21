#include "land.h"

Land::Land()
{
    for(int i=0;i<col;i++)
    {
        for(int j=0;j<row;j++)
        {
            land[i][j] = NOPLANT;
            landbutton[i][j] = new landbar(":/Image/background_bar.png");
            QPixmap pix(":/Image/background_bar_no.png");
            landbutton[i][j]->setIcon(pix);
//            landbutton[i][j]->head = NULL;
//            landbutton[i][j]->setIconSize(pix.size());
        }
    }
}

//Land::Land(int x,int y)
//{
//    col = x;
//    row = y;
//    for(int i=0;i<col;i++)
//    {
//        for(int j=0;j<row;j++)
//        {
//            land[i][j] = NOPLANT;
//            landbutton[i][j] = new landbar(":/Image/background_bar.png");
//            QPixmap pix(":/Image/background_bar_no.png");
//            landbutton[i][j]->setIcon(pix);
////            landbutton[i][j]->head = NULL;
////            landbutton[i][j]->setIconSize(pix.size());
//        }
//    }
//}
//void Land::plant(int TPYE)
//{
//    if(TPYE==SUNFLOWER)
//    {
//        Sunflower::plant();
//    }
//}
