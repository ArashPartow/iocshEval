/**
 * \file evalExprTK.hpp
 *
 * \ingroup iocshEval
 *
 * \brief expression evalator using the exprtk library
 *
 * This file hold functions for the expression evaluation.
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

#ifndef EVALEXPRTK_H_
#define EVALEXPRTK_H_

/**
  * \brief interface to exprtk
  *
  * \param expression expression to evaluate
  * \param result pointer to the result
  */
int evalExprTK(const char* expression, double *result);

#endif  /* EVALEXPRTK_H_ */
