#ifndef MODELPARAMS_H
#define MODELPARAMS_H

#include <cstdlib>
/**
 * @brief The ModelParams class conatain all input parameters for model
 */

class ModelParams
{
    size_t areaWidth;
    size_t timing;
    float density;
    float probabilityToBorn;
    float probabilityToDeath;

public:
    ModelParams(size_t areaWidth, size_t timing, float density, float probabilityToBorn, float probabilityToDeath);
    ModelParams(const ModelParams&) = default;
    ModelParams(ModelParams&&) = default;
    ModelParams& operator=(const ModelParams&) = default;
    ModelParams& operator=(ModelParams&&) = default;

    ~ModelParams() = default;

    size_t getAreaWidth() const;

    size_t getTiming() const;
    void setTiming(size_t);

    float getDensity() const;
    float getProbabilityToBorn() const;
    float getProbabilityToDeath() const;
};

#endif // MODELPARAMS_H
