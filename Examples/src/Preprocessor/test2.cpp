#include <iostream>

#ifdef PIPPO
// If pippo is defined this part of text will be contained in
// the output file
#endif

#ifdef PLUTO
std::cout<<"Fatta"<<std::endl;
//If pluto is defined this part of text will be contained in
//the output file
#endif
