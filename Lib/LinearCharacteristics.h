#ifndef LINEAR_CHARACTERISTICS_H_
#define LINEAR_CHARACTERISTICS_H_

class LinearCharacteristics
{
public:
    LinearCharacteristics() {};
    LinearCharacteristics(float, float);
    LinearCharacteristics(float, float, float, float);
    LinearCharacteristics(float, float, float, float, float, float);
    float evaluate(float);
    void setup(float, float);
    void setup(float, float, float, float);
    void setup(float, float, float, float, float, float);
		void correctExistingOffset(float);
    float operator()(float x)
    {
        return evaluate(x);
    }
    virtual ~LinearCharacteristics();

private:
    float gain;
    float offset;
    float ulim;
    float llim;
};

#endif