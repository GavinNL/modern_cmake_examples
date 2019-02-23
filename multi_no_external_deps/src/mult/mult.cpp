#include <math/mult/mult.h>
#include <math/add/add.h>

int math::mult( int a, int b )
{
    int r = 0;
    for(int i=0;i<a;i++)
    {
        r = math::add(r, b);
    }
    return r;
}
