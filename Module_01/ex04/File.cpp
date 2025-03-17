/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   File.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/16 17:04:46 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/03/17 20:46:43 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "File.hpp"

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

bool File::openFile(const std::string& fileName) {
	std::ifstream file(fileName);
	if (file.is_open() == false) {
		std::cerr << "Error: Could not open file " << fileName << std::endl;
		return (false);
	}
	fileData.assign((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
	file.close();
	this->fileName = fileName;
	return (true);
}

bool File::writeFile(const std::string& fileName, const std::string& newFileData) {
	std::ofstream file(fileName);
	if (file.is_open() == false) {
		std::cerr << "Error: Could not write to file " << fileName << std::endl;
		return (false);
	}
	file << newFileData;
	file.close();
	return (true);
}
