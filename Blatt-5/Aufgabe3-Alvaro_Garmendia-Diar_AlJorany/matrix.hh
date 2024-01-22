#include <iostream>
#include <array>
#include <vector>

template<typename T, size_t N, size_t M>
class Matrix {
private:
    std::array<std::array<T, M>, N> data;

public:
    Matrix() : data({}) {}

    template <typename Container>

    void print() const {
        for (const auto &row: data) {
            for (const auto &elem: row) {
                std::cout << elem << ' ';
            }
            std::cout << '\n';
        }
    }

    T &get(size_t i, size_t j) {
        return data[i][j];
    }

    Matrix<T, M, N> transpose() const {
        Matrix<T, M, N> transposed;
        for (size_t i = 0; i < N; ++i) {
            for (size_t j = 0; j < M; ++j) {
                transposed.get(j, i) = data[i][j];
            }
        }
        return transposed;
    }

    Matrix<T, N, M> add(const Matrix<T, N, M> &other) const {
        Matrix<T, N, M> result;
        for (size_t i = 0; i < N; ++i) {
            for (size_t j = 0; j < M; ++j) {
                result.get(i, j) = data[i][j] + other.get(i, j);
            }
        }
        return result;
    }

    Matrix<T, N, M> subtract(const Matrix<T, N, M> &other) const {
        Matrix<T, N, M> result;
        for (size_t i = 0; i < N; ++i) {
            for (size_t j = 0; j < M; ++j) {
                result.get(i, j) = data[i][j] - other.get(i, j);
            }
        }
        return result;
    }

    template<size_t P>
    Matrix<T, N, P> multiply(const Matrix<T, M, P> &other) const {
        Matrix<T, N, P> result;
        for (size_t i = 0; i < N; ++i) {
            for (size_t j = 0; j < P; ++j) {
                for (size_t k = 0; k < M; ++k) {
                    result.get(i, j) += data[i][k] * other.get(k, j);
                }
            }
        }
        return result;
    }
};
