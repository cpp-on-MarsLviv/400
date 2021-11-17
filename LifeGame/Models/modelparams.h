#ifndef MODELPARAMS_H
#define MODELPARAMS_H

#include <cstdlib>
/**
 * @brief The ModelParams class conatain all input parameters for model
 */

class ModelParams
{
    int areaWidth;
    size_t timing;
public:
    ModelParams(int areaWidth, size_t timing);
    int getAreaWidth() const;
    size_t getTiming() const;
};

#endif // MODELPARAMS_H
