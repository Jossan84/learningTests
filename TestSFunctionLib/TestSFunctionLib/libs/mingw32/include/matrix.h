#ifndef _MATRIX_H
#define _MATRIX_H

#include "types.h"

/// \brief Matrix structure.
typedef struct
{
  /// \brief Number of rows.
  uint16t nrows;
  /// \brief Number of columns.
  uint16t ncols;
  /// \brief Pointer to data.
  float64t *data;
} Matrix;

/// \brief Set a matrix.
/// \param[in] a A pointer to matrix.
/// \param[in] data A pointer to data array.
/// \param[in] nrows Number of rows.
/// \param[in] ncols Number of columns.
/// \return 0 for success.
int8t setMatrix(Matrix *a, float64t *data, uint16t nrows, uint16t ncols);

/// \brief Initialize matrix to zero.
/// \param[in] a A pointer to matrix.
/// \return 0 for success.
int8t initZeroMatrix(Matrix *a);

/// \brief Change matrix size function. Only if (nrows * ncols) matches
/// \param[in] a A pointer to input matrix.
/// \param[in] nrows Number of output rows.
/// \param[in] ncols Number of output columns.
/// \return 0 for success.
int8t changeSizeMatrix(Matrix *a, uint16t nrows, uint16t ncols);

/// \brief Copy matrix function.
/// \param[in] a A pointer to input matrix.
/// \param[out] s A pointer to output matrix.
/// \return 0 for success.
int8t copyMatrix(Matrix const *a, Matrix *s);

/// \brief Transpose matrix function.
/// \param[in] a A pointer to input matrix.
/// \param[out] s A pointer to output matrix.
/// \return 0 for success.
int8t transposeMatrix(Matrix const *a, Matrix *s);

/// \brief Sum 2 matrices function.
/// \param[in] a A pointer to first matrix.
/// \param[in] b A pointer to second matrix.
/// \param[out] s A pointer to resulting matrix.
/// \return 0 for success.
int8t sumMatrix(Matrix const *a, Matrix const *b, Matrix *s);

/// \brief Multiply 2 matrices function.
/// \param[in] a A pointer to first matrix.
/// \param[in] b A pointer to second matrix.
/// \param[out] s A pointer to resulting matrix.
/// \return 0 for success.
int8t multMatrix(Matrix const *a, Matrix const *b, Matrix *s);

/// \brief Print matrix.
/// \param[in] a A pointer to matrix.
/// \return 0 for success.
int8t printMatrix(Matrix const *a, char const *name);

#endif
