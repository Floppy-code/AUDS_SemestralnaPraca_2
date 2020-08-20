#include "vector.h"
#include "../ds_routines.h"
#include <cstdlib>
#include <cstring>

namespace structures {

	Vector::Vector(size_t size) :
		memory_(calloc(size, 1)),
		size_(size)
	{
	}

	Vector::Vector(Vector&& other) : memory_(other.memory_), size_(other.size_)
	{
		if (this != &other)
		{
			free(other.memory_);
			other.memory_ = nullptr;
			other.size_ = 0;
		}
	}

	Vector & Vector::operator=(Vector && other)
	{
		if (this != &other)
		{
			memory_ = other.memory_;
			size_ = other.size_;
			free(other.memory_);
			other.memory_ = nullptr;
			other.size_ = 0;
		}
		return *this;
	}

	Vector::Vector(const Vector& other) :
		Vector(other.size_)
	{
		memory_ = memcpy(memory_, other.memory_, size_);
	}

	Vector::~Vector()
	{
		free(memory_);
		memory_ = nullptr;
		size_ = 0;
	}

	Structure* Vector::clone() const
	{
		return new Vector(*this);
	}

	size_t Vector::size() const
	{
		return size_;
	}

	Structure & Vector::operator=(const Structure & other)
	{
		if (this != &other)
		{
			*this = dynamic_cast<const Vector&>(other);
		}
		return *this;
	}

	Vector& Vector::operator=(const Vector& other)
	{
		if (this != &other)
		{
			size_ = other.size_;
			memory_ = realloc(memory_, size_);
			memory_ = memcpy(memory_, other.memory_, size_);
		}
		return *this;
	}

	bool Vector::operator==(const Vector& other) const
	{
		return (this == &other) || ((size_ == other.size_) && !memcmp(memory_, other.memory_, size_));
	}

	byte& Vector::operator[](const int index)
	{
		DSRoutines::rangeCheckExcept(index, size_, "Invalid index!");
		return *(reinterpret_cast<byte*>(memory_) + index);
	}

	byte Vector::operator[](const int index) const
	{
		DSRoutines::rangeCheckExcept(index, size_, "Invalid index!");
		return *(reinterpret_cast<byte*>(memory_) + index);
	}

	byte& Vector::readBytes(const int index, const int count, byte& dest)
	{
		DSRoutines::rangeCheckExcept(index, size_, "Invalid index!");
		DSRoutines::rangeCheckExcept(index + count - 1, size_, "Invalid index + count!");

		memcpy(&dest, getBytePointer(index), count);
		return dest;
	}

	void Vector::copy(const Vector& src, const int srcStartIndex, Vector& dest, const int destStartIndex, const int length)
	{
		//DSRoutines::rangeCheckExcept(srcStartIndex, src.size_, "Invalid src index!");
		DSRoutines::rangeCheckExcept(srcStartIndex + length - 1, src.size_, "Invalid src index + count!");

		//DSRoutines::rangeCheckExcept(destStartIndex, dest.size_, "Invalid dest index!");
		DSRoutines::rangeCheckExcept(destStartIndex + length - 1, dest.size_, "Invalid dest index + count!");

		if ((src == dest) && ((destStartIndex >= srcStartIndex && destStartIndex < srcStartIndex + length) || (srcStartIndex >= destStartIndex && srcStartIndex < destStartIndex + length)))
		{
			memmove(dest.getBytePointer(destStartIndex), src.getBytePointer(srcStartIndex), length);
		}
		else 
		{
			memcpy(dest.getBytePointer(destStartIndex), src.getBytePointer(srcStartIndex), length);
		}
	}

	byte* Vector::getBytePointer(const int index) const
	{
		DSRoutines::rangeCheckExcept(index, size_, "Invalid index!");
		return reinterpret_cast<byte*>(memory_) + index;
	}
}