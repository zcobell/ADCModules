#include "pixel.h"
#include <limits>

Pixel::Pixel() { this->setInvalid(); }

Pixel::Pixel(size_t i, size_t j) {
  this->m_i = i;
  this->m_j = j;
  return;
}

void Pixel::set(const size_t &i, const size_t &j) {
  this->m_i = i;
  this->m_j = j;
  return;
}

size_t Pixel::i() const { return this->m_i; }

size_t Pixel::j() const { return this->m_j; }

bool Pixel::isValid() {
  return this->m_i < std::numeric_limits<size_t>::max() &&
         this->m_j < std::numeric_limits<size_t>::max();
}

void Pixel::setInvalid() {
  this->m_i = std::numeric_limits<size_t>::max();
  this->m_j = this->m_i;
}