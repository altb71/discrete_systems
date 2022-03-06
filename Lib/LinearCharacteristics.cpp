#include "LinearCharacteristics.h"

LinearCharacteristics::LinearCharacteristics(float gain,float offset)
{
    this->gain = gain;
    this->offset = offset;
}

LinearCharacteristics::LinearCharacteristics(float xmin,float xmax, float ymin, float ymax)
{
    this->gain = (ymax - ymin)/(xmax - xmin);
    this->offset = xmax - ymax/this->gain;
    this->ulim = 999999.0;
    this->llim = -999999.0;

}

LinearCharacteristics::LinearCharacteristics(float xmin,float xmax, float ymin, float ymax,float ll, float ul)
{
    this->gain = (ymax - ymin)/(xmax - xmin);
    this->offset = xmax - ymax/this->gain;
    this->llim = ll;
    this->ulim = ul;

}

LinearCharacteristics::~LinearCharacteristics() {}

float LinearCharacteristics::evaluate(float x)
{
    float dum = this->gain*(x - this->offset);
    if(dum > this->ulim)
        dum = this->ulim;
    if(dum < this->llim)
        dum = this->llim;
    return dum;
}

void LinearCharacteristics::setup(float gain,float offset)
{
    this->gain = gain;
    this->offset = offset;
    this->ulim = 999999.0;
    this->llim = -999999.0;
}

void LinearCharacteristics::setup(float xmin,float xmax, float ymin, float ymax)
{
    this->gain = (ymax - ymin)/(xmax - xmin);
    this->offset = xmax - ymax/this->gain;
    this->ulim = 999999.0;
    this->llim = -999999.0;
}

void LinearCharacteristics::setup(float xmin,float xmax, float ymin, float ymax,float ll, float ul)
{
    this->gain = (ymax - ymin)/(xmax - xmin);
    this->offset = xmax - ymax/this->gain;
    this->llim = ll;
    this->ulim = ul;
}

void LinearCharacteristics::correctExistingOffset(float y_offset)
{
    if(gain > 0.0) this->offset = this->offset + 1.0/(this->gain)*y_offset;
}
