/**
 * \file iocshEval.hpp
 *
 * \defgroup iocshEval
 *
 * \brief Provides iocshFunctions for expression evaluation
 *
 * This package provides the ability to evaluated mathematical expression
 *
 * \note this is work in progress
 *
 * \author Dr. Niko Kivel
 *
 * \version 0.1
 *
 * \date 2020/04
 *
 * Contact: niko.kivel@psi.ch
 *
 */

#ifndef IOCSHEVAL_H_
#define IOCSHEVAL_H_

/**
  * \brief ternary evalation, result >=1 ==> TRUE, result <1 ==> FALSE
  *
  * \param envVarName iocsh environment variable to set
  * \param expression expression to evaluate
  * \param trueString string to set the envVar to if TRUE
  * \param falseString string to set the envVar to if FALSE
*/
int epicsEnvSetTernary(const char *envVarName, const char *expression, const char *trueString, const char *falseString);

#endif  /* IOCSHEVAL_H_ */
