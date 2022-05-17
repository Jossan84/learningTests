#ifndef _POLY_H
#define _POLY_H

#include "types.h"
#include "matrix.h"

/// \brief Get point by parameter substitution in polynomial (coefficients in ascending order).
/// \param[in] poly A pointer to polynomial.
/// \param[in] t A parameter value.
/// \param[out] point The point.
/// \return 0 for success.
uint8t getPointPoly(Matrix const *poly, float64t t, Matrix *point);

/// \brief Derive polynomial coefficients (coefficients in ascending order).
/// \param[in] poly A pointer to polynomial.
/// \param[in] dOrder Derivation order.
/// \param[out] dpoly A pointer to derivated polynomial.
/// \return 0 for success.
uint8t derivePoly(Matrix const *poly, uint8t dOrder, Matrix *dpoly);

#endif
