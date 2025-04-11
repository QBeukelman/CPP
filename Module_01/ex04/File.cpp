/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   File.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbeukelm <qbeukelm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 17:04:46 by quentinbeuk       #+#    #+#             */
/*   Updated: 2025/04/11 11:25:39 by qbeukelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "File.hpp"
#include <iostream>
#include <fstream>

File::File() : fileName(""), fileData("") {}
File::File(const std::string& fileName, std::string fileData) : fileName(fileName), fileData(fileData) {}
File::~File() {}

void	File::setFileName(const std::string& newFileName) {
	this->fileName = newFileName;
}

std::string	File::getFileName() const {
	return (this->fileName);
}

void	File::setFileData(const std::string& newFileData) {
	this->fileData = newFileData;
}

std::string	File::getFileData() const {
	return (this->fileData);
}

bool	File::openFile(const std::string& fileName) {
	std::ifstream	file(fileName.c_str());
	
	if (file.is_open() == false) {
		std::cerr << "Error: Could not open file " << fileName << std::endl;
		return (false);
	}
	fileData.assign((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
	file.close();
	this->fileName = fileName;
	return (true);
}

bool	File::writeFile(const std::string& fileName, const std::string& newFileData) {
	std::ofstream	file(fileName.c_str());
	
	if (file.is_open() == false) {
		std::cerr << "Error: Could not write to file " << fileName << std::endl;
		return (false);
	}
	file << newFileData;
	file.close();
	return (true);
}
