/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 18:10:54 by mtigunit          #+#    #+#             */
/*   Updated: 2024/01/02 09:05:04 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

template <typename T>
class Array {
	private:
		unsigned int	_length;
		T				*_data;
	public:
		Array();
		Array(const Array& copy);
		Array&	operator=(const Array& src);
		~Array();

		Array(unsigned int n);
		T&	operator[](unsigned int index);
		unsigned int	size() const;
};

template <typename T>
Array<T>::Array() : _length(0) {
	_data = new T[_length];
}

template <typename T>
Array<T>::Array(unsigned int n) : _length(n), _data(new T[n]) {
	for (size_t i = 0; i < n; i++) {
		_data[i] = T();
	}
}

template <typename T>
Array<T>::Array(const Array& copy) : _length(copy.size()), _data(new T[_length]) {
	*this = copy;
}

template <typename T>
Array<T>&	Array<T>::operator=(const Array& src) {
	if (this != &src) {
		if (_data) {
			delete[] _data;
			_data = NULL;
		}
		if (src.size()) {
			_length = src.size();
			_data = new T[_length];
			for (unsigned int i = 0; i < _length; ++i) {
				_data[i] = src._data[i];
			}
		}
	}
	return (*this);
}

template <typename T>
Array<T>::~Array() {
    if (_data) {
		delete[] _data;
	}
}

template <typename T>
T& Array<T>::operator[](unsigned int index) {
	if (index >= _length || _data == nullptr) {
		throw std::out_of_range("Index out of range");
	}
	return (_data[index]);
}

template <typename T>
unsigned int	Array<T>::size() const {
	return (_length);
}
