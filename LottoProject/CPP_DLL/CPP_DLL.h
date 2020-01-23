// LottoDllCpp.h - Contains declarations of functions
#pragma once

#ifdef LOTTODLLCPP_EXPORTS
#define LOTTODLLCPP_API __declspec(dllexport)
#else
#define LOTTODLLCPP_API __declspec(dllimport)
#endif


extern "C" LOTTODLLCPP_API int numberOfHits(int*generatedNumbers, int*numbersFromFile);

extern "C" LOTTODLLCPP_API int calculatePrices(int*numbersOfWins, int*winForOnePerson, int poolOfMoney);

