#pragma once
#include<exception>
#include<string>

class ParserException : public std::exception {};

class invalidInputData : public ParserException {
public:
	const char* what() const noexcept override {
		return "Input data is invalid";
	}
};