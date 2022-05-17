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
/// \param[out] matrix A pointer to matrix.
/// \param[in] data A pointer to data array.
/// \param[in] nrows Number of rows.
/// \param[in] ncols Number of columns.
/// \return 0 for success.
int8t setMatrix(Matrix *matrix, float64t *data, uint16t nrows, uint16t ncols);

/// \brief Initialize matrix to zero.
/// \param[in] matrix A pointer to matrix.
/// \return 0 for success.
int8t initZeroMatrix(Matrix *matrix);

/// \brief Change matrix size function. Only if (nrows * ncols) matches
/// \param[in] matrix A pointer to input matrix.
/// \param[in] nrows Number of output rows.
/// \param[in] ncols Number of output columns.
/// \return 0 for success.
int8t changeSizeMatrix(Matrix *matrix, uint16t nrows, uint16t ncols);

/// \brief Copy matrix function.
/// \param[in] matrixInput A pointer to input matrix.
/// \param[out] matrixOutput A pointer to output matrix.
/// \return 0 for success.
int8t copyMatrix(Matrix const *matrixInput, Matrix *matrixOutput);

/// \brief Transpose matrix function.
/// \param[in] matrixInput A pointer to input matrix.
/// \param[out] matrixOutput A pointer to output matrix.
/// \return 0 for success.
int8t transposeMatrix(Matrix const *matrixInput, Matrix *matrixOutput);

/// \brief Sum 2 matrices function.
/// \param[in] matrixInput1 A pointer to first matrix.
/// \param[in] matrixInput2 A pointer to second matrix.
/// \param[out] matrixOutput A pointer to resulting matrix.
/// \return 0 for success.
int8t sumMatrix(Matrix const *matrixInput1, Matrix const *matrixInput2, Matrix *matrixOutput);

/// \brief Multiply 2 matrices function.
/// \param[in] matrixInput1 A pointer to first matrix.
/// \param[in] matrixInput2 A pointer to second matrix.
/// \param[out] matrixOutput A pointer to resulting matrix.
/// \return 0 for success.
int8t multMatrix(Matrix const *matrixInput1, Matrix const *matrixInput2, Matrix *matrixOutput);

/// \brief Print matrix.
/// \param[in] matrix A pointer to matrix.
/// \return 0 for success.
int8t printMatrix(Matrix const *matrix, char const *name);

#endif
