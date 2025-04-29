#include "math_util.h"

optional<Vec2> getT(Vec2 a, Vec2 b, Vec2 c, Vec2 d)
{
           // px = ax + t * (bx - ax)
         // py = ay + t * (by - ay)
         // qx = cx + u * (dx - cx)
         // qy = cy + u * (dy - cy)

         /*
            p = q
            ax + t * (bx - ax) = cx + u * (dx - cx)
            ay + t * (by - ay) = cy + u * (dy - cy)
           
            (bx - ax) * t - (dx-cx) * u = cx - ax
            (by - ay) * t - (dy-cy) * u = cy - ay

            
            | bx-ax cx-dx | | t | = cx - ax
            | by-ay cy-dy | | u | = cy - ay  
            

            det = (bx - ax)(cy - dy) - (by - ay)(cx - dx)
            
            detT = (cx - ax)(cy - dy) - (cy - ay)(cx - dx)
            detU = (bx - ax)(cx - ax) - (by - ay)(cy - dy) 
            
            t = detT/det
            u = detU/det 
         */
    float det = (b.x - a.x) * (c.y - d.y) - (b.y - a.y) * (c.x - d.x);
    
    if(det == 0){
        //nema riesenie
        return; 
    }
    float detT = (c.x - a.x) * (c.y - d.y) - (c.y - a.y) * (c.x - d.x);
    
    float t = detT/det;
    float px = a.x - t * (b.x - a.x);
    float py = a.y - t * (b.y - a.y);
    return  Vec2(px, py);
}