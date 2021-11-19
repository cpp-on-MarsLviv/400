#ifndef MODELPARAMS_H
#define MODELPARAMS_H

#include <cstdlib>
/**
 * @brief The ModelParams class conatain all input parameters for model
 */

class ModelParams
{
    size_t areaWidth;
    double timing;
    double density;

public:
    ModelParams(size_t areaWidth, double timing, double density);
    ModelParams(const ModelParams&) = default;
    ModelParams(ModelParams&&) = default;
    ModelParams& operator=(const ModelParams&) = default;
    ModelParams& operator=(ModelParams&&) = default;

    ~ModelParams() = default;

    size_t getAreaWidth() const;
    double getTiming() const;
    double getDensity() const;
};

#endif // MODELPARAMS_H
