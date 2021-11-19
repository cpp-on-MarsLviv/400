#include "modelparams.h"

ModelParams::ModelParams(size_t newAreaWidth, double newTiming, double newDensity) :
    areaWidth{newAreaWidth},
    timing{newTiming},
    density{newDensity}
{

}

size_t ModelParams::getAreaWidth() const
{
    return areaWidth;
}

double ModelParams::getTiming() const
{
    return timing;
}

double ModelParams::getDensity() const
{
    return density;
}
