#include "ParticleDis.h"
#include <cmath>

double ParticleDis::Value(int index,double in0,double in1,double in2) {
   input0 = (in0 - 609.663)/812.913;
   input1 = (in1 - 1086.55)/1575.83;
   input2 = (in2 - 7219.39)/8611.26;
   switch(index) {
     case 0:
         return neuron0x937e1c8();
     default:
         return 0.;
   }
}

double ParticleDis::Value(int index, double* input) {
   input0 = (input[0] - 609.663)/812.913;
   input1 = (input[1] - 1086.55)/1575.83;
   input2 = (input[2] - 7219.39)/8611.26;
   switch(index) {
     case 0:
         return neuron0x937e1c8();
     default:
         return 0.;
   }
}

double ParticleDis::neuron0x935dd40() {
   return input0;
}

double ParticleDis::neuron0x937ddc8() {
   return input1;
}

double ParticleDis::neuron0x937dfc8() {
   return input2;
}

double ParticleDis::input0x937e2f0() {
   double input = -0.802904;
   input += synapse0x935d078();
   input += synapse0x93257d8();
   input += synapse0x935dca0();
   return input;
}

double ParticleDis::neuron0x937e2f0() {
   double input = input0x937e2f0();
   return ((input < -709. ? 0. : (1/(1+exp(-input)))) * 1)+0;
}

double ParticleDis::input0x937e4a8() {
   double input = -0.70544;
   input += synapse0x937e6a8();
   input += synapse0x937e6d0();
   input += synapse0x937e6f8();
   return input;
}

double ParticleDis::neuron0x937e4a8() {
   double input = input0x937e4a8();
   return ((input < -709. ? 0. : (1/(1+exp(-input)))) * 1)+0;
}

double ParticleDis::input0x937e720() {
   double input = -1.98547;
   input += synapse0x937e938();
   input += synapse0x937e960();
   input += synapse0x937e988();
   return input;
}

double ParticleDis::neuron0x937e720() {
   double input = input0x937e720();
   return ((input < -709. ? 0. : (1/(1+exp(-input)))) * 1)+0;
}

double ParticleDis::input0x937e9b0() {
   double input = 7.47339;
   input += synapse0x937ebc8();
   input += synapse0x937ebf0();
   input += synapse0x937ec18();
   return input;
}

double ParticleDis::neuron0x937e9b0() {
   double input = input0x937e9b0();
   return ((input < -709. ? 0. : (1/(1+exp(-input)))) * 1)+0;
}

double ParticleDis::input0x937ec40() {
   double input = -1.22304;
   input += synapse0x937ee58();
   input += synapse0x937ee80();
   input += synapse0x937eea8();
   return input;
}

double ParticleDis::neuron0x937ec40() {
   double input = input0x937ec40();
   return ((input < -709. ? 0. : (1/(1+exp(-input)))) * 1)+0;
}

double ParticleDis::input0x937eed0() {
   double input = -0.780534;
   input += synapse0x937f0e8();
   input += synapse0x937f110();
   input += synapse0x935def8();
   input += synapse0x90323f0();
   input += synapse0x937f1c0();
   return input;
}

double ParticleDis::neuron0x937eed0() {
   double input = input0x937eed0();
   return ((input < -709. ? 0. : (1/(1+exp(-input)))) * 1)+0;
}

double ParticleDis::input0x937f1e8() {
   double input = 2.0788;
   input += synapse0x937f400();
   input += synapse0x937f428();
   input += synapse0x937f450();
   input += synapse0x937f478();
   input += synapse0x937f4a0();
   return input;
}

double ParticleDis::neuron0x937f1e8() {
   double input = input0x937f1e8();
   return ((input < -709. ? 0. : (1/(1+exp(-input)))) * 1)+0;
}

double ParticleDis::input0x937f4c8() {
   double input = 1.44632;
   input += synapse0x937f6e0();
   input += synapse0x937f708();
   input += synapse0x937f730();
   input += synapse0x937f758();
   input += synapse0x937f780();
   return input;
}

double ParticleDis::neuron0x937f4c8() {
   double input = input0x937f4c8();
   return ((input < -709. ? 0. : (1/(1+exp(-input)))) * 1)+0;
}

double ParticleDis::input0x937e1c8() {
   double input = 1.67091;
   input += synapse0x937f880();
   input += synapse0x937f8a8();
   input += synapse0x937f8d0();
   return input;
}

double ParticleDis::neuron0x937e1c8() {
   double input = input0x937e1c8();
   return (input * 1)+0;
}

double ParticleDis::synapse0x935d078() {
   return (neuron0x935dd40()*2.12922);
}

double ParticleDis::synapse0x93257d8() {
   return (neuron0x937ddc8()*3.17292);
}

double ParticleDis::synapse0x935dca0() {
   return (neuron0x937dfc8()*-1.71442);
}

double ParticleDis::synapse0x937e6a8() {
   return (neuron0x935dd40()*-2.31149);
}

double ParticleDis::synapse0x937e6d0() {
   return (neuron0x937ddc8()*2.15531);
}

double ParticleDis::synapse0x937e6f8() {
   return (neuron0x937dfc8()*4.4844);
}

double ParticleDis::synapse0x937e938() {
   return (neuron0x935dd40()*2.35164);
}

double ParticleDis::synapse0x937e960() {
   return (neuron0x937ddc8()*-2.02953);
}

double ParticleDis::synapse0x937e988() {
   return (neuron0x937dfc8()*-4.1989);
}

double ParticleDis::synapse0x937ebc8() {
   return (neuron0x935dd40()*-7.655);
}

double ParticleDis::synapse0x937ebf0() {
   return (neuron0x937ddc8()*0.174641);
}

double ParticleDis::synapse0x937ec18() {
   return (neuron0x937dfc8()*-3.54513);
}

double ParticleDis::synapse0x937ee58() {
   return (neuron0x935dd40()*1.62544);
}

double ParticleDis::synapse0x937ee80() {
   return (neuron0x937ddc8()*-0.518022);
}

double ParticleDis::synapse0x937eea8() {
   return (neuron0x937dfc8()*-4.24569);
}

double ParticleDis::synapse0x937f0e8() {
   return (neuron0x937e2f0()*-1.24415);
}

double ParticleDis::synapse0x937f110() {
   return (neuron0x937e4a8()*-5.40013);
}

double ParticleDis::synapse0x935def8() {
   return (neuron0x937e720()*1.67516);
}

double ParticleDis::synapse0x90323f0() {
   return (neuron0x937e9b0()*-4.97751);
}

double ParticleDis::synapse0x937f1c0() {
   return (neuron0x937ec40()*4.44946);
}

double ParticleDis::synapse0x937f400() {
   return (neuron0x937e2f0()*-4.15991);
}

double ParticleDis::synapse0x937f428() {
   return (neuron0x937e4a8()*-2.60932);
}

double ParticleDis::synapse0x937f450() {
   return (neuron0x937e720()*4.0201);
}

double ParticleDis::synapse0x937f478() {
   return (neuron0x937e9b0()*8.3468);
}

double ParticleDis::synapse0x937f4a0() {
   return (neuron0x937ec40()*1.51098);
}

double ParticleDis::synapse0x937f6e0() {
   return (neuron0x937e2f0()*-0.597815);
}

double ParticleDis::synapse0x937f708() {
   return (neuron0x937e4a8()*0.852609);
}

double ParticleDis::synapse0x937f730() {
   return (neuron0x937e720()*0.965848);
}

double ParticleDis::synapse0x937f758() {
   return (neuron0x937e9b0()*4.08365);
}

double ParticleDis::synapse0x937f780() {
   return (neuron0x937ec40()*1.69291);
}

double ParticleDis::synapse0x937f880() {
   return (neuron0x937eed0()*0.474778);
}

double ParticleDis::synapse0x937f8a8() {
   return (neuron0x937f1e8()*-1.36545);
}

double ParticleDis::synapse0x937f8d0() {
   return (neuron0x937f4c8()*-0.297118);
}

