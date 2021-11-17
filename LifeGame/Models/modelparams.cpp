#include "modelparams.h"

ModelParams::ModelParams(int newAreaWidth, size_t newTiming) : areaWidth{newAreaWidth}, timing{newTiming}
{

}

int ModelParams::getAreaWidth() const
{
    return areaWidth;
}

size_t ModelParams::getTiming() const
{
    return timing;
}
