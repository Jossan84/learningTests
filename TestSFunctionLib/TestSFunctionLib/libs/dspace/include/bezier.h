#ifndef _BEZIER_H
#define _BEZIER_H

#include "types.h"
#include "matrix.h"

/// \brief Bezier structure.
typedef struct
{
  /// \brief Bezier degree.
  uint8t degree;
  /// \brief Bezier id.
  uint16t id;
  /// \brief Bezier length [m].
  float64t length;
  /// \brief Pointer to bezier coefficients polynomials.
  Matrix *bezierCoeffsPoly;
  /// \brief Pointer to bezier points.
  Matrix *bezierPoints;
} Bezier;

/// \brief Set bezier.
/// \param[out] bezier A pointer to bezier.
/// \param[in] bezierPoints A pointer to bezier points.
/// \param[in] bezierCoeffsPoly A pointer to bezier coefficients polynomial.
/// \param[in] id Bezier id.
/// \return 0 for success.
int8t setBezier(Bezier *bezier, Matrix *bezierPoints, Matrix *bezierCoeffsPoly, uint16t id);

/// \brief Get point by parameter substitution in polynomial (coefficients in ascending order).
/// \param[in] poly A pointer to polynomial.
/// \param[in] t A parameter value.
/// \param[out] point The point.
/// \return 0 for success.
uint8t getPointBezier(Bezier const *bezier, float64t t, Matrix *point);

#endif
