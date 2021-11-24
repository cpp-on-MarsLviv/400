#include "modelparams.h"

#include <QDebug>

ModelParams::ModelParams(size_t newAreaWidth, size_t newTiming, float newDensity, float newProbabilityToBorn, float newProbabilityToDeath) :
    areaWidth{newAreaWidth},
    timing{newTiming},
    density{newDensity},
    probabilityToBorn{newProbabilityToBorn},
    probabilityToDeath{newProbabilityToDeath}
{

}

size_t ModelParams::getAreaWidth() const
{
    return areaWidth;
}

size_t ModelParams::getTiming() const
{
    return timing;
}

void ModelParams::setTiming(size_t newTiming)
{
    timing = newTiming;
}

float ModelParams::getDensity() const
{
    return density;
}

float ModelParams::getProbabilityToBorn() const
{
    return probabilityToBorn;
}

float ModelParams::getProbabilityToDeath() const
{
    return probabilityToDeath;
}
